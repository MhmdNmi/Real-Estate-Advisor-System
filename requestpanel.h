#ifndef REQUESTPANEL_H
#define REQUESTPANEL_H

#include <QDialog>
#include "request.h"
#include "manager.h"
#include <QMessageBox>

namespace Ui {
class requestPanel;
}

class requestPanel : public QDialog {
    Q_OBJECT

    manager * onUser;
public:
    explicit requestPanel(manager * = nullptr, QWidget *parent = nullptr);
    ~requestPanel();

private slots:
    void on_pShow_clicked();

    void on_pDossier_clicked();

    void on_pConfirm_clicked();

private:
    Ui::requestPanel *ui;
};

#endif // REQUESTPANEL_H
