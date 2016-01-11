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
		inline void save( void );
		void loop( void );
		inline void toggle_game_state( void );
		inline void print_stats( void ) const;
		inline void pause( void );
		inline void resume( void );
		PlaneDND();
		~PlaneDND();
};

#endif