#include "apartment.h"

apartment::apartment(int _tArea, int _nFloors, int _nUnits, bool _elevator, double _basePrice, string _address, string _picAdd) : house(_tArea, _basePrice, _address, _picAdd) {
    setElevator(_elevator);
    setNFloors(_nFloors);
    setNUnits(_nUnits);
    //allHouses.push_back(this);
}


int apartment::wHouse() {
    return 2;
}
double apartment::calPrice() {
    return basePrice * tArea* 0.8;
}
unit* apartment::getUnit(int _id) {
    return units[_id];
}
vector <unit *> apartment::getUnitsVec(){
    return units;
}
bool apartment::getElevator() {
    return elevator;
}
int apartment::getNFloors() {
    return nFloors;
}
int apartment::getNUnits() {
    return nUnits;
}
void apartment::addUnit(unit* _unit) {
    units.push_back(_unit);
}
void apartment::setElevator(bool _elevator) {
    elevator = _elevator;
}
void apartment::setNFloors(int _nFloors) {
    nFloors = _nFloors;
}
void apartment::setNUnits(int _nUnits) {
    nUnits = _nUnits;
}
void apartment::setUnitsID(){
    int n = 1;
    for (auto i : units) {
        i->setID(n);
        n++;
    }
}
