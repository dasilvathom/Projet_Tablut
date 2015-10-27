#include <iostream>

#include "Tablut.h"

using namespace std;

int main()
{
    /* Petit test de l'aléatoire en c++ */
    /*srand(time(0));
    int random_variable;
    int i;
    int tab[10] = {0,0,0,0,0,0,0,0,0,0};
    for(i=0; i<100; i++){
        random_variable = rand()%10;
        tab[random_variable]++;
    }
    for(i=0; i<10; i++){
        cout << i << "-" << tab[i] << endl;
    }*/
    /* Fin du test, à ne pas effacer pour l'instant */

    srand(time(0));// Toujours le faire pour l'aléatoire de l'ia

    /* Fonctionne */
    Tablut tablut = Tablut("Bebere", "Jean", true, true);
    tablut.jouer();
    tablut.afficherFin();
}
