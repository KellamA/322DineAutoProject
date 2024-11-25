/********************************************************************************
** Form generated from reading UI file 'MenuScreenUI.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUSCREENUI_H
#define UI_MENUSCREENUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_MenuScreenUI
{
public:
    QListWidget *listWidget;
    QPushButton *addToCartButton;
    QPushButton *toCheckoutButton;
    QPushButton *logOutButton;
    QPushButton *seeCartButton;

    void setupUi(QDialog *MenuScreenUI)
    {
        if (MenuScreenUI->objectName().isEmpty())
            MenuScreenUI->setObjectName("MenuScreenUI");
        MenuScreenUI->resize(496, 393);
        listWidget = new QListWidget(MenuScreenUI);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(140, 120, 256, 192));
        addToCartButton = new QPushButton(MenuScreenUI);
        addToCartButton->setObjectName("addToCartButton");
        addToCartButton->setGeometry(QRect(110, 340, 93, 29));
        toCheckoutButton = new QPushButton(MenuScreenUI);
        toCheckoutButton->setObjectName("toCheckoutButton");
        toCheckoutButton->setGeometry(QRect(280, 340, 151, 29));
        logOutButton = new QPushButton(MenuScreenUI);
        logOutButton->setObjectName("logOutButton");
        logOutButton->setGeometry(QRect(380, 20, 93, 29));
        seeCartButton = new QPushButton(MenuScreenUI);
        seeCartButton->setObjectName("seeCartButton");
        seeCartButton->setGeometry(QRect(20, 20, 93, 29));

        retranslateUi(MenuScreenUI);

        QMetaObject::connectSlotsByName(MenuScreenUI);
    } // setupUi

    void retranslateUi(QDialog *MenuScreenUI)
    {
        MenuScreenUI->setWindowTitle(QCoreApplication::translate("MenuScreenUI", "Dialog", nullptr));
        addToCartButton->setText(QCoreApplication::translate("MenuScreenUI", "Add To Cart", nullptr));
        toCheckoutButton->setText(QCoreApplication::translate("MenuScreenUI", "Proceed to Checkout", nullptr));
        logOutButton->setText(QCoreApplication::translate("MenuScreenUI", "Log Out", nullptr));
        seeCartButton->setText(QCoreApplication::translate("MenuScreenUI", "View Cart", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MenuScreenUI: public Ui_MenuScreenUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUSCREENUI_H
