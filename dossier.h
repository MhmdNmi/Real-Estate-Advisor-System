#ifndef DOSSIER_H
#define DOSSIER_H

#define COM 0.05

#include "apartment.h"
#include "unit.h"
#include "nvilla.h"
#include "svilla.h"

class dossier {
protected:
    string dossierID;
    house* h;
    int type; //0.nvilla, 1.svilla 2.apartment
    int id;
    double commission;
public:
    dossier(string, house* = NULL, double = COM, int = 0, int = 0);
    virtual double fPrice() = 0;
    house* getHouse();
    int getType();
    int getId();
    double getCommission();
    void setHouse(house* _h);
    void setType(int _type);
    void setId(int _id);
    void setCommission(double _commission);
    string getDossID();
    void setDossID(string);
};

#endif // DOSSIER_H
