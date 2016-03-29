#include "Item.h"

Item::Item( std::string name, Quality quality, Type type ){
    
    this->name = name;
    this->quality = quality;
    this->type = type;
}

std::string Item::get_name( void ) const { return name; }

void Item::set_name( std::string name ) { this->name = name; return; }

Quality Item::get_quality( void  ) const { return this->quality; }
void Item::set_quality( Quality quality ){ this->quality = quality; }
Type Item::get_type( void ) const { return this->type; }
void Item::set_type( Type type ) { this->type = type; }