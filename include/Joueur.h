#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED

#include <string>
#include <ctime>
#include <cstdlib>

#define VERT 3
#define JAUNE 4
#define TAILLE 9

using namespace std;

class Joueur
{
    public:
        Joueur();
        Joueur(string unNom, int uneCouleur, bool estIa):nom(unNom), couleur(uneCouleur), ia(estIa) {};
        void jouer(int & i1, int & j1, int & i2, int & j2) const;
        void jouerIA(int & i1, int & j1, int & i2, int & j2) const;
        string const getNom() const { return nom; };
        int const getCouleur() const { return couleur; };
        int const estIa() const { return ia; };
        virtual ~Joueur();
    protected:
    private:
        string nom;
        int couleur;
        bool ia;
};

#endif // JOUEUR_H_INCLUDED
