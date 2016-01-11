#ifndef _HERO_
#define _HERO_

#include "Entity.h"

class Hero : public Entity {
	
	public:
	
		const int hero_class_id;
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
		Hero( const std::string, const int, HeroClass );
		~Hero( void );
	private:
	
		HeroClass hero_class;
};

#endif