#include <iostream>
#include "ObjetMobile.h"
#include "Balle.h"
#include "Pendule.h"
#include "Gravite.h"
#include "IntegrateurEulerCromer.h"

using namespace std;


//les tests ne peuvent pas correspondre, on ne nous donne ni le pas de temps ni le rayon du pendule

int main(){

	Gravite grav({0.0,-9.81,0.0});
	Pendule pend(0.4,0.0,0.01,0.1,{0.0,-9.81,0.0},{0.0,2.0,1.0},0.2);
	IntegrateurEulerCromer inte(0.1);
	
	cout<<"Nous avons :"<<endl;
	cout<<"Un champ de forces:"<<grav<<endl;
	cout<<"Un pendule\n"<<pend<<pend.get_position()<<endl;
	
	for(int i(1); i<20;++i){
		
		cout<<"L'intégration "<<i<<" donne: "<<endl;
		inte.integre(pend);
		cout<<pend<<endl;
		
		}
	
	return 0;

}
