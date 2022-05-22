#include "cadenaMio.h"
Cadena::~Cadena(){
    delete [] this->cad;
}
Cadena::Cadena(){
    this->cad = new char(1);
    this->cad[0] = '\0';
}
Cadena::Cadena(const char* cad){
    this->cad = new char(strlen(cad)+1);
    strcpy(this->cad, cad);
}
Cadena::Cadena(const Cadena& c){
    this->cad = new char(strlen(c.cad)+1);
    strcpy(this->cad, c.cad);
}
// constructor que simplifica los operator +
Cadena::Cadena(const char* c1, const char* c2)
{
    this->cad = new char(strlen(c1) + strlen(c2) + 1);
    strcpy(this->cad, c1);
    strcat(this->cad, c2);
}
Cadena Cadena::operator+(const Cadena& c) const{
    /*
    char* concat = new char(strlen(this->cad) + strlen(c.cad));
    strcpy(concat, this->cad);
    strcat(concat, c.cad);
    Cadena retConcat(concat);

    delete [] concat;
    return retConcat;
    */
    // se reduce a esto
    return Cadena(this->cad, c.cad);
}

Cadena Cadena::operator+(const char* cad) const{
    /*
    char* concat = new char(strlen(this->cad) + strlen(cad));
    strcpy(concat, this->cad);
    strcat(concat, cad);
    Cadena retConcat(concat);

    delete [] concat;
    return retConcat;
    */
    //se reduce a esto
    return Cadena(this->cad, cad);
}
ostream& operator <<(ostream& sal, const Cadena& c){
    return sal << c.cad;
}
istream& operator >>(istream& ent, Cadena& c){
    return ent >> c.cad;
}
unsigned Cadena::longitud() const{
    return strlen(cad);
}
Cadena operator+(const char* cad, const Cadena& c)
{
    return Cadena(cad, c.cad);
}
