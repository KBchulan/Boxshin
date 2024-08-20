#pragma once
#include"game_scene.h"
class Game_Scene_Pause :public Scene {
public:

	Game_Scene_Pause() = default;
	~Game_Scene_Pause() = default;

	//进入场景
	virtual void scene_enter() { }

	//处理数据
	virtual void data_input(const ExMessage& msg) { }

	//数据更新
	virtual void data_update(int delta) { }

	//图形绘制
	virtual void picture_draw() { }

	//退出场景
	virtual void scene_exit() { }
protected:

};