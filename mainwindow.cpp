#include "mainwindow.h"
#include "selldosspanel.h"
#include "rentdosspanel.h"
#include "villapanel.h"
#include "apartmentpanel.h"
#include "unitpanel.h"
#include "requestpanel.h"
#include <ctime>

extern vector <nUser*> allNUsers;
extern vector <manager*> allManagers;
extern vector <request*> allRequests;
extern QMultiMap <double, nVilla*> allNVillas;
extern QMultiMap <double, sVilla*> allSVillas;
extern QMultiMap <double, apartment*> allApartments;
extern QMultiMap <double, sellDossier*> allSellDossiers;
extern QMultiMap <double, rentDossier*> allRentDossiers;

void MainWindow::loadFiles(){
    qDebug() << "Loading Files!";
    ifstream f;
    f.open("requests.txt");
    bool _type;
    string _username, _dossID, t;
    if (f.is_open()) {
        qDebug() << "Requests Opened!";
        while (f.good()) {
            t = _username;
            f >> _type >> _username >> _dossID;
            if (t != _username) {
                user * _onUser;
                dossier * _onDossier;
                bool f = 0;
                for (auto i : allNUsers) if (_username == i->getUername()) {
                    f = 1;
                    _onUser = i;
                    break;
                }
                if (f) for (auto i : allManagers) if (_username == i->getUername()){
                    _onUser = i;
                    f = 0;
                    break;
                }
                if (_type) for (auto i : allRentDossiers) if (_dossID == i->getDossID()) {
                    _onDossier = i;
                    break;
                }
                else for (auto i : allSellDossiers) if (_dossID == i->getDossID()) {
                    _onDossier = i;
                    break;
                }
                allRequests.push_back(new request(_onUser, _onDossier, _type));
                qDebug() << QString::fromStdString(_username) << QString::fromStdString(_dossID);
            }
        }
        f.close();
    }
    qDebug() << "Requests Closed!";

    f.open("nVillas.txt");
    string _address, _picAdd;
    int _tArea, _cArea, _bYardArea, _fYardArea, _rooms;
    double _basePrice;
    if (f.is_open()) {
        qDebug() << "North Villas Opened!";
        while (f.good()) {
            t = _address;
            f >> _tArea >> _cArea >> _bYardArea >> _fYardArea >> _basePrice >> _rooms >> _address >> _picAdd;
            if (t != _address) {
                nVilla * nv = new nVilla(_tArea, _cArea, _bYardArea, _fYardArea, _basePrice, _rooms, _address, _picAdd);
                allNVillas.insert(nv->calPrice(), nv);
            }
        }
        f.close();
    }
    qDebug() << "North Villas Closed!";

    f.open("sVillas.txt");
    int _parking;
    if (f.is_open()) {
        qDebug() << "South Villas Opened!";
        while (f.good()) {
            t = _address;
            f >> _tArea >> _cArea >> _bYardArea >> _parking >> _basePrice >> _rooms >> _address >> _picAdd;
            if (t != _address) {
                sVilla * sv = new sVilla(_tArea, _cArea, _bYardArea, _parking, _basePrice, _rooms, _address, _picAdd);
                allSVillas.insert(sv->calPrice(), sv);
            }
        }
        f.close();
    }
    qDebug() << "South Villas Closed!";

    f.open("apartments.txt");
    int _nFloors, _nUnits, _floorN, _use;
    bool _elevator;
    if (f.is_open()) {
        qDebug() << "Apartments Opened!";
        while (f.good()) {
            t = _address;
            f >> _tArea >> _nFloors >> _nUnits >> _elevator >> _basePrice >> _address >> _picAdd;
            if (t != _address) {
                apartment * a = new apartment(_tArea, _nFloors, _nUnits, _elevator, _basePrice, _address, _picAdd);
                allApartments.insert(a->calPrice(), a);
                for (int i = 0; i < _nFloors; i++) {
                    f >> _nFloors >> _rooms >> _cArea >> _use >> _picAdd;
                    a->addUnit(new unit(_floorN, _rooms, _cArea, a, _use, _picAdd));
                }
                a->setUnitsID();
            }
        }
        f.close();
    }
    qDebug() << "Apartments Closed!";

    f.open("sellDossiers.txt");
    double _commission;
    bool _sellcond;
    int _id;
    if (f.is_open()) {
        qDebug() << "Sell Dossiers Opened!";
        while (f.good()) {
            t = _address;
            f >> _dossID >> _address >> _commission >> _sellcond >> _type >> _id;
            if (t != _address) {
                house* _h;
                if (_type == 0) for (auto i : allNVillas) if (i->getAddress() == _address) {
                    _h = i;
                    break;
                }
                else if (_type == 1) for (auto i : allSVillas) if (i->getAddress() == _address) {
                    _h = i;
                    break;
                }
                else if (_type == 2) for (auto i : allApartments) if (i->getAddress() == _address) {
                    _h = i;
                    break;
                }
                sellDossier * a = new sellDossier(_dossID, _h, _commission, _sellcond, _type, _id);
                allSellDossiers.insert(a->fPrice(), a);
            }
        }
        f.close();
    }
    qDebug() << "Sell Dossiers Closed!";

    f.open("rentDossiers.txt");
    int _rentTime;
    if (f.is_open()) {
        qDebug() << "Rent Dossiers Opened!";
        while (f.good()) {
            t = _address;
            f >> _dossID >> _address >> _commission >> _rentTime >> _type >> _id;
            if (t != _address) {
                house* _h;
                if (_type == 0) for (auto i : allNVillas) if (i->getAddress() == _address) {
                    _h = i;
                    break;
                }
                else if (_type == 1) for (auto i : allSVillas) if (i->getAddress() == _address) {
                    _h = i;
                    break;
                }
                else if (_type == 2) for (auto i : allApartments) if (i->getAddress() == _address) {
                    _h = i;
                    break;
                }
                rentDossier * a = new rentDossier(_dossID, _h, _commission, _rentTime, _type, _id);
                allRentDossiers.insert(a->fPrice(), a);
            }
        }
        f.close();
    }
    qDebug() << "Rent Dossiers Closed!";
}

