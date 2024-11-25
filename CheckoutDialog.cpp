// CheckoutDialog.cpp
#include "CheckoutDialog.h"
#include "ui_CheckoutDialog.h"
#include "main.h"
#include <QMessageBox>

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
        QString itemDetails = QString("%1 x %2 - $%3")
            .arg(item.getItemQuantity())
            .arg(QString::fromStdString(item.getItemName()))
            .arg(item.getItemPrice(), 0, 'f', 2);
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

    if (cart->verifyPayment(cardNum)) {
        QMessageBox::information(this, "Success", "Payment successful! Your order has been confirmed.");

        std::time_t t = std::time(nullptr);
        std::tm* now = std::localtime(&t);
        char dateBuffer[11]; // Enough to store "YYYY-MM-DD\0"
        std::strftime(dateBuffer, sizeof(dateBuffer), "%Y-%m-%d", now);
        std::string date(dateBuffer);


        // Retrieve the items from the cart
        std::vector<std::tuple<int, std::string, int>> items;
        for (const auto &item : cart->getItems()) {
            items.push_back(item.convertToTuple());
        }


        std::cout << "Before if(orderDB)" << endl;
        if (orderDB) {
            std::cout << "In if(orderDB)" << endl;
            //orderDB->setFileName("orders.csv");
            std::cout << "fileName in calculateTotalPrice: " << orderDB->getFileName() << std::endl;
            orderDB->addOrder(/*orderNumber*/ 1, date, items, /*specialRequest*/ "");  // Update as needed
        }
        std::cout << "After if(orderDB)" << endl;



        accept();  // Close the dialog with success
    } else {
        QMessageBox::warning(this, "Payment Failed", "Invalid payment details. Please try again.");
    }
}

void CheckoutDialog::onCancelButtonClicked() {
    reject();  // Close the dialog without proceeding
}
