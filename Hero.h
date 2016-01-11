#ifndef _HERO_
#define _HERO_

#include "Entity.h"

class Hero : public Entity {
	
	public:
	
		enum HeroClass {
			BARBARIAN = 0,
			ASSASSIN,
			PALADIN,
			DRUID,
			NECROMANCER,
			SORCERESS,
			AMAZON
		};
		
		HeroClass get_hero_class( void ) const;
		Hero( std::string, HeroClass );
		~Hero( void );
	private:

		HeroClass hero_class;
};

#endif