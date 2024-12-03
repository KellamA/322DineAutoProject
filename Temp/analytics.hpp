#ifndef ANALYTICS_HPP
#define ANALYTICS_HPP

#include <string>
#include <vector>
#include <tuple>
#include <map>
#include <ctime>

class Analytics {
public:
    Analytics(const std::string& ordersFileName);
    void runAnalytics();

private:
    std::string ordersFileName;
    std::vector<std::string> ordersData;

    void loadOrders();
    void promptTimeRange();
    void promptAnalyticsType();
    void calculateMostOrdersInSingleDay();
    void calculateMostOrderedItem();

    // Helper functions
    std::tm parseDate(const std::string& dateStr);
    bool isDateInRange(const std::tm& date);
    std::vector<std::tuple<int, int>> parseOrderItems(const std::vector<std::string>& orderFields, size_t& index);

    // Data members for user selection
    std::tm startDate;
    std::tm endDate;

    // Stores the parsed orders data
    std::vector<std::tuple<std::tm, std::vector<std::tuple<int, int>>>> orders; // Each order: date, items [(ItemID, Quantity)]
};

#endif // ANALYTICS_HPP
