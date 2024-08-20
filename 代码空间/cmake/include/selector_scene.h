#ifndef _SELECTOR_SCENE_H_
#define _SELECTOR_SCENE_H_

#include"scene.h"
#include"button.h"
#include"scene_manager.h"

extern int flag;
extern SceneManager scene_manager;

class SelectorScene :public Scene {
public:
	SelectorScene() = default;
	~SelectorScene() = default;

	void scene_enter() {
		//各种按钮位置初始化
	}

	void data_input(const ExMessage& msg) {
		if (msg.message == WM_LBUTTONDOWN) {
			flag = 3;
		}
		scene_manager.switch_to(flag);
		//处理玩家输入
	}

	void data_update(int delta) {
		//更新各种信息
	}

	void picture_draw() {
		std::cout << "22222" << std::endl;
		//绘制图片
	}

	void scene_exit() {
		//退出场景，释放资源
	}

private:
	
};



#endif // !_SELECTOR_SCENE_H_
