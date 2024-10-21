#include "shoppingCart.hpp"

void shoppingCart::addToCart(const menuItem &newItem)
{
    this->cart.push_back(newItem);
}

void shoppingCart::displayCart()
{
    for (const auto& item : cart)
    {
        cout << "itemID: " << item.getItemID() << " itemName: " << item.getItemName() << " itemQuantity: " << item.getItemQuantity() << endl;
    }
    
}
