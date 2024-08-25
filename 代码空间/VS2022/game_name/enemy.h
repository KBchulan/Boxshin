#ifndef _ENEMTY_H_
#define _ENEMTY_H_

#include"animation.h"

class Enemy {

public:
	Enemy() = default;
	~Enemy() = default;

	void set_atlas(Atlas* atlas) {
		this->atlas_enemy_idle = atlas;
	}

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
	Atlas* atlas_enemy_idle;
	POINT enemy_position;
	bool is_alive = true;
};



#endif // _ENEMTY_H_