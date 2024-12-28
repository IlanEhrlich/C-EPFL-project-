#include <iostream>
#include "Pendule.h"
#include "Vecteur.h"

using namespace std;

int main(){

	Vecteur posdep(-1,0,0);
	Vecteur vit(0,0,-1);
	
	
	Pendule salut(posdep, vit, 0.5, 0.7);
	
	cout<<salut<<endl;
	
	return 0;

}
