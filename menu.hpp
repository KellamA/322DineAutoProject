#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "shoppingCart.hpp"

using namespace std;

class menu
{
public:
   void displayItem(const vector<menu>& menu);
   vector<menu> getMenu(const std::string& menuFile);
   std::vector<std::tuple<int, std::string, int>> menuSelect(const vector<menu>& menu);

   shoppingCart getCart();

private:
   int id;
   std::string itemName;
   float price;

   shoppingCart mCart;

};

#endif
