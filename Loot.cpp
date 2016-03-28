#include "Loot.h"

Loot::Loot( std::string name, Quality quality, Type type ){

    this->name = name;
    this->quality = quality;
    this->type = type;
}

Loot::~Loot( void ){ }