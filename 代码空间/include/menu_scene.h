#ifndef _MENU_SCENE_H_
#define _MENU_SCENE_H_

#include"scene.h"
#include"button.h"
#include"scene_manager.h"

extern int flag;
extern SceneManager scene_manager;


class MenuScene :public Scene {
public:
	MenuScene() = default;
	~MenuScene() = default;

	void scene_enter() {
		//放个音乐
		//初始化按钮一类的
	}

	void data_input(const ExMessage& msg) {
		if (msg.message == WM_LBUTTONDOWN) {
			flag = 2;
		}
		scene_manager.switch_to(flag);
		//处理按键信息
	}

	void data_update(int delta) {
		//数据更新
	}

	void picture_draw() {
		std::cout << "1111" << std::endl;
		//绘制一些按钮一类的
	}

	void scene_exit() {
		//退出逻辑，如恢复按钮状态机
	}

public:
	//此处定义按钮
	/*class StartGame:public Button{
	public:
		Setbutton(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed,int x,int y)
		:Button(rect, path_img_idle, path_img_hovered, path_img_pushed, x, y) {}
		~Setbutton() = default;
	protected:
		void OnClick() {
			flag = 4;
		}
	}
	
	*/

};

#endif // !_MENU_SCENE_H_
