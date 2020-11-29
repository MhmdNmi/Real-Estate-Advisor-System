#include "signup.h"
#include "ui_signup.h"
#include <QMessageBox>

#include <ctime>
#include <QString>

extern vector <nUser*> allNUsers;
extern vector <manager*> allManagers;
//extern QMultiMap <double, sellDossier*> allSellDossiers;
//extern QMultiMap <double, rentDossier*> allRentDossiers;
//extern QMultiMap <double, apartment*> allApartments;
//extern QMultiMap <double, nVilla*> allNVillas;
//extern QMultiMap <double, sVilla*> allSVillas;

signup::signup(QWidget *parent) :  QMainWindow(parent), ui(new Ui::signup) {
    ui->setupUi(this);
    ui->rNUser->setChecked(1);
    ui->sbYear->setRange(1970, 2000);
    ui->sbYear->setValue(1999);
    ui->sbMonth->setRange(1, 12);
    ui->sbMonth->setValue(3);
    ui->sbDay->setRange(1, 31);
    ui->sbDay->setValue(26);
    this->setFixedSize(320, 300);
    this->setWindowTitle("Sign Up");
    ui->lPassword->setEchoMode(QLineEdit::Password);
    ui->lRPassword->setEchoMode(QLineEdit::Password);
    ui->lFCredit->setText("0");
}

signup::~signup() {
    delete ui;
}

void signup::on_pCancel_clicked() {
    this->close();
}

void signup::on_pRegister_clicked() {
    if (ui->lName->text() != "" && ui->lRPassword->text() != "" && ui->lPassword->text() != "" && ui->lUsername->text() != ""){
        if (ui->lPassword->text() == ui->lRPassword->text()){
            bool f = 0;
            time_t now = time(0);
            tm *ltm = localtime(&now);
            if (ui->rManager->isChecked()){
                for (auto i : allManagers) if (ui->lUsername->text().toStdString() == i->getUername()) f = 1;
                if (f) QMessageBox::information(this, "Error", "Username is Taken!", QMessageBox::Ok);
                else {
                    allManagers.push_back(new manager(ui->lName->text().toStdString(), *(new date(ui->sbYear->value(), ui->sbMonth->value(), ui->sbDay->value())), ui->lUsername->text().toStdString(), ui->lPassword->text().toStdString(), *(new date(ltm->tm_year + 1970, ltm->tm_mon + 1, ltm->tm_mday)), 1, ui->lFCredit->text().toInt()));
                    QMessageBox::information(this, "Error", "You are Successfuly Registered!", QMessageBox::Ok);
                }
            }
            else if (ui->rNUser->isChecked()) {
                for (auto i : allNUsers) if (ui->lUsername->text().toStdString() == i->getUername()) f = 1;
                if (f) QMessageBox::information(this, "Error", "Username is Taken!", QMessageBox::Ok);
                else {
                    allManagers.push_back(new manager(ui->lName->text().toStdString(), *(new date(ui->sbYear->value(), ui->sbMonth->value(), ui->sbDay->value())), ui->lUsername->text().toStdString(), ui->lPassword->text().toStdString(), *(new date(ltm->tm_year + 1970, ltm->tm_mon + 1, ltm->tm_mday)), 1, ui->lFCredit->text().toInt()));
                    QMessageBox::information(this, "Error", "You are Successfuly Registered!", QMessageBox::Ok);
                }
            }
        }
        else QMessageBox::information(this, "Error", "Password and ReWrite Missmatch!!", QMessageBox::Ok);
    }
    else QMessageBox::information(this, "Error", "Fill All Lines!", QMessageBox::Ok);
}
