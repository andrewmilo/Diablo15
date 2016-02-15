#ifndef _ENEMY_
#define _ENEMY_

class Enemy : public Entity {
	
	public:
		Enemy( void );
		Enemy( Entity& enemy, int variance );
		~Enemy( void );
	
	private:
	
};

#endif