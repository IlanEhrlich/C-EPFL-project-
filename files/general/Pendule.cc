#include <iostream>
#include "Pendule.h"

using namespace std;
	

Vecteur Pendule::evolution() const{
	
	double teta(p.get_coord(0));
	double teta_point(p_1st.get_coord(0));
	
	double phi_point(p_1st.get_coord(1));
	
	if (abs(phi_point)<1e-4){ //cas particulier du pendule plan: somme des forces prise en compte 
		double b(18.5e-6);
		
		Vecteur d(1,0,0);
		Vecteur y(0,-1,0);
		
		Vecteur u(cos(teta),-sin(teta),0);
		
		double somme=cos(teta)*(force*d)-sin(teta)*(force*y)-b/longueur*teta_point;
		
		Vecteur resultat(somme/(masse*longueur),0, 0);

		return resultat;
		}
		
	else{	//nous tentons ici le pendule sphérique (pas très au point)
		
		double coord1=sin(teta)*(cos(teta)*phi_point*phi_point+9.81/longueur);
		
		double coord2=-2/tan(teta)*teta_point*phi_point;
		
		Vecteur resultat(coord1,coord2, 0.0);
		
		return resultat;
		
		}

	}


Vecteur Pendule::get_position()const {
	
	double teta = p.get_coord(0);
	double phi = p.get_coord(1);

	double c1 = longueur*sin(teta)*cos(phi);
	double c2 = -longueur*cos(teta);
	double c3 = -longueur*sin(teta)*sin(phi);
	
	Vecteur retour(c1,c2,c3);
	
	return retour+position_origine;
	}
	
	
Vecteur Pendule::get_vitesse()const 
{
	double teta = p.get_coord(0);
	double teta_point = p_1st.get_coord(0);
	
	double phi = p.get_coord(1);
	double phi_point = p_1st.get_coord(1);

	double c1 = longueur*teta_point*sin(teta);
	double c2 = longueur*(teta_point*cos(teta)-phi_point*sin(teta)*sin(phi));
	double c3 = -longueur*(teta_point*cos(teta)*sin(phi)+phi_point*sin(teta)*cos(phi));
	
	Vecteur retour(c2,c1,c3);
	
	return retour;
}


Vecteur Pendule::get_force()const //cette méthode est la seule dans laquelle
{								  //nous n'avons même pas essayer d'utiliser la formule du pendule sphérique (complément math-phy)
	double P1(p.get_coord(0));	  //La formule utilisé est donc celle du pendule poliare	
	double P1p(p_1st.get_coord(0));
	double f((this->evolution()).get_coord(0));
	
	double x(f*cos(P1)-P1p*P1p*sin(P1));
	double y(f*sin(P1)+P1p*P1p*cos(P1));
	
	Vecteur retour(x, y, 0.0);
	
	return masse*longueur*retour;
	return force;
}
	
void Pendule::set_vitesse(Vecteur const& autre)
{
	double a(autre.get_coord(0));
	double b(autre.get_coord(1)); 
	double c(autre.get_coord(2));
	
	
	double teta = p.get_coord(0);
	double phi = p.get_coord(1);
	
	
	if(abs(sin(teta))>1e-4){
		
		p_1st.set_coord(0,b/(longueur*sin(teta)));
		
		if(abs(sin(phi))>1e-4){
				p_1st.set_coord(1,(p_1st.get_coord(0)*cos(teta)-a)/sin(teta)/sin(phi));
			}
		else{
				p_1st.set_coord(1,-c/sin(teta)/cos(phi)); //le cosinus et le sinus ne peuvent pas être tous deux simultanément nuls
			}
		}
	else
	{
		if(abs(sin(phi))>1e-4)
		{
			p_1st.set_coord(0, -c/(longueur*cos(teta)*sin(phi)));
		}
		else
		{
			p_1st.set_coord(0, a/(longueur*cos(teta)*cos(phi)));
		}
		p_1st.set_coord(1, 0.0);
	}
}




	
Balle Pendule::bal()const 
	{
		Vecteur po(this->get_position());
		Vecteur vi(this->get_vitesse());
		Vecteur f(this->get_force());
		Balle b(po, vi, rayon, masse, f);
		return b;
	}
	
//Pour les chocs :

void Pendule::agit_sur(ObjetMobile& x2)
	{
		Balle balle_du_pendule(this->bal());//le choc d'un pendule qui agit sur une ObjetMobile est définit comme le choc entre la balle dudit pendule et l'ObjetMobile
		balle_du_pendule.agit_sur(x2);
		Vecteur fi(this->get_force());
		this->ajoute_force(balle_du_pendule.get_force()-fi);
		this->set_vitesse(balle_du_pendule.get_vitesse());
	}
	

Vecteur Pendule::direction() const{
	
	Vecteur v(get_vitesse());
	return v*(1/v.norme());
	
	}
	

string Pendule::affiche()const{
		
	string retour("Pendule: \n\n");
	retour+=this->ObjetMobile::affiche();
	
	retour+="Position de l'origine: ";
	retour+=position_origine.affiche();
	retour+="\n";
	retour+="Longueur du fil: ";
	retour+=to_string(longueur);
	retour+="\n";
	retour+="Vecteur P: ";
	retour+=p.affiche();
	retour+="\n";
	retour+="Vecteur p_1st: ";
	retour+=p_1st.affiche();
	retour+="\n\n";
	
	
	return retour;
	
	}
	
	
ostream& operator<<(ostream& sortie, Pendule const& obj) //il y a apparemment un problème que je ne comprends pas lorsque j'essaie de le mettre en const&
{	
	sortie<<obj.affiche();

	return sortie;
}
