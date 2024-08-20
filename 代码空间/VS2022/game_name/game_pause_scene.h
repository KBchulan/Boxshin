#ifndef GAME_PAUSE_SCENE_H
#define GAME_PAUSE_SCENE_H

#include"scene.h"
#include"button.h"
#include"scene_manager.h"

class GamePauseScene : public Scene {
public:
	GamePauseScene() = default;
	~GamePauseScene() = default;

	void scene_enter() {
		//进入场景
	}

	void data_input(const ExMessage& msg) {
		//输入数据
	}

	void data_update(int delta) {
		//更新数据
	}

	void picture_draw() {
		//绘制图片
	}

	void scene_exit() {
		//退出场景
	}

private:



};


#endif // !GAME_PAUSE_SCENE_H