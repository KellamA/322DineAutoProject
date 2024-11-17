#include <iostream>
#include <vector>
#include <tuple>    
#include <filesystem>
#include <fstream>     // For file handling
#include <sstream>     // For string streams
#include <string>      // For std::string
#include <map>         // For std::map
#include <vector>      // For std::vector
#include <algorithm>   // For std::max_element
#include <ctime>       // For time and date handling
#include <iomanip>     // For std::get_time (date parsing)


#include "orderDataBase.hpp"
#include "shoppingCart.hpp"
#include "menu.hpp"
#include "menuItem.hpp"
#include "analytics.hpp"
int main() {
    std::string fileName = "../orders.csv"; // Specify the name of the CSV file
    // generic file name so it can find it on any of our computers
    OrderDatabase orderDB(fileName);

    int logIn;
    
    std::cout << "Please login: (1 customer, 2 admin, 3 Analytics Test, anything else ends)" << endl;
    std::cin >> logIn;

    int orderNumber;
    std::string date;
    int numItems;
    std::string specialRequest;

    string name;

    switch(logIn){
    case 1: {       
        std::string filename = "../menu.csv"; // if debugging it needs to be menu.csv, if running build it needs to be ../menu.csv

    menu m;
    vector<menu> Menu = m.getMenu(filename);
    std::vector<std::tuple<int, std::string, int>> items1;
    
    if (!Menu.empty()) {
        m.displayItem(Menu);
        items1 = m.menuSelect(Menu);
    } else {
        std::cout << "Menu is empty or file not found." << std::endl;
        break;
    }

    // Get the current date in YYYY-MM-DD format
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);
    std::ostringstream dateStream;
    dateStream << std::put_time(now, "%Y-%m-%d");
    date = dateStream.str(); // Store the current date in 'date'

    std::cout << "Date automatically set to: " << date << "\n";

    std::cout << "Enter any special requests (or leave blank if none): ";
    std::getline(std::cin, specialRequest);

    // Add the order to the database
    orderDB.addOrder(5, date, items1, specialRequest);

    std::cout << "Order has been added to the database.\n";
    break;
    }
    case 2: {
        // Manually enter order details
    std::cout << "Enter order number: ";
    std::cin >> orderNumber;

    std::cin.ignore(); // Ignore the leftover newline character from previous input

    // Get the current date in YYYY-MM-DD format
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);
    std::ostringstream dateStream;
    dateStream << std::put_time(now, "%Y-%m-%d");
    date = dateStream.str(); // Store the current date in 'date'

    std::cout << "Order date automatically set to: " << date << "\n";

    std::cout << "Enter the number of items in the order: ";
    std::cin >> numItems;

    std::vector<std::tuple<int, std::string, int>> items;

    // For each item, ask for the item ID, name, and quantity
    for (int i = 0; i < numItems; i++) {
        int itemID;
        std::string itemName;
        int itemQuantity;

        std::cout << "Enter details for item " << i + 1 << ":\n";
        std::cout << "Item ID: ";
        std::cin >> itemID;

        std::cin.ignore(); // Ignore the newline character

        std::cout << "Item name: ";
        std::getline(std::cin, itemName);

        std::cout << "Item quantity: ";
        std::cin >> itemQuantity;

        // Add the item to the vector
        items.push_back(std::make_tuple(itemID, itemName, itemQuantity));
    }

    std::cin.ignore(); // Ignore the newline character before entering special requests

    // Ask for any special request
    std::cout << "Enter any special requests (or leave blank if none): ";
    std::getline(std::cin, specialRequest);

    // Add the order to the database
    orderDB.addOrder(orderNumber, date, items, specialRequest);

    std::cout << "Order has been added to the database.\n";

        
    
        return 0;
    }
    case 3:
    {
        Analytics analytics(fileName);
        analytics.runAnalytics();

    }
}
}


