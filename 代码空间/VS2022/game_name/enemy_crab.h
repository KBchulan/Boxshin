#ifndef _ENEMY_CRAB_H_
#define _ENEMY_CRAB_H_

//变大能被推
//当触发一定情况可行走

#include "enemy.h"

extern Atlas atlas_enemy_crab;


class Enemy_crab :public Enemy {
public:
	Enemy_crab() {

	}
	~Enemy_crab() = default;


};


#endif // _ENEMY_CRAB_H_
