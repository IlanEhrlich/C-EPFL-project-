#pragma once

#include <iostream>


//méthode du forward declaration au lieu de include: impossible d'importer ces classes qui elles-mêmes importent supportadessin, éviter la dépendance mutuelle

class Pendule;
class Balle;
class Plan;
class PortionPlan;
class Brique;
class Gravite;
class Vent;
class Ventilateur;
class Obstacle;
class ObjetMobile;
class ChampForces;
class Systeme;


class SupportADessin{

	public:
		
		//on remarquera que seules les méthodes dessine sur classes non-abstraites sont définies ; aucun besoin pour champforces, obstacle et objetmobile
		//nous avions pensé les coder en const&, mais l'exemple du cours le donnait juste en référence (p8)
		
		virtual void dessine(Pendule &)=0;
		virtual void dessine(Balle &)=0;
		virtual void dessine(Plan &)=0;
		virtual void dessine(Brique &)=0;
		virtual void dessine(PortionPlan &)=0;
		virtual void dessine(Gravite &)=0;
		virtual void dessine(Vent &)=0;
		virtual void dessine(Ventilateur &)=0;
		virtual void dessine(Systeme&)=0;
		
		//pas de constructeurs : aucun attribut, et peu en commun entre vueopengl et textviewer
		
		//destructeur
		virtual ~SupportADessin() = default;
		
};
