#ifndef orderDataBase_hpp
#define orderDataBase_hpp

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <sstream>
#include <tuple>

class OrderDatabase {
public:
    OrderDatabase(const std::string& fileName);
    void addOrder(int orderNumber, const std::string& date, const std::vector<std::tuple<int, std::string, int>>& items, const std::string& specialRequest);
    void saveOrderToCSV();
    std::vector<std::string> readOrders();

    // Adding a new addOrder() -Shian
    void addOrder(int orderNumber, const std::string& date, const std::vector<std::tuple<int, std::string, int>>& items, const std::string& specialRequest, const std::string& orderName, float totalPrice);


private:
    std::string fileName;
    std::vector<std::string> currentOrderData;
    void formatOrder(int orderNumber, const std::string& date, const std::vector<std::tuple<int, std::string, int>>& items, const std::string& specialRequest);
    
    // Adding a new formatOrder() -Shian
    void formatOrder(int orderNumber, const std::string& date, const std::vector<std::tuple<int, std::string, int>>& items, const std::string& specialRequest, const std::string &orderName, float totalPrice);
};

#endif
