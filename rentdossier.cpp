#include "rentdossier.h"


rentDossier::rentDossier(string _dossID, house* _h, double _commission, int _rentTime, int _type, int _id) : dossier(_dossID, _h, _commission, _type, _id) {
    mortcal();
    rentcal();
    rentTime = _rentTime;
}

void rentDossier::mortcal() {
    if (type == 0 || type == 1) mortgage = h->calPrice() * 0.05;
    else {
        apartment* a = dynamic_cast<apartment*> (h);
        mortgage = a->getUnit(id)->calPrice() * 0.05;
    }
}
void rentDossier::rentcal() {
    if (type == 0 || type == 1) rent = h->calPrice() * 0.01;
    else {
        apartment* a = dynamic_cast<apartment*> (h);
        rent = a->getUnit(id)->calPrice() * 0.01;
    }
}
double rentDossier::fPrice() {
    return mortgage * (1 + commission) + rent * rentTime;
}
double rentDossier::getMort() {
    return mortgage;
}
double rentDossier::getRent() {
    return rent;
}
double rentDossier::getRentTime() {
    return rentTime;
}
void rentDossier::setRentTime(double _rentTime) {
    rentTime = _rentTime;
}

