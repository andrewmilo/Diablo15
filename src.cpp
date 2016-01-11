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