#ifndef _ENEMTY_H_
#define _ENEMTY_H_

#include"animation.h"

class Enemy {
public:
	Enemy() = default;
	~Enemy() = default;

	void set_position(POINT position) {
		this->enemy_position = position;
	}

	void set_animation(const Animation& animation) {
		this->animation_enemy_idle = animation;
	}

	void dead() {
		this->is_alive = false;
	}

	bool is_dead() const {
		return !is_alive;
	}

	Animation& animation() {
		return this->animation_enemy_idle;
	}

	POINT& position() {
		return this->enemy_position;
	}

private:
	Animation animation_enemy_idle;
	POINT enemy_position;
	bool is_alive = true;


};



#endif // _ENEMTY_H_



/*
1.位置
2.input
3.update
4.draw
5.	bool is_can_bemove = true;	//是否可以被移动
	bool is_can_move = true;	//是否可以移动
	

*/