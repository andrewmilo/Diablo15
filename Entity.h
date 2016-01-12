#ifndef _ENTITY_
#define _ENTITY_

#include <string>

class Entity {
	
	protected:
		Entity( const std::string,
				const std::string );
	
		std::string name;
		std::string description;
		unsigned int level;
		int strength;
		int dexterity;
		int vitality;
		int intelligence;
		int positionX;
		int positionY;
		int orientation;
		
	public:
		virtual ~Entity( void );
	
		std::string get_name( void ) const;
		std::string get_description( void ) const;
		unsigned int get_level( void ) const;
		int get_strength( void ) const;
		int get_dexterity( void ) const;
		int get_vitality( void ) const;
		int get_intelligence( void ) const;
		int get_positionX( void ) const;
		int get_positionY( void ) const;
		int get_orientation( void ) const;
		
		void set_strength( const int );
		void set_dexterity( const int );
		void set_vitality( const int );
		void set_intelligence( const int );
		void set_positionX( const int );
		void set_positionY( const int );
		void set_orientation( const int );
		
		void attack( Entity& ) const;
		void move( const int steps, const char direction );
};

#endif