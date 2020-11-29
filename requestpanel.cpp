#include "requestpanel.h"
#include "ui_requestpanel.h"
#include "rentdosspanel.h"
#include "selldosspanel.h"
#include "villapanel.h"
#include "apartmentpanel.h"
#include "manager.h"

#include <QMessageBox>

extern vector <nUser*> allNUsers;
extern vector <manager*> allManagers;
extern vector <request*> allRequests;
extern QMultiMap <double, sellDossier*> allSellDossiers;
extern QMultiMap <double, rentDossier*> allRentDossiers;
extern QMultiMap <double, apartment*> allApartments;
extern QMultiMap <double, nVilla*> allNVillas;
extern QMultiMap <double, sVilla*> allSVillas;

requestPanel::requestPanel(manager * _onUser, QWidget *parent) : QDialog(parent), ui(new Ui::requestPanel) {
    ui->setupUi(this);
    onUser = _onUser;
    this->setWindowTitle("Requests");
    ui->lName->setReadOnly(1);
    ui->lUsername->setReadOnly(1);
    ui->lCredit->setReadOnly(1);
    for (auto i : allRequests) ui->reqList->addItem(QString::number(i->getDossier()->getId()));
}

requestPanel::~requestPanel() {
    delete ui;
}

void requestPanel::on_pShow_clicked() {
    if (ui->reqList->currentItem()){
        for (auto i : allRequests) if (i->getDossier()->getId() == ui->reqList->currentItem()->text().toInt()){
            ui->lName->setText(QString::fromStdString(i->getUser()->getName()));
            ui->lUsername->setText(QString::fromStdString(i->getUser()->getUername()));
            ui->lCredit->setText(QString::number(i->getUser()->getCredit()));
            break;
        }
    }
    else QMessageBox::information(this, "Error", "Select an Item Please!", QMessageBox::Ok);
}

void requestPanel::on_pDossier_clicked() {
    if (ui->reqList->currentItem()){
        for (auto i : allRequests) if (i->getDossier()->getId() == ui->reqList->currentItem()->text().toInt()){
            if (!(i->getType())){
                sellDossier * s = dynamic_cast<sellDossier *>(i->getDossier());
                SellDossPanel *dp = new SellDossPanel(s, 0, onUser);
                dp->show();
            }
            else {
                rentDossier * s = dynamic_cast<rentDossier *>(i->getDossier());
                RentDossPanel *dp = new RentDossPanel(s, 0, onUser);
                dp->show();
            }
            break;
        }
    }
    else QMessageBox::information(this, "Error", "Select an Item Please!", QMessageBox::Ok);
}

void requestPanel::on_pConfirm_clicked() {
    if (ui->reqList->currentItem()){
        for (auto i : allRequests) if (i->getDossier()->getId() == ui->reqList->currentItem()->text().toInt()){
            if (i->getUser()->getCredit() >= i->getDossier()->fPrice()){
                i->getUser()->decCredit(i->getDossier()->fPrice());
                onUser->riseCredit(i->getDossier()->fPrice());
            }
            else QMessageBox::information(this, "Error", "Not Enough Credit For User!", QMessageBox::Ok);
            break;
        }
    }
    else QMessageBox::information(this, "Error", "Select an Item Please!", QMessageBox::Ok);
}
