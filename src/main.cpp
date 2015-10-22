#include <iostream>

#include "Tablut.h"
#include "Plateau.h"

using namespace std;

int main()
{
	cout << "\n Coucou ! \t" << endl;
    Plateau plateau = Plateau();
    plateau.afficher();

    cout << endl;
    plateau(4,4).afficher();
    plateau(4,4).modifPion(-1);
    plateau(4,4).afficher();
    plateau.afficher();
    cout << endl;
}
