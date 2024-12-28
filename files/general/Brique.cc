#include <iostream>
#include "Brique.h"

using namespace std;


Vecteur Brique:: point_plus_proche(ObjetMobile const& x)const{
	Vecteur x2(Face[0].point_plus_proche(x));

	for(size_t i(1); i<Face.size(); i++)
	{
		Vecteur test(Face[i].point_plus_proche(x));
		
		Vecteur dxx2(x.get_position()-x2);
		Vecteur dxtest(x.get_position()-test);
		double distxx2(dxx2.norme());
		double distxtest(dxtest.norme());
		
		if(distxtest<distxx2)
		{
			x2=test;
		}
	}
	
	return x2;
}


string Brique::affiche()const{
	
	string retour("Brique:\n\n");
	retour+=this->Obstacle::affiche();
	
	retour+="Longueur: ";
	retour+=L.affiche();
	retour+="\n";
	retour+="Largeur: ";
	retour+=l.affiche();
	retour+="\n";
	retour+="Hauteur: ";
	retour+=to_string(h);
	retour+="\n";
	
	return retour;
	
	
	}	

ostream& operator<<(ostream& sortie, Brique const& bri) 
{
	sortie<<bri.affiche();	
	return sortie;
}

