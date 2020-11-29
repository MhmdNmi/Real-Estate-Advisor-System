#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QGroupBox>
#include <QListWidget>
#include <QPushButton>
#include <QMenuBar>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QDebug>
#include <fstream>
#include "manager.h"
#include "nuser.h"
#include "request.h"

using namespace std;

class MainWindow : public QMainWindow {
    Q_OBJECT

    bool access;
    user * onUser;
    QPushButton * pShowHouse; // tab 1 all houses
    QListWidget * allHousesList;
    QPushButton * pShowNVilla; // tab 2 nvillas
    QListWidget * nVillasList;
    QPushButton * pShowSVilla; // tab 2 svillas
    QListWidget * sVillasList;
    QPushButton * pShowApartment; // tab 2 apartments
    QListWidget * apartmentsList;
    QPushButton * pShowSellDossier; // tab 3 sell dossier
    QListWidget * sellDossierList;
    QPushButton * pShowRentDossier; // tab 3 rent dossier
    QListWidget * rentDossierList;
    QLineEdit * lBasePriceX; // tab 4 search XY
    QLineEdit * lCAreaY;
    QPushButton * pShowSearchXY;
    QPushButton * pSearchXY;
    QListWidget * listXY;
    QLineEdit * lAddressZ; // tab 4 search Z
    QPushButton * pShowSearchZ;
    QPushButton * pSearchZ;
    QListWidget * listZ;
    QLineEdit * lUnitsN; // tab 5 min units
    QPushButton * pShowSearchN;
    QPushButton * pSearchN;
    QListWidget * listN;
    QLineEdit * lUnitsMA; // tab 5 min unit area
    QPushButton * pShowSearchMA;
    QPushButton * pSearchMA;
    QListWidget * listMA;
    QLineEdit * lUnitsMR; // tab 5 unit rooms
    QPushButton * pShowSearchMR;
    QPushButton * pSearchMR;
    QListWidget * listMR;

public:
    explicit MainWindow(user *, QWidget *parent = nullptr);
    ~MainWindow();
    QListWidget * makeHouseList(vector <house *>);
    QListWidget * makeDossierList(vector <dossier *>);

public slots:
    void new_sell_Dossier();
    void new_Rent_Dossier();
    void pShowHouse_clicked();
    void pShowNVilla_clicked();
    void pShowSVilla_clicked();
    void pShowApartment_clicked();
    void pShowSearchXY_clicked();
    void pSearchXY_clicked();
    void pShowSearchZ_clicked();
    void pSearchZ_clicked();
    void pShowSearchN_clicked();
    void pSearchN_clicked();
    void pShowSearchMA_clicked();
    void pSearchMA_clicked();
    void pShowSearchMR_clicked();
    void pSearchMR_clicked();
    void pShowSellDossier_clicked();
    void pShowRentDossier_clicked();
    void reqsShow();
    void loadFiles();
    void saveFiles();

private:
    QWidget * makeTab1();
    QWidget * makeTab2();
    QWidget * makeTab3();
    QWidget * makeTab4();
    QWidget * makeTab5();
};

#endif // MAINWINDOW_H
