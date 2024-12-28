#include <iostream>
#include "IntegrateurNewmark.h"

using namespace std;


void IntegrateurNewmark::integre(ObjetMobile& obj) const
	{
		Vecteur pp(obj.get_p_1st());
		Vecteur p(obj.get_p());
		Vecteur s(obj.evolution());
		
		Vecteur q(p);
		do
		{
			q=obj.get_p();
			Vecteur r(obj.evolution());
			obj.set_p_1st(pp+(dt/2*(r+s)));
			obj.set_p(p+(dt*pp)+(dt*dt/3*(0.5*r+s)));
			
		}while(q.compare(obj.get_p())==false);
	}


std::string IntegrateurNewmark::affiche()const{
	
	string retour("Intégrateur Newmark\n\n");
	
	retour+="Pas de temps: ";
	retour+=to_string(dt);
	retour+="[s] \n";
	
	
	return retour;
	
	}


ostream& operator<<(std::ostream& sortie, IntegrateurNewmark const& inte){
	
	sortie<<inte.affiche();
	return sortie;
	
	}
