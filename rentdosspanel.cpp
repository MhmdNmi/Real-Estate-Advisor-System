#include "rentdosspanel.h"
#include "ui_rentdosspanel.h"

extern vector <request*> allRequests;
extern QMultiMap <double, rentDossier*> allRentDossiers;
extern QMultiMap <double, apartment*> allApartments;
extern QMultiMap <double, nVilla*> allNVillas;
extern QMultiMap <double, sVilla*> allSVillas;

RentDossPanel::RentDossPanel(rentDossier * _onDossier, int _access, user * _onUser, QWidget *parent) :  QDialog(parent), ui(new Ui::RentDossPanel) {
    ui->setupUi(this);
    onDossier = _onDossier;
    access = _access;
    ui->lFPrice->setReadOnly(1);
    ui->lRent->setReadOnly(1);
    ui->lMortgage->setReadOnly(1);
    if (access == 0 || access == 1){
        this->setWindowTitle("Rent Dossier");
        ui->lDID->setText(QString::fromStdString(onDossier->getDossID()));
        if (onDossier->getType() == 0) ui->lHType->setText("North Villa");
        else if (onDossier->getType() == 1) ui->lHType->setText("South Villa");
        else if (onDossier->getType() == 2) {
            ui->lHType->setText("Apartment");
            ui->lID->setText(QString::number(onDossier->getId()));
        }
        ui->lCommission->setText(QString::number(onDossier->getCommission()));
        ui->lMortgage->setText(QString::number(onDossier->getMort()));
        ui->lRent->setText(QString::number(onDossier->getRent()));
        ui->lRTime->setText(QString::number(onDossier->getRentTime()));
        ui->lFPrice->setText(QString::number(onDossier->fPrice()));
    }
    else {
        this->setWindowTitle("New Rent Dossier");
        ui->pRequest->setEnabled(0);
    }
}

RentDossPanel::~RentDossPanel() {
    delete ui;
}

void RentDossPanel::on_pSave_clicked() {
    onDossier->setDossID(ui->lDID->text().toStdString());
    if (ui->lHType->text() == "North Villa" || ui->lHType->text() == "0") onDossier->setType(0);
    else if (ui->lHType->text() == "South Villa" || ui->lHType->text() == "1") onDossier->setType(1);
    else if (ui->lHType->text() == "Apartment" || ui->lHType->text() == "2") onDossier->setType(2);
    onDossier->setCommission(ui->lCommission->text().toDouble());
    onDossier->setRentTime(ui->lRTime->text().toInt());
    onDossier->mortcal();
    onDossier->rentcal();
    QMessageBox::information(this, "Save", "Everything Successfully Saved!", QMessageBox::Ok);
}

void RentDossPanel::on_pHouse_clicked() {
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
        else if (onDossier->getType() == 2){
            apartment * v = dynamic_cast<apartment *>(onDossier->getHouse());
            apartmentPanel * vp = new apartmentPanel(v, access);
            vp->show();
        }
        else QMessageBox::information(this, "Error", "WTF??", QMessageBox::Ok);
    }
}

void RentDossPanel::on_pRequest_clicked() {
    request * r = new request(onUser, onDossier, 1);
    allRequests.push_back(r);
    QMessageBox::information(this, "Save", "Your Request is Saved!", QMessageBox::Ok);
}
