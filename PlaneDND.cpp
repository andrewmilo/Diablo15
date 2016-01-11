#include "PlaneDND.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <sstream>

PlaneDND::PlaneDND( void ) : SAVE_PATH( "save.txt" ){ }

PlaneDND::~PlaneDND( void ){ delete hero; }

void PlaneDND::start( void ){
	
	get_hero();
	
	loop(); // gameplay loop
}

void PlaneDND::loop( void ){
	
	while ( true ){
		
		std::string c;
		std::cin >> c;
		
		if( this->live ){
			
			// gameplay physics/mechanics
			
		}
		
		if( c == "save" || c == "s" ) { save(); }
		else if( c == "pause" ) pause();
		else if( c == "resume" ) resume();
		else if( c == "quit" || c == "q" ) { break; }
		else if( c == "stats" ){ print_stats(); }
	}
}

inline void PlaneDND::toggle_game_state( void ){ this->live = !this->live; }

inline void PlaneDND::pause( void ){ this->live = false; }

inline void PlaneDND::resume( void ){ this->live = true; }

void PlaneDND::get_hero( void ){

	// Try to De-serialize data
	if( std::ifstream( SAVE_PATH ) )
		de_serialize();
	else create_hero();
}

inline void PlaneDND::print_stats( void ) const {
	
	std::cout 
		<< std::endl
	    << this->hero->get_name()
		<< std::endl
		<< this->hero->get_strength()
		<< std::endl
		<< this->hero->get_dexterity()
		<< std::endl
		<< this->hero->get_vitality()
		<< std::endl
		<< this->hero->get_intelligence()
		<< std::endl;
}

void PlaneDND::create_hero(){
	
	std::ofstream is( SAVE_PATH );
		
	std::cout << " ** Enter a hero name: ";
	std::string name;
	std::cin >> name;
	
	std::cout << std::endl;
	
	std::cout << " ** Select a character. **" << std::endl;
	std::cout << "    [1] Barbarian." << std::endl;
	std::cout << "    [2] Sorceress." << std::endl;
	std::cout << "    [3] Paladin." << std::endl;
	std::cout << "    [4] Necromancer." << std::endl;
	std::cout << "    [5] Amazon." << std::endl;
	std::cout << "    [6] Druid." << std::endl;
	std::cout << "    [7] Assassin." << std::endl;
	
	int choice;
	
	while( choice != 1 
		&& choice != 2 
		&& choice != 3
		&& choice != 4 ){
		
		std::cin >> choice;
	}
	
	Hero::HeroClass heroClass;
	
	if( choice == 1 )
		heroClass = Hero::BARBARIAN;
	else if( choice == 2 )
		heroClass = Hero::SORCERESS;
	else if( choice == 3 )
		heroClass = Hero::PALADIN;
	else if( choice == 4 )
		heroClass = Hero::NECROMANCER;
	else if( choice == 5 )
		heroClass = Hero::AMAZON;
	else if( choice == 6 )
		heroClass = Hero::DRUID;
	else if( choice == 7 )
		heroClass = Hero::ASSASSIN;
		
	this->hero = new Hero( name, choice, heroClass ); // construct the hero
}

void PlaneDND::de_serialize( void ){
	
	std::ifstream infile( SAVE_PATH );
	unsigned int level;
	std::vector< std::string > v;
	
	std::string line;
	std::string temp;
	while( std::getline( infile, line ) ){
		
		std::istringstream iss( line );
		
		if( !( iss >> temp ) ) break;
		
		v.push_back( temp );
	}
	
	// Get Hero Name
	const std::string name = v[ 0 ];
	
	// Get Hero Class
	const Hero::HeroClass cl = static_cast<Hero::HeroClass>( atoi( v[ 1 ].c_str() ) );
	
	// Load stats
	const unsigned int strength = atoi( v[ 2 ].c_str() );
	const unsigned int dexterity = atoi( v[ 3 ].c_str() );
	const unsigned int vitality = atoi( v[ 4 ].c_str() );
	const unsigned int intelligence = atoi( v[ 5 ].c_str() );
	
	this->hero = new Hero( name, atoi( v[ 1 ].c_str() ), cl );
}

inline void PlaneDND::save( void ){
	
	std::ofstream of( this->SAVE_PATH );
	
	if( !this->hero ) return;
	
	of << this->hero->get_name()
	   << std::endl
	   << this->hero->hero_class_id
	   << std::endl
	   << this->hero->get_strength()
	   << std::endl
	   << this->hero->get_dexterity()
	   << std::endl
	   << this->hero->get_vitality()
	   << std::endl
	   << this->hero->get_intelligence();
	   
	std::cout << std::endl;   
	std::cout << std::endl;
	std::cout << " ** [GAME SAVED] **" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
}