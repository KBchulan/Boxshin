#ifndef _GAME_SCENE_H_
#define _GAME_SCENE_H_
//此处为主要内容

#include"scene.h"
#include"button.h"
#include"scene_manager.h"

extern int flag;
extern SceneManager scene_manager;

class GameScene :public Scene {
public:
	GameScene() = default;
	~GameScene() = default;

	void scene_enter() {
		//初始化
	}

	void data_input(const ExMessage& msg) {
		if (msg.message == WM_LBUTTONDOWN) {
			flag = 1;
		}
		scene_manager.switch_to(flag);
		//处理输入数据
	}

	void data_update(int delta) {
		//更新数据
	}

	void picture_draw() {
		std::cout << "33333" << std::endl;
		//绘制图形
	}

	void scene_exit() {
		//退出场景，释放资源
	}

private:

};


#endif // !_GAME_SCENE_H_
