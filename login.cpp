#include "login.h"
#include "ui_login.h"
#include "signup.h"
#include "mainwindow.h"

#include <fstream>
using namespace std;
#include <QDebug>
#include <QMessageBox>
#include <vector>

extern vector <nUser*> allNUsers;
extern vector <manager*> allManagers;
//extern QMultiMap <double, sellDossier*> allSellDossiers;
//extern QMultiMap <double, rentDossier*> allRentDossiers;
//extern QMultiMap <double, apartment*> allApartments;
//extern QMultiMap <double, nVilla*> allNVillas;
//extern QMultiMap <double, sVilla*> allSVillas;

void login::loadFiles() {
    qDebug() << "Loading Users Files!";
    ifstream fli;
    fli.open("managers.txt");
    string _name, _username, _password, t;
    bool _status;
    int _credit, _y, _m, _d, _yl, _ml, _dl;
    if (fli.is_open()) {
        qDebug() << "Managers Opened!";
        while (fli.good()) {
            t = _name;
            fli >> _name >> _y >> _m >> _d >> _username >> _password >> _status >> _credit >> _yl >> _ml >> _dl;
            if (t != _name) {
                allManagers.push_back(new manager(_name, *(new date(_y, _m, _d)), _username, _password, *(new date(_yl, _ml, _dl)), _status, _credit));
                qDebug() << QString::fromStdString(_name) << QString::fromStdString(_password);
            }
        }
        fli.close();
    }
    qDebug() << "Managers Closed!";
    fli.open("nUsers.txt");
    if (fli.is_open()) {
        qDebug() << "Normal Users Opened!";
        while (fli.good()) {
            t = _name;
            fli >> _name >> _y >> _m >> _d >> _username >> _password >> _status >> _credit >> _yl >> _ml >> _dl;
            if (t != _name) {
                allNUsers.push_back(new nUser(_name, *(new date(_y, _m, _d)), _username, _password, *(new date(_yl, _ml, _dl)), _status, _credit));
                qDebug() << QString::fromStdString(_name) << QString::fromStdString(_password);
            }
        }
        fli.close();
    }
    qDebug() << "Normal Users Closed!";
}

login::login(QWidget *parent) :  QDialog(parent), ui(new Ui::login){
    ui->setupUi(this);

    loadFiles();
    ui->rNUser->setChecked(1);
    this->setWindowTitle("Log In");
    ui->lPassword->setEchoMode(QLineEdit::Password);

}

void login::saveFiles(){
    ofstream f;
    f.open("managers.txt");
    qDebug() << "Managers Opened!";
    for (auto i : allManagers){
        date dB = i->getBirth();
        date dL = i->getLastLogin();
        f << i->getName() << " " << dB.getYear() << " " << dB.getMonth() << " " << dB.getDay() << " " << i->getUername() << " " << i->getPassword() << " " << i->getStatus() << " " << i->getCredit() << " " << dL.getYear() << " " << dL.getMonth() << " " << dL.getDay() << endl;
        qDebug() << QString::fromStdString(i->getName()) << QString::fromStdString(i->getPassword());
    }
    f.close();
    qDebug() << "Managers Closed!";
    f.open("nUsers.txt");
    qDebug() << "Normal Users Opened!";
    for (auto i : allNUsers){
        date dB = i->getBirth();
        date dL = i->getLastLogin();
        f << i->getName() << " " << dB.getYear() << " " << dB.getMonth() << " " << dB.getDay() << " " << i->getUername() << " " << i->getPassword() << " " << i->getStatus() << " " << i->getCredit() << " " << dL.getYear() << " " << dL.getMonth() << " " << dL.getDay() << endl;
        qDebug() << QString::fromStdString(i->getName()) << QString::fromStdString(i->getPassword());
    }
    f.close();
    qDebug() << "Normal Users Closed!";
}

login::~login() {
    saveFiles();
    delete ui;
}

void login::on_pClose_clicked() {
    this->close();
}

void login::on_pSignup_clicked() {
    signup * s = new signup;
    s->show();
}

extern MainWindow * w;

void login::on_pLogin_clicked() {
    if (ui->lUsername->text() != "" && ui->lPassword->text() != "") {
        bool f = 0;
        if (ui->rManager->isChecked()){
            manager * t;
            for (auto i : allManagers) if (ui->lUsername->text().toStdString() == i->getUername()) {
                t = i;
                f = 1;
                break;
            }
            if (f) {
                if (t->isPass(ui->lPassword->text().toStdString())) {
                    w = new MainWindow(t);
                    w->show();
                    QMessageBox::information(this, "Loging In", "You are Successfuly Loged In!", QMessageBox::Ok);
                    this->close();
                }
            }
            else QMessageBox::information(this, "Error", "User Not Found!", QMessageBox::Ok);
        }
        else if (ui->rNUser->isChecked()) {
            nUser * t;
            for (auto i : allNUsers) if (ui->lUsername->text().toStdString() == i->getUername()) {
                t = i;
                f = 1;
                break;
            }
            if (f) {
                if (t->isPass(ui->lPassword->text().toStdString())) {
                    time_t now = time(0);
                    tm *ltm = localtime(&now);
                    t->setLastLogin(*(new date(ltm->tm_year + 1970, ltm->tm_mon + 1, ltm->tm_mday)));
                    w = new MainWindow(t);
                    w->show();
                    QMessageBox::information(this, "Loging In", "You are Successfuly Loged In!", QMessageBox::Ok);
                    this->hide();
                }
            }
            else QMessageBox::information(this, "Error", "User Not Found!", QMessageBox::Ok);
        }
    }
    else QMessageBox::information(this, "Error", "Fill the Lines!", QMessageBox::Ok);
}
