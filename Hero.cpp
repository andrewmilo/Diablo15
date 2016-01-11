#include "Hero.h"

Hero::Hero( std::string name, HeroClass heroclass ) : Entity( name ){
	
	this->level = 1;
	this->strength = 5;
	this->dexterity = 5;
	this->intelligence = 5;
	this->vitality = 5;
}

Hero::~Hero( void ){ }

Hero::HeroClass Hero::get_hero_class( void ) const { return this->hero_class; }