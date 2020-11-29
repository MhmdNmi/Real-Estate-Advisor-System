#include "unit.h"

unit::unit(int _floorN, int _rooms, int _cArea, apartment* _flat, int _use, string _picAdd) : base(_picAdd) {
    setFloorN(_floorN);
    setRooms(_rooms);
    setCArea(_cArea);
    setFlat(_flat);
    setUse(_use);
}
double unit::calPrice() {
    double p = flat->basePrice * cArea;
    p *= (1 + floorN * 0.05);
    p *= (1 + rooms * 0.05);
    p *= (1 + floorN * 0.05);
    if (use == 1) p *= 1.3;
    else if (use == 2) p *= 1.5;
    if (flat->elevator) p *= 1.02;
    return p;
}
int unit::getFloorN() {
    return floorN;
}
int unit::getRooms() {
    return rooms;
}
int unit::getCArea() {
    return cArea;
}
apartment* unit::getFlat() {
    return flat;
}
int unit::getUse() {
    return use;
}
void unit::setFloorN(int _floorN) {
    floorN = _floorN;
}
void unit::setRooms(int _rooms) {
    rooms = _rooms;
}
void unit::setCArea(int _cArea) {
    cArea = _cArea;
}
void unit::setFlat(apartment * _flat) {
    flat = _flat;
}
void unit::setUse(int _use) {
    use = _use;
}
void unit::setID(int _id){
    id = _id;
}
int unit::getID(){
    return id;
}
