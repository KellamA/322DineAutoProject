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
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_CheckoutDialog
{
public:
    QListWidget *cartSummaryList;
    QLabel *totalPriceLabel;
    QLineEdit *creditCardLineEdit;
    QPushButton *confirmButton;
    QPushButton *cancelButton;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *nameLine;
    QLabel *label_3;
    QTextEdit *specialRequestLineEdit;

    void setupUi(QDialog *CheckoutDialog)
    {
        if (CheckoutDialog->objectName().isEmpty())
            CheckoutDialog->setObjectName("CheckoutDialog");
        CheckoutDialog->resize(658, 468);
        cartSummaryList = new QListWidget(CheckoutDialog);
        cartSummaryList->setObjectName("cartSummaryList");
        cartSummaryList->setGeometry(QRect(180, 20, 251, 251));
        totalPriceLabel = new QLabel(CheckoutDialog);
        totalPriceLabel->setObjectName("totalPriceLabel");
        totalPriceLabel->setGeometry(QRect(260, 270, 101, 20));
        creditCardLineEdit = new QLineEdit(CheckoutDialog);
        creditCardLineEdit->setObjectName("creditCardLineEdit");
        creditCardLineEdit->setGeometry(QRect(130, 300, 113, 26));
        confirmButton = new QPushButton(CheckoutDialog);
        confirmButton->setObjectName("confirmButton");
        confirmButton->setGeometry(QRect(200, 390, 93, 29));
        cancelButton = new QPushButton(CheckoutDialog);
        cancelButton->setObjectName("cancelButton");
        cancelButton->setGeometry(QRect(330, 390, 93, 29));
        label = new QLabel(CheckoutDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 300, 101, 20));
        label_2 = new QLabel(CheckoutDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(320, 300, 131, 20));
        nameLine = new QLineEdit(CheckoutDialog);
        nameLine->setObjectName("nameLine");
        nameLine->setGeometry(QRect(460, 300, 113, 26));
        label_3 = new QLabel(CheckoutDialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(480, 60, 121, 20));
        specialRequestLineEdit = new QTextEdit(CheckoutDialog);
        specialRequestLineEdit->setObjectName("specialRequestLineEdit");
        specialRequestLineEdit->setGeometry(QRect(470, 90, 141, 101));

        retranslateUi(CheckoutDialog);

        QMetaObject::connectSlotsByName(CheckoutDialog);
    } // setupUi

    void retranslateUi(QDialog *CheckoutDialog)
    {
        CheckoutDialog->setWindowTitle(QCoreApplication::translate("CheckoutDialog", "Dialog", nullptr));
        totalPriceLabel->setText(QCoreApplication::translate("CheckoutDialog", "TextLabel", nullptr));
        confirmButton->setText(QCoreApplication::translate("CheckoutDialog", "Confirm", nullptr));
        cancelButton->setText(QCoreApplication::translate("CheckoutDialog", "Cancel", nullptr));
        label->setText(QCoreApplication::translate("CheckoutDialog", "Card Number", nullptr));
        label_2->setText(QCoreApplication::translate("CheckoutDialog", "Name for the order", nullptr));
        label_3->setText(QCoreApplication::translate("CheckoutDialog", "Special Requests", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CheckoutDialog: public Ui_CheckoutDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKOUTDIALOG_H
