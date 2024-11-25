/********************************************************************************
** Form generated from reading UI file 'CheckoutDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECKOUTDIALOG_H
#define UI_CHECKOUTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_CheckoutDialog
{
public:
    QListWidget *cartSummaryList;
    QLabel *totalPriceLabel;
    QLineEdit *creditCardLineEdit;
    QPushButton *confirmButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *CheckoutDialog)
    {
        if (CheckoutDialog->objectName().isEmpty())
            CheckoutDialog->setObjectName("CheckoutDialog");
        CheckoutDialog->resize(533, 395);
        cartSummaryList = new QListWidget(CheckoutDialog);
        cartSummaryList->setObjectName("cartSummaryList");
        cartSummaryList->setGeometry(QRect(130, 20, 256, 192));
        totalPriceLabel = new QLabel(CheckoutDialog);
        totalPriceLabel->setObjectName("totalPriceLabel");
        totalPriceLabel->setGeometry(QRect(230, 220, 63, 20));
        creditCardLineEdit = new QLineEdit(CheckoutDialog);
        creditCardLineEdit->setObjectName("creditCardLineEdit");
        creditCardLineEdit->setGeometry(QRect(100, 260, 113, 26));
        confirmButton = new QPushButton(CheckoutDialog);
        confirmButton->setObjectName("confirmButton");
        confirmButton->setGeometry(QRect(180, 310, 93, 29));
        cancelButton = new QPushButton(CheckoutDialog);
        cancelButton->setObjectName("cancelButton");
        cancelButton->setGeometry(QRect(310, 310, 93, 29));

        retranslateUi(CheckoutDialog);

        QMetaObject::connectSlotsByName(CheckoutDialog);
    } // setupUi

    void retranslateUi(QDialog *CheckoutDialog)
    {
        CheckoutDialog->setWindowTitle(QCoreApplication::translate("CheckoutDialog", "Dialog", nullptr));
        totalPriceLabel->setText(QCoreApplication::translate("CheckoutDialog", "TextLabel", nullptr));
        confirmButton->setText(QCoreApplication::translate("CheckoutDialog", "Confirm", nullptr));
        cancelButton->setText(QCoreApplication::translate("CheckoutDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CheckoutDialog: public Ui_CheckoutDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKOUTDIALOG_H
