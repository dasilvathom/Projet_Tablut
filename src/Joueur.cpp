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
    //cin >> i1;
    while( !(cin >> i1) ) {
        string tmp;
        cin.clear();
        cin >> tmp;
        cout << "La valeur est invalide !!!" << endl;
        cout << "i1 = ";
    }
    cout << "j1 = ";
    //cin >> j1;
    while( !(cin >> j1) ) {
        string tmp;
        cin.clear();
        cin >> tmp;
        cout << "La valeur est invalide !!!" << endl;
        cout << "j1 = ";
    }
    cout << "Entrez les coordonnees ou deplacer le pion :\ni2 = ";
    //cin >> i2;
    while( !(cin >> i2) ) {
        string tmp;
        cin.clear();
        cin >> tmp;
        cout << "La valeur est invalide !!!" << endl;
        cout << "i2 = ";
    }
    cout << "j2 = ";
    //cin >> j2;
    while( !(cin >> j2) ) {
        string tmp;
        cin.clear();
        cin >> tmp;
        cout << "La valeur est invalide !!!" << endl;
        cout << "j2 = ";
    }

    cout << "(" << i1 << ", " << j1 << ") => (" << i2 << ", " << j2 << ")" << endl;
}

void Joueur::jouerIA(int & i1, int & j1, int & i2, int & j2) const
{
    // choix aleatoire du pion à deplacer
    i1 = rand()%TAILLE;
    j1 = rand()%TAILLE;

    // choix aleatoire pour le deplacement
    if(rand()%4 == 0){ // haut
        j2 = j1;
        rand()%i1;
    }
    else if(rand()%4 == 1){ // bas
        j2 = j1;
        rand()%(TAILLE-i1) + i1;
    }
    else if(rand()%4 == 2){ // droite
        i2 = i1;
        rand()%(TAILLE-j1) + j1;
    }
    else if(rand()%4 == 3){ // gauche
        i2 = i1;
        rand()%j1;
    }
}