void MainWindow::saveFiles(){
    qDebug() << "Saving Files!";
    ofstream f;
    f.open("requests.txt");
    for (auto i : allRequests) f << i->getType() << " " << i->getUser()->getUername() << " " << i->getDossier()->getDossID() << endl;
    f.close();
    qDebug() << "Requests Closed!";

    f.open("nVillas.txt");
    for (auto i : allNVillas) f << i->getArea() << " " << i->getCArea() << " " << i->getBYardArea() << " " << i->getFYardArea() << " " << i->getBasePrice() << " " << i->getRooms() << " " << i->getAddress() << " " << i->getPic() << endl;
    f.close();
    qDebug() << "South Villas Closed!";

    f.open("sVillas.txt");
    for (auto i : allSVillas) f << i->getArea() << " " << i->getCArea() << " " << i->getBYardArea() << " " << i->getParking() << " " << i->getBasePrice()  << " " << i->getRooms() << " " << i->getAddress() << " " << i->getPic() << endl;
    f.close();
    qDebug() << "North Villas Closed!";

    f.open("apartments.txt");
    for (auto i : allApartments) {
        f << i->getArea() << " " << i->getNFloors() << " " << i->getNUnits() << " " << i->getElevator() << " " << i->getBasePrice()<< " " << i->getAddress() << " " << i->getPic() << endl;
        for (auto j : i->getUnitsVec()) f << j->getFloorN() << " " << j->getRooms() << " " << j->getCArea() << " " << j->getUse() << " " << j->getPic() << endl;
    }
    f.close();
    qDebug() << "Apartments Closed!";

    f.open("sellDossiers.txt");
    qDebug() << "Sell Dossiers Opened!";
    for (auto i : allSellDossiers) f << i->getDossID() << " " << i->getHouse()->getAddress() << " " << i->getCommission() << " " << i->getCond() << " " << i->getType() << " " << i->getId() << endl;
    f.close();
    qDebug() << "Sell Dossiers Closed!";

    f.open("rentDossiers.txt");
    qDebug() << "Rent Dossiers Opened!";
    for (auto i : allRentDossiers) f << i->getDossID() << " " << i->getHouse()->getAddress() << " " << i->getCommission() << " " << i->getRentTime() << " " << i->getType() << " " << i->getId() << endl;
    f.close();
    qDebug() << "Rent Dossiers Closed!";
}

QListWidget * MainWindow::makeHouseList(vector <house *> vec){
    QListWidget * houseList = new QListWidget;
    for (auto i : vec) houseList->addItem(QString::fromStdString(i->getAddress()));
    return houseList;
}

QListWidget * MainWindow::makeDossierList(vector <dossier *> vec){
    QListWidget * dossierList = new QListWidget;
    for (auto i : vec) dossierList->addItem(QString::fromStdString(i->getDossID()));
    return dossierList;
}

