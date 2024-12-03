#include "menuItem.hpp"

menuItem::menuItem(int newItemID, string newItemName, int newItemQuantity)
{
    this->itemID = newItemID;
    this->itemName = newItemName;
    this->itemQuantity = newItemQuantity;
    this->itemPrice = 0.0;
    this->itemSR = "";
}

menuItem::menuItem(int newItemID, string newItemName, int newItemQuantity, float newItemPrice)
{
    this->itemID = newItemID;
    this->itemName = newItemName;
    this->itemQuantity = newItemQuantity;
    this->itemPrice = newItemPrice;
    this->itemSR = "";
}

menuItem::menuItem(int newItemID, string newItemName, int newItemQuantity, float newItemPrice, string newItemSR)
{
    this->itemID = newItemID;
    this->itemName = newItemName;
    this->itemQuantity = newItemQuantity;
    this->itemPrice = newItemPrice;
    this->itemSR = newItemSR;
}

menuItem::menuItem()
{
    this->itemID = 0;
    this->itemName = "";
    this->itemQuantity = 0;   
    this->itemPrice = 0.0;
    this->itemSR = "";
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

float menuItem::getItemPrice() const
{
    return this->itemPrice;
}

string menuItem::getItemSR() const
{
    return this->itemSR;
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

void menuItem::setItemPrice(float newItemPrice)
{
    this->itemPrice = newItemPrice;
}

void menuItem::setItemSR(string newItemSR)
{
    this->itemSR = newItemSR;
}

tuple<int, string, int> menuItem::convertToTuple() const
{
    tuple<int, string, int> itemTuple = make_tuple(this->getItemID(), this->getItemName(), this->getItemQuantity());
    return itemTuple;
}
