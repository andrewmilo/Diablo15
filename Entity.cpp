#include "Entity.h"

Entity::Entity( const std::string name, 
				const std::string desc ){ 
	
	this->name = name;
    this->health = 100.0f;
	this->description = desc;
}

Entity::~Entity( void ){ }

std::string Entity::get_name( void ) const { return this->name; }
std::string Entity::get_description( void ) const { return this->description; }
unsigned int Entity::get_level( void ) const { return this->level; }
int Entity::get_strength( void ) const { return this->strength; }
int Entity::get_dexterity( void ) const { return this->dexterity; }
int Entity::get_vitality( void ) const { return this->vitality; }
int Entity::get_intelligence( void ) const { return this->intelligence; }
int Entity::get_positionX( void ) const { return this->positionX; }
int Entity::get_positionY( void ) const { return this->positionY; }
int Entity::get_orientation( void ) const { return this->orientation; }

void Entity::set_strength( const int strength ) { this->strength = strength; }
void Entity::set_dexterity( const int dexterity ) { this->dexterity = dexterity; }
void Entity::set_vitality( const int vitality ) { this->vitality = vitality; }
void Entity::set_intelligence( const int intelligence ) { this->intelligence = intelligence; }
void Entity::set_positionX( const int positionX ) { this->positionX = positionX; }
void Entity::set_positionY( const int positionY ) { this->positionY = positionY; }
void Entity::set_orientation( const int orientation ) { this->orientation = orientation; }

float Entity::damage( void ) const {
    
    return this->dexterity 
         + this->strength
         + this->intelligence
         + this->vitality;
}

void Entity::attack( Entity& other ) const {
	
	other.health -= this->damage();
}

void Entity::move( const int steps, const char direction ){
	
	//this->position += 
}