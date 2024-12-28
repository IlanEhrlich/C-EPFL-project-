#pragma once

#include <iostream>
#include "ChampForces.h"
#include "ObjetMobile.h"
#include "SupportADessin.h"
#include "PortionPlan.h"

#include "Systeme.h"


class Vent: public ChampForces{

	public:
	
		bool influence(ObjetMobile const& obj)const;
		
		virtual Vent* copie() const override{return new Vent(*this);}//n
		
		void ajoute_a(Systeme& s) const{s.ajoute(*this);}
	
		virtual void agit_sur(ObjetMobile&) const override;
		
		virtual void dessine_sur(SupportADessin& support)override{ support.dessine(*this); }
		
		virtual std::string affiche()const override;
		
		
		//constructeurs
		//constructeur par défaut
		Vent()=delete;
		
		//constructeur de copie
		Vent(Vent const&)=default;
		
		//pour plus de souplesse, nous avons beaucoup d'attributs, mais ils sont souvenet liés dans le constructeur. L'accès est donc facilité, et il n'est nul besoin de tous les entrer en paramètres dans le constructeur
		Vent(Vecteur const& origine, Vecteur const& Longueur, Vecteur const& largeur, double si, double V)  //l'intensité de la force est le vecteur de direction n et de longueur égale au facteur par lequel il faut multiplier le carré du rayon de l'objetmobile sur lequel elle agira
			: ChampForces({0,0,0}), mur(origine, Longueur, largeur), sigma(si), V0(V) //il est nécessaire de laisser une valeur éphémère pour le champforces, sinon il ne compile pas 
			{
				intensite=3.77*V0*V0*mur.get_normal();
			}
		
		//destructeur
		virtual ~Vent()override=default;
		
		
	private: 
	
		//à la différence de ventilateur, ce n'est pas une brique mais un portion plan que possède le vent: cela lui sert à définir son parallélépipède rectangle qui caractérise son champ d'action:
		//il faut donc un rectangle, puis une profondeur: sigma
		//de plus, on a une intensité V0, qui sera directement liée à l'intensité
		PortionPlan mur;
		double sigma;
		double V0;
	
};


std::ostream& operator<<(std::ostream& sortie, Vent const&);
