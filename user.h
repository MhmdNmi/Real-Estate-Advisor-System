#ifndef USER_H
#define USER_H

#include "date.h"
#include <string>
using namespace std;

class user {
protected:
    string name;
    date birth;
    bool status; //0.fired, 1.employed
    string username;
    string password;
    int credit;
    date lastLogin;
public:
    user(string, date, string, string, date, bool = 1, int = 0);
    void setName(string _name);
    void setBirth(date _birth);
    void setUsername(string _username);
    void setPassword(string _password);
    void setStatus(bool _status);
    void setCredit(int _credit);
    void riseCredit(int _credit);
    void decCredit(int _credit);
    string getName();
    date getBirth();
    bool getStatus() const;
    string getUername();
    string getPassword();
    bool isPass(string _pass);
    int getCredit();
    date getLastLogin();
    void setLastLogin(date);
    virtual bool isManager() const = 0;
    bool operator<(const user &a) const;
};

#endif // USER_H
