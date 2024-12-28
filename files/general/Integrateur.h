#pragma once
#include <iostream>
#include "Vecteur.h"
#include "ObjetMobile.h"

class Integrateur{
	public :
		
		virtual std::string affiche()const=0;
		
		virtual void integre(ObjetMobile & obj) const = 0;
		
		virtual Integrateur* copie() const =0;
		
		double get_dt()const{return dt;}
		void set_dt(double delt){dt=delt;} //utile dans GLwidget.cc
		
		//constructeur
		//constructeur de copie 
		Integrateur(Integrateur const&)=default;
		
		Integrateur(double deltt=1e-5)
		:dt(deltt)
		{
			if(deltt<=0)
			{
				dt=1e-5;
			}
		}
		
		//destructeur
		virtual ~Integrateur()=default;
		
	protected :
		double dt;
};	

