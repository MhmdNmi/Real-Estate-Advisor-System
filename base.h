#ifndef BASE_H
#define BASE_H

#include <string>
using namespace std;

class base {
protected:
    string picAdd;
    bool sell;
    //picture!!!
public:
    base(string);
    ~base();
    bool isSold();
    void setSold();
    string getPic();
    void setPic(string);
    virtual double calPrice() = 0;
};

#endif // BASE_H
