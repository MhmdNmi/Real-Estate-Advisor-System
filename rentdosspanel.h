#ifndef RENTDOSSPANEL_H
#define RENTDOSSPANEL_H

#include "rentdossier.h"
#include "villapanel.h"
#include "apartmentpanel.h"
#include "request.h"
#include <QDialog>
#include <QMessageBox>

namespace Ui {
class RentDossPanel;
}

class RentDossPanel : public QDialog {
    Q_OBJECT

    rentDossier * onDossier;
    int access;
    user * onUser;
public:
    explicit RentDossPanel(rentDossier *, int, user *, QWidget *parent = nullptr);
    ~RentDossPanel();

private slots:
    void on_pSave_clicked();

    void on_pHouse_clicked();

    void on_pRequest_clicked();

private:
    Ui::RentDossPanel *ui;
};

#endif // RENTDOSSPANEL_H
