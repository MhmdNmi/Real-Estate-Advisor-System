#include "nvilla.h"

nVilla::nVilla(int _tArea, int _cArea, int _bYardArea, int _fYardArea, double _basePrice, int _rooms, string _address, string _picAdd) : villa(_tArea, _cArea, _bYardArea, _basePrice, _rooms, _address, _picAdd) {
    setFYardArea(_fYardArea);
    //allHouses.push_back(this);
}
int nVilla::wHouse() {
    return 0;
}
double nVilla::calPrice() {
    return basePrice * (cArea + fYardArea * 0.3 + bYardArea * 0.15);
}
void nVilla::setFYardArea(int _fYardArea) {
    fYardArea = _fYardArea;
}
int nVilla::getFYardArea() {
    return fYardArea;
}

bool nVilla::operator<(nVilla a){
    if (this->calPrice() < a.calPrice()) return 1;
    return 0;
}
