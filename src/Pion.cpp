#include "Pion.h"

#include <iostream>

using namespace std;

Pion::~Pion()
{
    //dtor
}

void Pion::afficher() const{
    if(this->type == VIDE){
        cout<< ".";
    }
    else if(this->type == ROI){
        cout<< "R";
    }
    else if(this->type == MOSCOVITES){
        cout<< "M";
    }
    else if(this->type == SOLDATS){
        cout<< "S";
    }
    else{
        cout<< "X";
    }
}
