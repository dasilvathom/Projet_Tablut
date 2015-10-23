#include "Tablut.h"

Tablut::Tablut()
{
    plateau = Plateau();
}

Tablut::~Tablut()
{
    //dtor
}

Plateau Tablut::getPlateau(){
    return this->plateau;
}
