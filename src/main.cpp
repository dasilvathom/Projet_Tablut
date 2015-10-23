#include <iostream>

#include "Tablut.h"

using namespace std;

int main()
{
    /* Fonctionne */
	cout << "\n Coucou ! \t" << endl;
    Plateau plateau = Plateau();
    plateau.afficher();

    cout << endl;
    plateau(4,4).afficher();
    plateau(4,4).modifPion(-1);
    plateau(4,4).afficher();
    plateau.afficher();
    cout << endl;

    /* Ne fonctionne pas */
    /* << "\n Coucou ! \t" << endl;
    Plateau plateau2 = Plateau();
    plateau2.afficher();

    cout << endl;
    plateau2(4,4).afficher();
    plateau2.getPion(4,4).modifPion(-1);
    plateau2(4,4).afficher();
    plateau2.afficher();
    cout << endl;*/

    /* Fonctionne avec plateau public */
    /*cout << "\n Coucou ! \t" << endl;
	Tablut tablut = Tablut();
    tablut.plateau.afficher();

    cout << endl;
    tablut.plateau(4,4).afficher();
    tablut.plateau(4,4).modifPion(-1);
    tablut.plateau(4,4).afficher();
    tablut.plateau.afficher();
    cout << endl;*/

    /* Ne fonctionne pas */
    cout << "\n Coucou ! \t" << endl;
	Tablut tablut = Tablut();
    tablut.getPlateau().afficher();

    cout << endl;
    tablut.getPlateau()(4,4).afficher();
    tablut.getPlateau()(4,4).modifPion(-1);
    tablut.getPlateau()(4,4).afficher();
    tablut.getPlateau().afficher();
    cout << endl;

    /* Fonctionne */
    /*cout << "\n Coucou ! \t" << endl;
	Tablut tablut = Tablut();
    tablut.getPlateau().afficher();

    cout << endl;
    Plateau test = tablut.getPlateau();
    test(4,4).afficher();
    test(4,4).modifPion(-1);
    test(4,4).afficher();
    tablut.getPlateau().afficher();
    cout << endl;*/
}
