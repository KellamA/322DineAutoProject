#include "menuItem.hpp"

menuItem::menuItem(int newItemID, string newItemName, int newItemQuantity)
{
    ItemID = newItemID;
    ItemName = newItemName;
    ItemQuantity = newItemQuantity;
}

int menuItem::getItemID() const
{
    return this->ItemID;
}

string menuItem::getItemName() const
{
    return this->ItemName;
}

int menuItem::getItemQuantity() const
{
    return this->ItemQuantity;
}
