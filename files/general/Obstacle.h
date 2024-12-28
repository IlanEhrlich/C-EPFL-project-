#pragma once 

#include <iostream>
#include "Vecteur.h"
#include "ObjetMobile.h"
#include "ObjetSimple.h"


class Obstacle: public ObjetSimple{
	
	public :
	
		virtual Obstacle* copie() const = 0;
		
		virtual Vecteur point_plus_proche(ObjetMobile const&)const=0; //propre à chaque ssclasse d'obstacle
		
		double distance(ObjetMobile const& objet)const;
		
		void agit_sur(ObjetMobile& x1) const;
		
		Vecteur get_O()const{return O;}
		
		virtual std::string affiche()const override;
	
	
		//constructeurs
		//constructeur par défaut
		Obstacle()=delete;
		
		//contructeur de copie
		Obstacle(Obstacle const&)=default;
		
		Obstacle(Vecteur origine)
		:O(origine)    
		{}
	
		//destructeur 
		virtual ~Obstacle()override = default;
		
	protected :
		Vecteur O;
};
