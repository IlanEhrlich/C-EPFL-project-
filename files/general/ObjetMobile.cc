#include <iostream>
#include "ObjetMobile.h"
#include "Integrateur.h"


using namespace std;

void ObjetMobile::evolue(Integrateur const& inte){inte.integre(*this);}

double ObjetMobile::masse_volumique()const{
	return 3*masse/(4*pi*rayon*rayon*rayon); 
	}

void ObjetMobile::ajoute_force(Vecteur const& df){
	force+=df;
	}
	
string ObjetMobile::affiche()const{
	
	string retour("");
	
	retour+="Position: ";
	retour+=(this->get_position()).affiche();
	retour+="\n";
	retour+="Vitesse: ";
	retour+=(this->get_vitesse()).affiche();
	retour+="\n";
	
	retour+="Rayon: ";
	retour+=to_string(rayon);
	retour+="\n";
	retour+="Masse: ";
	retour+=to_string(masse);
	retour+="\n";
	retour+="Masse volumique: ";
	retour+=to_string(this->masse_volumique());
	retour+="\n";
	retour+="Force totale: ";
	retour+=force.affiche();
	retour+="\n";
	
	return retour;
	
	}
	
