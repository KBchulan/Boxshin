#ifndef _GAME_CONCRETE_SCENE_H_
#define _GAME_CONCRETE_SCENE_H_

#include"item.h"
#include"game_scene.h"
#include"player_lypo.h"
#include"player_diver.h"
#include"enemy_crab.h"
#include"enemy_fish.h"
#include"map_randow_create.h"

extern int flag;

//玩家信息
extern Player* player;
extern POINT player_position;
extern int player_map_x, player_map_y;

//敌人信息
Enemy* enemy_crab = nullptr;

//地图信息
extern int game_map[14][12];

POINT penetration_wall_position = { 0,0 };			//可穿过墙的位置
POINT penetration_wall_position_01 = { 0,0 };		//可穿过墙的位置
POINT button_position = { 0,0 };					//按钮的位置

GameScene* game_background_scene;

class Map61 :public Scene {
public:
	Map61() = default;
	~Map61() = default;

	void scene_enter() {
		game_background_scene = new GameScene();
		game_background_scene->scene_enter();

		coral=new Coral();
		star=new Star();

		for (int i = 0; i < 14; i++) {
			game_map[i][2] = 3;
			game_map[i][9] = 3;
		}
		for (int i = 0; i < 12; i++) {
			game_map[3][i] = 3;
			game_map[10][i] = 3;
		}
		game_map[6][3] = 3;
		game_map[6][4] = 3;
		game_map[6][5] = 3;
		game_map[7][5] = 3;
		game_map[8][5] = 3;

		game_map[7][4] = 4;


		player->set_position(5, 5, 1);

	}

	void data_input(const ExMessage& msg) {
		game_background_scene->data_input(msg);
		player->data_input(msg);
	}

	void data_update(int delta) {
		if (flag != 61) {
			scene_manager.switch_to(flag);
		}
		player->data_update(delta);
	}

	void picture_draw() {
		game_background_scene->picture_draw();
		player->picture_draw();

		for (int i = 0; i < 14; i++) {
			for (int j = 0; j < 12; j++) {
				switch (game_map[i][j]) {
				case 3:
					coral->picture_draw(i, j);
					break;
				case 4:
					star->picture_draw(i, j);
				default:
					break;
				}
			}
		}

	}

	void scene_exit() {
		game_background_scene->scene_exit();
		memset(game_map, 0, sizeof(game_map));
		delete coral;
		delete star;
		delete game_background_scene;
	}

private:
	Coral* coral;
	Star* star;

};

class Map62 :public Scene {
public:
	Map62() = default;
	~Map62() = default;


	void scene_enter() {
		game_background_scene = new GameScene();
		game_background_scene->scene_enter();

		player->set_position(3, 5, 2);
		penetration_wall_position = { 7,2 };
		penetration_wall_position_01 = { 7,2 };

		star = new Star();
		coral = new Coral();
		bubble = new Bubble();
		enemy_crab = new EnemyCrab();
		coral_bullle = new CoralBullle();
		penetration_wall = new Penetration_wall();

		game_map[enemy_crab->enemy_x][enemy_crab->enemy_y] = 2;

		for (int i = 0; i <= 7; i++) {
			game_map[i][1] = 3;
		}
		for (int i = 7; i < 13; i++) {
			game_map[i][0] = 3;
		}
		game_map[2][0] = game_map[3][0] = 3;
		for (int i = 0; i < 12; i++) {
			game_map[12][i] = 3;
		}
		for (int i = 1; i < 11; i++) {
			game_map[0][i] = 3;
		}
		game_map[1][10] = game_map[2][10] = game_map[3][10] = game_map[3][11] = game_map[4][11] = game_map[5][11] = game_map[5][10] = 3;
		for (int i = 5; i < 13; i++) {
			game_map[i][10] = 3;
		}
		game_map[13][4] = game_map[13][5] = 3;
		for (int i = 3; i < 8; i++) {
			game_map[7][i] = 3;
		}
		for (int i = 9; i < 11; i++) {
			game_map[7][i] = 3;
		}
		for (int i = 8; i <= 11; i++) {
			game_map[i][5] = 3;
		}

		game_map[4][10] = 5;
		game_map[4][9] = 6;

		game_map[10][3] = 4;
		game_map[10][8] = 4;

		game_map[7][2] = 7;


	}

	void data_input(const ExMessage& msg) {
		game_background_scene->data_input(msg);
		
		player->data_input(msg);
		enemy_crab->data_input(msg);
		
		
	}

	void data_update(int delta) {	
		star->data_update(delta);
		coral->data_update(delta);
		bubble->data_update(delta);
		enemy_crab->data_update(delta);
		player->data_update(delta);		
		coral_bullle->data_update(delta);
		penetration_wall->data_update(delta);
		if (flag != 62) {
			scene_manager.switch_to(flag);
		}
	}

