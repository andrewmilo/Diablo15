#include <iostream>

#include "PlaneDND.h"

int main(){
	
	// Create game
	PlaneDND planeDND;
	
	std::cout << " Press Y to play." << std::endl;
	char y;
	cin >> y;
	
	if( y == 'y' ) 
		planeDND.start();
	
}