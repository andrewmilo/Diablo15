#ifndef _ITEM_
#define _ITEM_

#include <string>
#include "Quality.h"
#include "Type.h"

class Item {

public:

    Item( std::string, Quality, Type, bool );
    
    std::string get_name( void ) const;
    Quality get_quality( void  ) const;
    Type get_type( void ) const;
    float get_durability( void ) const;
    
    void set_name( std::string name );
    void set_quality( Quality quality );
    void set_type( Type type );
    void set_durability( float );
    
private:
    std::string name;
    float durability;
    bool soulbound;
    Quality quality;
    Type type;
};

#endif