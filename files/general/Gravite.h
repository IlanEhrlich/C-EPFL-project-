#pragma once

#include <iostream>
#include "ChampForces.h"
#include "ObjetMobile.h"
#include "SupportADessin.h"

#include "Systeme.h"

class Gravite: public ChampForces{

	public:
	
		virtual std::string affiche()const override;
		virtual bool influence(ObjetMobile const&)const override{return 1;} //portée infinie
		
		virtual Gravite* copie() const override{return new Gravite(*this);}
	
		void ajoute_a(Systeme& s) const{s.ajoute(*this);}
	
		virtual void agit_sur(ObjetMobile&) const override;
		
		virtual void dessine_sur(SupportADessin& support)override{ support.dessine(*this); }
		
		
		//constructeurs
		//constructeur par défaut
	
		//constructeur de copie
		Gravite(Gravite const&)=default;
		
		Gravite(Vecteur intens={0,-9.81,0})  //initialisé par défaut à la gravité terrestre selon notre système d'axes
		: ChampForces(intens) 
		{}
		
		Gravite(double module) 
		: ChampForces({0,-module,0}) 
		{}
	
		//destructeur
		virtual~Gravite() override = default;
	
};


std::ostream& operator<<(std::ostream& sortie, Gravite const& grav);
