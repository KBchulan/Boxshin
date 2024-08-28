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
extern POINT penetration_wall_position;
extern int enemy_target_x, enemy_target_y;

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

		animation_player_big_left.set_loop(true);
		animation_player_big_left.set_interval(75);

		animation_player_big_right.set_loop(true);
		animation_player_big_right.set_interval(75);

		animation_player_win.set_loop(true);
		animation_player_win.set_interval(75);

		animation_player_die.set_loop(true);
		animation_player_die.set_interval(75);

		//初始化定时器
		timer_player_win.set_one_shot(false);
		timer_player_win.set_wait_time(1500);
		timer_player_win.set_callback(
			[&]() {
				is_win = false;
				flag++;
				//scene_manager.switch_to(flag);
			}
		);

		timer_player_die.set_one_shot(false);
		timer_player_die.set_wait_time(1500);
		timer_player_die.set_callback(
			[&]() {
				is_live = true;
				scene_manager.switch_to(flag);
			}
		);

	}
	~Player() = default;

	void set_position(int x, int y,int num_star) {
		player_map_x = x;
		player_map_y = y;
		this->target_x = x;
		this->target_y = y;
		player_position.x = 80 + x * 80;
		player_position.y = 60 + y * 50;
		target_star = num_star;
		getten_star = 0;
		is_facing_right = true;
		is_big = false;
		is_live = true;
		is_win = false;

		switch (flag) {
		case 62:
			big_steps = 20;
			moved_steps = 0;
			break;

		default:
			break;
		}
	}

	virtual void data_input(const ExMessage& msg) {
		if (!is_win && is_live) {
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
				if (is_big)
					moved_steps++;
				break;
			}
		}
	}

	virtual void data_update(int delta) {
		//动画类更新，定时器更新
		if (!is_win) {
			animation_player_idle_left.data_update(delta);
			animation_player_idle_right.data_update(delta);
			animation_player_big_left.data_update(delta);
			animation_player_big_right.data_update(delta);
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

			//重置原来位置
			if (game_map[target_x][target_y] != 3 
				&& game_map[target_x][target_y] != 2
				&& game_map[target_x][target_y] != 5
				&& game_map[target_x][target_y] != 7) {
				is_moving = true;
				game_map[player_map_x][player_map_y] = 0;
			}
			else if (game_map[target_x][target_y] == 7 && !is_big) {
				is_moving = true;
				game_map[player_map_x][player_map_y] = 0;
			}
			else if (game_map[target_x][target_y] == 2) {
				if (!is_big) {
					is_live = false;
				}
				else {
					enemy_target_x += (target_x - player_map_x);
					enemy_target_y += (target_y - player_map_y);
				}
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
						getten_star++;
						if (getten_star == target_star) {
							is_win = true;
							getten_star = 0;
						}
					}

					if (game_map[player_map_x][player_map_y] == 6) {
						is_big = true;
					}

					if (moved_steps == big_steps) {
						is_big = false;
						moved_steps = 0;
						game_map[pre_position_bubble.x][pre_position_bubble.y] = pre_map_value;
					}

					if (game_map[player_map_x][player_map_y] == 6) {
						pre_map_value = game_map[player_map_x][player_map_y];
						pre_position_bubble = {player_map_x,player_map_y};
					}

					game_map[player_map_x][player_map_y] = 1;			//更新新位置

				}
			}
		}

		game_map[penetration_wall_position.x][penetration_wall_position.y] = 7;
	}

	virtual void picture_draw() {
		if (is_win) {
			animation_player_win.picture_draw(player_position.x, player_position.y);
		}
		else {
			if (is_live) {
				if (is_big) {
					if (is_facing_right)
						animation_player_big_right.picture_draw(player_position.x, player_position.y);
					else
						animation_player_big_left.picture_draw(player_position.x, player_position.y);

					Draw_big_steps_num();
				}
				else
					if (is_facing_right)
						animation_player_idle_right.picture_draw(player_position.x + 10, player_position.y + 6);
					else
						animation_player_idle_left.picture_draw(player_position.x + 10, player_position.y + 6);
			}
			else {
				animation_player_die.picture_draw(player_position.x, player_position.y);
			}
		}

	}

private:
	void Draw_big_steps_num() {
		static TCHAR arr[64];
		_stprintf_s(arr, _T("%d"), big_steps - moved_steps);
		setbkmode(TRANSPARENT);
		outtextxy(player_position.x + 40, player_position.y, arr);
	}

protected:
	int target_star = 0;
	int getten_star = 0;

	int big_steps;
	int moved_steps;

	int pre_map_value = 0;
	POINT pre_position_bubble = { 0,0 };

	int speed = 15;					//标定移动速度
	int target_x, target_y;			//目标位置

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
