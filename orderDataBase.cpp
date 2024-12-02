#include "orderDataBase.hpp"
#include <tuple>

// Constructor to set the file name for the database
OrderDatabase::OrderDatabase(const std::string& fileName) : fileName(fileName) {}

// Adds an order to the internal order data and prepares it for saving to CSV
void OrderDatabase::addOrder(int orderNumber, const std::string& date, const std::vector<std::tuple<int, std::string, int>>& items, const std::string& specialRequest) {
    formatOrder(orderNumber, date, items, specialRequest);
    saveOrderToCSV();
}

// Formats the order data into a CSV-friendly format
void OrderDatabase::formatOrder(int orderNumber, const std::string& date, const std::vector<std::tuple<int, std::string, int>>& items, const std::string& specialRequest) {
    std::stringstream ss;
    ss << orderNumber << "," << date;

    // For each item in the order, append its details to the CSV string
    for (const auto& item : items) {
        ss << "," << std::get<0>(item) << "," << std::get<1>(item) << "," << std::get<2>(item);
    }

    // Add the special request
    ss << "," << specialRequest;

    // Store the formatted order in the vector for later use
    currentOrderData.push_back(ss.str());
}

//addOrder() with name and price
void OrderDatabase::addOrder(int orderNumber, const std::string& date, const std::string &orderName, float totalPrice, const std::vector<std::tuple<int, std::string, int>>& items, const std::string& specialRequest)
{
    formatOrder(orderNumber, date, orderName, totalPrice, items, specialRequest);
    saveOrderToCSV();
}

//formatOrder() with name and price
void OrderDatabase::formatOrder(int orderNumber, const std::string& date, const std::string &orderName, float totalPrice, const std::vector<std::tuple<int, std::string, int>>& items, const std::string& specialRequest)
{
    std::stringstream ss;
    ss << orderNumber << "," << date << "," << orderName << "," << totalPrice;

    // For each item in the order, append its details to the CSV string
    for (const auto& item : items) {
        ss << "," << std::get<0>(item) << "," << std::get<1>(item) << "," << std::get<2>(item);
    }

    // Add the special request
    ss << "," << specialRequest;

    // Store the formatted order in the vector for later use
    currentOrderData.push_back(ss.str());
}

// Saves the current order data to the CSV file
void OrderDatabase::saveOrderToCSV() {
    std::ofstream outFile;

    // Open the file in append mode so we don't overwrite existing orders
    outFile.open(fileName, std::ios::app);
    if (outFile.is_open()) {
        for (const auto& order : currentOrderData) {
            outFile << order << "\n";
        }
        outFile.close();
        currentOrderData.clear();
    } else {
        std::cerr << "Error: Could not open the file." << std::endl;
    }
}

// Reads all the orders from the CSV file
std::vector<std::string> OrderDatabase::readOrders() {
    std::vector<std::string> orders;
    std::ifstream inFile(fileName);
    std::string line;

    if (inFile.is_open()) {
        while (std::getline(inFile, line)) {
            orders.push_back(line);
        }
        inFile.close();
    } else {
        std::cerr << "Error: Could not read the file." << std::endl;
    }

    return orders;
}


