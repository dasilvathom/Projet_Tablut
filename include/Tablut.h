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
        Joueur const & getJoueur1() const { return j1; };
        Joueur const & getJoueur2() const { return j2; };
        Plateau const & getPlateau() const { return plateau; };
        void jouer();
    protected:
    private:
        Plateau plateau;
        Joueur j1;
        Joueur j2;
};

#endif // TABLUT_H
