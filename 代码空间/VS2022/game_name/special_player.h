#ifndef _SPECIAL_PLAYER_H_
#define _SPECIAL_PLAYER_H_

#include<easyx.h>

#include"timer.h"
#include"animation.h"
#include"scene_manager.h"

extern int flag;
extern SceneManager scene_manager;

extern Atlas game_atlas_gamer_diver_win;
extern Atlas game_atlas_gamer_diver_die;
extern Atlas game_atlas_gamer_diver_left_small;
extern Atlas game_atlas_gamer_diver_right_small;


class SpecialPlayer {
public:
	SpecialPlayer() {
		special_player_idle_left.set_loop(true);
		special_player_idle_left.set_atlas(&game_atlas_gamer_diver_left_small);
		special_player_idle_left.set_interval(75);

		special_player_idle_right.set_loop(true);
		special_player_idle_right.set_atlas(&game_atlas_gamer_diver_right_small);
		special_player_idle_right.set_interval(75);

		animation_player_win.set_loop(true);
		animation_player_win.set_atlas(&game_atlas_gamer_diver_win);
		animation_player_win.set_interval(75);

		//初始化定时器
		timer_player_win.set_one_shot(false);
		timer_player_win.set_wait_time(1500);
		timer_player_win.set_callback(
			[&]() {
				is_win = false;
				flag++;
			}
		);

	}
	~SpecialPlayer() = default;

	void set_init(int x, int y, int num) {
		this->position.x = x;
		this->position.y = y;
		win_stars = num;
		get_star_num = 0;
	}

	void data_input(const ExMessage& msg) {
		switch (msg.message) {
		case WM_KEYDOWN:
			switch (msg.vkcode) {
			case VK_UP:
				is_move_up = true; 
				break;
			case VK_DOWN:
				is_move_down = true;
				break;
			case VK_LEFT:
				is_move_left = true; 
				break;
			case VK_RIGHT:
				is_move_right = true; 
				break;
			}
			break;

		case WM_KEYUP:
			switch (msg.vkcode) {
			case VK_UP:
				is_move_up = false;
				break;
			case VK_DOWN:
				is_move_down = false;
				break;
			case VK_LEFT:
				is_move_left = false; 
				break;
			case VK_RIGHT:
				is_move_right = false; 
				break;
			}
			break;
		}
	}

	void data_update(int delta) {
		animation_player_win.data_update(delta);
		special_player_idle_left.data_update(delta);
		special_player_idle_right.data_update(delta);

		int dir_x = is_move_right - is_move_left;
		int dir_y = is_move_down - is_move_up;
		double len_dir = sqrt(dir_x * dir_x + dir_y * dir_y);
		if (len_dir) {
			double normalized_x = dir_x / len_dir;
			double normalized_y = dir_y / len_dir;
			position.x += (int)(SPEED * normalized_x);
			position.y += (int)(SPEED * normalized_y);
		}

		if (get_star_num == win_stars)
			is_win = true;
	}

	void picture_draw() {
		static bool is_facing_left = false;
		int dir_x = is_move_right - is_move_left;

		if (dir_x > 0) {
			is_facing_left = false;
		}
		else if (dir_x < 0) {
			is_facing_left = true;
		}

		if (is_facing_left) 
			special_player_idle_left.picture_draw(position.x,position.y);
		else
			special_player_idle_right.picture_draw(position.x, position.y);
	}

	const POINT& GetPosition() const {
		return position;
	}

	void change() {
		get_star_num++;
	}

	const int& get_win_star() {
		return this->win_stars;
	}


private:
	const int SPEED = 6;
	int win_stars = 0;
	int get_star_num = 0;
	POINT position;

	Animation special_player_idle_left;
	Animation special_player_idle_right;
	bool is_win = false;

	bool is_move_up = false;
	bool is_move_down = false;
	bool is_move_left = false;
	bool is_move_right = false;

	Animation animation_player_win;

	Timer timer_player_win;


};

#endif // !_SPECIAL_PLAYER_H_
