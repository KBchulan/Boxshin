#ifndef _ENEMY_FISH_H_
#define _ENEMY_FISH_H_

#include "enemy.h"

extern Atlas atlas_enemy_fish;
//小的时候碰到死，大的时候不动

class enemy_fish :public Enemy {
public:
	enemy_fish() = default;
	~enemy_fish() = default;

	
};

#endif // !_ENEMY_FISH_H_