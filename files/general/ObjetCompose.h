#pragma once

#include <iostream>
#include "Dessinable.h"

//classe de structure, elle ne possède rien à part un destructeur

class ObjetCompose: public Dessinable {
	
	public :
	
		//destructeur
		virtual ~ObjetCompose()= default;
	
};
