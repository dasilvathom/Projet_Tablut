#ifndef PLATEAU_H
#define PLATEAU_H

#include <stdio.h>
#include <vector>
#include "Pion.h"

#define TAILLE 9

#define CASECENTRE ((TAILLE-1)/2)

class Plateau
{
    public:
        Plateau();
        virtual ~Plateau();
        Pion& operator() (size_t const i, size_t const j) { return plateau[i * TAILLE + j]; }; // obtenir un pion par surchage d'operateur
        Pion& getPion(size_t i, size_t j);
        bool movePion(int const i1, int const j1, int const i2, int const j2, int couleur);
        void afficher() const;
    protected:
    private:
        std::vector<Pion> plateau;
};

#endif // PLATEAU_H
