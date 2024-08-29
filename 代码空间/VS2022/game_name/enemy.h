#ifndef _ENEMTY_H_
#define _ENEMTY_H_

#include<easyx.h>
#include<vector>

#include"player.h"
#include"animation.h" 
#include"scene_manager.h"

extern int flag;
extern int game_map[14][12];
extern SceneManager scene_manager;

int enemy_target_x , enemy_target_y;			//�����ƶ��������

class Enemy {
public:
	Enemy() {
		animation_enemy_idle.set_interval(75);
		animation_enemy_idle.set_loop(true);
	}
	~Enemy() = default;
	int enemy_x, enemy_y;							//����


	bool get_is_can_bemove() const {
		return is_can_bemove;
	}

	virtual void data_input(const ExMessage& msg) {
		
	}

	virtual void data_update(int delta) {
		animation_enemy_idle.data_update(delta);
		enemy_position.x = enemy_x * 80 + 80;
		enemy_position.y = enemy_y * 50 + 60;

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
	
	}

	void picture_draw() {
		animation_enemy_idle.picture_draw(enemy_position.x, enemy_position.y);
	}

	POINT get_position()const {
		return POINT{ enemy_x, enemy_y };
	}

protected:
	Animation animation_enemy_idle;		//����
	POINT enemy_position;				//λ��
	POINT enemy_target;					//Ŀ������
	bool is_can_bemove = false;			//�Ƿ���Ա��ƶ�
	bool is_can_move = false;			//�Ƿ�����ƶ�
	int move_sum = 0;					//�ƶ��ܴ���
	int speed = 15;						//�ٶ�

};



#endif // _ENEMTY_H_