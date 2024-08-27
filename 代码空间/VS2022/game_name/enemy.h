#ifndef _ENEMTY_H_
#define _ENEMTY_H_

#include<easyx.h>
#include<vector>

#include"player.h"
#include"animation.h" 
#include"scene_manager.h"

extern int flag;
extern int game_map[14][12];
extern SceneManager scene_manager;

class Enemy {
public:
	Enemy() {
		animation_enemy_idle.set_interval(75);
		animation_enemy_idle.set_loop(true);
	}
	~Enemy() = default;

	void set_position(int x, int y) {
		this->enemy_x = x;
		this->enemy_y = y;
		enemy_position.x = x * 80 + 80;
		enemy_position.y = y * 50 + 60;
	}

	bool get_is_can_bemove() const {
		return is_can_bemove;
	}

	virtual void data_input(const ExMessage& msg) {}

	virtual void data_update(int delta) {
		animation_enemy_idle.data_update(delta);
		enemy_position.x = enemy_x * 80 + 80;
		enemy_position.y = enemy_y * 50 + 60;
	}

	void picture_draw() {
		animation_enemy_idle.picture_draw(enemy_position.x, enemy_position.y);
	}

protected:
	Animation animation_enemy_idle;		//动画
	POINT enemy_position;				//位置
	int enemy_x, enemy_y;				//坐标
	bool is_can_bemove = false;			//是否可以被移动
	bool is_can_move = false;			//是否可以移动
	int move_sum = 0;					//移动总次数

};



#endif // _ENEMTY_H_