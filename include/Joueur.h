#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED

#include <string>

#define VERT 3
#define JAUNE 4

using namespace std;

class Joueur
{
    public:
        Joueur();
        Joueur(string unNom, int uneCouleur):nom(unNom), couleur(uneCouleur) {};
        void jouer(int & i1, int & j1, int & i2, int & j2) const;
        string const getNom() const { return nom; };
        int const getCouleur() const { return couleur; };
        virtual ~Joueur();
    protected:
    private:
        string nom;
        int couleur;
};

#endif // JOUEUR_H_INCLUDED
