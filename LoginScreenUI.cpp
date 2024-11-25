#include "LoginScreenUI.h"
#include "ui_LoginScreenUI.h"
#include "MenuScreenUI.h"
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

    if (validateCredentials(username, password)) {
        QMessageBox::information(this, "Login Successful", "Welcome!");

        std::string ordersFile = "orders.csv"; // Ensure this path matches your setup
        OrderDatabase *orderDB = new OrderDatabase(ordersFile);

        MenuScreenUI *menuScreen = new MenuScreenUI(nullptr, orderDB);
        this->close(); // Close the login screen
        menuScreen->exec();
    } else {
        QMessageBox::warning(this, "Login Failed", "Incorrect username or password.");
    }
}


bool LoginScreenUI::validateCredentials(const QString &username, const QString &password) {
    QFile file("credentials.csv");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Unable to open credentials file.");
        return false;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");
        if (fields.size() == 2) {
            QString fileUsername = fields.at(0).trimmed();
            QString filePassword = fields.at(1).trimmed();
            if (username == fileUsername && password == filePassword) {
                return true; // Credentials match
            }
        }
    }
    return false; // No match found
}
