#pragma once

#include <iostream>
#include "SupportADessin.h"



class Dessinable{
	
	public: 
	
		virtual void dessine_sur(SupportADessin& support)=0;//intérêt principal de la classe
		virtual std::string affiche()const=0;
		
		//destructeur
		virtual ~Dessinable()= default;
	
	};
