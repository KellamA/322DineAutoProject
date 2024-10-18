#include <iostream>
#include <string>
#include <vector>

using namespace std;

class menuItem
{
public:
    menuItem(int itemID, string itemName, int itemQuantity);
    ~menuItem();

    int getItemID();
    string getItemName();
    int getItemQuantity();

private:
    int itemId;
    string itemName;
    int itemQuantity;
};