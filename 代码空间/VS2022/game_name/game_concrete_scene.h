#ifndef _GAME_CONCRETE_SCENE_H_
#define _GAME_CONCRETE_SCENE_H_

#include"game_scene.h"

GameScene* game_background_scene;

class Map61 :public Scene {
public:
	Map61() = default;
	~Map61() = default;
	
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

class Map62 :public Scene {
public:
	Map62() = default;
	~Map62() = default;

	/*
	������:
	����: ����ؿ�����
	*/
	void scene_enter() {
		game_background_scene = new GameScene();
		game_background_scene->scene_enter();
	}

	/*
	������:
	����: ����ؿ�������Ϣ
	*/
	void data_input(const ExMessage& msg) {
		game_background_scene->data_input(msg);
	}

	/*
	������:
	����: ���¹ؿ�����
	*/
	void data_update(int delta) {
		game_background_scene->data_update(delta);
	}

	/*
	������:
	����: ���ƹؿ�����
	*/
	void picture_draw() {
		game_background_scene->picture_draw();
	}

	/*
	������:
	����: �˳��ؿ�����
	*/
	void scene_exit() {
		game_background_scene->scene_exit();
	}

private:


};

class Map63 :public Scene {
public:
	Map63() = default;
	~Map63() = default;

	/*
	������:
	����: ����ؿ�����
	*/
	void scene_enter() {
		game_background_scene = new GameScene();
		game_background_scene->scene_enter();
	}

	/*
	������:
	����: ����ؿ�������Ϣ
	*/
	void data_input(const ExMessage& msg) {
		game_background_scene->data_input(msg);
	}

	/*
	������:
	����: ���¹ؿ�����
	*/
	void data_update(int delta) {
		game_background_scene->data_update(delta);
	}

	/*
	������:
	����: ���ƹؿ�����
	*/
	void picture_draw() {
		game_background_scene->picture_draw();
	}

	/*
	������:
	����: �˳��ؿ�����
	*/
	void scene_exit() {
		game_background_scene->scene_exit();
	}

private:


};

class Map64 :public Scene {
public:
	Map64() = default;
	~Map64() = default;

	/*
	������:
	����: ����ؿ�����
	*/
	void scene_enter() {
		game_background_scene = new GameScene();
		game_background_scene->scene_enter();
	}

	/*
	������:
	����: ����ؿ�������Ϣ
	*/
	void data_input(const ExMessage& msg) {
		game_background_scene->data_input(msg);
	}

	/*
	������:
	����: ���¹ؿ�����
	*/
	void data_update(int delta) {
		game_background_scene->data_update(delta);
	}

	/*
	������:
	����: ���ƹؿ�����
	*/
	void picture_draw() {
		game_background_scene->picture_draw();
	}

	/*
	������:
	����: �˳��ؿ�����
	*/
	void scene_exit() {
		game_background_scene->scene_exit();
	}

private:


};

class Map65 :public Scene {
public:
	Map65() = default;
	~Map65() = default;

	/*
	������:
	����: ����ؿ�����
	*/
	void scene_enter() {
		game_background_scene = new GameScene();
		game_background_scene->scene_enter();
	}

	/*
	������:
	����: ����ؿ�������Ϣ
	*/
	void data_input(const ExMessage& msg) {
		game_background_scene->data_input(msg);
	}

	/*
	������:
	����: ���¹ؿ�����
	*/
	void data_update(int delta) {
		game_background_scene->data_update(delta);
	}

	/*
	������:
	����: ���ƹؿ�����
	*/
	void picture_draw() {
		game_background_scene->picture_draw();
	}

	/*
	������:
	����: �˳��ؿ�����
	*/
	void scene_exit() {
		game_background_scene->scene_exit();
	}

private:


};

class Map66 :public Scene {
public:
	Map66() = default;
	~Map66() = default;

	/*
	������:
	����: ����ؿ�����
	*/
	void scene_enter() {
		game_background_scene = new GameScene();
		game_background_scene->scene_enter();
	}

	/*
	������:
	����: ����ؿ�������Ϣ
	*/
	void data_input(const ExMessage& msg) {
		game_background_scene->data_input(msg);
		game_background_scene->data_input(msg);
	}

	/*
	������:
	����: ���¹ؿ�����
	*/
	void data_update(int delta) {
		game_background_scene->data_update(delta);
	}

	/*
	������:
	����: ���ƹؿ�����
	*/
	void picture_draw() {
		game_background_scene->picture_draw();
	}

	/*
	������:
	����: �˳��ؿ�����
	*/
	void scene_exit() {
		game_background_scene->scene_exit();
	}

private:


};

class Map67 :public Scene {
public:
	Map67() = default;
	~Map67() = default;

	/*
	������:
	����: ����ؿ�����
	*/
	void scene_enter() {
		game_background_scene = new GameScene();
		game_background_scene->scene_enter();
	}

	/*
	������:
	����: ����ؿ�������Ϣ
	*/
	void data_input(const ExMessage& msg) {
		game_background_scene->data_input(msg);
	}

	/*
	������:
	����: ���¹ؿ�����
	*/
	void data_update(int delta) {
		game_background_scene->data_update(delta);
	}

	/*
	������:
	����: ���ƹؿ�����
	*/
	void picture_draw() {
		game_background_scene->picture_draw();
	}

	/*
	������:
	����: �˳��ؿ�����
	*/
	void scene_exit() {
		game_background_scene->scene_exit();
	}

private:


};

#endif // !_GAME_CONCRETE_SCENE_H_
