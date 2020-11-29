#ifndef SVILLA_H
#define SVILLA_H

#include "villa.h"

class sVilla : public villa {
    int parkingArea;
public:
    sVilla(int = 0, int = 0, int = 0, int = 0, double = 0, int = 0, string = "", string = "");
    int wHouse();
    double calPrice();
    void setParking(int _parking);
    int getParking();
};

#endif // SVILLA_H
