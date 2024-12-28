#pragma once 

#include <iostream>
#include "Vecteur.h"
#include "ObjetMobile.h"
#include "ObjetSimple.h"


class ChampForces: public ObjetSimple{
	
	public:
	
		virtual ChampForces* copie() const = 0;
	
		virtual std::string affiche()const override;
		
		virtual bool influence(ObjetMobile const&)const=0; // sert à régir la portée des forces: par exemple le vent a une influence limitée à son parallélépipède d'action, tandis que la gravité ne l'est pas
		//cela sert surtout à agit_sur des deux classes filles
		
		virtual void agit_sur(ObjetMobile &)const=0;
		
		void set_intensite(Vecteur);
		
		Vecteur get_intensite() const{return intensite;}
		
		//constructeurs
		//constructeur par défaut
		ChampForces()=delete;
		
		//constructeur de copie
		ChampForces(ChampForces const&)=default;
		
		ChampForces(Vecteur const& autre)
		: intensite(autre) 
		{}
		
		//destructeur
		virtual ~ChampForces() override=default;
		
		
	protected:
	
		Vecteur intensite;
	
	};


