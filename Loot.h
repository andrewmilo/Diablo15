#ifndef _LOOT_
#define _LOOT_

#include <string>
#include "Quality.h"
#include "Type.h"

class Loot {
	
public:
    Loot( std::string name, Quality quality, Type type );
    ~Loot( void );
    
private:
    std::string name;
	Quality quality;
	Type type;
};

#endif