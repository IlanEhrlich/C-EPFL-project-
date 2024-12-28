#include <iostream>
#include "PortionPlan.h"

using namespace std;

Vecteur PortionPlan::point_plus_proche(ObjetMobile const& x)const 
{
	
	Vecteur eL(L*(1/L.norme()));
	
	Vecteur el(l*(1/l.norme()));
	
	Vecteur x2(x.get_position()+((O-x.get_position())*normal)*normal);
	
	double xkL((x2-O)*eL);
	double xkl((x2-O)*el);
	
	if(xkL>L.norme())
	{x2=x2-(xkL-L.norme())*eL;}
	else if(xkL<0)
	{x2=x2-xkL*eL;}
	
	if(xkl>l.norme())
	{x2=x2-(xkl-l.norme())*el;}
	else if(xkl<0)
	{x2=x2-xkl*el;}
	
	return x2;
}


string PortionPlan::affiche()const{
	
	string retour("Portion de Plan:\n\n");
	retour+=this->Plan::affiche();
	
	
	//retour+="Origine: ";
	//retour+=O.affiche();
	retour+="Longueur: ";
	retour+=L.affiche();
	retour+="\nLargeur: ";
	retour+=l.affiche();
	//retour+="\nNormale:";
	//retour+=normal.affiche();
	
	return retour;
	
	}

ostream& operator<<(ostream& sortie, PortionPlan const& portionplan) //il y a apparemment un problème que je ne comprends pas lorsque j'essaie de le mettre en const&
{
	sortie<<portionplan.affiche();	
	return sortie;
}
