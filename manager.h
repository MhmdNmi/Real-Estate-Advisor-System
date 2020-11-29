#ifndef MANAGER_H
#define MANAGER_H

#include "user.h"
#include "house.h"
#include "dossier.h"
#include <set>

class manager : public user {
    set <house>* estates;
    set <dossier>* allDossiers;
public:
    manager(string, date, string, string, date, bool = 1, int = 0);
    set <house>* getEstates();
    set <dossier>* getAllDoss();
    bool isManager() const;
    void setEstates(set <house>* _estates);
    void setAllDoss(set <dossier>* _allDossiers);
};

#endif // MANAGER_H
