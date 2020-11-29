#include "unitpanel.h"
#include "ui_unitpanel.h"

#include <QGraphicsPixmapItem>

unitPanel::unitPanel(unit * _onUnit, int _access, QWidget *parent) : QDialog(parent), ui(new Ui::unitPanel) {
    ui->setupUi(this);
    onUnit = _onUnit;
    access = _access;
    if (access == 0 || access == 1){
        if (onUnit->isSold()) this->setWindowTitle("Sold Unit");
        else this->setWindowTitle("Unit for Sell");
        QGraphicsScene * plate = new QGraphicsScene();
        QGraphicsPixmapItem * pic = new QGraphicsPixmapItem(QPixmap(QString::fromStdString(onUnit->getPic())));
        plate->addItem(pic);
        ui->lPicAdd->setText(QString::fromStdString(onUnit->getPic()));
        ui->graphicsView->setScene(plate);
        ui->lCArea->setText(QString::number(onUnit->getCArea()));
        ui->lRooms->setText(QString::number(onUnit->getRooms()));
        ui->lFloorN->setText(QString::number(onUnit->getFloorN()));
        if (access == 0){
            ui->lPicAdd->setReadOnly(1);
            ui->lCArea->setReadOnly(1);
            ui->lRooms->setReadOnly(1);
            ui->lFloorN->setReadOnly(1);
            ui->pSave->setDisabled(1);
        }
    }
    else this->setWindowTitle("New Unit");
}

unitPanel::~unitPanel() {
    delete ui;
}

void unitPanel::on_pClose_clicked() {
    close();
}

void unitPanel::on_pSave_clicked() {
    onUnit->setPic(ui->lPicAdd->text().toStdString());
    onUnit->setCArea(ui->lCArea->text().toInt());
    onUnit->setRooms(ui->lRooms->text().toInt());
    onUnit->setFloorN(ui->lFloorN->text().toInt());
}
