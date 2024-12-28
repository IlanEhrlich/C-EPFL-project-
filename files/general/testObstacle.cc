#include <iostream>
#include "Vecteur.h"
#include "Obstacle.h"
#include "Plan.h"
#include "PortionPlan.h"
#include "Brique.h"
#include "Balle.h"
#include "ObjetMobile.h"

using namespace std;

int main(){
	
	
	cout<<"Nous avons:"<<endl;
	Plan plan({0, 0, 0}, {0, 0, 1});
	Brique brique({0, 0, 0.5}, {0, -0.6, 0}, {0.8, 0, 0},0.5);
	Balle balle({1.2, -0.4, 0.3}, {0, 0, 0}, 0.2, 0.100530964914873, {0, 0, -0.591725259488945});
	
	cout<<plan<<endl;
	cout<<brique<<endl;
	cout<<balle<<endl;
	
	cout<<"tests :"<<endl;
	
	cout<<plan.point_plus_proche(balle)<<"#point plus proche plan"<<endl;
	cout<<plan.distance(balle)<<"#distance plan"<<endl;
	cout<<brique.point_plus_proche(balle)<<"#point plus proche brique"<<endl;
	cout<<brique.distance(balle)<<"#distance brique"<<endl;
	
	cout<<"je déplace la balle en : 1.2 -0.4 1.3"<<endl;
	balle.set_p({1.2, -0.4, 1.3});
	cout<<balle<<endl;
	
	cout<<"tests :"<<endl;
	
	cout<<plan.point_plus_proche(balle)<<"#point plus proche plan"<<endl;
	cout<<plan.distance(balle)<<"#distance plan"<<endl;
	cout<<brique.point_plus_proche(balle)<<"#point plus proche brique"<<endl;
	cout<<brique.distance(balle)<<"#distance brique"<<endl;
	
	cout<<"je déplace la balle en : 0.2 -0.4 1.3"<<endl;
	balle.set_p({0.2, -0.4, 1.3});
	cout<<balle<<endl;
	
	cout<<"tests :"<<endl;
	
	cout<<plan.point_plus_proche(balle)<<"#point plus proche plan"<<endl;
	cout<<plan.distance(balle)<<"#distance plan"<<endl;
	cout<<brique.point_plus_proche(balle)<<"#point plus proche brique"<<endl;
	cout<<brique.distance(balle)<<"#distance brique"<<endl;	

	Vecteur x(plan.point_plus_proche(balle));
	cout<<x<<endl;
	double dx(plan.distance(balle));			//TESTOBSCTACLE
	cout<<dx<<endl;
	cout<<endl;
	
	
	
	Vecteur y(brique.point_plus_proche(balle));
	
	
	cout<<y<<endl;
	double dy(brique.distance(balle));
	cout<<dy<<endl;
	cout<<endl;
		
	return 0;
	}
