#include "selldosspanel.h"
#include "ui_selldosspanel.h"

extern vector <request*> allRequests;
extern QMultiMap <double, sellDossier*> allSellDossiers;
extern QMultiMap <double, apartment*> allApartments;
extern QMultiMap <double, nVilla*> allNVillas;
extern QMultiMap <double, sVilla*> allSVillas;

SellDossPanel::SellDossPanel(sellDossier * _onDossier, int _access, user * _onUser, QWidget *parent) :  QDialog(parent), ui(new Ui::SellDossPanel) {
    ui->setupUi(this);
    onDossier = _onDossier;
    onUser = _onUser;
    access = _access;
    ui->lFPrice->setReadOnly(1);
    if (access == 0 || access == 1){
        this->setWindowTitle("Sell Dossier");
        ui->lDID->setText(QString::fromStdString(onDossier->getDossID()));
        if (onDossier->getType() == 0) ui->lHType->setText("North Villa");
        else if (onDossier->getType() == 1) ui->lHType->setText("South Villa");
        else if (onDossier->getType() == 2) {
            ui->lHType->setText("Apartment");
            ui->lID->setText(QString::number(onDossier->getId()));
        }
        ui->lCommission->setText(QString::number(onDossier->getCommission()));
        ui->lSCond->setText(QString::number(onDossier->getCond()));
        ui->lFPrice->setText(QString::number(onDossier->fPrice()));
    }
    else {
        this->setWindowTitle("New Sell Dossier");
        ui->pRequest->setEnabled(0);
    }
}

SellDossPanel::~SellDossPanel() {
    delete ui;
}

void SellDossPanel::on_pSave_clicked() {
    onDossier->setDossID(ui->lDID->text().toStdString());
    if (ui->lHType->text() == "North Villa" || ui->lHType->text() == "0") onDossier->setType(0);
    else if (ui->lHType->text() == "South Villa" || ui->lHType->text() == "1") onDossier->setType(1);
    else if (ui->lHType->text() == "Apartment" || ui->lHType->text() == "2") onDossier->setType(2);
    onDossier->setCommission(ui->lCommission->text().toDouble());
    onDossier->setCond(ui->lSCond->text().toInt());
    QMessageBox::information(this, "Save", "Everything Successfully Saved!", QMessageBox::Ok);
}

void SellDossPanel::on_pHouse_clicked() {
    if (access == 2){
        if (onDossier->getType() == 0){
            nVilla * v = new nVilla;
            villaPanel * vp = new villaPanel(v, access);
            vp->exec();
            allNVillas.insert(v->calPrice(), v);
            onDossier->setHouse(v);
        }
        else if (onDossier->getType() == 1){
            sVilla * v = new sVilla;
            villaPanel * vp = new villaPanel(v, access);
            vp->exec();
            allSVillas.insert(v->calPrice(), v);
            onDossier->setHouse(v);
        }
        else if (onDossier->getType() == 2){
            apartment * a = new apartment;
            apartmentPanel * ap = new apartmentPanel(a, access);
            ap->exec();
            allApartments.insert(a->calPrice(), a);
            onDossier->setHouse(a);
        }
        else QMessageBox::information(this, "Error", "WTF??", QMessageBox::Ok);
    }
    else {
        if (onDossier->getType() == 0 || onDossier->getType() == 1) {
            villa * v = dynamic_cast<villa *>(onDossier->getHouse());
            villaPanel * vp = new villaPanel(v, access);
            vp->show();
        }
        else if (onDossier->getType() == 2) {
            apartment * v = dynamic_cast<apartment *>(onDossier->getHouse());
            apartmentPanel * vp = new apartmentPanel(v, access);
            vp->show();
        }
        else QMessageBox::information(this, "Error", "WTF??", QMessageBox::Ok);
    }
}

void SellDossPanel::on_pRequest_clicked() {
    request * r = new request(onUser, onDossier, 0);
    allRequests.push_back(r);
    QMessageBox::information(this, "Save", "Your Request is Saved!", QMessageBox::Ok);
}
