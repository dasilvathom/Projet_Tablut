#include "Plateau.h"

#include <iostream>

using namespace std;

Plateau::Plateau()
{
    int i,j;
    // Remplir le plateau avec des pions vides
    for(i=0;i<TAILLE;i++){
        for(j=0;j<TAILLE;j++){
            if((i == CASECENTRE) && (j == CASECENTRE)){ // On place un roi
                /* Methode 1 */
                /*Pion p = Pion(0);
                Pion& refp = p;
                plateau.push_back(refp);*/
                /* ------ */
                /* Methode 2 */
                plateau.push_back(Pion(0)); // vector<T>::push_back(const T&)
                /* ------ */
                /* Methode 3 */
                //plateau.push_back(move(Pion(0))); // vector<T>::push_back(T&&)
                /* ------ */
            }
            else if((i==4 && j>1 && j<7) || (j==4 && i>1 && i<7)){ // On place les soldats
                /* Methode 2 */
                plateau.push_back(Pion(1));
                /* ------ */
            }
            else if(((i==0 || i==8) && j>2 && j<6) || ((j==0 || j==8) && i>2 && i<6) || (i==4 && (j==1 || j==7)) || (j==4 && (i==1 || i==7))){ // On place les soldats
                /* Methode 2 */
                plateau.push_back(Pion(2)); // vector<T>::push_back(const T&)
                /* ------ */
            }
            else{ // On place un pion vide
                /* Methode 2 */
                plateau.push_back(Pion(-1));
                /* ------ */
            }
        }
    }
    // Placer le roi

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

Pion Plateau::getPion(size_t i, size_t j) const{
    return plateau[i * TAILLE + j];
}

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
