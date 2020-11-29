#include "nuser.h"

nUser::nUser(string _name, date _birth, string _username, string _password, date _lastlogin, bool _status, int _credit) : user(_name, _birth, _username, _password, _lastlogin, _status, _credit) {}
set <dossier*>* nUser::getMyDoss() {
    return &myDossiers;
}
bool nUser::isManager() const{
    return 0;
}
void nUser::addMyDoss(dossier* _dossier) {
    myDossiers.insert(_dossier);
}
