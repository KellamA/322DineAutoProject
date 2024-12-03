#include "LoginScreenUI.h"
#include "ui_LoginScreenUI.h"
#include "MenuScreenUI.h"
#include "AdminScreenUI.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDir>

LoginScreenUI::LoginScreenUI(QWidget *parent) :
    QDialog(parent),  // Change QWidget to QDialog
    ui(new Ui::LoginScreenUI)
{
    ui->setupUi(this);

    // Connect the login button to the onLoginButtonClicked slot
    connect(ui->loginButton, &QPushButton::clicked, this, &LoginScreenUI::onLoginButtonClicked);
}

LoginScreenUI::~LoginScreenUI() {
    delete ui;
}

void LoginScreenUI::onLoginButtonClicked() {
    QString username = ui->usernameEdit->text();
    QString password = ui->passwordEdit->text();

    QString role;

    if (validateCredentials(username, password, role)) {
        QMessageBox::information(this, "Login Successful", "Welcome, " + username + "!");
        this->close(); // Close the login screen

        std::string ordersFile = "orders.csv"; // Path to orders file

        if (role == "admin") {
            // Admin flow
            AdminScreenUI adminScreen; // Create and display Admin screen
            adminScreen.exec();
        } else {
            // Customer flow
            auto orderDB = std::make_shared<OrderDatabase>(ordersFile);
            MenuScreenUI menuScreen(nullptr, orderDB.get());
            menuScreen.exec();
        }

    } else {
        QMessageBox::warning(this, "Login Failed", "Incorrect username or password.");
    }
}


bool LoginScreenUI::validateCredentials(const QString &username, const QString &password, QString &role) {
    QFile file("credentials.csv");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Unable to open credentials file.");
        return false;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");
        if (fields.size() == 3) { // Expect username, password, and role
            QString fileUsername = fields.at(0).trimmed();
            QString filePassword = fields.at(1).trimmed();
            QString fileRole = fields.at(2).trimmed();
            if (username == fileUsername && password == filePassword) {
                role = fileRole; // Set the role for further processing
                return true; // Credentials match
            }
        }
    }
    return false; // No match found
}
