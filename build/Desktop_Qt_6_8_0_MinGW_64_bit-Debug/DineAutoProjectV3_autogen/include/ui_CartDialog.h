/********************************************************************************
** Form generated from reading UI file 'CartDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARTDIALOG_H
#define UI_CARTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_CartDialog
{
public:
    QTableWidget *cartTable;
    QPushButton *removeItemButton;
    QPushButton *closeButton;

    void setupUi(QDialog *CartDialog)
    {
        if (CartDialog->objectName().isEmpty())
            CartDialog->setObjectName("CartDialog");
        CartDialog->resize(492, 389);
        cartTable = new QTableWidget(CartDialog);
        cartTable->setObjectName("cartTable");
        cartTable->setGeometry(QRect(120, 20, 256, 192));
        removeItemButton = new QPushButton(CartDialog);
        removeItemButton->setObjectName("removeItemButton");
        removeItemButton->setGeometry(QRect(132, 270, 101, 29));
        closeButton = new QPushButton(CartDialog);
        closeButton->setObjectName("closeButton");
        closeButton->setGeometry(QRect(280, 270, 93, 29));

        retranslateUi(CartDialog);

        QMetaObject::connectSlotsByName(CartDialog);
    } // setupUi

    void retranslateUi(QDialog *CartDialog)
    {
        CartDialog->setWindowTitle(QCoreApplication::translate("CartDialog", "Dialog", nullptr));
        removeItemButton->setText(QCoreApplication::translate("CartDialog", "Remove Item", nullptr));
        closeButton->setText(QCoreApplication::translate("CartDialog", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CartDialog: public Ui_CartDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARTDIALOG_H
