#pragma once 

#include <iostream>
#include "ObjetCompose.h"
#include "Vent.h"
#include "Brique.h"
#include "ObjetMobile.h"
#include "SupportADessin.h"
#include "Systeme.h"


class Ventilateur: public ObjetCompose{

	public: 
		
		void agit_sur(ObjetMobile& obj) const{souffle.agit_sur(obj); paroi.agit_sur(obj);}
			
		virtual std::string affiche()const override;
		
		//const Brique* get_ptr_paroi()const{return &paroi;}
		//const Vent* get_ptr_souffle()const{return &souffle;}
		
		virtual void dessine_sur(SupportADessin& support)override{ support.dessine(*this); }
		
		void ajoute_a(Systeme &sys) const;
		
		
		//constructeur
		//constructeur par défaut
		Ventilateur()=delete;
		
		//constructeur de copie
		Ventilateur(Ventilateur const&)=default;
		
		Ventilateur(Vecteur const& origine, Vecteur const& Longueur, Vecteur const& largeur, double si, double V, double h)
		:paroi(origine, Longueur, largeur, h), souffle(origine,Longueur,largeur,si,V)
		{}
		
		//destructeur 
		~Ventilateur()override=default;
		
		
	private:
		Brique paroi;
		Vent souffle;
};


std::ostream& operator<<(std::ostream&, Ventilateur const&);


