#ifndef NVILLA_H
#define NVILLA_H

#include "villa.h"

class nVilla : public villa {
    int fYardArea;
public:
    nVilla(int = 0, int = 0, int = 0, int = 0, double = 0, int = 0, string = "", string = "");
    int wHouse();
    double calPrice();
    void setFYardArea(int _fYardArea);
    int getFYardArea();
    bool operator<(nVilla a);
};

#endif // NVILLA_H
