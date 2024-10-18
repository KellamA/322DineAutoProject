#include "shoppingCart.hpp"

void shoppingCart::addToCart(const menuItem &item)
{
    cart.push_back(item);
}
