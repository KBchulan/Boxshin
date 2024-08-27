#ifndef _GAME_CONCRETE_SCENE_H_
#define _GAME_CONCRETE_SCENE_H_

#include"item.h"
#include"game_scene.h"
#include"player_lypo.h"
#include"player_diver.h"

extern int flag;
//玩家信息
extern Player* player;
extern POINT player_position;

//敌人信息


//地图信息
extern int game_map[14][12];


GameScene* game_background_scene;

class Map61 :public Scene {
public:
	Map61() = default;
	~Map61() = default;

	void scene_enter() {
		game_background_scene = new GameScene();
		game_background_scene->scene_enter();

		coral = new Coral();
		star = new Star();

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

		player->set_position(5, 5);

	}

	void data_input(const ExMessage& msg) {
		game_background_scene->data_input(msg);
		player->data_input(msg);
	}

	void data_update(int delta) {
		game_background_scene->data_update(delta);
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
		//delete coral;
		//delete star;
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
	}

	void data_input(const ExMessage& msg) {
		game_background_scene->data_input(msg);
	}

	void data_update(int delta) {
		game_background_scene->data_update(delta);
	}

	void picture_draw() {
		game_background_scene->picture_draw();
	}

	void scene_exit() {
		game_background_scene->scene_exit();
	}

private:


};

class Map63 :public Scene {
public:
	Map63() = default;
	~Map63() = default;

	void scene_enter() {
		game_background_scene = new GameScene();
		game_background_scene->scene_enter();
	}

	void data_input(const ExMessage& msg) {
		game_background_scene->data_input(msg);
	}

	void data_update(int delta) {
		game_background_scene->data_update(delta);
	}

	void picture_draw() {
		game_background_scene->picture_draw();
	}

	void scene_exit() {
		game_background_scene->scene_exit();
	}

private:


};

class Map64 :public Scene {
public:
	Map64() = default;
	~Map64() = default;

	void scene_enter() {
		game_background_scene = new GameScene();
		game_background_scene->scene_enter();
	}

	void data_input(const ExMessage& msg) {
		game_background_scene->data_input(msg);
	}

	void data_update(int delta) {
		game_background_scene->data_update(delta);
	}

	void picture_draw() {
		game_background_scene->picture_draw();
	}

	void scene_exit() {
		game_background_scene->scene_exit();
	}

private:


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
		game_background_scene->data_update(delta);
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
	}

	void data_input(const ExMessage& msg) {
		game_background_scene->data_input(msg);
		game_background_scene->data_input(msg);
	}

	void data_update(int delta) {
		game_background_scene->data_update(delta);
	}

	void picture_draw() {
		game_background_scene->picture_draw();
	}

	void scene_exit() {
		game_background_scene->scene_exit();
	}

private:


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
		game_background_scene->data_update(delta);
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
