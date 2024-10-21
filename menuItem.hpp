#include <iostream>
#include <string>

using namespace std;

class menuItem
{
public:
    menuItem(int newItemID, string newItemName, int newItemQuantity);

    int getItemID() const;
    string getItemName() const;
    int getItemQuantity() const;

private:
    int ItemID;
    string ItemName;
    int ItemQuantity;
};