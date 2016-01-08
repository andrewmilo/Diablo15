#include "Entity.h"

Entity::Entity( std::string name ){ 
	
	this->name = name;
}

Entity::~Entity( void ){ }

void Entity::attack( Entity& other ) const {
	
	//other.health -= this->strength;
}

void Entity::move( const int steps, const char direction ){
	
	//this->position += 
}