#include "CartDialog.h"
#include "ui_CartDialog.h"
#include <QMessageBox>

CartDialog::CartDialog(QWidget *parent, shoppingCart *cart) :
    QDialog(parent),
    ui(new Ui::CartDialog),
    cart(cart)  // Initialize the shopping cart pointer
{
    ui->setupUi(this);

    // Set up the QTableWidget
    ui->cartTable->setColumnCount(3);
    ui->cartTable->setHorizontalHeaderLabels({"Item Name", "Quantity", "Total Price"});
    ui->cartTable->horizontalHeader()->setStretchLastSection(true);

    // Populate the cart items
    populateCart();

    // Connect the remove button
    connect(ui->removeItemButton, &QPushButton::clicked, this, &CartDialog::onRemoveItemButtonClicked);
    connect(ui->closeButton, &QPushButton::clicked, this, &CartDialog::onCloseButtonClicked);
}

CartDialog::~CartDialog() {
    delete ui;
}

void CartDialog::populateCart() {
    ui->cartTable->setRowCount(0);  // Clear the table

    if (cart) {
        const auto &items = cart->getItems();
        for (size_t i = 0; i < items.size(); ++i) {
            const auto &item = items[i];

            // Add a new row for each item
            ui->cartTable->insertRow(i);
            ui->cartTable->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(item.getItemName())));
            ui->cartTable->setItem(i, 1, new QTableWidgetItem(QString::number(item.getItemQuantity())));
            ui->cartTable->setItem(i, 2, new QTableWidgetItem(QString::number(item.getItemPrice())));
        }
    }
}

void CartDialog::onRemoveItemButtonClicked() {
    // Get the selected row
    int row = ui->cartTable->currentRow();
    if (row >= 0 && cart) {
        QString itemName = ui->cartTable->item(row, 0)->text();
        cart->removeFromCart(itemName.toStdString());
        ui->cartTable->removeRow(row);  // Remove the row from the table
        QMessageBox::information(this, "Item Removed", itemName + " has been removed from your cart.");
    } else {
        QMessageBox::warning(this, "No Selection", "Please select an item to remove.");
    }
}

void CartDialog::onCloseButtonClicked() {
    this->close();  // Close the dialog
}
