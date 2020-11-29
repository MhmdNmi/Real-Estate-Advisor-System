#ifndef VILLAPANEL_H
#define VILLAPANEL_H

#include <QDialog>
#include "svilla.h"
#include "nvilla.h"

namespace Ui {
class villaPanel;
}

class villaPanel : public QDialog {
    Q_OBJECT

    villa * onHouse;
    int access;
public:
    explicit villaPanel(villa * = nullptr, int = 0, QWidget *parent = nullptr);
    ~villaPanel();

private slots:
    void on_pClose_clicked();

    void on_pSave_clicked();

private:
    Ui::villaPanel *ui;
};

#endif // VILLAPANEL_H
