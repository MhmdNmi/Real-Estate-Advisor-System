#include "request.h"

request::request(user * _onUser, dossier * _onDossier, bool _type) {
    onUser = _onUser;
    onDossier = _onDossier;
    type = _type;
}
void request::setUser(user * _onUser){
    onUser = _onUser;
}
user * request::getUser(){
    return onUser;
}
void request::setDossier(dossier * _onDossier){
    onDossier = _onDossier;
}
dossier * request::getDossier(){
    return onDossier;
}
void request::setType(bool _type){
    type = _type;
}
bool request::getType(){
    return type;
}