QWidget * MainWindow::makeTab1(){
    QWidget * cTab1 = new QWidget;
    QMultiMap <double, house*> allHouses;
    for (auto i : allNVillas) allHouses.insert(i->calPrice(), i);
    for (auto i : allSVillas) allHouses.insert(i->calPrice(), i);
    for (auto i : allApartments) allHouses.insert(i->calPrice(), i);
    vector <house *> vech;
    for (auto i : allHouses) vech.push_back(i);
    QVBoxLayout * tab1Layout = new QVBoxLayout;
    QGroupBox * hBox = new QGroupBox("All Houses: ");
    QVBoxLayout * hBoxLayout = new QVBoxLayout;
    allHousesList = makeHouseList(vech);
    hBoxLayout->addWidget(allHousesList);
    hBox->setLayout(hBoxLayout);
    tab1Layout->addWidget(hBox);
    pShowHouse = new QPushButton("Show");
    hBoxLayout->addWidget(pShowHouse);
    pShowHouse->setFixedWidth(200);
    cTab1->setLayout(tab1Layout);
    connect(pShowHouse, SIGNAL(clicked()), this, SLOT(pShowHouse_clicked()));
    return cTab1;
}

QWidget * MainWindow::makeTab2(){
    QWidget * cTab2 = new QWidget;
    QVBoxLayout * tab2Layout = new QVBoxLayout;

    QGroupBox * nVillaBox = new QGroupBox("North Villas: ");
    QHBoxLayout * nVillaBoxLayout = new QHBoxLayout;
    vector <house *> vecn;
//    for (auto i : allNVillas) vecn.push_back(i.second);
    for (auto i : allNVillas) vecn.push_back(i);
    nVillasList = makeHouseList(vecn);
    nVillaBoxLayout->addWidget(nVillasList);
    pShowNVilla = new QPushButton("Show");
    nVillaBoxLayout->addWidget(pShowNVilla);
    nVillaBox->setLayout(nVillaBoxLayout);
    tab2Layout->addWidget(nVillaBox);
    connect(pShowNVilla, SIGNAL(clicked()), this, SLOT(pShowNVilla_clicked()));

    QGroupBox * sVillaBox = new QGroupBox("South Villas: ");
    QHBoxLayout * sVillaBoxLayout = new QHBoxLayout;
    vector <house *> vecs;
    for (auto i : allSVillas) vecs.push_back(i);
//    for (auto i : allSVillas) vecs.push_back(i.second);
    sVillasList = makeHouseList(vecs);
    sVillaBoxLayout->addWidget(sVillasList);
    pShowSVilla = new QPushButton("Show");
    sVillaBoxLayout->addWidget(pShowSVilla);
    sVillaBox->setLayout(sVillaBoxLayout);
    tab2Layout->addWidget(sVillaBox);
    connect(pShowSVilla, SIGNAL(clicked()), this, SLOT(pShowSVilla_clicked()));

    QGroupBox * apartmentBox = new QGroupBox("Apartments: ");
    QHBoxLayout * apartmentBoxLayout = new QHBoxLayout;
    vector <house *> veca;
//    for (auto i : allApartments) veca.push_back(i.second);
    for (auto i : allApartments) veca.push_back(i);
    apartmentsList = makeHouseList(veca);
    apartmentBoxLayout->addWidget(apartmentsList);
    pShowApartment = new QPushButton("Show");
    apartmentBoxLayout->addWidget(pShowApartment);
    apartmentBox->setLayout(apartmentBoxLayout);
    tab2Layout->addWidget(apartmentBox);
    connect(pShowApartment, SIGNAL(clicked()), this, SLOT(pShowApartment_clicked()));

    cTab2->setLayout(tab2Layout);
    return cTab2;
}

QWidget * MainWindow::makeTab3(){
    QWidget * cTab3 = new QWidget;
    QVBoxLayout * tab3Layout = new QVBoxLayout;

    QGroupBox * sellDossierBox = new QGroupBox("Sell Dossiers: ");
    QHBoxLayout * sellDossierBoxLayout = new QHBoxLayout;
    vector <dossier *> vecn;
//    for (auto i : allSellDossiers) vecn.push_back(i.second);
    for (auto i : allSellDossiers) vecn.push_back(i);
    sellDossierList = makeDossierList(vecn);
    sellDossierBoxLayout->addWidget(sellDossierList);
    pShowSellDossier = new QPushButton("Show");
    sellDossierBoxLayout->addWidget(pShowSellDossier);
    sellDossierBox->setLayout(sellDossierBoxLayout);
    tab3Layout->addWidget(sellDossierBox);
    connect(pShowSellDossier, SIGNAL(clicked()), this, SLOT(pShowSellDossier_clicked()));

    QGroupBox * rentDossierBox = new QGroupBox("Rent Dossiers: ");
    QHBoxLayout * rentDossierBoxLayout = new QHBoxLayout;
    vector <dossier *> vecs;
//    for (auto i : allRentDossiers) vecs.push_back(i.second);
    for (auto i : allRentDossiers) vecs.push_back(i);
    rentDossierList = makeDossierList(vecs);
    rentDossierBoxLayout->addWidget(rentDossierList);
    pShowRentDossier = new QPushButton("Show");
    rentDossierBoxLayout->addWidget(pShowRentDossier);
    rentDossierBox->setLayout(rentDossierBoxLayout);
    tab3Layout->addWidget(rentDossierBox);
    connect(pShowRentDossier, SIGNAL(clicked()), this, SLOT(pShowRentDossier_clicked()));

    cTab3->setLayout(tab3Layout);
    return cTab3;
}

