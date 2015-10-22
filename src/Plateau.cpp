#include "Plateau.h"

#include <iostream>

using namespace std;

Plateau::Plateau()
{
    //plateau.push_back(new Pion(0));
    int i,j;
    // Remplir le plateau avec des pions vides
    for(i=0;i<TAILLE;i++){
        for(j=0;j<TAILLE;j++){
            if((i*TAILLE*j) == CASECENTRE){// On place un pion vide
                // On place un roi
                /* Methode 1*/
                Pion p = Pion(0);
                Pion& refp = p;
                plateau.push_back(refp);
                /* ------ */
                /* Methode 2*/
                //plateau.push_back(Pion(0));
                /* ------ */
            }
            else{
                plateau.push_back(Pion(-1)); // On place un pion vide
            }
        }
    }
    // Placer le roi
    //plateau.erase(plateau.begin()+CASECENTRE);
    //plateau.insert(plateau.begin()+CASECENTRE,Pion(0));

    // Placer les soldats

    // Placer les moscovites

}

Plateau::~Plateau()
{
    //dtor
}

/*Pion& operator() (size_t const i, size_t const j)
{
	return plateau[i * TAILLE + j];
}*/

void Plateau::afficher() const{
    int i,j;
    cout<<endl;
    for(i=0;i<TAILLE;i++){
        cout<< "\t";
        for(j=0;j<TAILLE;j++){
            this->getPion(i,j).afficher();
            cout<< " ";
        }
        cout<<endl;
    }
    cout<<endl;
}

Pion Plateau::getPion(size_t i, size_t j) const{
    return plateau[i * TAILLE + j];
}