	void picture_draw() {
		game_background_scene->picture_draw();

		for (int i = 0; i < 14; i++) {
			for (int j = 0; j < 12; j++) {
				switch (game_map[i][j]) {
				case 2:
					enemy_crab->picture_draw();
					break;
				case 3:
					coral->picture_draw(i, j);
					break;
				case 4:
					star->picture_draw(i, j);
					break;
				case 5:
					coral_bullle->picture_draw(i, j);
					break;
				case 6:
					bubble->picture_draw(i, j);
					break;
				case 7:
					penetration_wall->picture_draw(i, j);
					break;
				default:
					break;
				}
			}
		}

		
		player->picture_draw();

	}

	void scene_exit() {
		game_background_scene->scene_exit();
		memset(game_map, 0, sizeof(game_map));
		enemy_crab = nullptr;

		delete star;
		delete coral;
		delete bubble;
		delete coral_bullle;
		delete penetration_wall;
		delete game_background_scene;
	}

private:
	Star* star;
	Coral* coral;
	Bubble* bubble;
	CoralBullle* coral_bullle;
	Penetration_wall* penetration_wall;

};

class Map63 :public Scene {
public:
	Map63() = default;
	~Map63() = default;

	void scene_enter() {
		game_background_scene = new GameScene();
		game_background_scene->scene_enter();

		player->set_position(4, 5, 1);
		penetration_wall_position = { 7,5 };
		penetration_wall_position_01 = { 8,5 };
		button_position = { 6,7 };

		star = new Star();
		door = new Door();
		coral = new Coral();
		bubble = new Bubble();
		enemy_crab = new EnemyCrab();
		game_button = new GameButton();
		coral_bullle = new CoralBullle();
		penetration_wall = new Penetration_wall();

		for (int i = 0; i < 14; i++) {
			game_map[i][2] = 3;
			game_map[i][8] = 3;
		}
		for (int i = 0; i < 12; i++) {
			game_map[2][i] = 3;
			game_map[13][i] = 3;
		}

		game_map[3][3] = 3;
		game_map[4][3] = 3;
		game_map[5][3] = 3;
		game_map[3][7] = 3;
		game_map[4][7] = 3;
		game_map[5][7] = 3;
		game_map[7][4] = 3;
		game_map[8][4] = 3;
		game_map[7][6] = 3;
		game_map[8][6] = 3;
		game_map[10][3] = 3;
		game_map[11][3] = 3;
		game_map[12][3] = 3;
		game_map[10][7] = 3;
		game_map[11][7] = 3;
		game_map[12][7] = 3;
		game_map[7][9] = 3;
		game_map[8][9] = 3;

		game_map[7][5] = 7;			// 可穿越墙壁
		game_map[8][5] = 7;			// 可穿越墙壁
		game_map[6][7] = 8;			// 机关触发器
		game_map[10][4] = 9;		// 机关门
		game_map[10][5] = 9;		// 机关门
		game_map[10][6] = 9;		// 机关门
		game_map[9][7] = 5;			// 泡泡
		game_map[9][6] = 6;			// 泡泡

		game_map[11][5] = 4;		// 星星

		game_map[7][3] = 2;			// 螃蟹
	}

	void data_input(const ExMessage& msg) {
		game_background_scene->data_input(msg);

		player->data_input(msg);
		enemy_crab->data_input(msg);
	}

	void data_update(int delta) {
		star->data_update(delta);
		door->data_update(delta);
		coral->data_update(delta);
		bubble->data_update(delta);
		enemy_crab->data_update(delta);
		game_button->data_update(delta);
		player->data_update(delta);
		coral_bullle->data_update(delta);
		penetration_wall->data_update(delta);

		if (flag != 63) {
			scene_manager.switch_to(flag);
		}
	}

	void picture_draw() {
		game_background_scene->picture_draw();
		setbkmode(TRANSPARENT);
		outtextxy(370, 40, _T("Our button needs to be touched by the crab. If the character touches it, please start again."));
		for (int i = 0; i < 14; i++) {
			for (int j = 0; j < 12; j++) {
				switch (game_map[i][j]) {
				case 2:
					if (i == 6 && j == 7)
						game_button->picture_draw(i, j);
					enemy_crab->picture_draw();
					break;
				case 3:
					coral->picture_draw(i, j);
					break;
				case 4:
					star->picture_draw(i, j);
					break;
				case 5:
					coral_bullle->picture_draw(i, j);
					break;
				case 6:
					bubble->picture_draw(i, j);
					break;
				case 7:
					penetration_wall->picture_draw(i, j);
					break;
				case 8:
					game_button->picture_draw(i, j);
					break;
				case 9:
					if (!(enemy_crab->enemy_x == 6 && enemy_crab->enemy_y == 7))
						door->picture_draw(i, j);
					else
						game_map[i][j] = 0;
					break;
				default:
					break;
				}
			}
		}

		if (player_map_x == 6 && player_map_y == 7) {
			game_button->picture_draw(0, 0);
		}
		player->picture_draw();
		
	}

	void scene_exit() {
		game_background_scene->scene_exit();
		memset(game_map, 0, sizeof(game_map));
		enemy_crab = nullptr;

		delete star;
		delete door;
		delete coral;
		delete bubble;
		delete coral_bullle;
		delete game_button;
		delete penetration_wall;
		delete game_background_scene;
	}

private:
	Star* star;
	Door* door;
	Coral* coral;
	Bubble* bubble;
	CoralBullle* coral_bullle;
	GameButton* game_button;
	Penetration_wall* penetration_wall;

};

