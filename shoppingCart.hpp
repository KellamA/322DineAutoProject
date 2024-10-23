#include "menuItem.hpp"
#include <vector>

class shoppingCart
{
public:
    void addToCart(const menuItem& newItem);
    void removeFromCart(const string& itemToRemove);
    void displayCart();
    void addToCart(const tuple<int,string,int> newItem);

private:
    vector<menuItem> cart;
    vector<tuple<int, string, int>> tupleCart;
};

