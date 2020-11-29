#include "dossier.h"

dossier::dossier(string _dossID, house* _h, double _commission, int _type, int _id) {
    setHouse(_h);
    setType(_type);
    setId(_id);
    setCommission(_commission);
    setDossID(_dossID);
}
house* dossier::getHouse() {
    return h;
}
int dossier::getType() {
    return type;
}
int dossier::getId() {
    return id;
}
double dossier::getCommission() {
    return commission;
}
void dossier::setHouse(house* _h) {
    h = _h;
}
void dossier::setType(int _type) {
    type = _type;
}
void dossier::setId(int _id) {
    id = _id;
}
void dossier::setCommission(double _commission) {
    commission = _commission;
}
string dossier::getDossID(){
    return dossierID;
}
void dossier::setDossID(string _dossID){
    dossierID = _dossID;
}
