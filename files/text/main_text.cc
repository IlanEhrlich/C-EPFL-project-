#include "TextViewer.h"
#include <iostream>
#include "Pendule.h"
#include "Balle.h"
#include "Plan.h"
#include "PortionPlan.h"
#include "Brique.h"
#include "Systeme.h"

using namespace std;

int main()
{
	TextViewer txt;
	
	
	Systeme enfin({},{},{},1e-5);

	
	Balle lol({-1.5,10, -10},{0,0,0},1,1,{0,-9.81,0});
	lol.ajoute_a(enfin);

	
	Gravite z({0,-9.81,0});
	z.ajoute_a(enfin);

	Brique brique({-2, 0, -10.0}, {0, 3, 0}, {2, 0, 0},1);
	brique.ajoute_a(enfin);

	
	Plan p1({0,-2,0}, {0.0, 1.0,0.0});
	p1.ajoute_a(enfin);
	
	
	Pendule salut({3,0,0},{0,0,0}, 0.5, 0.7,{0,0,0},{2,2,-3},1.0);
	
	salut.ajoute_a(enfin);

	txt.dessine(enfin);
  return 0;
}
