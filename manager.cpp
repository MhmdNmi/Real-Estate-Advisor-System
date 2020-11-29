#include "manager.h"

manager::manager(string _name, date _birth, string _username, string _password, date _lastlogin, bool _status, int _credit) : user(_name, _birth, _username, _password, _lastlogin, _status, _credit) {}
set <house>* manager::getEstates() {
    return estates;
}
set <dossier>* manager::getAllDoss() {
    return allDossiers;
}
bool manager::isManager() const {
    return 1;
}
void manager::setEstates(set <house>* _estates) {
    estates = _estates;
}
void manager::setAllDoss(set <dossier>* _allDossiers) {
    allDossiers = _allDossiers;
}
