#ifndef CARTDIALOG_H
#define CARTDIALOG_H

#include <QDialog>
#include <QTableWidget>
#include "Temp/shoppingCart.hpp"

namespace Ui {
class CartDialog;
}

class CartDialog : public QDialog {
    Q_OBJECT

public:
    explicit CartDialog(QWidget *parent = nullptr, shoppingCart *cart = nullptr);
    ~CartDialog();

private slots:
    void populateCart();
    void onRemoveItemButtonClicked();
    void onCloseButtonClicked();

private:
    Ui::CartDialog *ui;
    shoppingCart *cart;  // Pointer to the shopping cart
};

#endif // CARTDIALOG_H
