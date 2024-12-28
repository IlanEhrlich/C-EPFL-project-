#include <iostream>
#include "Vecteur.h"
#include "ChampForces.h"
#include "constantes.h"
#include "Gravite.h"
#include "Vent.h"
#include "Balle.h"


using namespace std;


int main(){


	Gravite champ_gravitationnel(g);//apparement faut vrmt laisser ces brackets
	
	//cout<<champ_gravitationnel<<endl;
	
	Vent brise({0,0,0},{1,0,0},{0,1,0},1,4);
	
	cout<<brise<<endl;
	
	Balle bonjour({0.5,0.5,0.5},{0,0,0}, 2.3, 3.4, {0,0,0});

	brise.agit_sur(bonjour);
	cout<<bonjour<<endl;

	return 0;
}
