#ifndef MENUSCREENUI_H
#define MENUSCREENUI_H

#include <QDialog>
#include <QListWidget>
#include <QPushButton>
#include "Temp/menu.hpp"
#include "Temp/menuItem.hpp"
#include "Temp/shoppingCart.hpp"
#include "Temp/orderDataBase.hpp"

namespace Ui {
class MenuScreenUI;
}

class MenuScreenUI : public QDialog {
    Q_OBJECT

public:
    explicit MenuScreenUI(QWidget *parent = nullptr, OrderDatabase *orderDB = nullptr);
    ~MenuScreenUI();

private:
    Ui::MenuScreenUI *ui;
    menu menuInstance;
    shoppingCart cart;
    OrderDatabase *orderDB;

    void loadMenuItems();
    //void handleMenuSelection();

    void onAddToCartButtonClicked();
    void onSeeCartButtonClicked();
    void onToCheckoutButtonClicked();
    void onLogOutButtonClicked();
    void onRemoveFromCartButtonClicked();
};

#endif // MENUSCREENUI_H
