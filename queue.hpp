#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <string>
#include <vector>
#include <tuple>
#include <atomic>
#include <mutex>
#include <condition_variable>

class OrderQueue {
public:
    OrderQueue(const std::string& ordersFileName);
    void run();

private:
    std::string ordersFileName;
    std::vector<int> clearedOrderNumbers;
    std::mutex clearedOrdersMutex;

    struct Order {
        int orderNumber;
        std::string date;
        std::vector<std::tuple<int, std::string, int>> items; // ItemID, ItemName, Quantity
        std::string specialRequest;
    };

    std::vector<Order> orders;
    std::mutex ordersMutex;

    void loadOrders();
    void displayOrders();
    void inputThreadFunction();
    void clearOrder(int orderNumber);
    std::string getCurrentDate();

    std::atomic<bool> running;
    std::condition_variable cv;

    // Mutex for synchronizing console output
    std::mutex outputMutex;
};

#endif // ORDERQUEUE_HPP
