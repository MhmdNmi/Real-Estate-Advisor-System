#ifndef SELLDOSSIER_H
#define SELLDOSSIER_H

#include "dossier.h"

class sellDossier : public dossier {
    bool sellCond; // 0. cash, 1. check
public:
    sellDossier(string, house* = NULL, double = COM, bool = 0, int = 0, int = 0);
    double fPrice();
    bool getCond();
    void setCond(bool _sellcond);
};


#endif // SELLDOSSIER_H
