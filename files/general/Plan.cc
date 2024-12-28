#include <iostream>
#include "Plan.h"

using namespace std;

Vecteur Plan::point_plus_proche(ObjetMobile const& x)const{
	
	return x.get_position()+((O-x.get_position())*normal)*normal;
	}
	
	
std::string Plan::affiche()const{
	
	string retour("Plan:\n\n");
	retour+=this->Obstacle::affiche();
	
	retour+="Vecteur normal: ";
	retour+=normal.affiche();
	retour+="\n";
	
	return retour;
	
	}

ostream& operator<<(ostream& sortie, Plan const& plan) //il y a apparemment un problème que je ne comprends pas lorsque j'essaie de le mettre en const&
{
	sortie<<plan.affiche();
	return sortie;
}