QWidget * MainWindow::makeTab4(){
    QWidget * cTab4 = new QWidget;
    QVBoxLayout * tab4Layout = new QVBoxLayout;

    QGroupBox * searchXYBox = new QGroupBox("Search by Base Price & Construction Area: ");
    QGridLayout * searchXYBoxLayout = new QGridLayout;
    searchXYBoxLayout->addWidget(new QLabel("Max Base Price: "), 0, 0);
    lBasePriceX = new QLineEdit;
    searchXYBoxLayout->addWidget(lBasePriceX, 0, 1);
    searchXYBoxLayout->addWidget(new QLabel("Min Construction Area: "), 1, 0);
    lCAreaY = new QLineEdit;
    searchXYBoxLayout->addWidget(lCAreaY, 1, 1);
    pShowSearchXY = new QPushButton("Show");
    pShowSearchXY->setFixedWidth(200);
    pSearchXY = new QPushButton("Search");
    pSearchXY->setFixedWidth(200);
    searchXYBoxLayout->addWidget(pSearchXY, 2, 0);
    searchXYBoxLayout->addWidget(pShowSearchXY, 2, 1);
    listXY = new QListWidget;
    searchXYBoxLayout->addWidget(listXY, 3, 0, 4, 2);
    searchXYBox->setLayout(searchXYBoxLayout);
    tab4Layout->addWidget(searchXYBox);
    connect(pSearchXY, SIGNAL(clicked()), this, SLOT(pSearchXY_clicked()));
    connect(pShowSearchXY, SIGNAL(clicked()), this, SLOT(pShowSearchXY_clicked()));

    QGroupBox * searchZBox = new QGroupBox("Search by Address: ");
    QGridLayout * searchZBoxLayout = new QGridLayout;
    searchZBoxLayout->addWidget(new QLabel("Address Bound: "), 0, 0);
    lAddressZ = new QLineEdit;
    searchZBoxLayout->addWidget(lAddressZ, 0, 1);
    pShowSearchZ = new QPushButton("Show");
    pShowSearchZ->setFixedWidth(200);
    pSearchZ = new QPushButton("Search");
    pSearchZ->setFixedWidth(200);
    searchZBoxLayout->addWidget(pSearchZ, 1, 0);
    searchZBoxLayout->addWidget(pShowSearchZ, 1, 1);
    listZ = new QListWidget;
    searchZBoxLayout->addWidget(listZ, 2, 0, 4, 2);
    searchZBox->setLayout(searchZBoxLayout);
    tab4Layout->addWidget(searchZBox);
    connect(pSearchZ, SIGNAL(clicked()), this, SLOT(pSearchZ_clicked()));
    connect(pShowSearchZ, SIGNAL(clicked()), this, SLOT(pShowSearchZ_clicked()));

    cTab4->setLayout(tab4Layout);
    return cTab4;
}

