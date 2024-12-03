#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <string>
#include <vector>
#include <tuple>
#include <atomic>
#include <mutex>
#include <condition_variable>

struct Order {
    int orderNumber;
    std::string date;
    std::string orderName;
    float totalPrice;
    std::vector<std::tuple<int, std::string, int>> items; // ItemID, ItemName, Quantity
    std::string specialRequest;

};

class OrderQueue {
public:
    OrderQueue(const std::string& ordersFileName);
    void run();

    std::vector<Order> getOrders();
    bool ClearOrder(int orderNumber);

private:
    std::string ordersFileName;
    std::vector<int> clearedOrderNumbers;
    std::mutex clearedOrdersMutex;



    std::vector<Order> orders;
    std::mutex ordersMutex;

    void loadOrders();
    void displayOrders();
    void inputThreadFunction();
    void clearOrder(int orderNumber);
    std::string getCurrentDate();

    void saveOrders(const std::string &filePath);

    std::atomic<bool> running;
    std::condition_variable cv;

    // Mutex for synchronizing console output
    std::mutex outputMutex;
};

#endif // ORDERQUEUE_HPP
