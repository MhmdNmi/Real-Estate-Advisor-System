#ifndef SELLDOSSPANEL_H
#define SELLDOSSPANEL_H

#include "selldossier.h"
#include "villapanel.h"
#include "apartmentpanel.h"
#include "request.h"
#include <QDialog>
#include <QMessageBox>

namespace Ui {
class SellDossPanel;
}

class SellDossPanel : public QDialog
{
    Q_OBJECT

    sellDossier * onDossier;
    int access;
    user * onUser;
public:
    explicit SellDossPanel(sellDossier *, int, user * ,QWidget *parent = nullptr);
    ~SellDossPanel();

private slots:
    void on_pSave_clicked();

    void on_pHouse_clicked();

    void on_pRequest_clicked();

private:
    Ui::SellDossPanel *ui;
};

#endif // SELLDOSSPANEL_H
