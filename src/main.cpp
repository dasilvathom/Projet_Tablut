#include <iostream>

#include "Tablut.h"

using namespace std;

int main()
{
    /* Fonctionne */
    Plateau plateau = Plateau();
    plateau.afficher();
    cout << endl;
    plateau.movePion(2, 4, 2, 6, VERT);
    plateau.afficher();
    plateau.movePion(4, 6, 3, 6, JAUNE);
    plateau.afficher();
    plateau.movePion(3, 6, 9, 6, 2);
    plateau.afficher();
    plateau.movePion(6, 6, 5, 6, 2);
    cout << endl;
}
