#include "apartmentpanel.h"
#include "ui_apartmentpanel.h"

#include "unitpanel.h"
#include <QGraphicsPixmapItem>

apartmentPanel::apartmentPanel(apartment * _onHouse, int _access, QWidget *parent) : QDialog(parent), ui(new Ui::apartmentPanel) {
    ui->setupUi(this);
    access = _access;
    onHouse = _onHouse;
    if (access == 0 || access == 1){
        if (onHouse->isSold()) this->setWindowTitle("Sold Apartment");
        else this->setWindowTitle("Apartment for Sell");
        onHouse->setUnitsID();
        QGraphicsScene * plate = new QGraphicsScene();
        QGraphicsPixmapItem * pic = new QGraphicsPixmapItem(QPixmap(QString::fromStdString(onHouse->getPic())));
        plate->addItem(pic);
        ui->lPicAdd_2->setText(QString::fromStdString(onHouse->getPic()));
        ui->graphicsView->setScene(plate);
        ui->lTArea->setText(QString::number(onHouse->getArea()));
        ui->lNFloors->setText(QString::number(onHouse->getNFloors()));
        ui->lNUnits->setText(QString::number(onHouse->getNUnits()));
        ui->lBasePrice->setText(QString::number(onHouse->getBasePrice()));
        ui->lAddress->setText(QString::fromStdString(onHouse->getAddress()));
        if (onHouse->getElevator()) ui->checkBox->setChecked(1);
        for (auto i : onHouse->getUnitsVec()) ui->listWidget->addItem(QString::number(i->getID()));
        if (access == 0){
            ui->lPicAdd_2->setReadOnly(1);
            ui->lTArea->setReadOnly(1);
            ui->lNFloors->setReadOnly(1);
            ui->lNUnits->setReadOnly(1);
            ui->lBasePrice->setReadOnly(1);
            ui->lAddress->setReadOnly(1);
            ui->checkBox->setCheckable(0);
            ui->pSave->setDisabled(1);
        }
    }
    else this->setWindowTitle("New Apartment");
}

apartmentPanel::~apartmentPanel() {
    delete ui;
    onHouse->setUnitsID();
}

void apartmentPanel::on_pClose_clicked() {
    close();
}

void apartmentPanel::on_pShowUnit_clicked(){
    unitPanel * up = new unitPanel(onHouse->getUnit(ui->listWidget->currentItem()->text().toInt()));
    up->show();
}

void apartmentPanel::on_pAddUnit_clicked() {
    unit * u = new unit(0, 0, 0, onHouse);
    onHouse->addUnit(u);
    unitPanel * up = new unitPanel(u);
    up->show();
}

void apartmentPanel::on_pSave_clicked() {
    onHouse->setPic(ui->lPicAdd_2->text().toStdString());
    onHouse->setArea(ui->lTArea->text().toInt());
    onHouse->setNFloors(ui->lNFloors->text().toInt());
    onHouse->setNUnits(ui->lNUnits->text().toInt());
    onHouse->setBasePrice(ui->lBasePrice->text().toDouble());
    onHouse->setAddress(ui->lAddress->text().toStdString());
    if (ui->checkBox->isChecked()) onHouse->setElevator(1);
    else onHouse->setElevator(0);
}
