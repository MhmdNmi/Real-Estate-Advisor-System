#ifndef RENTDOSSIER_H
#define RENTDOSSIER_H

#include "dossier.h"

class rentDossier : public dossier {
    double mortgage;
    double rent;
    int rentTime;
public:
    rentDossier(string, house* = NULL, double = COM, int = 0, int = 0, int = 0);
    void mortcal();
    void rentcal();
    double fPrice();
    double getMort();
    double getRent();
    double getRentTime();
    void setRentTime(double);
};


#endif // RENTDOSSIER_H
