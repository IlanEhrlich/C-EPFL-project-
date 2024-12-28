#pragma once

#include <iostream>
#include "Vecteur.h"
#include "ObjetMobile.h"
#include <cmath>
#include "constantes.h"
#include <string>
#include "SupportADessin.h"
#include "Balle.h"

#include "Systeme.h"

class Pendule: public ObjetMobile{
	
	public:
		//Nous avions commencé à coder le pendule sphérique mais nous n'avons pas réussi, on conseil d'utiliser le pendule polaire (p et p_1st à une dimendion lors de l'initialisation).  Note : Le pendule sphérique semble marcher mais seulement si p_1st est de dimension 1 et si il ne subit pas de choc
		virtual Pendule* copie() const override{return new Pendule(*this);}
	
		void ajoute_a(Systeme& s) const{s.ajoute(*this);}
	
		virtual Vecteur evolution() const override;
		
		virtual void dessine_sur(SupportADessin& support) override{ support.dessine(*this); }

		virtual std::string affiche()const override;	
		
		double get_longueur()const{return longueur;}
		
		void set_longueur(double l){longueur=l;}
		
		Vecteur get_position_origine()const{return position_origine;}
		
		virtual Vecteur get_position()const override;	
		
		virtual Vecteur get_vitesse()const override;//Ces trois getters vont donner les attributs de la balle au bout du pendule
		
		virtual Vecteur get_force()const override;
		
		virtual void set_vitesse(Vecteur const& autre) override; //cette méthode est surtout utile pour les chocs
		
		Balle bal() const;
		
		virtual void agit_sur(ObjetMobile& x2) override;
				
		Vecteur direction() const;
		
		
		//constructeurs
		//constructeur par défaut
		Pendule()=delete;
		
		//constructeur de copie
		Pendule(Pendule const&)=default;
		
		Pendule(Vecteur p_init,Vecteur p_1st_init, double rayon=1.0, double masse=1.0, Vecteur force=vecteur_nul,Vecteur pos_origine=vecteur_nul, double lon=1.0) //meilleure position pour l'argument de la longueur? 
		:ObjetMobile(p_init, p_1st_init, rayon, masse, force),
		position_origine(pos_origine), longueur(lon)
		{
			while(position_origine.dimension()<3)
			{
				position_origine.augmente(0);
			}
			while(position_origine.dimension()>3)
			{
				position_origine.vpop_back();
			}
			
			if(lon<=0)
			{
				if(lon==0.0){longueur=1.0;}
				else{longueur=-1*lon;}
			}
		}
	
		//destructeur
		virtual ~Pendule()override = default;
		
	
	private:
	
		Vecteur position_origine;
		double longueur;
			
	};


//opérateur externe, cout
std::ostream& operator<<(std::ostream& sortie, Pendule const& obj);
