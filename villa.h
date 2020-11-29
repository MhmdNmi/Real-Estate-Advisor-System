#ifndef VILLA_H
#define VILLA_H

#include "house.h"

class villa : public house {
protected:
    int cArea;
    int bYardArea;
    int rooms;
public:
    villa(int = 0, int = 0, int = 0, double = 0, int = 0, string = "", string = "");
    virtual double calPrice() { return 0; }
    virtual int wHouse() { return 0; }
    void setCArea(int _cArea);
    void setBYardArea(int _bYardArea);
    void setRooms(int _rooms);
    int getCArea();
    int getBYardArea();
    int getRooms();
};

#endif // VILLA_H
