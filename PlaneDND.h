#ifndef _PLANEDND_
#define _PLANEDND_

#include "Hero.h"

class PlaneDND {
	
	private:
		Hero* hero;
		const char* SAVE_PATH;
		volatile bool live;
	
	public:
		void start( void );
		void get_hero( void );
		void de_serialize( void );
		void create_hero( void );
		void save( void );
		void loop( void );
		void toggle_game_state( void );
		void print_stats( void ) const;
		PlaneDND();
		~PlaneDND();
};

#endif