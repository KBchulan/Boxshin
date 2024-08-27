#ifndef _ENEMTY_H_
#define _ENEMTY_H_

#include<easyx.h>
#include<vector>

#include"animation.h" 
#include"scene_manager.h"

extern int flag;
extern int game_map[14][12];
extern SceneManager scene_manager;

class Enemy {
public:
	Enemy() = default;
	~Enemy() = default;

	void set_position(int x, int y) {
		this->x = x;
		this->y = y;
		enemy_position.x = x * 80 + 80;
		enemy_position.y = y * 50 + 60;
	}

	virtual void data_input(const ExMessage& msg) {

	}

	virtual void data_update(int delta) {
		animation_enemy_idle.data_update(delta);
	}

	void picture_draw() {
		if (is_alive) {
			animation_enemy_idle.picture_draw(enemy_position.x, enemy_position.y);
		}
	}

	void dead() {
		this->is_alive = false;
	}

protected:
	Animation animation_enemy_idle;		//����
	POINT enemy_position;				//λ��
	int x, y;							//����	
	bool is_alive = true;				//�Ƿ���
	bool is_can_bemove = true;			//�Ƿ���Ա��ƶ�
	bool is_can_move = true;			//�Ƿ�����ƶ�

};



#endif // _ENEMTY_H_