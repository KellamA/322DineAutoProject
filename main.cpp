#include "iostream"
#include <vector>
#include <tuple>    
#include "orderDataBase.hpp"
#include "shoppingCart.hpp"

int main() {
    std::string fileName = "../orders.csv"; // Specify the name of the CSV file
    // generic file name so it can find it on any of our computers
    OrderDatabase orderDB(fileName);
//Everyting between this and the comment marker "END" is test code for now and should be removed later
    int orderNumber;
    std::string date;
    int numItems;
    std::string specialRequest;

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
    menuItem newItem(123456, "Bob", 2);
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
    cart.displayCart();

    return 0;

}


