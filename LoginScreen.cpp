#include "LoginScreen.h"
#include "ui_LoginScreen.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

LoginScreen::LoginScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginScreen)
{
    ui->setupUi(this);

    // Connect the login button to the onLoginButtonClicked slot
    connect(ui->loginButton, &QPushButton::clicked, this, &LoginScreen::onLoginButtonClicked);
}

LoginScreen::~LoginScreen() {
    delete ui;
}

void LoginScreen::onLoginButtonClicked() {
    QString username = ui->usernameEdit->text();
    QString password = ui->passwordEdit->text();

    if (validateCredentials(username, password)) {
        QMessageBox::information(this, "Login Successful", "Welcome!");
        // Transition to the menu screen here
    } else {
        QMessageBox::warning(this, "Login Failed", "Incorrect username or password.");
    }
}

bool LoginScreen::validateCredentials(const QString &username, const QString &password) {
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
