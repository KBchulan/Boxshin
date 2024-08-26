#ifndef _PLAYER_H_
#define _PLAYER_H_

#include<easyx.h>
#include<vector>

#include"animation.h" 
#include"scene_manager.h"

extern int flag;
extern int game_map[26][16];
extern POINT player_position;
extern SceneManager scene_manager;

class Player {
public:
	Player() = default;

	~Player() = default;

	void set_position(int x, int y) {
		this->x = x;
		this->y = y;
		this->target_x = x;
		this->target_y = y;
		player_position.x = 120 + x * 40;
		player_position.y = 40 + y * 40;
	}

	void set_big(bool is_big){
		this->is_big = is_big;
	}

	virtual void data_input(const ExMessage& msg) {
		switch (msg.message) {
		case WM_KEYDOWN:
			switch (msg.vkcode) {
			case VK_UP:
				move_direction = Direction::UP;
				break;
			case VK_DOWN:
				move_direction = Direction::DOWN;
				break;
			case VK_LEFT:
				move_direction = Direction::LEFT;
				break;
			case VK_RIGHT:
				move_direction = Direction::RIGHT;
				break;
			}
			break;
		case WM_KEYUP:
			move_direction = Direction::NONE;
			break;
		}
	}

	virtual void data_update(int delta) {
		pre_flag = flag;
		//更新input内容的映射
		if (move_direction != Direction::NONE && game_map[x][y] != 3) {
			target_x = x;
			target_y = y;
			switch (move_direction) {
			case Direction::UP:
				target_y--;
				break;
			case Direction::DOWN:
				target_y++;
				break;
			case Direction::LEFT:
				target_x--;
				break;
			case Direction::RIGHT:
				target_x++;
				break;
			}
			move_direction = Direction::NONE;
			is_moving = true;
			game_map[x][y] = 0;		//重置原来位置
		}

		// 更新player位置
		if (is_moving && is_live) {
			int target_position_x = 120 + target_x * 40;
			int target_position_y = 40 + target_y * 40;
			if (player_position.x < target_position_x) {
				player_position.x += speed * delta;
				if (player_position.x > target_position_x)
					player_position.x = target_position_x;
			}
			else if (player_position.x > target_position_x) {
				player_position.x -= speed * delta;
				if (player_position.x < target_position_x)
					player_position.x = target_position_x;
			}
			else if (player_position.y < target_position_y) {
				player_position.y += speed * delta;
				if (player_position.y > target_position_y) 
					player_position.y = target_position_y;
			}
			else if (player_position.y > target_position_y) {
				player_position.y -= speed * delta;
				if (player_position.y < target_position_y)
					player_position.y = target_position_y;
			}

			//如果到达目标位置，停止移动
			if (player_position.x == target_position_x && player_position.y == target_position_y) {
				is_moving = false;
				x = target_x;
				y = target_y;
				game_map[x][y] = 1;			//更新新位置
			}
		}

		if (game_map[x][y] == 2) {
			is_live = false;
		}

		if (game_map[x][y] == 4) {
			is_win = true;
			flag++;
		}

	}

	virtual void picture_draw() {
		if (is_live) {
			if (is_big)
				animation_player_big.picture_draw(player_position.x, player_position.y);
			else
				animation_player_idle.picture_draw(player_position.x, player_position.y);
		}

		if (flag != pre_flag && is_win) {
			animation_player_win.picture_draw(player_position.x, player_position.y);
			is_win = false;
			scene_manager.switch_to(flag);
		}

	}

private:
	enum class Direction {
		NONE,
		UP,
		DOWN,
		LEFT,
		RIGHT
	};

protected:
	int x, y;					//标定map[x][y]的位置
	int speed = 15;				//标定移动速度
	int target_x, target_y;		//目标位置
	int pre_flag;				//标定上一帧的flag

	bool is_moving = false;		//标定是否在移动
	bool is_big = false;		//标定是否为无敌状态
	bool is_live = true;		//标定是否存活
	bool is_win = false;		//标定是否胜利

	Direction move_direction = Direction::NONE;

protected:
	Animation animation_player_idle;
	Animation animation_player_big;
	Animation animation_player_win;
	Animation animation_player_die;
	Animation animation_player_water;

};


#endif // !
