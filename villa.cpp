#include "villa.h"


villa::villa(int _tArea, int _cArea, int _bYardArea, double _basePrice, int _rooms, string _address, string _picAdd) : house(_tArea, _basePrice, _address, _picAdd) {
    setCArea(_cArea);
    setBYardArea(_bYardArea);
    setRooms(_rooms);
}
void villa::setCArea(int _cArea) {
    cArea = _cArea;
}
void villa::setBYardArea(int _bYardArea) {
    bYardArea = _bYardArea;
}
void villa::setRooms(int _rooms) {
    rooms = _rooms;
}
int villa::getCArea() {
    return cArea;
}
int villa::getBYardArea() {
    return bYardArea;
}
int villa::getRooms() {
    return rooms;
}
