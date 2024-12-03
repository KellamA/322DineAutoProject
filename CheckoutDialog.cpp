// CheckoutDialog.cpp
#include "CheckoutDialog.h"
#include "ui_CheckoutDialog.h"
#include "main.h"
#include <QMessageBox>
#include <cstdlib>
#include <filesystem>

#include <fstream>
#include <sstream>
#include <algorithm>

int getHighestOrderNumber(const std::string &filePath) {
    std::ifstream inFile(filePath);
    if (!inFile.is_open()) {
        std::cerr << "Error: Could not open orders file: " << filePath << std::endl;
        return 1; // Default starting order number
    }

    int highestOrderNumber = 1; // Default starting order number
    std::string line;

    while (std::getline(inFile, line)) {
        std::stringstream ss(line);
        std::string orderNumberStr;

        // Extract the order number (first column in CSV)
        if (std::getline(ss, orderNumberStr, ',')) {
            try {
                int orderNumber = std::stoi(orderNumberStr);
                highestOrderNumber = std::max(highestOrderNumber, orderNumber);
            } catch (const std::invalid_argument &) {
                // Handle non-numeric values (if any)
                continue;
            }
        }
    }

    inFile.close();
    return highestOrderNumber;
}


CheckoutDialog::CheckoutDialog(QWidget *parent, shoppingCart *cart, OrderDatabase *orderDB)
    : QDialog(parent), ui(new Ui::CheckoutDialog), cart(cart), orderDB(orderDB) {
    ui->setupUi(this);

    // Populate the cart summary and calculate the total price
    populateCartSummary();
    calculateTotalPrice();

    // Connect buttons to their respective slots
    connect(ui->confirmButton, &QPushButton::clicked, this, &CheckoutDialog::onConfirmButtonClicked);
    connect(ui->cancelButton, &QPushButton::clicked, this, &CheckoutDialog::onCancelButtonClicked);
}

CheckoutDialog::~CheckoutDialog() {
    delete ui;
}

void CheckoutDialog::populateCartSummary() {
    // Populate the cart summary with items from the cart
    for (const auto &item : cart->getItems()) {
        QString itemDetails = QString("x%1 %2 - $%3")
            .arg(item.getItemQuantity())
            .arg(QString::fromStdString(item.getItemName()))
            .arg(item.getItemPrice(), 0, 'f', 2);

        if(!item.getItemSR().empty())
        {
            itemDetails += QString("\n Special Request: %1").arg(QString::fromStdString(item.getItemSR()));
        }

        ui->cartSummaryList->addItem(itemDetails);
    }
}

void CheckoutDialog::calculateTotalPrice() {
    float totalPrice = cart->calculateTotalPrice();
    ui->totalPriceLabel->setText(QString("Total: $%1").arg(totalPrice, 0, 'f', 2));
}

void CheckoutDialog::onConfirmButtonClicked() {

    QString cardNumber = ui->creditCardLineEdit->text().trimmed();
    std::string cardNum = cardNumber.toStdString();

    QString orderName = ui->nameLine->text().trimmed();
    std::string name = orderName.toStdString();

    QString specialRequest = ui->specialRequestLineEdit->toPlainText();
    std::string specialRequestStr = specialRequest.toStdString();


    if(orderName.isEmpty())
    {
        QMessageBox::warning(this, "Order Name Missing", "Please enter your name for the order.");
        return;
    }
    if (!cart->verifyPayment(cardNum)) {
        QMessageBox::warning(this, "Payment Failed", "Invalid payment details. Please try again.");
        return;
    }


        QMessageBox::information(this, "Success", "Payment successful! Your order has been confirmed.");

        std::time_t t = std::time(nullptr);
        std::tm* now = std::localtime(&t);
        char dateBuffer[11]; // Enough to store "YYYY-MM-DD\0"
        std::strftime(dateBuffer, sizeof(dateBuffer), "%Y-%m-%d", now);
        std::string date(dateBuffer);

        const std::string ordersFile = "orders.csv"; // Ensure this matches your setup
        int highestOrderNumber = getHighestOrderNumber(ordersFile);
        int orderNum = highestOrderNumber + 1;

        // Retrieve the items from the cart
        std::vector<std::tuple<int, std::string, int>> items;

        for (const auto &item : cart->getItems()) {
            items.push_back(std::make_tuple(item.getItemID(), item.getItemName(), item.getItemQuantity()));
        }


        float totalPrice = cart->getTotalPrice();



        std::cout << "Before if(orderDB)" << endl;
        if (orderDB) {
            std::cout << "In if(orderDB)" << endl;
            //orderDB->setFileName("orders.csv");
            std::cout << "fileName in calculateTotalPrice: " << orderDB->getFileName() << std::endl;
            orderDB->addOrder(/*orderNumber*/ orderNum, date, name, totalPrice, items, /*specialRequest*/ specialRequestStr);  // Update as needed
        }
        std::cout << "After if(orderDB)" << endl;




       /* std::string buildPath = "build/Desktop_Qt_6_8_0_MinGW_64_bit-Debug/orders.csv";
        std::string tempPath = "Temp/orders.csv";

        try {
            std::filesystem::copy_file(buildPath, tempPath, std::filesystem::copy_options::overwrite_existing);
            std::cout << "Orders file synced to Temp directory!" << std::endl;
        } catch (const std::exception &e) {
            std::cerr << "Failed to sync orders file: " << e.what() << std::endl;
        }*/

        cart->clearCart();

        accept();  // Close the dialog with success

}

void CheckoutDialog::onCancelButtonClicked() {
    reject();  // Close the dialog without proceeding
}
