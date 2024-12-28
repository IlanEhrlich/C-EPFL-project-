#include <iostream>
#include "Vecteur.h"
#include "ChampForces.h"

using namespace std;

void ChampForces::set_intensite(Vecteur valeur){
		intensite=valeur;}


string ChampForces::affiche()const{
	
	string retour("Intensité: ");
	retour+=intensite.affiche();
	retour+="\n";
	
	return retour;
	
	}
