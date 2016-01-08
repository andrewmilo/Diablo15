#include "PlaneDND.h"
#include <iostream>

PlaneDND::PlaneDND( void ){ }

PlaneDND::~PlaneDND( void ){ }

void PlaneDND::start( void ){
	
	//if( !( this->hero ) ) ( this->hero ) = new Hero();
	
	// std::cout << "X Movement: ";
	// int x_steps = 0;
	// std::cin >> x_steps;
	
	// std::cout << "Y Movement: ";
	// int y_steps = 0;
	// std::cin >> y_steps;
	
	char direction = '\0';
	
	while( direction != 'n'  ||
		   direction != 'N'  ||
		   direction != 'w'  ||
		   direction != 'W'  ||
		   direction != 'e'  ||
		   direction != 'E'  ||
		   direction != 's'  ||
		   direction != 'S' ){
		   
		std::cout << " Which way? ( N, W, E, S )" << std::endl;
		std::cin >> direction;
	}

	//hero.
	
}