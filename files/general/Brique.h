#pragma once
#include <iostream>
#include "Vecteur.h"
#include "ObjetMobile.h"
#include "Obstacle.h"
#include "PortionPlan.h"
#include "Plan.h"
#include "SupportADessin.h"

#include "Systeme.h"

class Brique: public Obstacle{
	
	public:
	
		virtual Brique* copie() const override{return new Brique(*this);}
	
		void ajoute_a(Systeme& s) const{s.ajoute(*this);}
	
		virtual Vecteur point_plus_proche(ObjetMobile const& x)const override;
		
		virtual std::string affiche()const override;
		
		virtual void dessine_sur(SupportADessin& support) override{ support.dessine(*this); }
		
		std::vector<PortionPlan> get_Face()const{return Face;}
	
		
		Vecteur get_L()const{return L;}
		Vecteur get_l()const{return l;}//Juste pour le problème de constructeur de brique
		double get_h()const{return h;}
		Vecteur get_O()const{return O;}//simple outil de vérification
		
		
		//constructeur
		//constructeur par défaut
		Brique()=delete;
		
		//contructeur de copie
		Brique(Brique const&)=default;
		
		Brique(Vecteur origine, Vecteur Longueur, Vecteur largeur, double hauteur)
			:Obstacle(origine), L(Longueur), l(largeur), h(hauteur), Face()
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
				
				if(Longueur*largeur!=0) //Longueur et largeur sont orthogonaliser par convention
				{
					l = largeur - ((largeur*(Longueur*(1/(Longueur.norme()))))*(Longueur*(1/(Longueur.norme()))));
				}
			  
				 Vecteur vh((h/((L^l).norme()))*(L^l));
				 
				 PortionPlan f1(O, L, l);
				 PortionPlan f2(O, -1*vh, L);
				 PortionPlan f3(O, l, -1*vh);	//les faces de la brique sont initialiser comme indiqué dans le complément math-physique
				 PortionPlan f4(O+L, -1*vh, l);
				 PortionPlan f5(O+l, L, -1*vh);
				 PortionPlan f6(O-vh, l, L);
				 
				 //Face.clear();
				 
				 Face.push_back(f1);
				 Face.push_back(f2);
				 Face.push_back(f3);
				 Face.push_back(f4);
				 Face.push_back(f5);
				 Face.push_back(f6);
				  
			}
		
		//destructeur
		virtual ~Brique() override = default; 
		
		
	private:
		Vecteur L;
		Vecteur l;
		double h;
		
		std::vector<PortionPlan> Face;//Ce tableau de PortionPlan représente les 6 faces de la briques
	
};

std::ostream& operator<<(std::ostream& sortie, Brique const& bri);
