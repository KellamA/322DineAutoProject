/********************************************************************************
** Form generated from reading UI file 'LoginScreenUI.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINSCREENUI_H
#define UI_LOGINSCREENUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LoginScreenUI
{
public:
    QPushButton *loginButton;
    QLineEdit *usernameEdit;
    QLineEdit *passwordEdit;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *LoginScreenUI)
    {
        if (LoginScreenUI->objectName().isEmpty())
            LoginScreenUI->setObjectName("LoginScreenUI");
        LoginScreenUI->resize(400, 300);
        loginButton = new QPushButton(LoginScreenUI);
        loginButton->setObjectName("loginButton");
        loginButton->setGeometry(QRect(150, 220, 93, 29));
        usernameEdit = new QLineEdit(LoginScreenUI);
        usernameEdit->setObjectName("usernameEdit");
        usernameEdit->setGeometry(QRect(140, 60, 113, 26));
        passwordEdit = new QLineEdit(LoginScreenUI);
        passwordEdit->setObjectName("passwordEdit");
        passwordEdit->setGeometry(QRect(140, 120, 113, 26));
        passwordEdit->setEchoMode(QLineEdit::EchoMode::Password);
        label = new QLabel(LoginScreenUI);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 60, 91, 20));
        label_2 = new QLabel(LoginScreenUI);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 120, 71, 20));

        retranslateUi(LoginScreenUI);

        QMetaObject::connectSlotsByName(LoginScreenUI);
    } // setupUi

    void retranslateUi(QDialog *LoginScreenUI)
    {
        LoginScreenUI->setWindowTitle(QCoreApplication::translate("LoginScreenUI", "Dialog", nullptr));
        loginButton->setText(QCoreApplication::translate("LoginScreenUI", "Login", nullptr));
        label->setText(QCoreApplication::translate("LoginScreenUI", "Username", nullptr));
        label_2->setText(QCoreApplication::translate("LoginScreenUI", "Password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginScreenUI: public Ui_LoginScreenUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINSCREENUI_H
