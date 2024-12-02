#include "analytics.hpp"
#include "orderDataBase.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <cctype>

Analytics::Analytics(const std::string& ordersFileName) : ordersFileName(ordersFileName) {
    loadOrders();
}

void Analytics::loadOrders() {
    OrderDatabase orderDB(ordersFileName);
    ordersData = orderDB.readOrders();

    // Now parse the ordersData into orders
    for (const std::string& line : ordersData) {
        std::stringstream ss(line);
        std::vector<std::string> fields;
        std::string field;

        // Split the line by commas
        while (std::getline(ss, field, ',')) {
            fields.push_back(field);
        }

        // Parse the order
        if (fields.size() < 2) {
            continue; // Invalid order line
        }

        size_t index = 0;
        int orderNumber = std::stoi(fields[index++]);
        std::tm date = parseDate(fields[index++]);

        // Adding stuff -Shian
        std::string orderName = fields[index++];
        float totalPrice = std::stof(fields[index++]);

        // Parse items
        std::vector<std::tuple<int, int>> items;
        try {
            items = parseOrderItems(fields, index);
        } catch (const std::exception& e) {
            std::cerr << "Error parsing items: " << e.what() << std::endl;
            continue;
        }

        // Add the order to orders vector
        orders.push_back(std::make_tuple(date, items));
    }
}

std::tm Analytics::parseDate(const std::string& dateStr) {
    std::tm tm_date = {};
    std::istringstream ss(dateStr);
    ss >> std::get_time(&tm_date, "%Y-%m-%d");
    if (ss.fail()) {
        std::cerr << "Failed to parse date: " << dateStr << std::endl;
    }
    return tm_date;
}

std::vector<std::tuple<int, int>> Analytics::parseOrderItems(const std::vector<std::string>& fields, size_t& index) {
    std::vector<std::tuple<int, int>> items;

    while (index + 2 < fields.size()) {
        // Try to read ItemID (int)
        int itemID;
        try {
            itemID = std::stoi(fields[index++]);
        } catch (const std::invalid_argument&) {
            // If we cannot parse an int, we have reached the special request or end of line
            // So, we break
            break;
        }

        // Read ItemName (string)
        std::string itemName = fields[index++];

        // Read ItemQuantity (int)
        int itemQuantity;
        try {
            itemQuantity = std::stoi(fields[index++]);
        } catch (const std::invalid_argument&) {
            throw std::runtime_error("Invalid item quantity.");
        }

        // Add item to items vector
        items.push_back(std::make_tuple(itemID, itemQuantity));
    }

    return items;
}

void Analytics::runAnalytics() {
    promptTimeRange();
    promptAnalyticsType();
}

void Analytics::promptTimeRange() {
    std::cout << "Select a time range for the analytics:\n";
    std::cout << "1. Last 7 days\n";
    std::cout << "2. Last 30 days\n";
    std::cout << "3. Last 365 days\n";
    std::cout << "4. Custom range\n";
    std::cout << "Enter your choice (1-4): ";

    int choice;
    std::cin >> choice;

    // Get the current date
    std::time_t t = std::time(nullptr);
    std::tm now = *std::localtime(&t);

    switch (choice) {
        case 1:
            startDate = now;
            startDate.tm_mday -= 7;
            std::mktime(&startDate);
            endDate = now;
            break;
        case 2:
            startDate = now;
            startDate.tm_mday -= 30;
            std::mktime(&startDate);
            endDate = now;
            break;
        case 3:
            startDate = now;
            startDate.tm_mday -= 365;
            std::mktime(&startDate);
            endDate = now;
            break;
        case 4: {
            // Prompt user for custom date range
            std::string startStr, endStr;
            std::cout << "Enter start date (YYYY-MM-DD): ";
            std::cin >> startStr;
            std::cout << "Enter end date (YYYY-MM-DD): ";
            std::cin >> endStr;

            startDate = parseDate(startStr);
            endDate = parseDate(endStr);
            break;
        }
        default:
            std::cout << "Invalid choice. Defaulting to last 7 days.\n";
            startDate = now;
            startDate.tm_mday -= 7;
            std::mktime(&startDate);
            endDate = now;
            break;
    }
}

void Analytics::promptAnalyticsType() {
    std::cout << "Select the analytics you want to perform:\n";
    std::cout << "1. Most orders placed in a single day over that time range\n";
    std::cout << "2. Most ordered food item during that time range\n";
    std::cout << "Enter your choice (1-2): ";

    int choice;
    std::cin >> choice;

    switch (choice) {
        case 1:
            calculateMostOrdersInSingleDay();
            break;
        case 2:
            calculateMostOrderedItem();
            break;
        default:
            std::cout << "Invalid choice.\n";
            break;
    }
}

bool Analytics::isDateInRange(const std::tm& date) {
    std::time_t date_time = std::mktime(const_cast<std::tm*>(&date));
    std::time_t start_time = std::mktime(&startDate);
    std::time_t end_time = std::mktime(&endDate);

    return date_time >= start_time && date_time <= end_time;
}

void Analytics::calculateMostOrdersInSingleDay() {
    // Map to store the count of orders per day
    std::map<std::string, int> ordersPerDay;

    for (const auto& order : orders) {
        const std::tm& date = std::get<0>(order);
        if (isDateInRange(date)) {
            // Format date as YYYY-MM-DD
            char buffer[11];
            std::strftime(buffer, 11, "%Y-%m-%d", &date);
            std::string dateStr(buffer);

            ordersPerDay[dateStr]++;
        }
    }

    // Find the date with the most orders
    int maxOrders = 0;
    std::string maxDate;
    for (const auto& pair : ordersPerDay) {
        if (pair.second > maxOrders) {
            maxOrders = pair.second;
            maxDate = pair.first;
        }
    }

    std::cout << "The date with the most orders is " << maxDate << " with " << maxOrders << " orders.\n";
}

void Analytics::calculateMostOrderedItem() {
    // Map to store the total quantity of each item
    std::map<int, int> itemQuantities; // ItemID -> TotalQuantity

    for (const auto& order : orders) {
        const std::tm& date = std::get<0>(order);
        if (isDateInRange(date)) {
            const auto& items = std::get<1>(order);
            for (const auto& item : items) {
                int itemID = std::get<0>(item);
                int quantity = std::get<1>(item);
                itemQuantities[itemID] += quantity;
            }
        }
    }

    // Find the item with the most total quantity
    int maxQuantity = 0;
    int maxItemID = 0;
    for (const auto& pair : itemQuantities) {
        if (pair.second > maxQuantity) {
            maxQuantity = pair.second;
            maxItemID = pair.first;
        }
    }

    std::cout << "The most ordered item is Item ID " << maxItemID << " with a total of " << maxQuantity << " units ordered.\n";
}
