#include "Item.h"

Item::Item( std::string name, Quality quality, Type type, bool soulbound=0 ){
    
    this->name = name;
    this->durability = 100.0f;
    this->quality = quality;
    this->type = type;
    this->soulbound = soulbound;
}

std::string Item::get_name( void ) const { return name; }
Type Item::get_type( void ) const { return this->type; }
Quality Item::get_quality( void  ) const { return this->quality; }

void Item::set_name( std::string name ) { this->name = name; }
void Item::set_quality( Quality quality ){ this->quality = quality; }
void Item::set_type( Type type ) { this->type = type; }