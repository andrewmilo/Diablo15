#include "Enemy.h"

Enemy::Enemy( void ){ }
Enemy::Enemy( Entity& enemy, int variance ){
	
	this->strength = enemy.strength + variance;
	this->dexterity = enemy.dexterity + variance;
	this->vitality = enemy.vitality + variance;
	this->intelligence = enemy.intelligence + variance;
}
Enemy::~Enemy( void ){ }