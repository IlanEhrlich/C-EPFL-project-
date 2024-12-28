#pragma once

#include <iostream>
#include "Obstacle.h"
#include "Vecteur.h"
#include "ObjetMobile.h"
#include "SupportADessin.h"

#include "Systeme.h"


class Plan: public Obstacle{
	public :
		//Cette classe n'est pas abstraite
		virtual Plan* copie() const override{return new Plan(*this);}
		
		virtual void ajoute_a(Systeme& s) const{s.ajoute(*this);}
	
		virtual Vecteur point_plus_proche(ObjetMobile const& x) const override;
		
		virtual std::string affiche()const override;
		
		virtual void dessine_sur(SupportADessin& support) override{ support.dessine(*this); }
		
		Vecteur get_normal()const{return normal;}
		
		
		//constructeurs
		//constructeur par défaut
		Plan()=delete;
		
		//constructeur de copie
		Plan(Plan const&)=default;
		
		Plan(Vecteur origine, Vecteur n)
			:Obstacle(origine), normal(n)
			{
				while(normal.dimension()<3)
				{
					normal.augmente(0.0);
				}
				while(normal.dimension()>3)
				{
					normal.vpop_back();
				}
				
				if(n.norme()!=1)
				{
					normal=n*(1/(n.norme()));
				}
			}
			
		//destructeur
		virtual ~Plan() override = default;	
		
		
	protected :
		Vecteur normal;
};


std::ostream& operator<<(std::ostream& sortie, Plan const&);
