#include "user.h"

user::user(string _name, date _birth, string _username, string _password, date _lastlogin, bool _status, int _credit) {
    setName(_name);
    setBirth(_birth);
    setUsername(_username);
    setPassword(_password);
    setStatus(_status);
    setCredit(_credit);
    setLastLogin(_lastlogin);
}
void user::setName(string _name) {
    name = _name;
}
void user::setBirth(date _birth) {
    birth = _birth;
}
void user::setUsername(string _username) {
    username = _username;
}
void user::setPassword(string _password) {
    password = _password;
}
void user::setStatus(bool _status) {
    status = _status;
}
void user::setCredit(int _credit) {
    credit = _credit;
}
void user::riseCredit(int _credit) {
    credit += _credit;
}
void user::decCredit(int _credit) {
    credit -= _credit;
}
string user::getName() {
    return name;
}
date user::getBirth() {
    return birth;
}
bool user::getStatus() const {
    return status;
}
string user::getUername() {
    return username;
}
string user::getPassword() {
    return password;
}
bool user::isPass(string _pass) {
    if (password == _pass) return 1;
    return 0;
}
int user::getCredit() {
    return credit;
}
date user::getLastLogin() {
    return lastLogin;
}
void user::setLastLogin(date _lastLogin) {
    lastLogin = _lastLogin;
}

bool user::operator<(const user &a) const{
    if (!this->isManager() && a.isManager()) return 1;
    else if (this->isManager() && !a.isManager()) return 0;
    else if (!this->getStatus() && a.getStatus()) return 1;
    return 0;
}
