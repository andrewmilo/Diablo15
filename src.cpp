#include <iostream>
#include <string>
#include "PlaneDND.h"

int main(){
	
	// Create game
	PlaneDND planeDND;
	
	std::cout << " ** Welcome to Diablo 1.5. blizzardtm. **" << std::endl;
	
	std::cout << std::endl;
	
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
		heroClass = Hero::HeroClass.BARBARIAN;
	else if( choice == 2 )
		heroClass = Hero::HeroClass.SORCERCESS;
	else if( choice == 3 )
		heroClass = Hero::HeroClass.PALADIN;
	else if( choice == 4 )
		heroClass = Hero::HeroClass.NECROMANCER;
	else if( choice == 5 )
		heroClass = Hero::HeroClass.AMAZON;
	else if( choice == 6 )
		heroClass = Hero::HeroClass.DRUID;
	else if( choice == 7 )
		heroClass = Hero::HeroClass.ASSASSIN;
	
	Hero hero( name ); // construct the hero
	
	std::cout << std::endl;
	
	std::cout << " Press Enter to start. " << std::endl;
	std::cin.ignore();

	planeDND.start();
	
}