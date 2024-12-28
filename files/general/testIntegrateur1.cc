#include <iostream>
#include "Integrateur.h"
#include "IntegrateurEulerCromer.h"
#include "Balle.h"
#include "Vecteur.h"
#include "ObjetMobile.h"
#include "constantes.h"
#include "Pendule.h"

using namespace std;



int main(){
	
	/*
	double t(0);
	Vecteur v1({0, 1});
	Vecteur v2({1, 2});
	Vecteur v3({0, -9.81*0.127});
	
	Balle bal(v1, v2, 0.01, 0.127, v3); 
	IntegrateurEulerCromer inte(0.01);
	
	cout<<"temps : "<<t<<endl;
		cout<<bal<<endl;	
		
	
	while(t<0.02)				//POUR TESTINTEGRATEUR1
	{
		inte.integre(bal);
		
		t=t+inte.get_dt();
		cout<<"temps : "<<t<<endl;
		cout<<bal<<endl;		
		
	}*/
	
	double t(0);
	
	Balle bal({0, 0, 0}, {0, 0.1, 0.2}, 0.2, 0.100530964914873, {0, 0, -0.591725259488945}); 
	IntegrateurEulerCromer inte(0.01);
	
	cout<<"temps : "<<t<<endl;
		cout<<bal<<endl;	
		
	
	while(t<0.04)				//POUR TESTINTEGRATEUR2
	{
		inte.integre(bal);
		
		t=t+inte.get_dt();
		cout<<"temps : "<<t<<endl;
		cout<<bal<<endl;		
		
	}
	
	
	return 0;
	
	
	}

