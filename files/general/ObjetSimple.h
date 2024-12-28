#pragma once

#include <iostream>
#include "Dessinable.h"

//classe de structure: elle ne possède rien à part un destructeur
class ObjetSimple: public Dessinable {
	
	public :

		//destructeur
		virtual ~ObjetSimple()= default;
};
