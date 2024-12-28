#pragma once 

#include <iostream>
#include <memory>
#include <vector>

#include "Dessinable.h"
#include "SupportADessin.h"
#include "Integrateur.h"
#include "IntegrateurEulerCromer.h"

#include "ObjetMobile.h"
#include "Obstacle.h"
#include "ChampForces.h"

//on remarquera que pour éviter les doubles inclusions, on n'inclut surtout pas les classes filles, et seulement les trois classes mères de ObjetSimple


class Systeme: public Dessinable{

	public: 
	
		void ajoute(ObjetMobile const& om){ptr_ObjetMobile.push_back(std::unique_ptr<ObjetMobile>(om.copie()));} //ici on utilise la copie polymorphique de l'ObjetSimple que l'on veut ajouter au systeme 
		void ajoute(Obstacle const& obs){ptr_Obstacle.push_back(std::unique_ptr<Obstacle>(obs.copie()));}		//et on push_back la collection correspondante avec un pointeur pointant sur ledit ObjetSimple
		void ajoute(ChampForces const& cf){ptr_ChampForces.push_back(std::unique_ptr<ChampForces>(cf.copie()));}
		
		void set_dt(double); //utile pour le graohisme, changer le pas de temps à chaque tour de boucle 
		void evolue();
		
		virtual std::string affiche()const override;
		void CF_affiche()const; //affichage des champs de force uniquement, utile pour l'initialisaiton de la page dans glwidget
		
		virtual void dessine_sur(SupportADessin&) override;
		
		void set_Integrateur(Integrateur const&);
		
		//constructeurs
		//constructeur de copie
		Systeme(Systeme const& sys)
		: ptr_Obstacle(), ptr_ObjetMobile(), ptr_ChampForces(), ptr_Integrateur()
		{
			for(size_t i(0); i<sys.ptr_ChampForces.size(); i++)
			{ptr_ChampForces.push_back(std::unique_ptr<ChampForces>(sys.ptr_ChampForces[i]->copie()));}
			for(size_t i(0); i<sys.ptr_Obstacle.size(); i++)				
			{ptr_Obstacle.push_back(std::unique_ptr<Obstacle>(sys.ptr_Obstacle[i]->copie()));}		//copie profonde
			for(size_t i(0); i<sys.ptr_ObjetMobile.size(); i++)
			{ptr_ObjetMobile.push_back(std::unique_ptr<ObjetMobile>(sys.ptr_ObjetMobile[i]->copie()));}
			
			ptr_Integrateur=std::unique_ptr<Integrateur>(sys.ptr_Integrateur->copie());
			}
		
		Systeme(std::vector<Obstacle*> obst={}, std::vector<ObjetMobile*> objs={}, std::vector<ChampForces*> chmp={}, Integrateur* inte=nullptr) 	//On ne peut pas recevoir un tableau d'instences d'une classe abstraite en argument
		: ptr_Obstacle(), ptr_ObjetMobile(), ptr_ChampForces(), ptr_Integrateur(std::unique_ptr<Integrateur>(inte))									//On donne néamoins ici la possibilité d'initialiser un systeme avec des tableau de pointeurs d'ObjetSimple
		{																																			//Si l'utilisateur ne souhaite pas manipuler des pointeurs, il peut simplement utiliser le constructeur et ajouter les ObjetSimple avec ajoute ou ajoute_a
			if (ptr_Integrateur==nullptr){ptr_Integrateur=std::unique_ptr<IntegrateurEulerCromer>(new IntegrateurEulerCromer(1e-5));}
			
			for(size_t i(0); i<chmp.size(); i++){this->ajoute(*chmp[i]);}
			for(size_t i(0); i<obst.size(); i++){this->ajoute(*obst[i]);}
			for(size_t i(0); i<objs.size(); i++){this->ajoute(*objs[i]);}
		}
		
		Systeme(std::vector<Obstacle*> obst, std::vector<ObjetMobile*> objs, std::vector<ChampForces*> chmp, double dt)
		: ptr_Obstacle(), ptr_ObjetMobile(), ptr_ChampForces(), ptr_Integrateur(std::unique_ptr<IntegrateurEulerCromer>(new IntegrateurEulerCromer(dt)))
		{
			for(size_t i(0); i<chmp.size(); i++){this->ajoute(*chmp[i]);}
			for(size_t i(0); i<obst.size(); i++){this->ajoute(*obst[i]);}
			for(size_t i(0); i<objs.size(); i++){this->ajoute(*objs[i]);}
		}
		
		//destructeur 
		virtual ~Systeme() override =default;
		
	private:
		
		//Nous avons décidé de rassembler les composantes selon ces trois catégories
		std::vector<std::unique_ptr<Obstacle>> ptr_Obstacle;
		std::vector<std::unique_ptr<ObjetMobile>> ptr_ObjetMobile;
		std::vector<std::unique_ptr<ChampForces>> ptr_ChampForces;
		
		std::unique_ptr<Integrateur> ptr_Integrateur;
		
};

std::ostream& operator<<(std::ostream& sortie, Systeme const&);
