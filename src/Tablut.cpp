#include "Tablut.h"

Tablut::Tablut(string unNom1, string unNom2)
{
    plateau = Plateau();
    j1 = Joueur(unNom1);
    j2 = Joueur(unNom2);
}

Tablut::~Tablut()
{
    //dtor
}

Plateau& Tablut::getPlateau(){
    Plateau& retPlateau = plateau;
    return retPlateau;
}
