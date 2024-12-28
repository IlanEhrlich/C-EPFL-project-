#pragma once 

#include <iostream>
#include "SupportADessin.h"
#include "Pendule.h"
#include "Balle.h"
#include "Plan.h"
#include "PortionPlan.h"
#include "Brique.h"
#include "Gravite.h"
#include "Vent.h"
#include "Systeme.h"
#include "Ventilateur.h"


class TextViewer: public SupportADessin{

	public:
	
	//il est ici impossible d'éviter la dupplication de code, étant donné que toutes ces méthodes ont été déclarées virtuellement dans SupportADessin.h

		virtual void dessine(Pendule &)override;
		virtual void dessine(Balle &) override;
		virtual void dessine(Plan &) override;
		virtual void dessine(Brique &) override;
		virtual void dessine(PortionPlan &) override;	
		virtual void dessine(Gravite &) override;
		virtual void dessine(Systeme & sys) override{sys.dessine_sur(*this);};
		virtual void dessine(Vent &) override;
		virtual void dessine(Ventilateur &) override;		
	
		virtual ~TextViewer() override = default;

};		

