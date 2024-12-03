#include "shoppingCart.hpp"
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>

shoppingCart::shoppingCart()
{
    this->orderName = "";
}

shoppingCart::shoppingCart(string newOrderName)
{
    this->orderName = newOrderName;
}

void shoppingCart::addToCart(const menuItem &newItem)
{
    this->cart.push_back(newItem);
}

void shoppingCart::removeFromCart(const string &itemToRemove)
{
   /* auto it = find(this->cart.begin(), this->cart.end(), itemToRemove);
    if (it != this->cart.end())
    {
        this->cart.erase(it);
        cout << itemToRemove.getItemName() << " has been removed from your cart!" << endl;
    } */

   cart.erase(std::remove_if(cart.begin(), cart.end(), [&itemToRemove](const menuItem& item) {return item.getItemName() == itemToRemove;}), cart.end());
    
}

// Decided to combine displayCart() and displayTotalPrice() into one function
void shoppingCart::displayCart()
{
    float totalPrice = 0.0;
    for (const auto& item : cart)
    {
        cout << "orderName: " << this->orderName << ", itemID: " << item.getItemID() << ", itemName: " << item.getItemName() << ", itemQuantity: " << item.getItemQuantity() << endl;
        totalPrice += item.getItemPrice();
    }
    cout << "The total price of " << this->orderName << "'s shopping cart is: $" << totalPrice << endl;
}

void shoppingCart::addToCart(const tuple<int, string, int>& newItem)
{
    this->tupleCart.push_back(newItem);
}

float shoppingCart::getTotalPrice()
{
    float totalPrice = 0.0;
    for (const auto& item : cart)
    {
        totalPrice += item.getItemPrice();
    }
    return totalPrice;
}

void shoppingCart::displayTotalPrice()
{
    float totalPrice = getTotalPrice();
    cout << "The total price of " << this->orderName << "'s shopping cart is: $" << totalPrice << endl;
}

void shoppingCart::setOrderName(string newOrderName)
{
    this->orderName = newOrderName;
}

string shoppingCart::getOrderName()
{
    return this->orderName;
}

/* void shoppingCart::readCreditCards(ifstream cardFile, vector<string>& cards)
{
     ifstream cardFile;
    cardFile.open("../creditCards.txt");
    //string cards[10];
    string line;  
    
    if (cardFile.is_open())
    {
        while (getline(cardFile, line))
        {
            //cout << line << endl;
            cards.push_back(line);
        }
    }
    else
    {
        cout << "Unable to open file!" << endl;
    }
}
 */
bool shoppingCart::verifyPayment(const std::string &CardNum)
{
    //temporary implementation of payment verification. Will change later
    /* string realCardNum = "12345";
    string cardNum = "0";
    do
    {
        cout << "Enter a valid credit card number to complete payment: (12345 is valid)" << endl;
        cin >> cardNum;
        if (cardNum != realCardNum)
        {
            cout << "That is not a valid credit card number!" << endl;
        }
        
    } while (cardNum != realCardNum);
     */
    vector<string> cards;
    ifstream cardFile;
    cardFile.open("creditCards.txt");
    string line;  
    
    if (cardFile.is_open())
    {
        while (getline(cardFile, line))
        {
            //cout << line << endl;
            cards.push_back(trim(line));
        }
        cardFile.close();
    }
    else
    {
        cout << "Unable to open file!" << endl;
        return false;
    }
    
    string cardNum = "0";
    cardNum = CardNum;
    //do
    //{
        cout << "Enter a valid credit card number to complete payment: (12345 is valid)" << endl;
        //cin >> cardNum;
        cardNum = trim(cardNum);
        cout << "cardNum in verifyPayment: " << cardNum << endl;
        if (std::find(cards.begin(), cards.end(), cardNum) != cards.end())
        {
            cout << "Payment has been completed!" << endl;
            return true;
        }
        else
        {
            cout << "That is not a valid credit card number!" << endl;
            return false;
        }
        
    //} while (std::find(cards.begin(), cards.end(), cardNum) == cards.end());
    
    
}

std::string shoppingCart::trim(const std::string &str) {
    if (str.empty()) {
        return str;  // Return the string if it's empty
    }

    size_t first = str.find_first_not_of(' ');
    if (first == std::string::npos) {
        return "";  // If no non-space character is found, return an empty string
    }

    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

float shoppingCart::calculateTotalPrice() const {
    float totalPrice = 0.0;
    for (const auto &item : cart) {
        totalPrice += item.getItemPrice();
    }
    return totalPrice;
}

shoppingCart &shoppingCart::operator=(const shoppingCart &rhs)
{
    cart = rhs.cart;
    return *this;
}

void shoppingCart::clearCart() {
    cart.clear();
}