QWidget * MainWindow::makeTab5(){
    QWidget * cTab5 = new QWidget;
    QVBoxLayout * tab5Layout = new QVBoxLayout;

    QGroupBox * searchNBox = new QGroupBox("Search by Units Num: ");
    QGridLayout * searchNBoxLayout = new QGridLayout;
    searchNBoxLayout->addWidget(new QLabel("Min Unit Num: "), 0, 0);
    lUnitsN = new QLineEdit;
    searchNBoxLayout->addWidget(lUnitsN, 0, 1);
    pShowSearchN = new QPushButton("Show");
    pShowSearchN->setFixedWidth(200);
    pSearchN = new QPushButton("Search");
    pSearchN->setFixedWidth(200);
    searchNBoxLayout->addWidget(pSearchN, 1, 0);
    searchNBoxLayout->addWidget(pShowSearchN, 1, 1);
    listN = new QListWidget;
    searchNBoxLayout->addWidget(listN, 2, 0, 4, 2);
    searchNBox->setLayout(searchNBoxLayout);
    tab5Layout->addWidget(searchNBox);
    connect(pSearchN, SIGNAL(clicked()), this, SLOT(pSearchN_clicked()));
    connect(pShowSearchN, SIGNAL(clicked()), this, SLOT(pShowSearchN_clicked()));

    QGroupBox * searchMABox = new QGroupBox("Search by Units Area: ");
    QGridLayout * searchMABoxLayout = new QGridLayout;
    searchMABoxLayout->addWidget(new QLabel("Min Unit Construction Area: "), 0, 0);
    lUnitsMA = new QLineEdit;
    searchMABoxLayout->addWidget(lUnitsMA, 0, 1);
    pShowSearchMA = new QPushButton("Show");
    pShowSearchMA->setFixedWidth(200);
    pSearchMA = new QPushButton("Search");
    pSearchMA->setFixedWidth(200);
    searchMABoxLayout->addWidget(pSearchMA, 1, 0);
    searchMABoxLayout->addWidget(pShowSearchMA, 1, 1);
    listMA = new QListWidget;
    searchMABoxLayout->addWidget(listMA, 2, 0, 4, 2);
    searchMABox->setLayout(searchMABoxLayout);
    tab5Layout->addWidget(searchMABox);
    connect(pSearchMA, SIGNAL(clicked()), this, SLOT(pSearchMA_clicked()));
    connect(pShowSearchMA, SIGNAL(clicked()), this, SLOT(pShowSearchMA_clicked()));

    QGroupBox * searchMRBox = new QGroupBox("Search by Units Rooms: ");
    QGridLayout * searchMRBoxLayout = new QGridLayout;
    searchMRBoxLayout->addWidget(new QLabel("Min Unit Rooms: "), 0, 0);
    lUnitsMR = new QLineEdit;
    searchMRBoxLayout->addWidget(lUnitsMR, 0, 1);
    pShowSearchMR = new QPushButton("Show");
    pShowSearchMR->setFixedWidth(200);
    pSearchMR = new QPushButton("Search");
    pSearchMR->setFixedWidth(200);
    searchMRBoxLayout->addWidget(pSearchMR, 1, 0);
    searchMRBoxLayout->addWidget(pShowSearchMR, 1, 1);
    listMR = new QListWidget;
    searchMRBoxLayout->addWidget(listMR, 2, 0, 4, 2);
    searchMRBox->setLayout(searchMRBoxLayout);
    tab5Layout->addWidget(searchMRBox);
    connect(pSearchMR, SIGNAL(clicked()), this, SLOT(pSearchMR_clicked()));
    connect(pShowSearchMR, SIGNAL(clicked()), this, SLOT(pShowSearchMR_clicked()));

    cTab5->setLayout(tab5Layout);
    return cTab5;
}

MainWindow::MainWindow(user * _onUser, QWidget *parent) : QMainWindow(parent) {
    loadFiles();
    onUser = _onUser;
    QVBoxLayout * mainLayout = new QVBoxLayout();
    setWindowTitle("Main Window");
    mainLayout->addWidget(new QLabel("Manager: " + QString::fromStdString(onUser->getName())));
    mainLayout->addWidget(new QLabel("Credit: " + QString::number(onUser->getCredit())));
    mainLayout->addWidget(new QLabel("Last LogIn: " + QString::number(onUser->getLastLogin().getYear()) + "/" + QString::number(onUser->getLastLogin().getMonth())+ "/" + QString::number(onUser->getLastLogin().getDay())));
    QMenuBar * myMenuBar = new QMenuBar();
    QMenu * fileMenu = myMenuBar->addMenu(tr("Menu"));
    mainLayout->setMenuBar(myMenuBar);
    if (_onUser->isManager()){
        access = 1;
        QAction * newSellDoss = fileMenu->addAction("New Sell Dossier");
        QAction * newRentDoss = fileMenu->addAction("New Rent Dossier");
        QAction * requests = fileMenu->addAction("Requests");
        connect(newSellDoss, SIGNAL(triggered(bool)), this, SLOT(new_sell_Dossier()));
        connect(newRentDoss, SIGNAL(triggered(bool)), this, SLOT(new_Rent_Dossier()));
        connect(requests, SIGNAL(triggered(bool)), this, SLOT(reqsShow()));
    }
    else access = 0;

    QAction * exitAction = fileMenu->addAction("Exit");
    connect(exitAction, SIGNAL(triggered(bool)), this, SLOT(close()));
    this->setMinimumWidth(500);

    QTabWidget * myTabBar = new QTabWidget;
    myTabBar->addTab(makeTab1(), "All Houses");
    myTabBar->addTab(makeTab2(), "All Houses Seprate");
    myTabBar->addTab(makeTab3(), "All Dossiers");
    myTabBar->addTab(makeTab4(), "Search in Dossiers");
    myTabBar->addTab(makeTab5(), "Search in Apartments");

    mainLayout->addWidget(myTabBar);
    QWidget * central = new QWidget;
    central->setLayout(mainLayout);
    this->setCentralWidget(central);
}

