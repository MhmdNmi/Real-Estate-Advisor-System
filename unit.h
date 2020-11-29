#ifndef UNIT_H
#define UNIT_H

#include "apartment.h"

class apartmentPanel;

class apartment;

class unit : public base {
    int id;
    int floorN;
    int rooms;
    int cArea;
    //picture???
    apartment* flat;
    int use; //0.none, 1.edari, 2.tejari
public:
    friend class apartmentPanel;
    friend class apartment;
    unit(int, int, int, apartment*, int = 0, string = "");
    double calPrice();
    int getFloorN();
    int getRooms();
    int getCArea();
    apartment* getFlat();
    int getUse();
    void setFloorN(int _floorN);
    void setRooms(int _rooms);
    void setCArea(int _cArea);
    void setFlat(apartment * _flat);
    void setUse(int _use);
    void setID(int);
    int getID();
};

#endif // UNIT_H