class Map64 :public Scene {
public:
	Map64() = default;
	~Map64() = default;

	void scene_enter() {
		game_background_scene = new GameScene();
		game_background_scene->scene_enter();
		player->set_position(4, 5, 1);

		fish_enemy = new enemy_fish();
		coral = new Coral();
		star = new Star();
		bubble = new Bubble();
		coral_bullle = new CoralBullle();

		fish_enemy->set_pos_xy(6, 10);
		fish_enemy->set_move_sum(0);

		for (int i = 0; i <= 13; i++) {
			game_map[i][0] = 3;
		}
		for (int j = 0; j <= 11; j++) {
			game_map[0][j] = 3;
		}
		for (int i = 0; i <= 13; i++) {
			game_map[i][11] = 3;
		}
		for (int j = 0; j <= 11; j++) {
			game_map[13][j] = 3;
		}
		for (int i = 0; i <= 8; i++) {
			game_map[i][8] = 3;
		}
		game_map[12][8] = 3;
		game_map[11][8] = 3;


		game_map[2][10] = 4;			//星星
		game_map[8][7] = 5;				//珊瑚
		game_map[8][6] = 6;				//泡泡


		game_map[fish_enemy->enemy_x][fish_enemy->enemy_y] = 21;			//预留给怪鱼的位置

	}

	void data_input(const ExMessage& msg) {
		game_background_scene->data_input(msg);
		player->data_input(msg);
		fish_enemy->data_input(msg);

	}

	void data_update(int delta) {
		player->data_update(delta);
		fish_enemy->data_update(delta);

		coral->data_update(delta);
		star->data_update(delta);
		bubble->data_update(delta);
		coral_bullle->data_update(delta);

		if (flag != 64) {
			scene_manager.switch_to(flag);
		}
	}

	void picture_draw() {
		game_background_scene->picture_draw();
		
		for (int i = 0; i < 14; i++) {
			for (int j = 0; j < 12; j++) {
				switch (game_map[i][j]) {
				case 3:
					coral->picture_draw(i, j);
					break;
				case 4:
					star->picture_draw(i, j);
					break;
				case 5:
					coral_bullle->picture_draw(i, j);
					break;
				case 6:
					bubble->picture_draw(i, j);
					break;
				case 21:case 22:
					fish_enemy->picture_draw();
					break;
				default:
					break;
				}
			}
		}
		player->picture_draw();
		
	}

	void scene_exit() {
		game_background_scene->scene_exit();
		memset(game_map, 0, sizeof(game_map));

		delete coral;
		delete star;
		delete bubble;
		delete coral_bullle;
		delete fish_enemy;
		delete game_background_scene;
	}

private:
	CoralBullle* coral_bullle;
	Bubble* bubble;
	Star* star;
	Coral* coral;
	enemy_fish* fish_enemy;

};

class Map65 :public Scene {
public:
	Map65() = default;
	~Map65() = default;

	void scene_enter() {
		game_background_scene = new GameScene();
		game_background_scene->scene_enter();
	}

	void data_input(const ExMessage& msg) {
		game_background_scene->data_input(msg);
	}

	void data_update(int delta) {
		if (flag != 65) {
			scene_manager.switch_to(flag);
		}
	}

	void picture_draw() {
		game_background_scene->picture_draw();
	}

	void scene_exit() {
		game_background_scene->scene_exit();
	}

private:

};

class Map66 :public Scene {
public:
	Map66() = default;
	~Map66() = default;

	void scene_enter() {
		game_background_scene = new GameScene();
		game_background_scene->scene_enter();
		map = new Map();
	}

	void data_input(const ExMessage& msg) {
		game_background_scene->data_input(msg);
		game_background_scene->data_input(msg);
		map->data_input(msg);
		if (msg.vkcode == 0x43 && msg.message == WM_KEYDOWN) {
			map->generate();
			scene_manager.switch_to(flag);
		}
	}

	void data_update(int delta) {
		map->data_update(delta);
		if (flag != 66) {
			scene_manager.switch_to(flag);
		}
	}

	void picture_draw() {
		game_background_scene->picture_draw();
		map->draw();
	}

	void scene_exit() {
		game_background_scene->scene_exit();
		delete map;
		delete game_background_scene;
	}

private:
	Map* map;

};

class Map67 :public Scene {
public:
	Map67() = default;
	~Map67() = default;

	void scene_enter() {
		game_background_scene = new GameScene();
		game_background_scene->scene_enter();
	}

	void data_input(const ExMessage& msg) {
		game_background_scene->data_input(msg);
	}

	void data_update(int delta) {
		if (flag != 67) {
			scene_manager.switch_to(flag);
		}
	}

	void picture_draw() {
		game_background_scene->picture_draw();
	}

	void scene_exit() {
		game_background_scene->scene_exit();
	}

private:


};

#endif // !_GAME_CONCRETE_SCENE_H_
