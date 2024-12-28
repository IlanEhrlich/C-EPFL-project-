#include <iostream>
#include <string>

#include "Systeme.h"
#include "Dessinable.h"
#include "Pendule.h"
#include "Balle.h"
#include "Obstacle.h"
#include "Plan.h"
#include "PortionPlan.h"
#include "Vent.h"
#include "Integrateur.h"
#include "IntegrateurEulerCromer.h"
#include "Ventilateur.h"
#include "Gravite.h"

using namespace std;


int main(){
	
	Systeme sys;
	Balle balle({0.0,0.0,0.3},{0.0,0.8,2.0},0.051111,0.00167784948285945,{0.0, 0.0, -0.00987582205611073});
	balle.ajoute_a(sys);
	
	Pendule pendule(1.5,-0.5,0.05,0.1,{0.0, -0.073322623865539, -0.963268946241630},{0.0,1.4,0.45},0.2);
	pendule.ajoute_a(sys);
	
	Plan plan({0, 0, 0}, {0, 0, 1});
	plan.ajoute_a(sys);
	
	Gravite gravite({0.0,0.0,-9.81});
	gravite.ajoute_a(sys);
	
	cout<<sys<<endl;

	
	return 0;
}
