#include <iostream>
#include "IntegrateurRungeKutta.h"

using namespace std;


void IntegrateurRungeKutta::integre(ObjetMobile& obj) const
	{
		Vecteur pi(obj.get_p());
		Vecteur ppi(obj.get_p_1st());
		
		Vecteur k1(ppi);
		Vecteur k1p(obj.evolution());
		Vecteur k2(((dt/2)*k1p)+ppi);
		
		obj.set_p(((dt/2)*k1)+pi);
		obj.set_p_1st(((dt/2)*k1p)+ppi);
		Vecteur k2p(obj.evolution());
		
		Vecteur k3(((dt/2)*k2p)+ppi);
		
		obj.set_p(((dt/2)*k2)+pi);
		obj.set_p_1st(((dt/2)*k2p)+ppi);
		Vecteur k3p(obj.evolution());
		
		Vecteur k4((dt*k3p)+ppi);
		
		obj.set_p(dt*k3+pi);
		obj.set_p_1st(dt*k3p+ppi);
		Vecteur k4p(obj.evolution());
		
		Vecteur pf(((k1+2*k2+2*k3+k4)*(dt/6))+pi);
		Vecteur ppf(((k1p+2*k2p+2*k3p+k4p)*(dt/6))+ppi);
		
		obj.set_p(pf);
		obj.set_p_1st(ppf);
	}


std::string IntegrateurRungeKutta::affiche()const{
	
	string retour("Intégrateur Runge-Kutta\n\n");
	
	retour+="Pas de temps: ";
	retour+=to_string(dt);
	retour+="[s] \n";
	
	
	return retour;
	
	}


ostream& operator<<(std::ostream& sortie, IntegrateurRungeKutta const& inte){
	
	sortie<<inte.affiche();
	return sortie;
	
	}
	
