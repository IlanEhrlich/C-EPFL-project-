#include <iostream>
#include "Systeme.h"

#include "SupportADessin.h"
using namespace std;


string Systeme::affiche()const{
	
	//On a distingué les trois catégories
	
	string retour("Notre système contient:\n\n");

	retour+="\nComme obstacles: \n";
	for(auto const& ptr_obs:ptr_Obstacle){
		retour+="-";
		retour+=ptr_obs->affiche();
		retour+="\n";
		}
		
	retour+="\nComme objets mobiles: \n";
	for(auto const& ptr_obj:ptr_ObjetMobile){
		retour+="-";
		retour+=ptr_obj->affiche();
		retour+="\n";
		}
		
	retour+="\nComme champs de force: \n";
	for(auto const& ptr_ch:ptr_ChampForces){
		retour+="-";
		retour+=ptr_ch->affiche();
		retour+="\n";
		}
		
	retour+="Utilisés avec l'intégrateur:\n";
	retour+=ptr_Integrateur->affiche();
	retour+="\n\n";
		
	return retour;

	}
	
void Systeme::CF_affiche()const
{
	cout<<"Les forces du système sont:\n"<<endl;
	for(size_t i(0);i<ptr_ChampForces.size();++i)
		{cout<<i+1<<") "<<ptr_ChampForces[i]->affiche();}

	
	}
	
void Systeme::dessine_sur(SupportADessin& support) //seule définition de dessine_sur indépendante de dessine, voir explication dans les réponses 
{
	for(auto const&ptr_obs:ptr_Obstacle)
		{ptr_obs->dessine_sur(support);}
		
	for(auto const&ptr_obj:ptr_ObjetMobile)
		{ptr_obj->dessine_sur(support);}
					
	for(auto const&ptr_ch:ptr_ChampForces)
		{ptr_ch->dessine_sur(support);}
}

void Systeme::set_dt(double dt){ptr_Integrateur->set_dt(dt);}

void Systeme::evolue()
{ 	//organsiation des chocs : chaque objet mobile va être confronté à tous les autres objets mobiles (qu'une fois, c'est pourquoi j commence à i+1, ligne 84), à chaque champ de forces et à chaque obstacle
	for(size_t i(0); i<ptr_ObjetMobile.size(); ++i)
	{
		ptr_ObjetMobile[i]->set_force({0, 0, 0});
		
		for(size_t k(0);k<ptr_ChampForces.size();++k)
		{
			ptr_ChampForces[k]->agit_sur(*ptr_ObjetMobile[i]); 
		} 
		for(auto const&h:ptr_Obstacle)
			{h->agit_sur(*ptr_ObjetMobile[i]);}
		
		for(size_t j(i+1); j<ptr_ObjetMobile.size();++j)
			{ptr_ObjetMobile[j]->agit_sur(*ptr_ObjetMobile[i]);}
		
		ptr_ObjetMobile[i]->evolue(*ptr_Integrateur); //on finit par faire évoluer les objets mobiles
	}
}
	

void Systeme::set_Integrateur(Integrateur const& inte){ptr_Integrateur=unique_ptr<Integrateur>(inte.copie());}

ostream& operator<<(ostream& sortie, Systeme const& systeme)
{
	sortie<<systeme.affiche();
	return sortie;
}
