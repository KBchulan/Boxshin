#ifndef _PLAYER_H_
#define _PLAYER_H_

#include<easyx.h>
#include<vector>

#include"animation.h" 

extern int game_map[26][16];
extern POINT player_position;
extern Atlas atlas_gamer_diver;

class Player {
public:
	Player() = default;

	~Player() = default;

	void set_position(int x, int y) {
		this->x = x;
		this->y = y;
	}

	void set_atlas(Atlas* atlas) {
		this->atlas_player_idle = atlas;
	}

	void set_animation(Animation* animation) {
		this->animation_player_idle = animation;
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

	virtual void data_update(int delta) {
		player_position.x = 120 + x * 40;
		player_position.y = 40 + y * 40;

	}

	virtual void picture_draw() {
		animation_player_idle->picture_draw(player_position.x, player_position.y);
	}

protected:
	void Move() {

	}

private:
	int x, y;			//标定map[x][y]的位置


private:
	Atlas* atlas_player_idle;
	Animation* animation_player_idle;


private:
	bool is_move_up = false;
	bool is_move_down = false;
	bool is_move_left = false;
	bool is_move_right = false;



};


#endif // !
