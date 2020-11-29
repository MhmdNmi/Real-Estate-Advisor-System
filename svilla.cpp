#include "svilla.h"

sVilla::sVilla(int _tArea, int _cArea, int _bYardArea, int _parking, double _basePrice, int _rooms, string _address, string _picAdd) : villa(_tArea, _cArea, _bYardArea, _basePrice, _rooms, _address, _picAdd) {
    setParking(_parking);
    //allHouses.push_back(this);
}

int sVilla::wHouse() {
    return 1;
}
double sVilla::calPrice() {
    return basePrice * (cArea + bYardArea * 0.3 + parkingArea * 0.15);
}
void sVilla::setParking(int _parking) {
    parkingArea = _parking;
}
int sVilla::getParking() {
    return parkingArea;
}
