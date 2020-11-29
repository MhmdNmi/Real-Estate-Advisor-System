#include "villapanel.h"
#include "ui_villapanel.h"

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>

villaPanel::villaPanel(villa * _onHouse, int _access, QWidget *parent) : QDialog(parent), ui(new Ui::villaPanel) {
    ui->setupUi(this);
    access = _access;
    onHouse = _onHouse;
    if (access == 0 || access == 1){
        if (onHouse->isSold()) this->setWindowTitle("Sold Villa");
        else this->setWindowTitle("Villa for Sell");
        QGraphicsScene * plate = new QGraphicsScene();
        QGraphicsPixmapItem * pic = new QGraphicsPixmapItem(QPixmap(QString::fromStdString(onHouse->getPic())));
        plate->addItem(pic);
        ui->lPicAdd->setText(QString::fromStdString(onHouse->getPic()));
        ui->graphicsView->setScene(plate);
        ui->lTArea->setText(QString::number(onHouse->getArea()));
        ui->lCArea->setText(QString::number(onHouse->getCArea()));
        ui->lRooms->setText(QString::number(onHouse->getRooms()));
        ui->lBYardArea->setText(QString::number(onHouse->getBYardArea()));
        ui->lBasePrice->setText(QString::number(onHouse->getBasePrice()));
        ui->lAddress->setText(QString::fromStdString(onHouse->getAddress()));
        nVilla * nV = dynamic_cast<nVilla *>(onHouse);
        if (nV){
            ui->lFYardArea->setText(QString::number(nV->getFYardArea()));
            ui->lParking->setText("!!!");
        }
        else {
            sVilla * sV = dynamic_cast<sVilla *>(onHouse);
            ui->lFYardArea->setText("!!!");
            ui->lParking->setText(QString::number(sV->getParking()));
        }
        if (access == 0){
            ui->lPicAdd->setReadOnly(1);
            ui->lTArea->setReadOnly(1);
            ui->lCArea->setReadOnly(1);
            ui->lRooms->setReadOnly(1);
            ui->lBYardArea->setReadOnly(1);
            ui->lBasePrice->setReadOnly(1);
            ui->lAddress->setReadOnly(1);
            ui->lFYardArea->setReadOnly(1);
            ui->lParking->setReadOnly(1);
            ui->pSave->setDisabled(1);
        }
    }
    else this->setWindowTitle("New Villa");
}

villaPanel::~villaPanel() {
    delete ui;
}

void villaPanel::on_pClose_clicked() {
    close();
}

void villaPanel::on_pSave_clicked(){
    onHouse->setPic(ui->lPicAdd->text().toStdString());
    onHouse->setArea(ui->lTArea->text().toInt());
    onHouse->setCArea(ui->lCArea->text().toInt());
    onHouse->setRooms(ui->lRooms->text().toInt());
    onHouse->setBYardArea(ui->lBYardArea->text().toInt());
    onHouse->setBasePrice(ui->lBasePrice->text().toInt());
    onHouse->setAddress(ui->lAddress->text().toStdString());
    nVilla * nV = dynamic_cast<nVilla *>(onHouse);
    if (nV){
        nV->setFYardArea(ui->lFYardArea->text().toInt());
    }
    else {
        sVilla * sV = dynamic_cast<sVilla *>(onHouse);
        sV->setParking(ui->lParking->text().toInt());
    }
}
