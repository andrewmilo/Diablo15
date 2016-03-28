#include "PlaneDND.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <sstream>

PlaneDND::PlaneDND( void ) : SAVE_PATH( "save.txt" ){ welcome(); }

PlaneDND::~PlaneDND( void ){ delete hero; }

void PlaneDND::welcome( void ){
	
	std::cout << std::endl
			  << " **                                    **"
			  << std::endl
			  << " ** Welcome to Diablo 1.5. blizzardtm, lmao. **" 
			  << std::endl
			  << " **                                    **"
			  << std::endl;
}

void PlaneDND::start( void ){
	
	get_hero();
	
	loop(); // gameplay loop
}

void PlaneDND::loop( void ){
	
	std::string c;
	
	while ( true ){
		
		std::cout << "> ";
		std::cin >> c;
		
		if( c == "save" || c == "s" ) { save(); }
		else if( c == "pause" ) pause();
		else if( c == "resume" ) resume();
		else if( c == "quit" || c == "q" ) { break; }
		else if( c == "stats" ){ print_stats(); }
		else if( c == "help" ){ print_help(); }
		else if( this->live ){
			
			// gameplay physics/mechanics
			
			const unsigned int level = this->hero->get_level();
			
			const int level_range = 2;
			
			
			
			//if(  )
			
			print_message( "Press Enter for next turn.", 1, 1 );
			this->set_turn( this->get_turn() + 1 ); // next turn
		}
	}
}

inline void PlaneDND::toggle_game_state( void ){ this->live = !this->live; }

inline void PlaneDND::print_help( void ) const { 
	
	print_message( "Commands", 1, 1 );
	std::cout << " save, s -- Saves the game. "
			  << std::endl
			  << " pause   -- pauses the game. "
			  << std::endl
			  << " resume  -- resumes the game. "
			  << std::endl
			  << " quit, q -- quits the game. "
			  << std::endl
			  << " stats   -- displays the stats of the character. "
			  << std::endl
			  << " help    -- displays help "
			  << std::endl << std::endl;
}

inline void PlaneDND::pause( void ){
	 
	this->live = false; 
	print_message( "GAME PAUSED", 2, 2 );
}

inline void PlaneDND::resume( void ){
	
	 this->live = true;
	 print_message( "GAME RESUMED", 2, 2 );
}

void PlaneDND::print_message( const std::string msg, 
							  int before, 
							  int after ) const {
								 
	 while( before-->0 ){ std::cout << std::endl; }
	 std::cout << " ** [" + msg + "] **" << std::endl;
	 while( after-->0 ){ std::cout << std::endl; }
}

void PlaneDND::get_hero( void ){

	// Try to De-serialize data
	if( std::ifstream( SAVE_PATH ) )
		de_serialize();
	else create_hero();
}

inline void PlaneDND::print_stats( void ) const {
	
	std::cout 
		<< std::endl
	    << "  name: " << this->hero->get_name()
		<< std::endl
		<< "  class: " << static_cast<Hero::HeroClass>( this->hero->hero_class_id )
		<< std::endl
		<< "  strength: " << this->hero->get_strength()
		<< std::endl
		<< "  dexterity: " << this->hero->get_dexterity()
		<< std::endl
		<< "  vitality: " << this->hero->get_vitality()
		<< std::endl
		<< "  intelligence: " << this->hero->get_intelligence()
		<< std::endl << std::endl;
}

void PlaneDND::create_hero(){
	
	std::ofstream is( SAVE_PATH );
		
	std::cout << " ** Enter a hero name: ";
	std::string name;
	std::getline( std::cin, name );
	
	std::cout << " ** Enter a hero description: ";
	std::string desc;
	std::getline( std::cin, desc );
	
	std::cout << std::endl;
	
	std::cout << " ** Select a character. **" << std::endl;
	std::cout << "    [1] Barbarian." << std::endl;
	std::cout << "    [2] Assassin." << std::endl;
	std::cout << "    [3] Paladin." << std::endl;
	std::cout << "    [4] Druid." << std::endl;
	std::cout << "    [5] Necromancer." << std::endl;
	std::cout << "    [6] Sorceress." << std::endl;
	std::cout << "    [7] Amazon." << std::endl << std::endl;
	
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
		
	this->hero = new Hero( name, desc, choice, heroClass ); // construct the hero
}

void PlaneDND::de_serialize( void ){
	
	std::ifstream infile( SAVE_PATH );
	unsigned int level;
	std::vector< std::string > v;
	
	std::string line;
	std::string temp;
	while( std::getline( infile, line ) ){

		v.push_back( line );
	}
	
	if( v.empty() ){
		 create_hero();
		 return;
	}
	
	// Get Hero Name
	const std::string name = v[ 0 ];
	print_message( "WELCOME BACK " + name, 1, 2 );
	
	// Hero Description
	const std::string desc = v[ 1 ];
	print_message( desc, 0, 2 );
	
	// Get Hero Class
	const Hero::HeroClass cl = static_cast<Hero::HeroClass>( atoi( v[ 2 ].c_str() ) );
	
	// Load stats
	const unsigned int strength = atoi( v[ 3 ].c_str() );
	const unsigned int dexterity = atoi( v[ 4 ].c_str() );
	const unsigned int vitality = atoi( v[ 5 ].c_str() );
	const unsigned int intelligence = atoi( v[ 6 ].c_str() );
	
	this->hero = new Hero( name, desc, atoi( v[ 1 ].c_str() ), cl );
	this->hero->set_strength( strength );
	this->hero->set_dexterity( dexterity );
	this->hero->set_vitality( vitality );
	this->hero->set_intelligence( intelligence );
}

inline void PlaneDND::save( void ){
	
	std::ofstream of( this->SAVE_PATH );
	
	if( !this->hero ) return;
	
	of << this->hero->get_name()
	   << std::endl
	   << this->hero->get_description()
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

	print_message( "GAME SAVED", 2, 2 );
}

unsigned int PlaneDND::get_turn( void ) const { return this->turn; }
void PlaneDND::set_turn( unsigned int i ){ this->turn=i; }