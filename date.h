#ifndef DATE_H
#define DATE_H


class date {
    int day;
    int month;
    int year;
public:
    date(int = 2000, int = 1, int= 1);
    void setDay(int _day);
    void setMonth(int _month);
    void setYear(int _year);
    int getDay();
    int getMonth();
    int getYear();
};

#endif // DATE_H