MainWindow::~MainWindow() {
    qDebug() << "MainWindow Destructor";
    time_t now = time(0);
    tm *ltm = localtime(&now);
    onUser->setLastLogin(*(new date(ltm->tm_year + 1900, ltm->tm_mon + 1, ltm->tm_mday)));
    saveFiles();
}

//Menu
void MainWindow::new_sell_Dossier(){
    sellDossier * sd = new sellDossier(QString::number(allSellDossiers.count() + 1).toStdString());
    SellDossPanel * sdp = new SellDossPanel(sd, 2, onUser);
    sdp->exec();
    allSellDossiers.insert(sd->fPrice(), sd);
}

void MainWindow::new_Rent_Dossier(){
    rentDossier * rd = new rentDossier(QString::number(allRentDossiers.count() + 1).toStdString());
    RentDossPanel * rdp = new RentDossPanel(rd, 2, onUser);
    rdp->exec();
    allRentDossiers.insert(rd->fPrice(), rd);
}

void MainWindow::reqsShow(){
    requestPanel * rp = new requestPanel;
    rp->show();
}

//tab1
void MainWindow::pShowHouse_clicked(){
    if (allHousesList->currentItem()){
        string m = allHousesList->currentItem()->text().toStdString();
        QMultiMap <double, house*> allHouses;
        for (auto i : allNVillas) allHouses.insert(i->calPrice(), i);
        for (auto i : allSVillas) allHouses.insert(i->calPrice(), i);
        for (auto i : allApartments) allHouses.insert(i->calPrice(), i);
        for (auto i : allHouses) if (m == i->getAddress()) {
            if (i->wHouse() == 0 || i->wHouse() == 1) {
                villa * v = dynamic_cast<villa *>(i);
                villaPanel * vp = new villaPanel(v, access);
                vp->show();
            }
            else if (i->wHouse() == 2){
                apartment * a = dynamic_cast<apartment *>(i);
                apartmentPanel * ap = new apartmentPanel(a, access);
                ap->show();
            }
            break;
        }
    }
    else QMessageBox::information(this, "Error", "Select an Item Please!", QMessageBox::Ok);
}

//tab2
void MainWindow::pShowNVilla_clicked(){
    if (nVillasList->currentItem()){
//        for (auto i : allNVillas) if (i.second->getAddress() == nVillasList->currentItem()->text().toStdString()){
//            villa * v = dynamic_cast<villa *>(i.second);
        for (auto i : allNVillas) if (i->getAddress() == nVillasList->currentItem()->text().toStdString()){
            villa * v = dynamic_cast<villa *>(i);
            villaPanel * vp = new villaPanel(v, access);
            vp->show();
            break;
        }
    }
    else QMessageBox::information(this, "Error", "Select an Item Please!", QMessageBox::Ok);
}

void MainWindow::pShowSVilla_clicked(){
    if (sVillasList->currentItem()){
//        for (auto i : allSVillas) if (i.second->getAddress() == sVillasList->currentItem()->text().toStdString()){
//            villa * v = dynamic_cast<villa *>(i.second);
        for (auto i : allSVillas) if (i->getAddress() == sVillasList->currentItem()->text().toStdString()){
            villa * v = dynamic_cast<villa *>(i);
            villaPanel * vp = new villaPanel(v, access);
            vp->show();
            break;
        }
    }
    else QMessageBox::information(this, "Error", "Select an Item Please!", QMessageBox::Ok);
}

void MainWindow::pShowApartment_clicked(){
    if (apartmentsList->currentItem()){
//        for (auto i : allApartments) if (i.second->getAddress() == apartmentsList->currentItem()->text().toStdString()){
//            apartment * a = dynamic_cast<apartment *>(i.second);
        for (auto i : allApartments) if (i->getAddress() == apartmentsList->currentItem()->text().toStdString()){
            apartment * a = dynamic_cast<apartment *>(i);
            apartmentPanel * vp = new apartmentPanel(a, access);
            vp->show();
            break;
        }
    }
    else QMessageBox::information(this, "Error", "Select an Item Please!", QMessageBox::Ok);
}

//tab3
void MainWindow::pShowSellDossier_clicked(){
    if (sellDossierList->currentItem()){
        for (auto i : allSellDossiers) if (i->getDossID() == sellDossierList->currentItem()->text().toStdString()){
            sellDossier * v = dynamic_cast<sellDossier *>(i);
            SellDossPanel * vp = new SellDossPanel(v, access, onUser);
            vp->show();
            break;
        }
    }
    else QMessageBox::information(this, "Error", "Select an Item Please!", QMessageBox::Ok);
}

