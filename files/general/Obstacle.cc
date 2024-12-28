#include <iostream>
#include "Obstacle.h"

using namespace std;

double Obstacle::distance(ObjetMobile const& objet)const{
	Vecteur vd(objet.get_position()-this->point_plus_proche(objet));
	return vd.norme()-objet.get_rayon();
	}
	
	

void Obstacle::agit_sur(ObjetMobile& x1)const  //les chocs sont les mêmes pour tous les obstacles
	{										   //définit comme décrit dans le complément math-physique.
		Vecteur x2(this->point_plus_proche(x1));//Comme agit_sur des ChampForces, cette méthode est const car les attributs de l'obstacle ne sont pas modifiés par un choc
		if(this->distance(x1)<=0)				//contrairement à agit_sur de ObjetMobile qui n'est pas const 
		{										//ces méthodes sont donc conceptuellement différentes 
			double alpha(0.8);
			double mu(0.01);
		
			Vecteur n(x1.get_position()-x2);
			n = n*(1/(n.norme()));
			
			double Fn1(x1.get_force()*n);
			if(Fn1<0)
			{
				x1.ajoute_force(-1*Fn1*n);
			}
			
			double vet(-1*x1.get_vitesse()*n);
		
			Vecteur vc(x1.get_vitesse()+vet*n);
			
			Vecteur dv(0);
			
			if(7*mu*(1+alpha)*vet>=2*vc.norme())
			{
				dv=(1+alpha)*vet*n-2/7*vc;
			}
			else
			{
				dv=(1+alpha)*vet*(n-(mu*vc*(1/vc.norme())));
			}
			
			if(dv.norme()>1e-9)//afin d'éviter les "comportements infinitésimaux"
			{
				x1.set_vitesse(x1.get_vitesse()+dv);
			}
		}
	}
	

string Obstacle::affiche()const{
	
	string retour("");
	
	retour+="Position de l'origine: ";
	retour+=O.affiche();
	retour+="\n";
	
	return retour;
	
	}


