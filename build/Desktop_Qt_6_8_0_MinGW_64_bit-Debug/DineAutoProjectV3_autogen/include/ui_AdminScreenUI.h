/********************************************************************************
** Form generated from reading UI file 'AdminScreenUI.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINSCREENUI_H
#define UI_ADMINSCREENUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AdminScreenUI
{
public:
    QListWidget *ordersList;
    QPushButton *clearOrderButton;
    QPushButton *logOutButton;

    void setupUi(QDialog *AdminScreenUI)
    {
        if (AdminScreenUI->objectName().isEmpty())
            AdminScreenUI->setObjectName("AdminScreenUI");
        AdminScreenUI->resize(681, 478);
        ordersList = new QListWidget(AdminScreenUI);
        ordersList->setObjectName("ordersList");
        ordersList->setGeometry(QRect(120, 20, 421, 291));
        clearOrderButton = new QPushButton(AdminScreenUI);
        clearOrderButton->setObjectName("clearOrderButton");
        clearOrderButton->setGeometry(QRect(280, 370, 93, 29));
        logOutButton = new QPushButton(AdminScreenUI);
        logOutButton->setObjectName("logOutButton");
        logOutButton->setGeometry(QRect(560, 30, 93, 29));

        retranslateUi(AdminScreenUI);

        QMetaObject::connectSlotsByName(AdminScreenUI);
    } // setupUi

    void retranslateUi(QDialog *AdminScreenUI)
    {
        AdminScreenUI->setWindowTitle(QCoreApplication::translate("AdminScreenUI", "Dialog", nullptr));
        clearOrderButton->setText(QCoreApplication::translate("AdminScreenUI", "Clear", nullptr));
        logOutButton->setText(QCoreApplication::translate("AdminScreenUI", "Log Out", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminScreenUI: public Ui_AdminScreenUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINSCREENUI_H
