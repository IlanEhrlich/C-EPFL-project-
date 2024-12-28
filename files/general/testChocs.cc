#include <iostream>
#include "Vecteur.h"
#include "Obstacle.h"
#include "Plan.h"
#include "PortionPlan.h"
#include "Gravite.h"
#include "Brique.h"
#include "Balle.h"
#include "ObjetMobile.h"
#include "Pendule.h"
#include "Integrateur.h"
#include "IntegrateurEulerCromer.h"
#include "Systeme.h"

using namespace std;



int main(){

	double fo(-9.81*(0.00167784948285945-4*3.14159265*1.2*0.051111*0.051111*0.051111/3));
	Balle b({0, 0.624, 0.0465234}, {0, 0.8, -2.59108}, 0.051111, 0.00167784948285945, {0, 0, fo});
	Plan p({0, 0, 0}, {0, 0, 1});
	
	cout<<"CAS 1 :"<<endl;
	cout<<endl;
	cout<<"avant rebond sol :"<<endl;
	
	cout<<b<<endl;
	
	cout<<p<<endl;
	
	
	cout<<"apres rebond sol :"<<endl;
	
	p.agit_sur(b);
	
	cout<<b<<endl;
	
	cout<<p<<endl;
	cout<<endl;
	cout<<endl;
	
	
	cout<<"CAS 2 :"<<endl;
	cout<<endl;
	cout<<"avant rebond sol :"<<endl;
	Balle b2({0, 1.36675, 0.283821}, {0, 0.715449, 0.0957368}, 0.051111, 0.00167784948285945, {0, 0, fo});
	double fo3(-9.81*(0.1-4*3.14159265*1.2*0.05*0.05*0.05/3));
	Balle b3({0, 1.46284, 0.260128}, {0, 0.419218, 0.13874}, 0.05, 0.1, {0, 0, fo3});
	cout<<b2<<endl;
	cout<<b3<<endl;

	b2.agit_sur(b3);
	cout<<"apres rebond sol :"<<endl;
	cout<<b2<<endl;
	
	cout<<b3<<endl;
	cout<<endl;
	cout<<endl;	
	
	
	return 0;
}
