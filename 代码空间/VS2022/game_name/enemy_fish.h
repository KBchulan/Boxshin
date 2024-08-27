

#include<easyx.h>
#include<vector>
#include"Windows.h"
#include"enemy.h"
#include"animation.h"
#include"timer.h"
#include"scene_manager.h"
#include"player.h"
extern Atlas atlas_enemy_fish;

extern int game_map[14][7];

class enemy_fish :public Enemy {

public:
	
	~enemy_fish() = default;

	enemy_fish(&atlas_enemy_fish);

	//来回移动三格，遇到墙壁不移动
	void move() {
		int time = 3;
		if (game_map[x][y] == 1) {
			time = -6;
		}
		while (time--) {
			if (game_map[x + 1][y] != 3) {
				Sleep(100);
				x++;
				game_map[x + 1][y] = 2;//去到的地方有怪
				game_map[x][y] = 0;//离开的地方没怪
			}
		}
		time += 6;
		while (time--) {
			if (game_map[x - 1][y] != 3){
				Sleep(100);
				x--;
				game_map[x - 1][y] = 2;//去到的地方有怪
				game_map[x][y] = 0;//离开的地方没怪
			}
		}


	}



private:
	Animation animation_enemy_fish; //动画
	POINT enemy_fish_position;			//位置
	bool is_alive = true;			//是否存活
	bool is_can_bemove = false;		//是否可以被移动
	bool is_can_move = true;		//是否可以移动
	int x = 160, y = 80;
};