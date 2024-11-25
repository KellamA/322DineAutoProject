#ifndef LOGINSCREEN_H
#define LOGINSCREEN_H

#include <QWidget>

namespace Ui {
class LoginScreen;
}

class LoginScreen : public QWidget {
    Q_OBJECT

public:
    explicit LoginScreen(QWidget *parent = nullptr);
    ~LoginScreen();

private slots:
    void onLoginButtonClicked();

private:
    Ui::LoginScreen *ui;
    bool validateCredentials(const QString &username, const QString &password);
};

#endif // LOGINSCREEN_H
