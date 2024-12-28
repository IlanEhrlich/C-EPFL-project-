#pragma once
#include <iostream>
#include "Vecteur.h"
#include "Integrateur.h"
#include "ObjetMobile.h"

class IntegrateurNewmark: public Integrateur{
	public :
	
	virtual void integre(ObjetMobile& obj) const override;
	
	virtual std::string affiche()const override;
	
	virtual IntegrateurNewmark* copie() const override{return new IntegrateurNewmark(*this);};
	
	
	//constructeurs
	//constructeur de copie
	IntegrateurNewmark(IntegrateurNewmark const&)=default;
	
	IntegrateurNewmark(double deltt)
	:Integrateur(deltt)
	{}
	
	//destructeur
	virtual ~IntegrateurNewmark() override = default;
};	


std::ostream& operator<<(std::ostream&, IntegrateurNewmark const&);
