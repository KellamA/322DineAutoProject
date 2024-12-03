#include "AdminScreenUI.h"
#include "ui_AdminScreenUI.h"
#include "LoginScreenUI.h"
#include <QMessageBox>
#include <QInputDialog>
#include <QTimer>

QString formatItems(const std::vector<std::tuple<int, std::string, int>>& items) {
    QString formattedItems;
    for (const auto& item : items) {
        int id = std::get<0>(item);
        std::string name = std::get<1>(item);
        int quantity = std::get<2>(item);

        formattedItems += QString("ID: %1, Name: %2, Quantity: %3\n")
                              .arg(id)
                              .arg(QString::fromStdString(name))
                              .arg(quantity);
    }
    return formattedItems.trimmed();
}


AdminScreenUI::AdminScreenUI(QWidget *parent, const std::string &ordersFile)
    : QDialog(parent),
    ui(new Ui::AdminScreenUI),
    orderQueue(ordersFile) {  // Initialize OrderQueue with the orders file
    ui->setupUi(this);

    // Connect button for clearing orders
    connect(ui->clearOrderButton, &QPushButton::clicked, this, &AdminScreenUI::onClearOrderButtonClicked);
    connect(ui->logOutButton, &QPushButton::clicked, this, &AdminScreenUI::onLogOutButtonClicked);
    // Refresh orders on load

    QTimer *refreshTimer = new QTimer(this);
    connect(refreshTimer, &QTimer::timeout, this, &AdminScreenUI::refreshOrders);
    refreshTimer->start(15000);

    refreshOrders();
}

AdminScreenUI::~AdminScreenUI() {
    delete ui;
}

void AdminScreenUI::refreshOrders() {
    ui->ordersList->clear();  // Clear the list before repopulating

    const auto orders = orderQueue.getOrders();  // Get the list of current orders
    for (const auto &order : orders) {
        // Format the order details
        QString orderDetails = QString("Order Number: %1\nOrder Name: %2\nTotal Price: $%3\nTotal Items: %4\n")
                                   .arg(order.orderNumber)
                                   .arg(QString::fromStdString(order.orderName))
                                   .arg(order.totalPrice, 0, 'f', 2)  // Format as a float with 2 decimal places
                                   .arg(order.items.size());          // Use the size of the items vector

        // Add each item with its details
        for (const auto &item : order.items) {
            orderDetails += QString("  - Item ID: %1, Name: %2, Quantity: %3\n")
            .arg(std::get<0>(item))  // Item ID
                .arg(QString::fromStdString(std::get<1>(item)))  // Item Name
                .arg(std::get<2>(item));  // Quantity
        }

        // Add the special request if it exists
        if (!order.specialRequest.empty()) {
            orderDetails += QString("Special Request: %1\n").arg(QString::fromStdString(order.specialRequest));
        }

        orderDetails += "------------------------------\n";  // Add a separator between orders
        ui->ordersList->addItem(orderDetails);
    }
}




void AdminScreenUI::onClearOrderButtonClicked() {
    bool ok;
    int orderNumber = QInputDialog::getInt(this, "Clear Order", "Enter Order Number:", 0, 0, 10000, 1, &ok);

    if (ok) {
        if (orderQueue.ClearOrder(orderNumber)) {
            QMessageBox::information(this, "Order Cleared", "Order " + QString::number(orderNumber) + " has been cleared.");
            refreshOrders();  // Refresh the orders display
        } else {
            QMessageBox::warning(this, "Error", "Failed to clear order. Order may not exist.");
        }
    }
}

void AdminScreenUI::onLogOutButtonClicked() {
    QMessageBox::information(this, "Log Out", "Logging out...");
    this->close();

    LoginScreenUI loginScreen; // Reopen the login screen
    if (loginScreen.exec() == QDialog::Accepted) {
        // Reopen the menu screen if login is successful
        this->exec();
    }
}

