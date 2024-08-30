#ifndef _ENEMY_FISH_H_
#define _ENEMY_FISH_H_

#include "enemy.h"

extern Atlas atlas_enemy_fish;
extern Atlas atlas_enemy_worried_fish;
extern bool is_big;

struct Move_direction {
	int x, y;
};

class enemy_fish :public Enemy {
public:
	enemy_fish() {
		animation_enemy_idle.set_atlas(&atlas_enemy_fish);
		is_can_move = true;
		is_can_bemove = false;

		move_direction_list.clear();

	}
	~enemy_fish() = default;

	std::vector<Move_direction> move_direction_list;
	int pre_move_sum = 0;
	int fish_target_x = 0
		, fish_target_y = 0;
	int idx = 0;

	void set_move_sum(int x) {
		this->move_sum = x;
		this->pre_move_sum = x;
	}

	void set_pos_xy(int x, int y) {
		this->enemy_x = x;
		this->enemy_y = y;
		fish_target_x = enemy_x;
		fish_target_y = enemy_y;
	}

	void data_input(const ExMessage& msg) {
		Enemy::data_input(msg);
		if (msg.message == WM_KEYDOWN) {
			switch (msg.vkcode) {
			case VK_UP:case VK_DOWN:case VK_LEFT:case VK_RIGHT:
				if (is_can_move && move_sum) {
					Move();
					move_sum--;
					if (!move_sum) {
						move_sum = pre_move_sum;
					}
				}
				break;
			}
		}
	}


	void data_update(int delta) {
		Enemy::data_update(delta);

		if (game_map[enemy_x][enemy_y] == 21) {
			if (enemy_x != fish_target_x || enemy_y != fish_target_y) {
				enemy_target.x = fish_target_x * 80 + 80;
				enemy_target.y = fish_target_y * 50 + 60;

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

					enemy_x = fish_target_x;
					enemy_y = fish_target_y;

					game_map[enemy_x][enemy_y] = 21;
				}
			}

		}

		if (is_big) {
			game_map[enemy_x][enemy_y] = 22;
			animation_enemy_idle.set_atlas(&atlas_enemy_worried_fish);
			is_can_move = false;
		}
		else {
			game_map[enemy_x][enemy_y] = 21;
			animation_enemy_idle.set_atlas(&atlas_enemy_fish);
			is_can_move = true;
		}

	}

	void picture_draw() {
		Enemy::picture_draw();
		
	}

	void picture_draw(int x,int y) {
		Enemy::picture_draw(x, y);
	}

	void push_back_to(int x, int y) {
		Move_direction move_direction = { x,y };
		move_direction_list.push_back(move_direction);
	}

	void Move() {
		if (idx != move_direction_list.size()) {
			Move_direction& current_move = move_direction_list[idx];
			fish_target_x += current_move.x;
			fish_target_y += current_move.y;
			idx++;
		}
		else {
			idx = 0;
		}
	}

};

#endif // !_ENEMY_FISH_H_