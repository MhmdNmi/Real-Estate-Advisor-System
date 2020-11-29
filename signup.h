#ifndef SIGNUP_H
#define SIGNUP_H

#include <QMainWindow>
#include "rentdossier.h"
#include "selldossier.h"
#include "manager.h"
#include "nuser.h"

namespace Ui {
class signup;
}

class signup : public QMainWindow
{
    Q_OBJECT

public:
    explicit signup(QWidget *parent = nullptr);
    ~signup();

private slots:
    void on_pCancel_clicked();

    void on_pRegister_clicked();

private:
    Ui::signup *ui;
};

#endif // SIGNUP_H
