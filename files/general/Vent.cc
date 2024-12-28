#include <iostream>
#include "Vent.h"

using namespace std;

bool Vent::influence(ObjetMobile const& obj)const{
	
	//toutes ces déclarations servent à caractériser le parallélépipède rectangle dans lequel le vent agit. cette méthode est donc simplement appelée dans agit_sur : il nous a semblé plus élégant de le faire en deux fois distinctes
	
	Vecteur x(obj.get_position());
	Vecteur n(mur.get_normal());
	Vecteur O(mur.get_O());
	Vecteur l(mur.get_l());
	Vecteur L(mur.get_L());
	double nL(L.norme());
	double nl(l.norme());
	Vecteur eL(L*(1/nL));
	Vecteur el(l*(1/nl));
	
	bool action(1);
	
	Vecteur pos_rel(x-O);
	
	action*=(pos_rel*n>0); //il suffit que l'un d'entre ceux-ci soit nul pour qu'action se retrouve à 0
	action*=(pos_rel*n<sigma);
	action*=(pos_rel*el>0);
	action*=(pos_rel*el<nl);
	action*=(pos_rel*eL>0);
	action*=(pos_rel*eL<nL);
	
	return action;
	}

void Vent::agit_sur(ObjetMobile& obj)const{

	double R(obj.get_rayon());
	if (this->influence(obj)){obj.ajoute_force(intensite*R*R);}
}

string Vent::affiche()const{
	
	string retour("Vent:\n\n");
	
	retour+=this->ChampForces::affiche();
	retour+=mur.affiche();
	retour+="\nProfondeur du champ: ";
	retour+=to_string(sigma);
	retour+="\nVitesse du flux d'air: ";
	retour+=to_string(V0);
	
	return retour;
	
	}

std::ostream& operator<<(std::ostream& sortie, Vent const& vent){

	sortie<<vent.affiche();
	
	return sortie;
}
