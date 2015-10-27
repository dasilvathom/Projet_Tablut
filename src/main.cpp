#include <iostream>

#include "Tablut.h"

using namespace std;

int main()
{
    /* Fonctionne */
    Tablut tablut = Tablut("Bebere", "Jean");
    tablut.jouer();
    tablut.afficherFin();
}
