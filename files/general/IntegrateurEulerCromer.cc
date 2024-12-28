#include <iostream>
#include "IntegrateurEulerCromer.h"

using namespace std;

void IntegrateurEulerCromer::integre(ObjetMobile& obj) const
	{
		obj.set_p_1st(dt*obj.evolution()+obj.get_p_1st());
		obj.set_p(dt*obj.get_p_1st()+obj.get_p());
	}


std::string IntegrateurEulerCromer::affiche()const{
	
	string retour("Intégrateur Euler-Cromer\n\n");
	
	retour+="Pas de temps: ";
	retour+=to_string(dt);
	retour+="[s] \n";
	
	
	return retour;
	
	}


ostream& operator<<(std::ostream& sortie, Integrateur const& inte){
	
	sortie<<inte.affiche();
	return sortie;
	
	}
