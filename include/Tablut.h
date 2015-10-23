#ifndef TABLUT_H
#define TABLUT_H

#include "Plateau.h"
#include "Joueur.h"

class Tablut
{
    public:
        Tablut(string unNom1, string unNom2);
        virtual ~Tablut();
        Plateau& getPlateau();
    protected:
    private:
        Plateau plateau;
        Joueur j1;
        Joueur j2;
};

#endif // TABLUT_H
