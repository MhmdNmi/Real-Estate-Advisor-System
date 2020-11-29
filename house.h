#ifndef HOUSE_H
#define HOUSE_H

#include "base.h"

class house : public base {
protected:
    int tArea; //total area
    int basePrice;
    string address;
    //picture???
public:
    house(int, int, string, string);
    virtual double calPrice() { return 0; }
    virtual int wHouse() {return 0;} // 0.nVilla, 1.sVilla, 2.apartment
    void setArea(int _tArea);
    void setBasePrice(int _basePrice);
    void setAddress(string _add);
    string getAddress();
    int getBasePrice();
    int getArea();
    bool operator<(house);
};
#endif // HOUSE_H


