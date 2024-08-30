#ifndef _ENEMY_CRAB_H_
#define _ENEMY_CRAB_H_

//变大能被推
//当触发一定情况可行走

#include "enemy.h"

extern Atlas atlas_enemy_crab;
extern Direction move_direction;
extern bool is_big;

int box_target_temp_x = 0,
box_target_temp_y = 0;

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

		if (enemy_x != enemy_target_x || enemy_y != enemy_target_y) {
			enemy_target.x = enemy_target_x * 80 + 80;
			enemy_target.y = enemy_target_y * 50 + 60;

			if (enemy_position.x < enemy_target.x) {
				enemy_position.x += speed * delta;
				if (enemy_position.x > enemy_target.x)
					enemy_position.x = enemy_target.x;
			}
			else if (enemy_position.x > enemy_target.x) {
				enemy_position.x -= speed * delta;
				if (enemy_position.x < enemy_target.x)
					enemy_position.x = enemy_target.x;
			}
			if (enemy_position.y < enemy_target.y) {
				enemy_position.y += speed * delta;
				if (enemy_position.y > enemy_target.y)
					enemy_position.y = enemy_target.y;
			}
			else if (enemy_position.y > enemy_target.y) {
				enemy_position.y -= speed * delta;
				if (enemy_position.y < enemy_target.y)
					enemy_position.y = enemy_target.y;
			}

			if (enemy_position.x == enemy_target.x && enemy_position.y == enemy_target.y) {
				game_map[enemy_x][enemy_y] = 0;

				enemy_x = enemy_target_x;
				enemy_y = enemy_target_y;

				game_map[enemy_x][enemy_y] = 2;
			}
		}

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
		case 64:
			if (enemy_x == 8 && enemy_y == 9)
				is_can_move = true;
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




class EnemyBox :public Enemy {
public:
	EnemyBox() {
		animation_enemy_idle.set_atlas(&atlas_enemy_crab);
		is_can_bemove = false;
		is_can_move = false;
		enemy_x = enemy_y = 0;
		box_target_x = enemy_x;
		box_target_y = enemy_y;
	}
	~EnemyBox() = default;

	void data_input(const ExMessage& msg) {
		Enemy::data_input(msg);

	}

	void data_update(int delta) {
		Enemy::data_update(delta);
		box_target_x = enemy_x;
		box_target_y = enemy_y;
		set_target_posxy();
		if (enemy_x != box_target_x || enemy_y != box_target_y) {
			box_target.x = box_target_x * 80 + 80;
			box_target.y = box_target_y * 50 + 60;

			if (enemy_position.x < box_target.x) {
				enemy_position.x += speed * delta;
				if (enemy_position.x > box_target.x)
					enemy_position.x = box_target.x;
			}
			else if (enemy_position.x > box_target.x) {
				enemy_position.x -= speed * delta;
				if (enemy_position.x < box_target.x)
					enemy_position.x = box_target.x;
			}
			if (enemy_position.y < box_target.y) {
				enemy_position.y += speed * delta;
				if (enemy_position.y > box_target.y)
					enemy_position.y = box_target.y;
			}
			else if (enemy_position.y > box_target.y) {
				enemy_position.y -= speed * delta;
				if (enemy_position.y < box_target.y)
					enemy_position.y = box_target.y;
			}

			if (enemy_position.x == box_target.x && enemy_position.y == box_target.y) {
				game_map[enemy_x][enemy_y] = 0;

				enemy_x = box_target_x;
				enemy_y = box_target_y;

				game_map[enemy_x][enemy_y] = box_number;
			}
		}

		//更新属性
		if (is_big) {
			is_can_bemove = true;
		}
	}

	void picture_draw(int x, int y) {
		Enemy::picture_draw(x, y);
	}

	void set_posxy(int x, int y) {
		enemy_x = x;
		enemy_y = y;
		box_target_x = enemy_x;
		box_target_y = enemy_y;
	}

	void set_target_posxy() {
		std::cout << box_target_temp_x << " " << box_target_temp_y << std::endl;
		box_target_x += box_target_temp_x;
		box_target_y += box_target_temp_y;
		box_target_temp_x = 0;
		box_target_temp_y = 0;
	}

	void set_number(int x) {
		box_number = x;
	}

	int box_target_x = 0;
	int box_target_y = 0;

private:
	POINT box_target;
	int box_number;


};


#endif // _ENEMY_CRAB_H_
