#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <sstream>
#include "PlaneDND.h"

void welcome( void );

int main(){

	welcome(); // welcome
	
	// Create game
	PlaneDND planeDND;
	
	std::cout << std::endl 
			  << " Press Enter to start. " 
			  << std::endl;
	std::cin.ignore(); // Wait for Enter key

	planeDND.start(); // start game
}

void welcome( void ){
	
	std::cout << std::endl
			  << " **                                    **"
			  << std::endl
			  << " ** Welcome to Diablo 1.5. blizzardtm. **" 
			  << std::endl
			  << " **                                    **"
			  << std::endl;
}