void MainWindow::pShowRentDossier_clicked(){
    if (rentDossierList->currentItem()){
        for (auto i : allRentDossiers) if (i->getDossID() == rentDossierList->currentItem()->text().toStdString()){
            rentDossier * v = dynamic_cast<rentDossier *>(i);
            RentDossPanel * vp = new RentDossPanel(v, access, onUser);
            vp->show();
            break;
        }
    }
    else QMessageBox::information(this, "Error", "Select an Item Please!", QMessageBox::Ok);
}

//tab4
void MainWindow::pSearchXY_clicked(){
    if (lBasePriceX->text() != "" && lCAreaY->text() != ""){
        QMultiMap <double, dossier*> allDossiers;
        for (auto i : allSellDossiers) allDossiers.insert(i->fPrice(), i);
        for (auto i : allRentDossiers) allDossiers.insert(i->fPrice(), i);
//        map <double, dossier*> allDossiers;
//        for (auto i : allSellDossiers) allDossiers.insert(i);
//        for (auto i : allRentDossiers) allDossiers.insert(i);
        vector <dossier *> vech;
        for (auto i : allDossiers) if (!(i->getHouse()->isSold())) {
            if (i->getType() == 0 || i->getType() == 1) {
                villa * v = dynamic_cast<villa *>(i->getHouse());
                if (v->getCArea() > lCAreaY->text().toInt() && v->getBasePrice() < lBasePriceX->text().toInt()) vech.push_back(i);
            }
            else {
                apartment * a = dynamic_cast<apartment *>(i->getHouse());
                if (a->getUnit(i->getId())->getCArea() > lCAreaY->text().toInt() && a->getBasePrice() < lBasePriceX->text().toInt()) vech.push_back(i);
            }
        }
        listXY->clear();
        for (auto i : vech) listXY->addItem(QString::fromStdString(i->getDossID()));
    }
    else QMessageBox::information(this, "Error", "Fill the Lines Please!", QMessageBox::Ok);
}

void MainWindow::pShowSearchXY_clicked(){
    if (listXY->currentItem()){
        bool f = 1;
        for (auto i : allSellDossiers) if (i->getDossID() == listXY->currentItem()->text().toStdString()){
            sellDossier * v = dynamic_cast<sellDossier *>(i);
            SellDossPanel * vp = new SellDossPanel(v, access, onUser);
            vp->show();
            f = 0;
            break;
        }
        if (f) for (auto i : allRentDossiers) if (i->getDossID() == listXY->currentItem()->text().toStdString()){
            rentDossier * v = dynamic_cast<rentDossier *>(i);
            RentDossPanel * vp = new RentDossPanel(v, access, onUser);
            vp->show();
            break;
        }
    }
    else QMessageBox::information(this, "Error", "Select an Item Please!", QMessageBox::Ok);
}

void MainWindow::pSearchZ_clicked(){
    if (lAddressZ->text() != ""){
        QMultiMap <double, dossier*> allDossiers;
        for (auto i : allSellDossiers) allDossiers.insert(i->fPrice(), i);
        for (auto i : allRentDossiers) allDossiers.insert(i->fPrice(), i);
        vector <dossier *> vech;
        for (auto i : allDossiers) if (!(i->getHouse()->isSold()) && i->getHouse()->getAddress().find(lAddressZ->text().toStdString()) != string::npos) vech.push_back(i);
        listZ->clear();
        for (auto i : vech) listZ->addItem(QString::fromStdString(i->getDossID()));
    }
    else QMessageBox::information(this, "Error", "Fill the Line Please!", QMessageBox::Ok);
}

void MainWindow::pShowSearchZ_clicked(){
    if (listZ->currentItem()){
        bool f = 1;
        for (auto i : allSellDossiers) if (i->getDossID() == listZ->currentItem()->text().toStdString()){
            sellDossier * v = dynamic_cast<sellDossier *>(i);
            SellDossPanel * vp = new SellDossPanel(v, access, onUser);
            vp->show();
            f = 0;
            break;
        }
        if (f) for (auto i : allRentDossiers) if (i->getDossID() == listZ->currentItem()->text().toStdString()){
            rentDossier * v = dynamic_cast<rentDossier *>(i);
            RentDossPanel * vp = new RentDossPanel(v, access, onUser);
            vp->show();
            break;
        }
    }
    else QMessageBox::information(this, "Error", "Select an Item Please!", QMessageBox::Ok);
}

//tab5
void MainWindow::pSearchN_clicked(){
    if (lUnitsN->text() != ""){
        QMultiMap <double, dossier*> allDossiers;
        for (auto i : allSellDossiers) allDossiers.insert(i->fPrice(), i);
        for (auto i : allRentDossiers) allDossiers.insert(i->fPrice(), i);
        vector <dossier *> vech;
        for (auto i : allDossiers) {
            if (i->getType() == 2 && !(i->getHouse()->isSold())) {
                apartment * a = dynamic_cast<apartment *>(i->getHouse());
                if (a->getNUnits() > lUnitsN->text().toInt()) vech.push_back(i);
            }
        }
        listN->clear();
        for (auto i : vech) listN->addItem(QString::fromStdString(i->getDossID()));
    }
    else QMessageBox::information(this, "Error", "Fill the Line Please!", QMessageBox::Ok);
}

