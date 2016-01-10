#ifndef _PLANEDND_
#define _PLANEDND_

#include "Hero.h"

class PlaneDND {
	
	private:
		Hero* hero;
	
	public:
		void start( Hero* );
		PlaneDND();
		~PlaneDND();
};

#endif