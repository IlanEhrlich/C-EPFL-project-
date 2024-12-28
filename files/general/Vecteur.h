#pragma once

#include <iostream>
#include <vector>


class Vecteur{

	public:
		
		//méthodes
		void augmente(double const& nouvelle_valeur);
		
		void set_coord(size_t position, double const& valeur); 
		
		std::string affiche()const;//anciennement void affiche()const;
		
		bool compare(Vecteur const& vecteur2)const;
		
		std::vector<double> get_vecteur() const;
		
		double get_coord(size_t indice) const;
		
		unsigned int dimension() const{return vect.size();}
		
		void vpop_back(){vect.pop_back();}
		
		//Vecteur addition(Vecteur vecteur2) const;
		//Vecteur soustraction(Vecteur vecteur2) const; //soustrait vecteur2 à vect
		Vecteur oppose()const;
		//Vecteur mult(double scalaire) const;
		//double prod_scal(Vecteur autre) const;
		//Vecteur prod_vect(Vecteur vecteur2) const;   //le premier c vect, vecteur2 le second
		double norme() const;
		double norme2() const;
		
		
		//opérateurs internes
		void operator+=(Vecteur const& vect2);
			
		void operator-=(Vecteur const& vect2);
		
		void operator*=(double const& scal);
			
		void operator^=(Vecteur const& vect2);
		
		void operator=(Vecteur const& vect2);//opérateur d'affectation
		
		
		//constructeurs
		//constructeur par défaut
		Vecteur() = delete;
		
		//constructeur de copie
		Vecteur(Vecteur const&)=default;
			
		Vecteur(double x, double y, double z) //ce constructeur empêche de créer des vecteurs à moins de trois dimensions
			: vect({x,y,z})
			{}
			
		Vecteur(std::vector<double> a)  //cependant, ceci ne marche pas en dimension 1: en faisant Vecteur v({1}), le compilateur ne comprend pas que {1} est de type vector<double>. 
			:vect(a)					//si on voulait utiliser ce constructeur, il faudrait expliciter par une déclaration ce type, mais ce serait embêtant. nous avons donc un autre constructeur pour une dimension unique
			{
				if(a.size()==0)
				{vect={0};}
			}
			
		Vecteur(double x, double y) 
			: vect({x,y})
			{}
		
		Vecteur(double x)
			{	
				std::vector<double> a(1,x);
				vect=a;
			}
	
		//destructeurs
		~Vecteur()=default;
		
		
		private:
	
			std::vector <double> vect;
	};



//opérateurs externes 
std::ostream& operator<<(std::ostream& sortie, Vecteur const& vect);

bool operator==(Vecteur const& vect1, Vecteur const& vect2);									

bool operator!=(Vecteur const& vect1, Vecteur const& vect2);	

Vecteur operator+(Vecteur const& vect1, Vecteur const& vect2);

Vecteur operator-(Vecteur const& vect1, Vecteur const& vect2);

Vecteur operator*(double const& scalaire, Vecteur const& vect);

Vecteur operator*(Vecteur const& vect, double const& scalaire);

double operator*(Vecteur const& vect1, Vecteur const& vect2);

Vecteur operator^(Vecteur const& vect1, Vecteur const& vect2);

Vecteur operator~(Vecteur const& vect1);
//Faut rajouter ces histoire de opration unaire ~, j'ai pas capté
