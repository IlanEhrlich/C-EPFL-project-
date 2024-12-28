#include <iostream>
#include <cmath>
#include "Integrateur.h"
#include "IntegrateurRungeKutta.h"
#include "Balle.h"
#include "Vecteur.h"
#include "ObjetMobile.h"
#include "constantes.h"
#include "Pendule.h"

using namespace std;



int main(){
	
	IntegrateurRungeKutta inte(0.01);
	
	Vecteur p(0, 1);
	Vecteur p_1st(1, 2);
	Vecteur f(0, -9.81);
	Balle bal(p, p_1st, 1, 1, f);
	
	double t(0);
	cout<<"temps : "<<t<<endl;
		cout<<bal<<endl;	
		
	
	while(t<0.7)				//POUR TESTINTEGRATEUR2
	{
		inte.integre(bal);
		
		t=t+inte.get_dt();
		cout<<"temps : "<<t<<endl;
		cout<<bal<<endl;		
		
	}
	return 0;
	
	
	}

