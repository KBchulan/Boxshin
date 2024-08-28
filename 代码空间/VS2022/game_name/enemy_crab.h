#ifndef _ENEMY_CRAB_H_
#define _ENEMY_CRAB_H_

//变大能被推
//当触发一定情况可行走

#include "enemy.h"

extern Atlas atlas_enemy_crab;
extern Direction move_direction;
extern bool is_big;

class EnemyCrab :public Enemy {
public:
	EnemyCrab() {
		animation_enemy_idle.set_atlas(&atlas_enemy_crab);
		is_can_move = false;
		is_can_bemove = false;
		switch (flag) {
		case 62:
			move_sum = 1;
			move_direction_list.clear();
			push_back_to(0, 1);
			enemy_x = 7;
			enemy_y = 8;
			enemy_target_x = enemy_x;
			enemy_target_y = enemy_y;
			break;
		case 63:
			move_sum = 4;
			move_direction_list.clear();
			push_back_to(0, 1);
			push_back_to(0, 1);
			push_back_to(0, 1);
			push_back_to(0, 1);
			enemy_x = 7;
			enemy_y = 3;
			enemy_target_x = enemy_x;
			enemy_target_y = enemy_y;
			break;
		default:
			break;
		}

	}
	~EnemyCrab() = default;

	void data_input(const ExMessage& msg) {
		Enemy::data_input(msg);
		if (msg.message == WM_KEYDOWN) {
			switch (msg.vkcode) {
			case VK_UP:case VK_DOWN:case VK_LEFT:case VK_RIGHT:
				if (is_can_move && move_sum) {
					Move();
					move_sum--;
				}
				break;
			}
		}
	}

	void data_update(int delta) {
		Enemy::data_update(delta);

		//更新属性
		if (is_big) {
			is_can_bemove = true;
		}

		switch (flag) {
		case 62:
			if (enemy_x == 8 && enemy_y == 8)
				is_can_move = true;
			break;
		case 63:
			if (enemy_x == 6 && enemy_y == 3)
				is_can_move = true;
			break;
		default:
			break;
		}

	}

	void picture_draw() {
		Enemy::picture_draw();
	}

	void push_back_to(int x, int y) {
		Move_direction move_direction = { x,y };
		move_direction_list.push_back(move_direction);
	}

	void Move() {
		if (!move_direction_list.empty()) {
			Move_direction& current_move = move_direction_list.front();
			enemy_target_x += current_move.x;
			enemy_target_y += current_move.y;
			move_direction_list.erase(move_direction_list.begin());
			if (move_sum == 0) {
				move_direction_list.clear();
				is_can_move = false;
			}
		}

	}

private:
	struct Move_direction {
		int x, y;
	};

private:
	std::vector<Move_direction> move_direction_list;

};


#endif // _ENEMY_CRAB_H_
