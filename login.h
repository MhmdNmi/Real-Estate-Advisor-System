#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "rentdossier.h"
#include "selldossier.h"
#include "manager.h"
#include "nuser.h"
#include <ctime>

namespace Ui {
class login;
}

class login : public QDialog {
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();
    void loadFiles();
    void saveFiles();

private slots:
    void on_pClose_clicked();
    void on_pSignup_clicked();
    void on_pLogin_clicked();

private:
    Ui::login *ui;
};

#endif // LOGIN_H
