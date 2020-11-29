#include "house.h"

house::house(int _tArea, int _basePrice, string _add, string _picAdd) : base(_picAdd) {
    setArea(_tArea);
    setBasePrice(_basePrice);
    setAddress(_add);
}
void house::setArea(int _tArea) {
    tArea = _tArea;
}
void house::setBasePrice(int _basePrice) {
    basePrice = _basePrice;
}
void house::setAddress(string _add) {
    address = _add;
}
string house::getAddress() {
    return address;
}
int house::getBasePrice() {
    return basePrice;
}
int house::getArea() {
    return tArea;
}

bool house::operator<(house a){
    if (this->calPrice() < a.calPrice()) return 1;
    return 0;
}
