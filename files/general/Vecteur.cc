#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include "Vecteur.h"

using namespace std;



void Vecteur::augmente(double const& nouvelle_valeur)
	{
		vect.push_back(nouvelle_valeur);
	}


void Vecteur::set_coord(size_t position, double const& valeur)
	{
		size_t taille(vect.size());
		size_t pos_verif(position);
		
		while(pos_verif>=taille)
		{
			cout<<"Position invalide, le vecteur possede "<<taille<<" dimenstions, veuillez entrer un nombre entier entre 0 et "<<taille-1<<endl;
			cin>>pos_verif;
		}	
		vect[pos_verif]=valeur;
	}
	
	
string Vecteur::affiche()const
	{
		std::string retour("");
		retour+='(';
		size_t i(0);
		while(i<vect.size()-1)
		{
			retour+=to_string(vect[i]);			
			retour+=", ";			
			++i;
		}
		retour+=to_string(vect[i]);
		retour+=')';
		return retour;
	}
	
	
bool Vecteur::compare(Vecteur const& vecteur2)const
{	
	vector<double> vect2(vecteur2.get_vecteur());
	
	bool retour(1);
	
	double prec(1e-13);
	
	if(vect2.size()==vect.size())
		{
			for(size_t i(0); i<vect.size();++i)
			{
				retour*=(abs(vect[i]-vect2[i])<prec);	//rajouter la precision	
			}
			return retour;
		}
		
	else
	{	
		return 0;
	}
}

	
vector<double> Vecteur::get_vecteur() const
	{
		return vect;
	}


double Vecteur::get_coord(size_t indice)const
	{ 
		return vect[indice];
	}


	
Vecteur Vecteur::oppose() const
{ 
	return vect*(-1);
}

	
double Vecteur::norme() const
{
	double retour(norme2());
	return sqrt(retour);
}


double Vecteur::norme2() const
{
	double retour(0);
	for(size_t i(0); i<vect.size();++i)
	{
		retour = vect[i]*vect[i]+retour;
	}
	return retour;
}





//opérateurs internes 
void Vecteur::operator+=(Vecteur const& vect2)
{	
	vector<double> vecteur2(vect2.get_vecteur());	
	if(vecteur2.size()<=vect.size()) 
	{
		for(size_t i(0); i<vecteur2.size();++i)
		{
			vect[i]+=vecteur2[i];
		}
	}
	else  
	{
		while(vect.size()<vecteur2.size())
		{
			this->augmente(0);
		}
		for(size_t i(0); i<vecteur2.size();++i)
		{
			vect[i]+=vecteur2[i];
		}
	}
}


void Vecteur::operator-=(Vecteur const& vect2)
{		
	vector<double> vecteur2(vect2.get_vecteur());	
	if(vecteur2.size()<=vect.size()) 
	{
		for(size_t i(0); i<vecteur2.size();++i)
		{
			vect[i]-=vecteur2[i];
		}
	}
	else  
	{
		while(vect.size()<vecteur2.size())
		{
			this->augmente(0);
		}
		for(size_t i(0); i<vecteur2.size();++i)
		{
			vect[i]-=vecteur2[i];
		}
	}
}
	
	
void Vecteur::operator*=(double const& scal)
{
	for(size_t i(0);i<vect.size();++i)
	{
		vect[i]=vect[i]*scal;
	}
}


void Vecteur::operator^=(Vecteur const& vect2)
{	
	vector<double> retour(3,0.0);
	vector<double> vecteur2(vect2.get_vecteur());
	
	while(vecteur2.size()<3)
	{
		vecteur2.push_back(0);
	}
	while(vecteur2.size()>3)
	{
		vecteur2.pop_back();
	}
	while(vect.size()<3)
	{
		vect.push_back(0);
	}
	while(vect.size()>3)
	{
		vect.pop_back();
	}
	retour[0]=(vect[1]*vecteur2[2]-vect[2]*vecteur2[1]);
	retour[1]=(vect[2]*vecteur2[0]-vect[0]*vecteur2[2]);
	retour[2]=(vect[0]*vecteur2[1]-vect[1]*vecteur2[0]);
			
	vect[0]=retour[0];
	vect[1]=retour[1];
	vect[2]=retour[2];
}


void Vecteur::operator=(Vecteur const& vect2)
{	
	vector<double> vecteur2(vect2.get_vecteur());	
	vect.clear();
		
	for(size_t i(0); i<vecteur2.size(); ++i)
	{		
		vect.push_back(vecteur2[i]);
	}
}
	
	
	


//opérateurs externes
std::ostream& operator<<(std::ostream& sortie, Vecteur const& vect){

	sortie<<vect.affiche();
	
	return sortie;
}


bool operator==(Vecteur const& vect1, Vecteur const& vect2)
{
	return vect1.compare(vect2);
}			


bool operator!=(Vecteur const& vect1, Vecteur const& vect2)
{
	return not(vect1.compare(vect2));	
}	

			
Vecteur operator+(Vecteur const& vect1, Vecteur const& vect2)
{
	
	Vecteur vect3(vect1);
	vect3+=vect2;
	return vect3;
	}

	
Vecteur operator-(Vecteur const& vect1, Vecteur const& vect2)
{
	Vecteur vect3(vect1);
	vect3-=vect2;
	
	return vect3;
}


Vecteur operator*(double const& scalaire, Vecteur const& vect)
{	
	Vecteur vect3(vect);
	vect3*=scalaire;
	
	return vect3;
}


Vecteur operator*(Vecteur const& vect, double const& scalaire)
{
	return scalaire*vect;
}


double operator*(Vecteur const& vecteur1, Vecteur const& vecteur2){
	
	double retour(0);
	vector<double> vect1(vecteur1.get_vecteur());
	vector<double> vect2(vecteur2.get_vecteur());
	
	if(vect1.size()==vect2.size())
		{
			for(size_t i(0);i<vect1.size();++i)
			{
				retour+=vect1[i]*vect2[i];
			}
		}
	else if(vect1.size()<vect2.size())
	{
		while(vect1.size()<vect2.size())
		{
			vect1.push_back(0);
		}
		for(size_t i(0);i<vect1.size();++i)
			{
				retour+=vect1[i]*vect2[i];
			}
	}
	else
	{
		while(vect2.size()<vect1.size())
		{
			vect2.push_back(0);
		}
		for(size_t i(0);i<vect1.size();++i)
			{
				retour+=vect1[i]*vect2[i];
			}
	}
	return retour;
}

	
Vecteur operator^(Vecteur const& vect1, Vecteur const& vect2){
	Vecteur vect3(vect1);
	vect3^=vect2;
	return vect3;
}


Vecteur operator~(Vecteur const& vect1){
	Vecteur vectr(vect1*(1/vect1.norme()));
	return vectr;
}
