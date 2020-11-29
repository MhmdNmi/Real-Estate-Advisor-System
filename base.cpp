#include "base.h"

base::base(string _picAdd) {
    sell = 0;
    setPic(_picAdd);
}
base::~base(){}
string base::getPic() {
    return picAdd;
}
bool base::isSold(){
    return sell;
}
void base::setSold(){
    sell = 1;
}
void base::setPic (string _picAdd){
    picAdd = _picAdd;
}
