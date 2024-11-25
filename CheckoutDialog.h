// CheckoutDialog.h
#ifndef CHECKOUTDIALOG_H
#define CHECKOUTDIALOG_H

#include <QDialog>
#include "Temp/shoppingCart.hpp"
#include "Temp/orderDataBase.hpp"


namespace Ui {
class CheckoutDialog;
}

class CheckoutDialog : public QDialog {
    Q_OBJECT

public:
    explicit CheckoutDialog(QWidget *parent = nullptr, shoppingCart *cart = nullptr, OrderDatabase *orderDB = nullptr);
    ~CheckoutDialog();

private slots:
    void onConfirmButtonClicked();
    void onCancelButtonClicked();

private:
    Ui::CheckoutDialog *ui;
    shoppingCart *cart;
    OrderDatabase *orderDB;
    void populateCartSummary();
    void calculateTotalPrice();
};

#endif // CHECKOUTDIALOG_H
