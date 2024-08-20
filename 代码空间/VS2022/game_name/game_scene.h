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
		if (flag == 1) {
			scene_exit();
		}
	}

	void picture_draw() {
		std::cout << "33333" << std::endl;
		//绘制图形
	}

	void scene_exit() {
		//退出场景，释放资源
	}

private:
	class Menu :public Button {
	public:
		Menu() = default;
		~Menu() = default;

		Menu(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int x, int y)
			:Button(rect, path_img_idle, path_img_hovered, path_img_pushed, x, y) {}

	protected:
		void OnClick() {
			flag = 1;
		}
	};

private:
	RECT menu_button;								//定义按钮矩形
	int menu_button_x = 100,
		menu_button_y = 50;							//按钮的长宽
	Menu menu;										//定义按钮

};


#endif // !_GAME_SCENE_H_
