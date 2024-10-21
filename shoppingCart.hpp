#include "menuItem.hpp"
#include <vector>

class shoppingCart
{
public:
    void addToCart(const menuItem& newItem);
    void displayCart();

private:
    vector<menuItem> cart;
};

