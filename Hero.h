#ifndef _HERO_
#define _HERO_

#include "Entity.h"

class Hero : public Entity {
	
	public:
	
		const int hero_class_id;
		enum HeroClass {
			BARBARIAN = 0,
			ASSASSIN = 1,
			PALADIN = 2,
			DRUID = 3,
			NECROMANCER = 4,
			SORCERESS = 5,
			AMAZON = 6
		};
		
		HeroClass get_hero_class( void ) const;
		
		Hero( const std::string, 
			  const std::string, 
			  const int, 
			  const HeroClass );
		~Hero( void );
	private:
	
		HeroClass hero_class;
};

#endif