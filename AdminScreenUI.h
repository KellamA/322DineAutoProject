#ifndef ADMINSCREENUI_H
#define ADMINSCREENUI_H

#include <QDialog>
#include "Temp/queue.hpp"  // Include your OrderQueue class

namespace Ui {
class AdminScreenUI;
}

class AdminScreenUI : public QDialog {
    Q_OBJECT

public:
    explicit AdminScreenUI(QWidget *parent = nullptr, const std::string &ordersFile = "orders.csv");
    ~AdminScreenUI();

private slots:
    void onClearOrderButtonClicked();  // Handle clearing an order
    void refreshOrders();             // Refresh the displayed orders

private:
    Ui::AdminScreenUI *ui;
    OrderQueue orderQueue;  // Instance of OrderQueue

    void onLogOutButtonClicked();
};

#endif  // ADMINSCREENUI_H
