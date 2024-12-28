#include <QApplication>
#include "glwidget.h"
#include "ObjetMobile.h"
#include "Pendule.h"
#include "Plan.h"
#include "Systeme.h"
#include "PortionPlan.h"
#include "Gravite.h"
#include "Brique.h"
#include "Ventilateur.h"
#include "IntegrateurNewmark.h"


using namespace std;

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);


	Systeme enfin;	
	IntegrateurNewmark in(1e-5);
	enfin.set_Integrateur(in);
																					
	Pendule salut({2.0, 0.0},{0.0, 0.0}, 0.5, 10,{0.0,0.0,0.0},{2.0,1.0,-5.0},2);
	salut.ajoute_a(enfin);
	
	 
	Plan p1({0,-2,0}, {0.0, 1.0,0.0});
	p1.ajoute_a(enfin);
	
	
	Gravite z({0,-9.81,0});
	z.ajoute_a(enfin);
	
	Vecteur q={2.0,1.0};
	Vecteur r={0.3,0.0};
	
	//Ventilateur(Vecteur const& origine, Vecteur const& Longueur, Vecteur const& largeur, double si, double V, double h)
	//Ventilateur venti({0.5,-1.0,-10.0},{-5.0,0.0,0.0},{0.0,0.0,5.0},4.0,100.0,0.5);
	
	
	Balle lol2({2.0, 6.0,-5.0},{0,0,0},0.5,10,{0,0,0});
	//lol2.ajoute_a(enfin);
	
	
	Balle lol({2.0,-1.5,-5.0},{0,0,0},0.5,10,{0,0,0});
	lol.ajoute_a(enfin);
	
	Ventilateur bri({-3, -2, -6}, {0, 3, 0}, {0, 0, 2}, 10, 30, 1);
	//bri.ajoute_a(enfin);
	
	//Balle lol2({2,2, -5},{0,2,0},0.5,10,{0,0,0});
	//lol2.ajoute_a(enfin);
		
	
	
	//Brique brique({-2, 0, -10.0}, {0, 3, 0}, {2, 0, 0},1);
	//brique.ajoute_a(enfin);
	
	
	GLWidget w(enfin);

	w.show();

	return a.exec();
	
	}
