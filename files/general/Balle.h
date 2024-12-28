#pragma once

#include <iostream>
#include "Vecteur.h"
#include "ObjetMobile.h"
#include "SupportADessin.h"

#include "Systeme.h"

//fondamentalement, peu change entre la balle et l'objetmobile, elles ont toutes deux les mêmes attributs, quasiment toutes les méthodes sont virtuelles

class Balle:public ObjetMobile{
	public:
	
		virtual Balle* copie() const override{return new Balle(*this);}
	
		void ajoute_a(Systeme& s) const{s.ajoute(*this);}
		
		virtual Vecteur evolution() const override;
		
		virtual void dessine_sur(SupportADessin& support) override{ support.dessine(*this); }
	
		virtual void set_vitesse(Vecteur const& autre) override{p_1st=autre;} //pour les chocs
		
		virtual Vecteur get_position()const override{return p;} //dans le cas de la balle, elle a trois degrés de liberté, donc il n'y a aucune différence entre p et position, et entre p_1st et vitesse
		virtual Vecteur get_vitesse()const override{return p_1st;}
		
		virtual Vecteur get_force()const override{return force;}
		
		virtual std::string affiche()const override;
		
		virtual void agit_sur(ObjetMobile& x2) override;
		
		
		//constructeurs
		//constructeur par défaut
		Balle()=delete;
		
		//constructeur de copie 
		Balle(Balle const&)=default;
		
		Balle(Vecteur p_init,Vecteur p_1st_init, double rayon=1.0, double masse=1.0, Vecteur force={0, 0, 0})
			:ObjetMobile(p_init, p_1st_init, rayon, masse, force) //pas besoin d'un autre constructeur
			{}
			
		//destructeur
		virtual ~Balle() override=default;	
	};	
	
//opérateur externe, cout
std::ostream& operator<<(std::ostream& sortie, Balle const& bal);
