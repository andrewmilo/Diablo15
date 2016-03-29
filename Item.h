#ifndef _ITEM_
#define _ITEM_

#include <string>
#include "Quality.h"
#include "Type.h"

class Item {

public:
    Item( std::string name, Quality quality, Type type );
    std::string get_name( void ) const;
    void set_name( std::string name );
    Quality get_quality( void  ) const;
    void set_quality( Quality quality );
    Type get_type( void ) const;
    void set_type( Type type );
    
private:
    std::string name;
    Quality quality;
    Type type;
};

#endif