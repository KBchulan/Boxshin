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
		this->target_x = x;
		this->target_y = y;
		player_position.x = 120 + x * 40;
		player_position.y = 40 + y * 40;
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
		//����input���ݵ�ӳ��
		if (move_direction != Direction::NONE) {
			target_x = x;
			target_y = y;
			switch (move_direction) {
			case Direction::UP:
				if (y > 0) target_y--;
				break;
			case Direction::DOWN:
				if (y < 15) target_y++;
				break;
			case Direction::LEFT:
				if (x > 0) target_x--;
				break;
			case Direction::RIGHT:
				if (x < 25) target_x++;
				break;
			}
			move_direction = Direction::NONE;
			is_moving = true;
			game_map[x][y] = 0;					 //����ԭ��λ��
		}
		//����playerλ��
		if (is_moving) {
			int target_position_x = 120 + target_x * 40;
			int target_position_y = 40 + target_y * 40;
			if (player_position.x < target_position_x) {
				player_position.x += speed * delta;
				if (player_position.x > target_position_x) player_position.x = target_position_x;
			}
			else if (player_position.x > target_position_x) {
				player_position.x -= speed * delta;
				if (player_position.x < target_position_x) player_position.x = target_position_x;
			}
			else if (player_position.y < target_position_y) {
				player_position.y += speed * delta;
				if (player_position.y > target_position_y) player_position.y = target_position_y;
			}
			else if (player_position.y > target_position_y) {
				player_position.y -= speed * delta;
				if (player_position.y < target_position_y) player_position.y = target_position_y;
			}
			//�������Ŀ��λ�ã�ֹͣ�ƶ�
			if (player_position.x == target_position_x && player_position.y == target_position_y) {
				is_moving = false;
				x = target_x;
				y = target_y;
				game_map[x][y] = 1;					//������λ��
			}
		}

	}

	virtual void picture_draw() {
		animation_player_idle->picture_draw(player_position.x, player_position.y);
	}

private:
	enum class Direction {
		NONE,
		UP,
		DOWN,
		LEFT,
		RIGHT
	};

private:
	int x, y;					//�궨map[x][y]��λ��
	int speed = 15;				//�궨�ƶ��ٶ�
	int target_x, target_y;		//Ŀ��λ��
	bool is_moving = false;		//�궨�Ƿ����ƶ�`

	Direction move_direction = Direction::NONE;


private:
	Atlas* atlas_player_idle;
	Animation* animation_player_idle;

};


#endif // !
