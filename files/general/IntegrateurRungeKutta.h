#pragma once
#include <iostream>
#include "Vecteur.h"
#include "Integrateur.h"
#include "ObjetMobile.h"

class IntegrateurRungeKutta: public Integrateur{
	public :
	//Atention cet intégrateur n'a pas été correctement testé
	virtual void integre(ObjetMobile& obj) const override;
	
	virtual std::string affiche()const override;
	
	virtual IntegrateurRungeKutta* copie() const override{return new IntegrateurRungeKutta(*this);};
	
	
	//constructeurs
	//constructeur de copie
	IntegrateurRungeKutta(IntegrateurRungeKutta const&)=default;
	
	IntegrateurRungeKutta(double deltt)
	:Integrateur(deltt)
	{}
	
	//destructeur
	virtual ~IntegrateurRungeKutta() override = default;
};	


std::ostream& operator<<(std::ostream&, IntegrateurRungeKutta const&);
