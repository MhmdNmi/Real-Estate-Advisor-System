#ifndef UNITPANEL_H
#define UNITPANEL_H

#include <QDialog>
#include "unit.h"

namespace Ui {
class unitPanel;
}

class unitPanel : public QDialog {
    Q_OBJECT

    unit * onUnit;
    int access;
public:
    explicit unitPanel(unit * = nullptr, int = 0, QWidget *parent = nullptr);
    ~unitPanel();

private slots:
    void on_pClose_clicked();

    void on_pSave_clicked();

private:
    Ui::unitPanel *ui;
};

#endif // UNITPANEL_H
