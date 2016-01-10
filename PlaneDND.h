#ifndef _PLANEDND_
#define _PLANEDND_

#include "Hero.h"

class PlaneDND {
	
	private:
		Hero* hero;
	
	public:
		void start( void );
		void get_hero( void );
		void de_serialize( void );
		void create_hero( void );
		PlaneDND();
		~PlaneDND();
};

#endif