void MainWindow::pShowSearchN_clicked(){
    if (listN->currentItem()){
        bool f = 1;
        for (auto i : allSellDossiers) if (i->getDossID() == listN->currentItem()->text().toStdString()){
            sellDossier * v = dynamic_cast<sellDossier *>(i);
            SellDossPanel * vp = new SellDossPanel(v, access, onUser);
            vp->show();
            f = 0;
            break;
        }
        if (f) for (auto i : allRentDossiers) if (i->getDossID() == listN->currentItem()->text().toStdString()){
            rentDossier * v = dynamic_cast<rentDossier *>(i);
            RentDossPanel * vp = new RentDossPanel(v, access, onUser);
            vp->show();
            break;
        }
    }
    else QMessageBox::information(this, "Error", "Select an Item Please!", QMessageBox::Ok);
}

void MainWindow::pSearchMA_clicked(){
    if (lUnitsMA->text() != ""){
        QMultiMap <double, dossier*> allDossiers;
        for (auto i : allSellDossiers) allDossiers.insert(i->fPrice(), i);
        for (auto i : allRentDossiers) allDossiers.insert(i->fPrice(), i);
        vector <dossier *> vech;
        for (auto i : allDossiers) {
            if (i->getType() == 2 && !(i->getHouse()->isSold())) {
                apartment * a = dynamic_cast<apartment *>(i->getHouse());
                if (a->getUnit(i->getId())->getCArea() > lUnitsMA->text().toInt()) vech.push_back(i);
            }
        }
        listMA->clear();
        for (auto i : vech) listMA->addItem(QString::fromStdString(i->getDossID()));
    }
    else QMessageBox::information(this, "Error", "Fill the Line Please!", QMessageBox::Ok);
}

void MainWindow::pShowSearchMA_clicked(){
    if (listMA->currentItem()){
        bool f = 1;
        for (auto i : allSellDossiers) if (i->getDossID() == listMA->currentItem()->text().toStdString()){
            sellDossier * v = dynamic_cast<sellDossier *>(i);
            SellDossPanel * vp = new SellDossPanel(v, access, onUser);
            vp->show();
            f = 0;
            break;
        }
        if (f) for (auto i : allRentDossiers) if (i->getDossID() == listMA->currentItem()->text().toStdString()){
            rentDossier * v = dynamic_cast<rentDossier *>(i);
            RentDossPanel * vp = new RentDossPanel(v, access, onUser);
            vp->show();
            break;
        }
    }
    else QMessageBox::information(this, "Error", "Select an Item Please!", QMessageBox::Ok);
}

void MainWindow::pSearchMR_clicked(){
    if (lUnitsMR->text() != ""){
        QMultiMap <double, dossier*> allDossiers;
        for (auto i : allSellDossiers) allDossiers.insert(i->fPrice(), i);
        for (auto i : allRentDossiers) allDossiers.insert(i->fPrice(), i);
        vector <dossier *> vech;
        for (auto i : allDossiers) {
            if (i->getType() == 2 && !(i->getHouse()->isSold())) {
                apartment * a = dynamic_cast<apartment *>(i->getHouse());
                if (a->getUnit(i->getId())->getRooms() > lUnitsMR->text().toInt()) vech.push_back(i);
            }
        }
        listMR->clear();
        for (auto i : vech) listMR->addItem(QString::fromStdString(i->getDossID()));
    }
    else QMessageBox::information(this, "Error", "Fill the Line Please!", QMessageBox::Ok);
}

void MainWindow::pShowSearchMR_clicked(){
    if (listMR->currentItem()){
        bool f = 1;
        for (auto i : allSellDossiers) if (i->getDossID() == listMR->currentItem()->text().toStdString()){
            sellDossier * v = dynamic_cast<sellDossier *>(i);
            SellDossPanel * vp = new SellDossPanel(v, access, onUser);
            vp->show();
            f = 0;
            break;
        }
        if (f) for (auto i : allRentDossiers) if (i->getDossID() == listMR->currentItem()->text().toStdString()){
            rentDossier * v = dynamic_cast<rentDossier *>(i);
            RentDossPanel * vp = new RentDossPanel(v, access, onUser);
            vp->show();
            break;
        }
    }
    else QMessageBox::information(this, "Error", "Select an Item Please!", QMessageBox::Ok);
}

