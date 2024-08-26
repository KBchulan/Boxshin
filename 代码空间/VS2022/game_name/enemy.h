#ifndef _ENEMTY_H_
#define _ENEMTY_H_

#include"animation.h"

class Enemy {
public:
	Enemy(Atlas* atlas, bool is_can_bemove = true, bool is_can_move = true) {
		this->is_can_bemove = is_can_bemove;
		this->is_can_move = is_can_move;
		this->animation_enemy_idle.set_atlas(atlas);
		this->animation_enemy_idle.set_interval(75);
		this->animation_enemy_idle.set_loop(true);
	}
	~Enemy() = default;

	void set_position(POINT position) {
		this->enemy_position = position;
	}

	void set_position(int x, int y) {
		this->enemy_position.x = x;
		this->enemy_position.y = y;
	}

	virtual void data_update(int delta) {
		animation_enemy_idle.data_update(delta);
	}
	virtual void data_input(const ExMessage& msg) {

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
	Animation animation_enemy_idle; //����
	POINT enemy_position;			//λ��
	bool is_alive = true;			//�Ƿ���
	bool is_can_bemove = true;		//�Ƿ���Ա��ƶ�
	bool is_can_move = true;		//�Ƿ�����ƶ�

};



#endif // _ENEMTY_H_



/*
1.λ��
2.input
3.update
4.draw
5.	bool is_can_bemove = true;	//�Ƿ���Ա��ƶ�
	bool is_can_move = true;	//�Ƿ�����ƶ�


*/