#ifndef _PLAYER_H_
#define _PLAYER_H_

#include<easyx.h>
#include<vector>

#include"animation.h"

extern POINT player_position;
extern Atlas atlas_gamer_diver;

class Player {
public:
	Player() = default;

	~Player() = default;

	void set_atlas(Atlas* atlas) {
		this->atlas_player_idle = atlas;
	}

	virtual void data_input(const ExMessage& msg) {
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

	virtual void data_update() {

	}

	virtual void picture_draw() {

	}

protected:
	void Move() {

	}

private:
	Atlas* atlas_player_idle;
	Animation animation_player_idle;


private:
	bool is_move_up = false;
	bool is_move_down = false;
	bool is_move_left = false;
	bool is_move_right = false;



};


#endif // !
