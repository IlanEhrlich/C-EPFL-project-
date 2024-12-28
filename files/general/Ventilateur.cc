#include <iostream>
#include "Ventilateur.h"

using namespace std;

string Ventilateur::affiche()const
	{
		string retour("Ventilateur, constitué d'une brique et de vent: \n\n");
	
		retour+=paroi.affiche();
		retour+=souffle.affiche();
		retour+="\n";
	
		return retour;
	}
	
//comme décrit dans le cours, il suffit d'ajouter au système chaque composante de l'objetcompose
void Ventilateur::ajoute_a(Systeme& sys)const
	{
		paroi.ajoute_a(sys);
		souffle.ajoute_a(sys);
	}


std::ostream& operator<<(std::ostream& sortie, Ventilateur const& ventilo)
	{
		sortie<<ventilo.affiche();
		return sortie;
	}
