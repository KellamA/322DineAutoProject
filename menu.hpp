#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "menuItem.hpp"

using namespace std;

class menu
{
public:
   void displayItem(const vector<menu>& menu);
   vector<menu> getMenu(const std::string& menuFile);
   //std::vector<std::tuple<int, std::string, int>> menuSelect(const vector<menu>& menu);
   std::tuple<int, std::string, int> menuSelect(const vector<menu>& menu);

   

private:
   int id;
   std::string itemName;
   float price;

};

#endif