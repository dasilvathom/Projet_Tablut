#include "Tablut.h"

Tablut::Tablut(string unNom1, string unNom2, bool ia1, bool ia2)
{
    plateau = Plateau();
    j1 = Joueur(unNom1, VERT, ia1);
    j2 = Joueur(unNom2, JAUNE, ia2);
}

Tablut::~Tablut()
{
    //dtor
}

void Tablut::jouer() {
    int i1, i2, j1, j2;
    Plateau& plateau = this->getPlateau();
    Joueur joueur1 = this->getJoueur1();
    Joueur joueur2 = this->getJoueur2();

    plateau.afficher();

    while(plateau.getFin() == false) {

        if(!joueur1.estIa()){
            joueur1.jouer(i1, j1, i2, j2);
            while(!plateau.movePion(i1, j1, i2, j2, joueur1.getCouleur())) {
                joueur1.jouer(i1, j1, i2, j2);
            }
            plateau.afficher();
        }
        else{
            joueur1.jouerIA(i1, j1, i2, j2);
            while(!plateau.movePion(i1, j1, i2, j2, joueur1.getCouleur())) {
                joueur1.jouerIA(i1, j1, i2, j2);
            }
        }

        //plateau.afficher();

        if(plateau.getFin() == false){
            if(!joueur2.estIa()){
                joueur2.jouer(i1, j1, i2, j2);
                while(!plateau.movePion(i1, j1, i2, j2, joueur2.getCouleur())) {
                    joueur2.jouer(i1, j1, i2, j2);
                }
                plateau.afficher();
            }
            else{
                joueur2.jouerIA(i1, j1, i2, j2);
                while(!plateau.movePion(i1, j1, i2, j2, joueur2.getCouleur())) {
                    joueur2.jouerIA(i1, j1, i2, j2);
                }
            }

            //plateau.afficher();
        }
    }
}

Plateau& Tablut::getPlateau(){
    Plateau& retPlateau = plateau;
    return retPlateau;
}

void Tablut::afficherFin(){
    cout << "Fin de la partie" << endl;

    Plateau& plateau = getPlateau();
    plateau.afficher();

    cout << "Le gagnant est : ";
    if(plateau.getRoiPresent()){
        cout << this->getJoueur1().getNom() << endl;
    }
    else{
        cout << this->getJoueur2().getNom() << endl;
    }
}
