#include <iostream>
#include "Gravite.h"

using namespace std;

string Gravite::affiche()const{
	
	string res = "Gravité:\n\n";
	res += this->ChampForces::affiche();
	
	return res;
	}

void Gravite::agit_sur(ObjetMobile& ball)const
	{
		if(this->influence(ball))
		{
			double rad(ball.get_rayon()); 
			double module((ball.get_masse()-4*3.14159265*rho_air*rad*rad*rad/3)*intensite.norme());
	
			Vecteur d(ball.get_force());

			ball.ajoute_force({0.0,-module,0.0}); //en phase avec Qt, notre axe vertical est l'axe y, et pointe vers le haut
		}
	}


std::ostream& operator<<(std::ostream& sortie, Gravite const& grav){

	sortie<<grav.affiche();
	
	return sortie;
}
