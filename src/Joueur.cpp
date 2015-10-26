#include "Joueur.h"

#include <iostream>

using namespace std;

Joueur::Joueur()
{
    //ctor
}

Joueur::~Joueur()
{
    //dtor
}

void Joueur::jouer(int & i1, int & j1, int & i2, int & j2) const
{
    cout << "Joueur " << this->getNom() << " a vous de jouer!" << endl;

    cout << "Entrez les coordonnees du pion a deplacer : \ni1 = ";
    cin >> i1;
    cout << "j1 = ";
    cin >> j1;
    cout << "Entrez les coordonnees ou deplacer le pion :\ni2 = ";
    cin >> i2;
    cout << "j2 = ";
    cin >> j2;

    cout << "(" << i1 << ", " << j1 << ") => (" << i2 << ", " << j2 << ")" << endl;

}
