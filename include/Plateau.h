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
        Pion & operator() (size_t const i, size_t const j) { return plateau[i * TAILLE + j]; }; // obtenir un pion par surchage d'operateur
        Pion getPion(size_t i, size_t j)const;
        void afficher() const;
    protected:
    private:
        std::vector<Pion> plateau;
        //std::vector<bool> etatCase; // une autre version pour ne pas avoir de pion vide
};

#endif // PLATEAU_H
