#include <iostream>
#include "Ventilateur.h"
#include "Balle.h"

using namespace std;


int main(){
	
	Ventilateur ikea({0,0,0},{1,0,0},{0,1,0},1,4,0.5);
	
	Balle bonjour({0.5,0.5,0.5},{0,0,0}, 2.3, 3.4, {0,0,0});
	
	ikea.agit_sur(bonjour);
	
	cout<<ikea<<"agit sur:"<<endl;
	
	cout<<bonjour<<endl;
	
	return 0;
	}




