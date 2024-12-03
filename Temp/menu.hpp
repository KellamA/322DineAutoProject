#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "menuItem.hpp"
#include "shoppingCart.hpp"

using namespace std;

class menu
{
public:
   void displayItem(const vector<menu>& menu);
   vector<menu> getMenu(const std::string& menuFile);
   std::vector<std::tuple<int, std::string, int>> menuSelect(const vector<menu>& menu);

   int getId() const { return id; }
   std::string getItemName() const { return itemName; }
   float getPrice() const { return price; }

   shoppingCart getCart();
   

private:
   int id;
   std::string itemName;
   float price;

   shoppingCart mCart;

};

#endif
