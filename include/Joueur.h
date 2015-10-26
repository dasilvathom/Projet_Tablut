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
        Joueur(string unNom):nom(unNom){};
        virtual ~Joueur();
    protected:
    private:
        string nom;
        int couleur;
};

#endif // JOUEUR_H_INCLUDED
