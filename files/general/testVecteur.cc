#include <iostream> 
#include <cmath>
#include <vector>
#include "Vecteur.h"

using namespace std;



int main(){
		
	Vecteur vect1(1.0);
	Vecteur vect2(2.6);
	

	vect1.augmente(0.0); 
	vect1.augmente(-0.1);
	vect1.set_coord(1, 2.0); 
	
	Vecteur vect3=vect1;
	cout << "Vecteur 1 : ";
	cout<<vect1 << endl;
	cout << vect2 << endl;
	cout << "Le vecteur 1 est ";
	if (vect1.compare(vect2)) {
	cout << "égal au";
	} else {
	cout << "différent du";
	}
	cout << " vecteur 2," << endl << "et est ";
	if (not vect1.compare(vect3)) {
	cout << "différent du";
	} else {
	cout << "égal au";
	}
	cout << " vecteur 3." << endl;

	
	
	return 0;
	}
