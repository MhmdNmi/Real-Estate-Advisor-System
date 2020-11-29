#include "date.h"

date::date(int _year, int _month, int _day) {
    this->setDay(_day);
    this->setMonth(_month);
    this->setYear(_year);
}
void date::setDay(int _day) {
    if (_day > 0 && _day <= 31) day = _day;
    else throw "Day out of range!";
}
void date::setMonth(int _month) {
    if (_month > 0 && _month <= 12) month = _month;
    else throw "Month out of range!";
}
void date::setYear(int _year) {
    year = _year;
}
int date::getDay() {
    return day;
}
int date::getMonth() {
    return month;
}
int date::getYear() {
    return year;
}
