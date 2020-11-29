#ifndef APARTMENT_H
#define APARTMENT_H

#include "house.h"
#include "unit.h"
#include <vector>

class unit;

class apartmentPanel;

class apartment : public house {
    bool elevator;
    int nFloors;
    int nUnits;
    vector <unit*> units;
public:
    apartment(int = 0, int = 0, int = 0, bool = 0, double = 0, string = "", string = "");
    int wHouse();
    friend class unit;
    friend class apartmentPanel;
    double calPrice();
    vector <unit *> getUnitsVec();
    unit* getUnit(int _id);
    bool getElevator();
    int getNFloors();
    int getNUnits();
    void addUnit(unit* _unit);
    void setElevator(bool _elevator);
    void setNFloors(int _nFloors);
    void setNUnits(int _nUnits);
    void setUnitsID();
};

#endif // APARTMENT_H
