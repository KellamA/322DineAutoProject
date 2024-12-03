#include "MenuScreenUI.h"
#include "ui_MenuScreenUI.h"
#include "Temp/menu.hpp"
#include "CartDialog.h"
#include "CheckoutDialog.h"
#include "LoginScreenUI.h"
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

    for (const auto& item : menuItems) {
        QString itemText = QString("%1 | %2 - $%3")
            .arg(item.getId())  // Add the Item ID
            .arg(QString::fromStdString(item.getItemName()))  // Item Name
            .arg(item.getPrice(), 0, 'f', 2);  // Price

        QListWidgetItem *listItem = new QListWidgetItem(itemText);
        listItem->setData(Qt::UserRole, item.getId());  // Store Item ID in the list item's data
        ui->listWidget->addItem(listItem);
    }
}

void MenuScreenUI::onAddToCartButtonClicked() {
    QListWidgetItem *selectedItem = ui->listWidget->currentItem();
    if (selectedItem) {
        QString itemText = selectedItem->text();
        qDebug() << "Selected Item Text:" << itemText;

        // Split by " | " to separate Item ID and the rest
        QStringList mainSplit = itemText.split(" | ");
        if (mainSplit.size() < 2) {
            QMessageBox::warning(this, "Error", "Failed to parse item details. Ensure the format is correct.");
            return;
        }

        QString itemIdText = mainSplit[0].trimmed(); // Extract Item ID as a string
        QString nameAndPrice = mainSplit[1].trimmed(); // Extract "ItemName - $Price"

        // Split by " - $" to separate Item Name and Price
        QStringList namePriceSplit = nameAndPrice.split(" - $");
        if (namePriceSplit.size() < 2) {
            QMessageBox::warning(this, "Error", "Failed to parse item name and price. Ensure the format is correct.");
            return;
        }

        QString itemName = namePriceSplit[0].trimmed(); // Extract Item Name
        float itemPrice = namePriceSplit[1].toFloat();  // Extract Item Price

        // Convert Item ID to an integer
        bool ok;
        int itemID = itemIdText.toInt(&ok);
        if (!ok) {
            QMessageBox::warning(this, "Error", "Invalid Item ID format.");
            return;
        }

        // Prompt for quantity
        int quantity = QInputDialog::getInt(this, "Enter Quantity", "Quantity:", 1, 1, 100, 1, &ok);
        if (!ok) return;

        // Create a menuItem object
        menuItem newItem(itemID, itemName.toStdString(), quantity, itemPrice * quantity);
        cart.addToCart(newItem);

        QMessageBox::information(this, "Item Added", "Added " + QString::number(quantity) + " " + itemName + " to your cart.");
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
    QMessageBox::information(this, "Log Out", "Logging out...");
    this->close();

    LoginScreenUI loginScreen; // Reopen the login screen
    if (loginScreen.exec() == QDialog::Accepted) {
        // Reopen the menu screen if login is successful
        this->exec();
    }
}
