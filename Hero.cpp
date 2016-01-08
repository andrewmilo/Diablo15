#include "Hero.h"

Hero::Hero( std::string name ) : Entity( name ){
	
	this->level = 1;
	this->strength = 5;
	this->dexterity = 5;
	this->intelligence = 5;
	this->vitality = 5;
}

Hero::~Hero( void ){ }