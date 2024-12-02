#include "queue.hpp"
#include "orderDataBase.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <thread>
#include <limits>

OrderQueue::OrderQueue(const std::string& ordersFileName) : ordersFileName(ordersFileName), running(true) {}

void OrderQueue::run() {
    // Start the input thread
    std::thread inputThread(&OrderQueue::inputThreadFunction, this);

    while (running) {
        loadOrders();
        displayOrders();

        // Wait for 15 seconds or until notified to stop
        std::unique_lock<std::mutex> lk(ordersMutex);
        cv.wait_for(lk, std::chrono::seconds(15));
    }

    // Join the input thread before exiting
    if (inputThread.joinable()) {
        inputThread.join();
    }
}

void OrderQueue::loadOrders() {
    // Load orders from the orders.csv file
    OrderDatabase orderDB(ordersFileName);
    std::vector<std::string> ordersData = orderDB.readOrders();

    std::string currentDate = getCurrentDate();

    // Temporary vector to store new orders
    std::vector<Order> newOrders;

    // Parse orders
    for (const std::string& line : ordersData) {
        std::stringstream ss(line);
        std::vector<std::string> fields;
        std::string field;

        while (std::getline(ss, field, ',')) {
            fields.push_back(field);
        }

        if (fields.size() < 2) continue;

        size_t index = 0;
        int orderNumber = std::stoi(fields[index++]);
        std::string date = fields[index++];

        if (date != currentDate) continue; // Only process today's orders

        // Check if order has been cleared
        {
            std::lock_guard<std::mutex> lg(clearedOrdersMutex);
            if (std::find(clearedOrderNumbers.begin(), clearedOrderNumbers.end(), orderNumber) != clearedOrderNumbers.end()) {
                continue;
            }
        }

        // Parse name and price
        std::string orderName = fields[index++];
        float totalPrice = std::stof(fields[index++]);

        // Parse items
        std::vector<std::tuple<int, std::string, int>> items;
        while (index + 2 < fields.size()) {
            // ItemID
            int itemID;
            try {
                itemID = std::stoi(fields[index++]);
            } catch (...) {
                break;
            }

            // ItemName
            std::string itemName = fields[index++];

            // Quantity
            int quantity;
            try {
                quantity = std::stoi(fields[index++]);
            } catch (...) {
                break;
            }

            items.push_back(std::make_tuple(itemID, itemName, quantity));
        }

        // Special Request
        std::string specialRequest = "";
        if (index < fields.size()) {
            specialRequest = fields[index];
        }

        Order order;
        order.orderNumber = orderNumber;
        order.date = date;
        order.orderName = orderName;
        order.totalPrice = totalPrice;
        order.items = items;
        order.specialRequest = specialRequest;

        newOrders.push_back(order);
    }

    // Update the orders vector safely
    {
        std::lock_guard<std::mutex> lg(ordersMutex);
        orders = std::move(newOrders);
    }
}

void OrderQueue::displayOrders() {
    // Clear the screen
    #if defined _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    std::vector<Order> currentOrders;

    // Copy the orders to avoid holding the mutex while displaying
    {
        std::lock_guard<std::mutex> lg(ordersMutex);
        currentOrders = orders;
    }

    // Lock output mutex to synchronize output
    std::lock_guard<std::mutex> outputLock(outputMutex);

    std::cout << "Current Orders:\n";
    if (currentOrders.empty()) {
        std::cout << "No orders in the queue.\n";
    } else {
        for (const auto& order : currentOrders) {
            std::cout << "Order Number: " << order.orderNumber << "\n";
            int totalItems = 0;
            for (const auto& item : order.items) {
                totalItems += std::get<2>(item);
            }
            if (!order.orderName.empty()) {
                std::cout << "Order Name: " << order.orderName << "\n";
            }
            std::cout << "Total Price: $" << order.totalPrice << "\n";
            std::cout << "Total Items: " << totalItems << "\n";
            std::cout << "Items:\n";
            for (const auto& item : order.items) {
                std::cout << " - Item ID: " << std::get<0>(item)
                          << ", Name: " << std::get<1>(item)
                          << ", Quantity: " << std::get<2>(item) << "\n";
            }
            if (!order.specialRequest.empty()) {
                std::cout << "Special Request: " << order.specialRequest << "\n";
            }
            std::cout << "-----------------------------\n";
        }
    }
}

void OrderQueue::inputThreadFunction() {
    while (running) {
        int clearOrderNumber;

        {
            // Lock output mutex before displaying the prompt
            std::lock_guard<std::mutex> outputLock(outputMutex);
            std::cout << "Enter Order Number to clear (or 0 to skip): ";
            std::cout.flush();
        }

        std::cin >> clearOrderNumber;

        // Clear the input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (std::cin.eof() || std::cin.fail()) {
            // If end-of-file or input stream error occurs, stop running
            running = false;
            cv.notify_all(); // Wake up the main thread to exit
            break;
        }

        if (clearOrderNumber != 0) {
            clearOrder(clearOrderNumber);
        }
    }
}

void OrderQueue::clearOrder(int orderNumber) {
    bool orderFound = false;

    {
        std::lock_guard<std::mutex> lg(ordersMutex);
        auto it = std::remove_if(orders.begin(), orders.end(),
            [orderNumber](const Order& order) {
                return order.orderNumber == orderNumber;
            });
        if (it != orders.end()) {
            orders.erase(it, orders.end());
            orderFound = true;
        }
    }

    {
        // Lock output mutex before printing messages
        std::lock_guard<std::mutex> outputLock(outputMutex);
        if (orderFound) {
            std::lock_guard<std::mutex> lg(clearedOrdersMutex);
            clearedOrderNumbers.push_back(orderNumber);
            std::cout << "Order " << orderNumber << " has been cleared.\n";
        } else {
            std::cout << "Order number not found.\n";
        }
        // Move the prompt to the next line
        std::cout << std::flush;
    }
}

std::string OrderQueue::getCurrentDate() {
    // Get current date in YYYY-MM-DD format
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);
    char buffer[11];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", now);
    return std::string(buffer);
}
