#ifndef MENUITEM_HPP
#define MENUITEM_HPP

#include <iostream>
#include <string>
#include <tuple>

using namespace std;


class menuItem
{
public:
    menuItem(int newItemID, string newItemName, int newItemQuantity);
    menuItem(int newItemID, string newItemName, int newItemQuantity, float newItemPrice);
    menuItem();

    int getItemID() const;
    string getItemName() const;
    int getItemQuantity() const;
    float getItemPrice() const;

    void setItemID(int newItemID);
    void setItemName(string newItemName);
    void setItemQuantity(int newItemQuantity);
    void setItemPrice(float newItemPrice);

    tuple<int, string, int> convertToTuple();

private:
    int itemID;
    string itemName;
    int itemQuantity;
    float itemPrice;
};

#endif