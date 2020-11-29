#include "mainwindow.h"
#include "login.h"

#include <QApplication>
#include <QString>
#include <map>
#include <ctime>
#include <QMultiMap>

vector <nUser*> allNUsers;
vector <manager*> allManagers;
vector <request*> allRequests;
QMultiMap <double, sellDossier*> allSellDossiers;
QMultiMap <double, rentDossier*> allRentDossiers;
QMultiMap <double, apartment*> allApartments;
QMultiMap <double, nVilla*> allNVillas;
QMultiMap <double, sVilla*> allSVillas;

MainWindow * w;

void addnVilla(nVilla * ab){
//    allNVillas.insert(pair<double, nVilla*>(ab->calPrice(), ab));
    allNVillas.insert(ab->calPrice(), ab);
    qDebug() << QString::fromStdString(ab->getAddress());
}

void addsVilla(sVilla * ab){
//    allSVillas.insert(pair<double, sVilla*>(ab->calPrice(), ab));
    allSVillas.insert(ab->calPrice(), ab);
    qDebug() << QString::fromStdString(ab->getAddress());
}

void addapartment(apartment * ab){
//    allApartments.insert(pair<double, apartment*>(ab->calPrice(), ab));
    allApartments.insert(ab->calPrice(), ab);
    qDebug() << QString::fromStdString(ab->getAddress());
    ab->addUnit(new unit(1, 2, 50, ab, 0));
    ab->addUnit(new unit(1, 2, 50, ab, 0));
    ab->addUnit(new unit(2, 2, 50, ab, 0));
    ab->addUnit(new unit(2, 2, 50, ab, 0));
    ab->addUnit(new unit(3, 2, 50, ab, 0));
    ab->addUnit(new unit(3, 2, 50, ab, 0));
    ab->addUnit(new unit(4, 2, 50, ab, 0));
    ab->addUnit(new unit(4, 2, 50, ab, 0));
    ab->setUnitsID();
}

void addsellDossier(sellDossier * ab){
    allSellDossiers.insert(ab->fPrice(), ab);
}

void addrentDossier(rentDossier * ab){
    allRentDossiers.insert(ab->fPrice(), ab);
}



int main(int argc, char *argv[]) {
    addnVilla(new nVilla(85, 225, 45, 52, 0, 2, "1.goli"));
    addnVilla(new nVilla(250, 218, 558, 45, 58, 4, "2.Ziafat"));
    addnVilla(new nVilla(365, 218, 55, 45, 58, 4, "3.Mehregan"));
    addnVilla(new nVilla(787, 628, 58, 45, 58, 4, "4.Keshavarz"));
    addnVilla(new nVilla(154, 128, 58, 45, 58, 4, "5.EmamReza"));
    addnVilla(new nVilla(265, 268, 58, 45, 58, 4, "6.Shahed"));
    addnVilla(new nVilla(263, 258, 58, 45, 58, 4, "7.Shora"));
    addnVilla(new nVilla(278, 287, 58, 45, 58, 4, "8.Modarres"));
    addnVilla(new nVilla(320, 248, 58, 45, 58, 4, "9.Fin"));
    addnVilla(new nVilla(120, 258, 58, 45, 58, 4, "10.AmirKabir"));
    addnVilla(new nVilla(350, 128, 58, 45, 1000, 1, "11.Moallem"));

    addsVilla(new sVilla(85, 225, 45, 52, 0, 2, "1.Motahari"));
    addsVilla(new sVilla(250, 218, 558, 45, 58, 4, "2.Mofatteh"));
    addsVilla(new sVilla(365, 218, 55, 45, 58, 4, "3.Emam"));
    addsVilla(new sVilla(787, 628, 58, 45, 58, 4, "4.Kamalalmolk"));
    addsVilla(new sVilla(154, 128, 58, 45, 58, 4, "5.Darvazedolat"));
    addsVilla(new sVilla(265, 268, 58, 45, 58, 4, "6.DarbeAta"));
    addsVilla(new sVilla(263, 258, 58, 45, 58, 4, "7.kahsni"));
    addsVilla(new sVilla(278, 287, 58, 45, 58, 4, "8.ziarati"));
    addsVilla(new sVilla(320, 248, 58, 45, 58, 4, "9.beheshti"));
    addsVilla(new sVilla(120, 258, 58, 45, 58, 4, "10.Madkhal"));
    addsVilla(new sVilla(350, 128, 58, 45, 4000, 2, "11.khademi"));

    addapartment(new apartment(500, 5, 8, 1, 0, "1.Danesh"));
    addapartment(new apartment(500, 5, 8, 1, 2, "2.Abazar"));
    addapartment(new apartment(500, 5, 8, 1, 4, "3.Amirieh"));
    addapartment(new apartment(500, 5, 8, 1, 3, "4.Najib"));
    addapartment(new apartment(500, 5, 8, 1, 2000, "5.Tarbiatyrr"));

    addsellDossier(new sellDossier("111", (allNVillas.begin() + 2).value(), 0.05, 1, 0, 0));
    addsellDossier(new sellDossier("112", (allSVillas.begin() + 2).value(), 0.05, 1, 0, 0));
    addsellDossier(new sellDossier("113", (allApartments.begin() + 2).value(), 0.05, 1, 2, 3));
////    string _dossID, house* _h, double _commission, bool _sellcond, bool _type, int _id;
    addrentDossier(new rentDossier("211", (allNVillas.begin() + 1).value(), 0.07, 5, 0, 0));
    addrentDossier(new rentDossier("212", (allSVillas.begin() + 1).value(), 0.07, 5, 1, 0));
    addrentDossier(new rentDossier("213", (allApartments.begin() + 1).value(), 0.07, 5, 2, 4));
////    string _dossID, house* _h, double _commission, int _rentTime, bool _type, int _id

    time_t now = time(0);
    tm *ltm = localtime(&now);
    allManagers.push_back(new manager("Mohammad", *(new date(1999, 3, 26)), "Mohammad", "Mohammad", *(new date(ltm->tm_year + 1900, ltm->tm_mon + 1, ltm->tm_mday)), 1, 50000));
    allNUsers.push_back(new nUser("Ali", *(new date(1999, 3, 26)), "Ali", "Ali", *(new date(ltm->tm_year + 1900, ltm->tm_mon + 1, ltm->tm_mday)), 1, 50000));
    QApplication a(argc, argv);
    login l;
    l.show();
    return a.exec();
}
