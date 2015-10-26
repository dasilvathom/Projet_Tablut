#include "Plateau.h"

#include <iostream>
#include <stdlib.h>

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
}

Plateau::~Plateau()
{
    //dtor
}

Pion& Plateau::getPion(size_t i, size_t j){
    Pion& retPion = plateau[i * TAILLE + j];
    return retPion;
}

void Plateau::afficher() const{
    int i,j;
    cout<<endl;
    for(i=0;i<TAILLE;i++){
        cout<< "\t";
        for(j=0;j<TAILLE;j++){
            //this->getPion(i,j).afficher();
            plateau[i * TAILLE + j].afficher();
            cout<< " ";
        }
        cout<<endl;
    }
    cout<<endl;
}

/*
 *  Fonction permettant de bouger le pion (i1, j1) vers la case (i2, j2), joué par le joueur
 *  ayant la couleur couleur.
 *
 *  Renvois true si le move a bien pu être effectué, false sinon
 *
 */

bool Plateau::movePion(int const i1, int const j1, int const i2, int const j2, int couleur) {

    // La case demandee est hors plateau
    if(i1 < 0 || i1 >= TAILLE || j1 < 0 || j1 >= TAILLE) {
        cout << "La case (" << i1 << ", " << j1 << ") est en dehors du plateau" << endl;
        return false;
    }

    // La case cible est hors plateau
    if(i2 < 0 || i2 >= TAILLE || j2 < 0 || j2 >= TAILLE) {
        cout << "La case (" << i2 << ", " << j2 << ") est en dehors du plateau" << endl;
        return false;
    }

    // Mouvement impossible, pas en ligne
    if(i1 != i2 && j1 != j2) {
        cout << "Mouvement impossible" << endl;
        return false;
    }

    if(i1 == i2 && j1 == j2) {
        cout << "Aucun mouvement" << endl;
        return false;
    }

    // On récupère les pions
    Pion& p1 = this->getPion(i1, j1);
    Pion& p2 = this->getPion(i2, j2);

    // Pas de pion à deplacer
    if(p1.estVide()) {
        cout << "Aucun pion aux coordonnees (" << i1 << ", " << j1 << ")" << endl;
        return false;
    }

    // Interdiction d'aller sur la case centrale pour les soldats / moscovites
    if( (p1.getType() == MOSCOVITES || p1.getType() == SOLDATS) && ((i2 == CASECENTRE) && (j2 == CASECENTRE)) ) {
        cout << "Ce Pion n'a pas le droit d'aller sur la case centrale" << endl;
        return false;
    }

    // La case est déjà occupée
    if(!p2.estVide()) {
        cout << "La case (" << i2 << ", " << j2 << ") est occupee" << endl;
        return false;
    }

    else {
        // Verification de la couleur
        bool pionVert = (p1.getType() == ROI || p1.getType() == SOLDATS) && (couleur == VERT);
        bool pionJaune = (p1.getType() == MOSCOVITES) && (couleur == JAUNE);
        if(pionVert || pionJaune) {

            bool possible = deplacementPossible(i1,j1,i2,j2);

            // Deplacement possible
            if(possible) {

                p2.modifPion(p1.getType());
                p1.modifPion(VIDE);

                /* Fonction de verifications a rajouter si Roi dans un bord, ou si pion capture */
                if(p2.getType() == ROI){
                    finPartie(i2,j2); // test de fin de partie
                    roiVoieLibre(i2,j2); // test si une ou plusieurs voie sont libre pour le roi
                }

                return true;
            }
            else {
                cout << "Mouvement impossible, une piece est sur le chemin" << endl;
                return false;
            }
        }
        else {
                cout << "Ce pion n'appartient pas a ce joueur" << endl;
                return false;
            }
    }

}

/*
    Verifie si on mouvement n'a pas d'obstacle
*/
bool Plateau::deplacementPossible(int const i1, int const j1, int const i2, int const j2){
    bool possible = true;

    int sensi;
    int sensj;

    if(i2 - i1 != 0) {
        sensi = (i2 - i1) / abs(i2 - i1);
    }
    else {
        sensi = 0;
    }

    if(j2 - j1 != 0) {
        sensj = (j2 - j1) / abs(j2 - j1);
    }
    else {
        sensj = 0;
    }

    int i = i1 + sensi;
    int j = j1 + sensj;

    while(possible && ((i == i2 && j != j2) || (i != i2 && j == j2))) {
        if(!(this->getPion(i, j).estVide())) {
            possible = false;
        }
        i += sensi;
        j += sensj;
    }

    return possible;
}

/*
    Verifie si une partie est finie
    si oui, l'attribut fin de plateau passe à vrai
*/
void Plateau::finPartie(size_t iRoi, size_t jRoi){
    if((iRoi == 0) || (iRoi == (TAILLE-1)) || (jRoi == 0) || (jRoi == (TAILLE-1))){
        fin = true;
    }
}

/*
    Verifie si le roi à la voie libre et affiche un message si necessaire
*/
void Plateau::roiVoieLibre(size_t iRoi, size_t jRoi){

    int nbLibre = 0;

    // Le roi n'est pas deja au bord
    if(!fin){
        // Vers le haut
        if(deplacementPossible(iRoi,jRoi,0,jRoi)){
            nbLibre++;
        }
        // Vers le bas
        if(deplacementPossible(iRoi,jRoi,(TAILLE-1),jRoi)){
            nbLibre++;
        }
        // Vers la droite
        if(deplacementPossible(iRoi,jRoi,iRoi,(TAILLE-1))){
            nbLibre++;
        }
        // Vers la gauche
        if(deplacementPossible(iRoi,jRoi,iRoi,0)){
            nbLibre++;
        }

        if(nbLibre == 1){
            cout << "\t Raichi" << endl;
        }
        else if(nbLibre > 1){
            cout << "\t Tuichi" << endl;
        }
    }
}
