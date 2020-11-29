#ifndef APARTMENTPANEL_H
#define APARTMENTPANEL_H

#include <QDialog>
#include "apartment.h"
#include "unit.h"

namespace Ui {
class apartmentPanel;
}

class apartmentPanel : public QDialog {
    Q_OBJECT

    apartment * onHouse;
    int access;
public:
    explicit apartmentPanel(apartment * = nullptr, int = 0, QWidget *parent = nullptr);
    ~apartmentPanel();

private slots:
    void on_pClose_clicked();

    void on_pShowUnit_clicked();

    void on_pAddUnit_clicked();

    void on_pSave_clicked();

private:
    Ui::apartmentPanel *ui;
};

#endif // APARTMENTPANEL_H
