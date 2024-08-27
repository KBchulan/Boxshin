#ifndef _ENEMY_CRAB_H_
#define _ENEMY_CRAB_H_
#include"enemy.h"
#include<easyx.h>
#include<vector>
#include"Windows.h"
#include"enemy.h"
#include"animation.h"
#include"timer.h"
#include"scene_manager.h"
#include"player.h"

extern int game_map[14][7];
extern Atlas atlas_enemy_crab;

class Enemy_crab:public Enemy
{
public:
	~Enemy_crab() = default;

	Enemy_crab(*atlas_enemy_crab);


	void set_position(int x, int y)
	{
		this->x = x;
		this->y = y;
		this->target_x = x;
		this->target_y = y;
		enemy_position.x = 80 + x * 80;
		enemy_position.y = 60 + y * 50;
	}

private:
	enum class Direction {
		DOWN,
		LEFT,
		RIGHT,
		NONE,
		UP
	};

	void set_direction(Direction direction)
	{
		if(is_can_bemove==true)
		move_direction = direction;
	}

	virtual void data_input(const ExMessage& msg) {
		Enemy::data_input(msg);
	}

	virtual void data_update(int delta) {
		//����input���ݵ�ӳ��
		animation_enemy_idle.data_update(delta);
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
			move_direction = Direction::DOWN;
			is_can_move = true;
			game_map[x][y] = 0;
		}

		// ����crabλ��
		if (is_can_move) {
			int target_position_x = 80 + target_x * 80;
			int target_position_y = 60 + target_y * 50;
			if (enemy_position.x < target_position_x) {
				enemy_position.x += speed * delta;
				if (enemy_position.x > target_position_x) enemy_position.x = target_position_x;
			}
			else if (enemy_position.x > target_position_x) {
				enemy_position.x -= speed * delta;
				if (enemy_position.x < target_position_x) enemy_position.x = target_position_x;
			}
			else if (enemy_position.y < target_position_y) {
				enemy_position.y += speed * delta;
				if (enemy_position.y > target_position_y) enemy_position.y = target_position_y;
			}
			else if (enemy_position.y > target_position_y) {
				enemy_position.y -= speed * delta;
				if (enemy_position.y < target_position_y) enemy_position.y = target_position_y;
			}

			//�������Ŀ��λ�ã�ֹͣ�ƶ�
			if (enemy_position.x == target_position_x && enemy_position.y == target_position_y) {
				is_can_move = false;
				x = target_x;
				y = target_y;
				game_map[x][y] = 2;			//������λ��
			}
		}
	}

private:
	int target_x, target_y;				//Ŀ��λ��
	int x, y;							//��ǰλ��
	int speed = 15;						//�궨�ƶ��ٶ�
	Direction move_direction=Direction::DOWN;			//�趨��ʼλ�Ʒ���Ϊ��

};


#endif // _ENEMY_CRAB_H_
