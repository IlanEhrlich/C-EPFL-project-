#include <iostream>
#include "Vecteur.h"
#include "Balle.h"
#include "constantes.h"

using namespace std;

Vecteur Balle::evolution() const{
	//simple mouvement ballistique: newton
	return force*(1/masse);
	
}

void Balle::agit_sur(ObjetMobile& x2){
	Vecteur testP(p-x2.get_position());
	if(testP.norme()<=(rayon + x2.get_rayon()))
	{
		double alpha(0.8);
		double mu(0.01);
		double la((1+alpha)*x2.get_masse()/(masse+x2.get_masse()));
		
		Vecteur n(p-x2.get_position());	//dans cette méthode, le comportement polymorphique 
		n = n*(1/(n.norme()));			//de get_position(), vitesse et force assure 
		double Fn1(force*n);			//le bon déroulement des chocs impliquant des pendules
		double Fn2(x2.get_force()*n);
		
		if(Fn1<0)
		{
			force=force-Fn1*n;
			x2.ajoute_force(Fn1*n);
		}
		if(Fn2>0)
		{
			force = force + Fn2*n;
			x2.ajoute_force(-1*Fn2*n);
		}
		
		double vet((x2.get_vitesse()-p_1st)*n);
		Vecteur vc(p_1st-x2.get_vitesse()+vet*n);
		Vecteur dv(0);
		if(7*mu*(1+alpha)*vet>=2*vc.norme())
		{
			dv = la*vet*n-(2*x2.get_masse()/(7*(masse + x2.get_masse()))*vc);
		}
		else
		{
			dv = la*vet*(n-mu*(vc*(1/vc.norme())));
		}
		if(dv.norme()>1e-9)
		{
			p_1st=p_1st+dv;
			x2.set_vitesse(x2.get_vitesse()-(masse/x2.get_masse())*dv);
		}
	}
	}
	
string Balle::affiche()const{
	
	string retour("Balle:\n\n");
	
	retour+=this->ObjetMobile::affiche();
	
	return retour;
	
	}

std::ostream& operator<<(std::ostream& sortie, Balle const& bal)
{
	sortie<<bal.affiche();
	return sortie;
}


