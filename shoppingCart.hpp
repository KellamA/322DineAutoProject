#ifndef SHOPPINGCART_HPP 
#define SHOPPINGCART_HPP

#include "menuItem.hpp"
#include <vector>

class shoppingCart
{
public:
    shoppingCart();
    shoppingCart(string newOrderName);
    
    void addToCart(const menuItem& newItem);
    void removeFromCart(const string& itemToRemove);
    void displayCart();
    void addToCart(const tuple<int,string,int>& newItem);
    float getTotalPrice();
    void displayTotalPrice();

    void setOrderName(string newOrderName);
    string getOrderName();

    //void readCreditCards(ifstream cardFile, vector<string>& cards);
    void verifyPayment();

    shoppingCart& operator=(const shoppingCart &rhs);

private:
    vector<menuItem> cart;
    vector<tuple<int, string, int>> tupleCart;
    string orderName;

};

#endif 