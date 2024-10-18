#include "menuItem.hpp"

class shoppingCart
{
public:
    //shoppingCart(int orderNumber, string date, int numItems);
    shoppingCart(vector<menuItem>& cart);
    ~shoppingCart();

    void addToCart(const menuItem& item);

private:
    /* int orderNumber;
    string date;
    int numItems; */
    vector<menuItem> cart;
    menuItem item;
};