#ifndef _ENEMY_FISH_H_
#define _ENEMY_FISH_H_

#include "enemy.h"

extern Atlas atlas_enemy_fish;
//С��ʱ�������������ʱ�򲻶�

class enemy_fish :public Enemy {
public:
	enemy_fish() = default;
	~enemy_fish() = default;

	enemy_fish(&atlas_enemy_fish);

	//�����ƶ���������ǽ�ڲ��ƶ�
	void move() {
		int time = 3;
		if (game_map[x][y] == 1) {
			time = -6;
		}
		while (time--) {
			if (game_map[x + 1][y] != 3) {
				Sleep(100);
				x++;
				game_map[x + 1][y] = 2;//ȥ���ĵط��й�
				game_map[x][y] = 0;//�뿪�ĵط�û��
			}
		}
		time += 6;
		while (time--) {
			if (game_map[x - 1][y] != 3) {
				Sleep(100);
				x--;
				game_map[x - 1][y] = 2;//ȥ���ĵط��й�
				game_map[x][y] = 0;//�뿪�ĵط�û��
			}
		}
	}



private:
	Animation animation_enemy_fish;		//����
	POINT enemy_fish_position;			//λ��
	bool is_alive = true;				//�Ƿ���
	bool is_can_bemove = false;			//�Ƿ���Ա��ƶ�
	bool is_can_move = true;			//�Ƿ�����ƶ�
	int x = 160, y = 80;
};

#endif // !_ENEMY_FISH_H_