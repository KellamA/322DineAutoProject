#ifndef LOGINSCREENUI_H
#define LOGINSCREENUI_H

#include <QDialog>

namespace Ui {
class LoginScreenUI;
}

class LoginScreenUI : public QDialog {
    Q_OBJECT

public:
    explicit LoginScreenUI(QWidget *parent = nullptr);
    ~LoginScreenUI();

private slots:
    void onLoginButtonClicked();

private:
    Ui::LoginScreenUI *ui;
    bool validateCredentials(const QString &username, const QString &password, QString &role);
};

#endif // LOGINSCREENUI_H
