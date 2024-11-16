#include <iostream>
#include <vector>
#include <tuple>    
#include <filesystem>

#include "orderDataBase.hpp"
#include "shoppingCart.hpp"
#include "menu.hpp"
#include "menuItem.hpp"

int main() {
    std::string fileName = "../orders.csv"; // Specify the name of the CSV file
    // generic file name so it can find it on any of our computers
    OrderDatabase orderDB(fileName);

    int logIn;
    
    std::cout << "Please login: (1 customer, 2 admin, anything else ends)" << endl;
    std::cin >> logIn;

    int orderNumber;
    std::string date;
    int numItems;
    std::string specialRequest;

    switch(logIn){
    case 1: {       
        std::string filename = "../menu.csv"; // if debugging it needs to be menu.csv, if running build it needs to be ../menu.csv

        menu m;
        vector<menu> Menu = m.getMenu(filename);
        std::vector<std::tuple<int, std::string, int>> items1;
        
        if(!Menu.empty())
        {
            m.displayItem(Menu);
            items1 = m.menuSelect(Menu);
        }
        else{
            cout << "Menu is empty or file not found." << endl;
            break;
        }
        
        std::cout << "What is todays date? ";
        std::cin >> date;
        std::cin.ignore();
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

        std::cout << "Enter order date (format: YYYY-MM-DD): ";
        std::getline(std::cin, date);

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


        // END
        
        // shoppingCart tests
        /* menuItem newItem(123456, "Bob", 2);
        shoppingCart cart;
        cart.addToCart(newItem);

            menuItem frenchFries;
            frenchFries.setItemID(22222);
            frenchFries.setItemName("French fries");
            frenchFries.setItemQuantity(5);

            cart.addToCart(frenchFries);

            cout << endl << "Cart before removal:" << endl;
            cart.displayCart();

        cout << endl << "Cart after removal:" << endl;
        cart.removeFromCart("Bob");
        cart.displayCart(); */

        // price of shopping cart tests
        

        shoppingCart cart("Bob");
        menuItem fries(12345, "fries", 5, 12.40);
        cart.addToCart(fries);
        menuItem burger(4231, "burger", 3, 4.20);
        cart.addToCart(burger);
        cart.displayCart();
        cart.displayTotalPrice();
        //cart.readCreditCards(cardFile, cards);
        cart.verifyPayment();
        

        return 0;
    }
}
}


