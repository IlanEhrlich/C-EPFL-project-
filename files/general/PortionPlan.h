#pragma once 
#include <iostream>
#include "Vecteur.h"
#include "Obstacle.h"
#include "ObjetMobile.h"
#include "Plan.h"
#include "SupportADessin.h"

#include "Systeme.h"

class PortionPlan: public Plan{		//surtout utile à la conceptionn de la brique
	
	public :
	
		virtual PortionPlan* copie() const override{return new PortionPlan(*this);}//n
	
		virtual void ajoute_a(Systeme& s) const override{s.ajoute(*this);}
	
		virtual Vecteur point_plus_proche(ObjetMobile const& x)const override;
		
		virtual std::string affiche()const override;
		
		virtual void dessine_sur(SupportADessin& support) override{ support.dessine(*this); }
		
		Vecteur get_L()const{return L;}
		
		Vecteur get_l()const{return l;}
		
		Vecteur get_n()const{return normal;}
		
		//constructeur 
		//constructeur par défaut
		PortionPlan()=delete;
		
		//constructeur de copie
		PortionPlan(PortionPlan const&)=default;
		
		PortionPlan(Vecteur const& origine, Vecteur const& Longueur, Vecteur const& largeur)
			:Plan(origine, Longueur^largeur), L(Longueur), l(largeur)//On part de la base que c'est dimension 3
			{
				while(L.dimension()<3)
				{
					L.augmente(0.0);
				}
				while(L.dimension()>3)
				{
					L.vpop_back();
				}
				while(l.dimension()<3)
				{
					l.augmente(0.0);
				}
				while(l.dimension()>3)
				{
					l.vpop_back();
				}
					
				if(Longueur*largeur!=0)
				{	
					l = largeur - ((largeur*(Longueur*(1/(Longueur.norme()))))*(Longueur*(1/(Longueur.norme()))));
					normal=Longueur^largeur;
					
					if(normal.norme()!=1)
					{
						normal=normal*(1/(normal.norme()));
					}
				}
			}
			
		//destructeur
		virtual ~PortionPlan() override = default; 
			
		
	private:
		Vecteur L;
		Vecteur l;
		
};


std::ostream& operator<<(std::ostream& sortie, PortionPlan const&);
