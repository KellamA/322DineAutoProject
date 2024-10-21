#include "shoppingCart.hpp"
#include "algorithm"

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

void shoppingCart::displayCart()
{
    for (const auto& item : cart)
    {
        cout << "itemID: " << item.getItemID() << " itemName: " << item.getItemName() << " itemQuantity: " << item.getItemQuantity() << endl;
    }
    
}
