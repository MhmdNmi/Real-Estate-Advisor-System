#ifndef REQUEST_H
#define REQUEST_H

#include "selldossier.h"
#include "rentdossier.h"
#include "nuser.h"

class request {
    user * onUser;
    dossier * onDossier;
    bool type; // 0.sell 1.rent
public:
    request(user *, dossier *, bool);
    void setUser(user *);
    user * getUser();
    void setDossier(dossier *);
    dossier * getDossier();
    void setType(bool);
    bool getType();
};

#endif // REQUEST_H
