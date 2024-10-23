#include "menuItem.hpp"

menuItem::menuItem(int newItemID, string newItemName, int newItemQuantity)
{
    this->itemID = newItemID;
    this->itemName = newItemName;
    this->itemQuantity = newItemQuantity;
}

menuItem::menuItem()
{
    this->itemID = 0;
    this->itemName = "";
    this->itemQuantity = 0;
}

int menuItem::getItemID() const
{
    return this->itemID;
}

string menuItem::getItemName() const
{
    return this->itemName;
}

int menuItem::getItemQuantity() const
{
    return this->itemQuantity;
}

void menuItem::setItemID(int newItemID)
{
    this->itemID = newItemID;
}

void menuItem::setItemName(string newItemName)
{
    this->itemName = newItemName;
}

void menuItem::setItemQuantity(int newItemQuantity)
{
    this->itemQuantity = newItemQuantity;
}

tuple<int, string, int> menuItem::convertToTuple()
{
    tuple<int, string, int> itemTuple = make_tuple(this->getItemID(), this->getItemName(), this->getItemQuantity());
    return itemTuple;
}
