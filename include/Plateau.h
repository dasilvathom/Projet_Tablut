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
        bool deplacementPossible(int const i1, int const j1, int const i2, int const j2);
        void roiVoieLibre(size_t iRoi, size_t jRoi);
        bool estCapture() const;
        void finPartie(size_t iRoi, size_t jRoi);
    protected:
    private:
        std::vector<Pion> plateau;
        bool fin = false;
};

#endif // PLATEAU_H
