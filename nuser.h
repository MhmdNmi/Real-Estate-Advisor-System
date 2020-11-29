#ifndef NUSER_H
#define NUSER_H

#include "user.h"
#include "dossier.h"
#include <set>

class nUser : public user {
    set <dossier*> myDossiers;
public:
    nUser(string, date, string, string, date, bool = 1, int = 0);
    set <dossier*>* getMyDoss();
    bool isManager() const;
    void addMyDoss(dossier* _dossier);
};

#endif // NUSER_H
