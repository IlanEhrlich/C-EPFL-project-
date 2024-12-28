#pragma once

#include <iostream>
#include "Vecteur.h"
#include "constantes.h"
#include "ObjetSimple.h"

class Integrateur;

class ObjetMobile: public ObjetSimple{
	
	public:
	
		virtual ObjetMobile* copie() const = 0; //générer le pointeur, fondamental pour le systeme 
		
		virtual Vecteur evolution() const=0; //spécifique à objetmobile, mais redéfini par chaque sous-classe en fonction du mouvement des objets en question 
		virtual void evolue(Integrateur const&); //seulement la réciproque à Integrateur::integre(ObjetMobile), pour donner la liberté de l'appeler dans un sens ou l'autre 
			
		virtual std::string affiche()const override;
		
		double masse_volumique()const;
		
		//getters utiles
		Vecteur get_p() const{return p;}
		Vecteur get_p_1st()const{return p_1st;}
		double get_rayon()const{return rayon;}			
		double get_masse()const{return masse;}		
		virtual Vecteur get_force()const{return force;}	
		virtual Vecteur get_position()const = 0; //la "véritable" position 
		virtual Vecteur get_vitesse()const = 0;//pareil pour la vitesse
		
		//ces deux méthodes pour les intégrateurs
		void set_p(Vecteur const& autre){p=autre;}//1
		void set_p_1st(Vecteur const& autre){p_1st=autre;}//2
		void set_force(Vecteur f){force=f;}
		virtual void set_vitesse(Vecteur const& autre) = 0;//utile pour les chocs
		void ajoute_force(Vecteur const& df);

		
		//Pour les chocs 
		virtual void agit_sur(ObjetMobile& x2) = 0;
		
		
		//constructeurs
		//constructeur par défaut
		ObjetMobile()=delete;
		
		//constructeur de copie
		ObjetMobile(ObjetMobile const&)=default;
		
		ObjetMobile(Vecteur p_init,Vecteur p_1st_init, double ray=1.0, double mas=1.0, Vecteur f={0,0,0})
			:p(p_init), p_1st(p_1st_init), rayon(ray), masse(mas), force(f)
			{ //la dimension est imposée à trois, pour éviter les additions de vecteurs de mauvaise taille: nous avons choisi les conventions à la gestion d'erreurs
				
				while(p.dimension()<3){p.augmente(0);}
				while(p.dimension()>3){p.vpop_back();}
				while(p_1st.dimension()<3){p_1st.augmente(0);}
				while(p_1st.dimension()>3){p_1st.vpop_back();}
				while(force.dimension()<3){force.augmente(0);}
				while(force.dimension()>3){force.vpop_back();}
				if(rayon<=0)
				{
					if(rayon==0.0){rayon=1.0;}
					else{rayon = -1*rayon;}
				}
				
				if(masse<=0)
				{
					if(masse==0.0){masse=1.0;}
					else{masse = -1*masse;}
				}
			}
		
		//destructeur
		virtual ~ObjetMobile() override = default;
		
		
	protected:
		
		Vecteur p;
		Vecteur p_1st;
	
		double rayon; //tous les objets mobiles sont considérés comme ayant une forme sphérique
		double masse;
		Vecteur force;
	};

