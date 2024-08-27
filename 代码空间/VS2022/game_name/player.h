#ifndef _PLAYER_H_
#define _PLAYER_H_

#include<easyx.h>
#include<vector>

#include"timer.h"
#include"animation.h" 
#include"scene_manager.h"

extern int flag;
extern int game_map[14][12];
extern POINT player_position;
extern SceneManager scene_manager;

enum class Direction {
	NONE,
	UP,
	DOWN,
	LEFT,
	RIGHT
};

Direction move_direction;						//标定移动方向，用于传入enemy和item中使用
int player_map_x, player_map_y;					//标定玩家在map[player_map_x][player_map_y]的位置
bool is_big = false;							//标定是否为无敌状态,用于传入enemy使用
bool is_moving = false;							//标定是否在移动,用于传入item中

class Player {
public:
	Player(){
		//初始化方向
		Direction move_direction = Direction::NONE;
		//初始化公共动画
		animation_player_idle_left.set_loop(true);
		animation_player_idle_left.set_interval(75);	

		animation_player_idle_right.set_loop(true);
		animation_player_idle_right.set_interval(75);	

		animation_player_win.set_loop(true);
		animation_player_win.set_interval(75);

		animation_player_die.set_loop(true);
		animation_player_die.set_interval(75);

		//初始化定时器
		timer_player_win.set_one_shot(true);
		timer_player_win.set_wait_time(1500);
		timer_player_win.set_callback(
			[&]() {
				is_win = false;
				flag++;
			}
		);

		timer_player_die.set_one_shot(true);
		timer_player_die.set_wait_time(1500);
		timer_player_die.set_callback(
			[&]() {
				is_live = true;
				flag = 4;
			}
		);

	}
	~Player() = default;

	void set_position(int x, int y) {
		player_map_x = x;
		player_map_y = y;
		this->target_x = x;
		this->target_y = y;
		player_position.x = 80 + x * 80;
		player_position.y = 60 + y * 50;
		pre_flag = flag;
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
				is_facing_right = false;
				break;
			case VK_RIGHT:
				move_direction = Direction::RIGHT;
				is_facing_right = true;
				break;
			}
			break;
		case WM_KEYUP:
			move_direction = Direction::NONE;
			break;
		}
	}

	virtual void data_update(int delta) {
		//切换场景
		if (flag != pre_flag) {
			pre_flag = flag;
			scene_manager.switch_to(flag);
		}

		//动画类更新，定时器更新
		if (!is_win) {
			animation_player_idle_left.data_update(delta);
			animation_player_idle_right.data_update(delta);
		}
		else {
			animation_player_win.data_update(delta);
			timer_player_win.data_update(delta);
		}
		
		//死亡动画更新
		if (!is_live) {
			animation_player_die.data_update(delta);
			timer_player_die.data_update(delta);
		}
		else {
			//更新input内容的映射
			if (move_direction != Direction::NONE) {
				target_x = player_map_x;
				target_y = player_map_y;
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
			}

			if (game_map[target_x][target_y] != 3) {
				is_moving = true;
				game_map[player_map_x][player_map_y] = 0;		//重置原来位置
			}
			else {
				is_moving = false;
				target_x = player_map_x;
				target_y = player_map_y;
			}

			// 更新player位置
			if (is_moving) {
				int target_position_x = 80 + target_x * 80;
				int target_position_y = 60 + target_y * 50;
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
					player_map_x = target_x;
					player_map_y = target_y;
					if (game_map[player_map_x][player_map_y] == 4) {
						is_win = true;
					}
					game_map[player_map_x][player_map_y] = 1;			//更新新位置
				}
			}
		}

		if (game_map[player_map_x][player_map_y] == 2) {
			//if(enemy_crab)
			is_live = false;
		}

		if (game_map[player_map_x][player_map_y] == 6) {
			is_big = true;
		}

	}

	virtual void picture_draw() {
		if (is_win) {
			animation_player_win.picture_draw(player_position.x, player_position.y);
		}
		else {
			if (is_live) {
				if (is_big)
					if (is_facing_right)
						animation_player_big_right.picture_draw(player_position.x, player_position.y);
					else
						animation_player_big_left.picture_draw(player_position.x, player_position.y);
				else
					if (is_facing_right)
						animation_player_idle_right.picture_draw(player_position.x, player_position.y);
					else
						animation_player_idle_left.picture_draw(player_position.x, player_position.y);
			}
			else {
				animation_player_die.picture_draw(player_position.x, player_position.y);
			}
		}

	}

protected:
	int speed = 15;					//标定移动速度
	int target_x, target_y;			//目标位置
	int pre_flag;					//标定上一帧的flag

	bool is_live = true;			//标定是否存活
	bool is_win = false;			//标定是否胜利
	bool is_facing_right = true;	//标定是否朝右
	bool is_win_over = false;		//标定胜利动画是否结束
	bool is_die_over = false;		//标定死亡动画是否结束

protected:
	Animation animation_player_idle_left;
	Animation animation_player_idle_right;
	Animation animation_player_big_left;
	Animation animation_player_big_right;

	Animation animation_player_win;
	Animation animation_player_die;

	Timer timer_player_win;
	Timer timer_player_die;

};


#endif // !
