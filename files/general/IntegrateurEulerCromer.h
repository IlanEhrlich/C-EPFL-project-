#pragma once
#include <iostream>
#include "Vecteur.h"
#include "Integrateur.h"
#include "ObjetMobile.h"

class IntegrateurEulerCromer: public Integrateur{
	public :
	
	virtual void integre(ObjetMobile& obj) const override;
	
	virtual std::string affiche()const override;
	
	virtual IntegrateurEulerCromer* copie() const override{return new IntegrateurEulerCromer(*this);};
	
	
	//constructeurs
	//constructeur de copie
	IntegrateurEulerCromer(IntegrateurEulerCromer const&)=default;
	
	IntegrateurEulerCromer(double deltt)
	:Integrateur(deltt)
	{}
	
	//destructeur
	virtual ~IntegrateurEulerCromer() override = default;
	
};	


std::ostream& operator<<(std::ostream&, Integrateur const&);
