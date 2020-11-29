#include "selldossier.h"

sellDossier::sellDossier(string _dossID, house* _h, double _commission, bool _sellcond, int _type, int _id) : dossier(_dossID, _h, _commission, _type, _id) {
    setCond(_sellcond);
    //allDossiers.push_back(this);
}
double sellDossier::fPrice() {
    if (type == 0 || type == 1) return h->calPrice()* (1 + commission);
    apartment * a = dynamic_cast<apartment*> (h);
    return a->getUnit(id)->calPrice() * (1 + commission);
}
bool sellDossier::getCond() {
    return sellCond;
}
void sellDossier::setCond(bool _sellcond) {
    sellCond = _sellcond;
}
