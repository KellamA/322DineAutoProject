#include "MenuScreenUI.h"
#include "ui_MenuScreenUI.h"
#include "Temp/menu.hpp"
#include "CartDialog.h"
#include "CheckoutDialog.h"
#include "main.h"
#include <QFile>
#include <QTextStream>
#include <QListWidgetItem>
#include <QMessageBox>
#include <QString>
#include <QInputDialog>



MenuScreenUI::MenuScreenUI(QWidget *parent, OrderDatabase *orderDB) :
    QDialog(parent),  // Use QDialog instead of QWidget
    ui(new Ui::MenuScreenUI),
    cart("User"),
    orderDB(orderDB)
{
    std::cout << "OrderDB in constructor: " << (orderDB ? "Valid" : "Null") << std::endl;

    ui->setupUi(this);


    connect(ui->addToCartButton, &QPushButton::clicked, this, &MenuScreenUI::onAddToCartButtonClicked);
    connect(ui->seeCartButton, &QPushButton::clicked, this, &MenuScreenUI::onSeeCartButtonClicked);
    connect(ui->toCheckoutButton, &QPushButton::clicked, this, &MenuScreenUI::onToCheckoutButtonClicked);
    connect(ui->logOutButton, &QPushButton::clicked, this, &MenuScreenUI::onLogOutButtonClicked);
    // Load menu items from CSV file
    loadMenuItems();
}

MenuScreenUI::~MenuScreenUI() {
    delete ui;
}

void MenuScreenUI::loadMenuItems() {
    // Load menu items from CSV using the backend
    std::vector<menu> menuItems = menuInstance.getMenu("menu.csv");

    if (menuItems.empty()) {
        QMessageBox::critical(this, "Error", "Failed to load menu items.");
        return;
    }

    // Populate the QListWidget with menu items
    for (const auto& item : menuItems) {
        QString itemText = QString::fromStdString(item.getItemName()) + " - $" + QString::number(item.getPrice());
        QListWidgetItem *listItem = new QListWidgetItem(itemText);
        ui->listWidget->addItem(listItem);
    }
}

void MenuScreenUI::onAddToCartButtonClicked() {
    QListWidgetItem *selectedItem = ui->listWidget->currentItem();
    if (selectedItem) {
        QString itemText = selectedItem->text();
        QStringList itemDetails = itemText.split(" - $");

        if (itemDetails.size() == 2) {
            QString itemName = itemDetails[0].trimmed();
            float itemPrice = itemDetails[1].toFloat();

            // Prompt for quantity
            bool ok;
            int quantity = QInputDialog::getInt(this, "Enter Quantity", "Quantity:", 1, 1, 100, 1, &ok);
            if (!ok) return;

            // Prompt for special request
            QString specialRequest = QInputDialog::getText(this, "Special Request", "Enter any special request (leave blank if none):", QLineEdit::Normal, "", &ok);
            if (!ok) return;

            // Create a menuItem object with the special request
            menuItem newItem(0, itemName.toStdString(), quantity, itemPrice * quantity, specialRequest.toStdString());
            cart.addToCart(newItem);

            QMessageBox::information(this, "Item Added", "Added " + QString::number(quantity) + " " + itemName + " to your cart.");
        }
    } else {
        QMessageBox::warning(this, "No Selection", "Please select an item to add to the cart.");
    }
}

void MenuScreenUI::onSeeCartButtonClicked() {
    CartDialog cartDialog(this, &cart);
    cartDialog.exec();  // Open the dialog
}


void MenuScreenUI::onRemoveFromCartButtonClicked() {
    // Prompt the user to enter the name of the item to remove
    bool ok;
    QString itemNameToRemove = QInputDialog::getText(this, "Remove Item", "Enter the name of the item to remove:", QLineEdit::Normal, "", &ok);
    if (ok && !itemNameToRemove.isEmpty()) {
        // Remove the item from the cart
        cart.removeFromCart(itemNameToRemove.toStdString());
        QMessageBox::information(this, "Item Removed", "Removed " + itemNameToRemove + " from your cart.");
    }
}


void MenuScreenUI::onToCheckoutButtonClicked() {
    //if(orderDB == nullptr) {
    //   QMessageBox::critical(this, "Error", "Order Database is not initialized.");
    //    return;
    //}

        std::cout << "About to read orders..." << std::endl;
        if (orderDB) {
            std::vector<std::string> orders = orderDB->readOrders();
            std::cout << "Read orders size: " << orders.size() << std::endl;
            for (const auto &order : orders) {
                std::cout << "Order: " << order << std::endl;
            }
        } else {
            std::cerr << "OrderDB is null!" << std::endl;
        }


    CheckoutDialog checkoutDialog(this, &cart, orderDB);
    if (checkoutDialog.exec() == QDialog::Accepted) {
        // Handle successful checkout
    } else {
        // Handle checkout cancellation
    }
}

void MenuScreenUI::onLogOutButtonClicked() {
    // Handle logging out
    QMessageBox::information(this, "Log Out", "Logging out...");

  //  cout << "before QFile: " << endl;
  //  QFile::copy("../DineAutoProjectV3/build/Desktop_Qt_6_8_0_MinGW_64_bit-Debug/orders.csv", "../DineAutoProjectV3/Temp/orders.csv");
  //  cout <<"After QFile. And closing: " << endl;

    //Main thing;

    //std::string buildDirOrders = "orders.csv";
    //std::string tempDirOrders = "Temp/orders.csv";
    //if (thing.copyFileContents(buildDirOrders, tempDirOrders)) {
    //    std::cout << "Orders file synced successfully!" << std::endl;
    //} else {
    //    std::cerr << "Failed to sync orders file!" << std::endl;
    //}
    cout << "Logging out" << endl;
    close();  // Close the menu screen
    cout << "Logged out" << endl;
    QApplication::quit();
    cout << "Application closed" << endl;
}
