#ifndef _MENU_SCENE_H_
#define _MENU_SCENE_H_

#include"scene.h"
#include"button.h"
#include"scene_manager.h"

extern int flag;
extern IMAGE img_menu_background;
extern SceneManager scene_manager;

extern IMAGE start_idle;
extern IMAGE start_hovered;
extern IMAGE start_pushed;

extern IMAGE set_idle;
extern IMAGE set_hovered;
extern IMAGE set_pushed;

extern IMAGE exit_idle;
extern IMAGE exit_hovered;
extern IMAGE exit_pushed;

class MenuScene :public Scene {
public:
	MenuScene() = default;
	~MenuScene() = default;

	void scene_enter() {
		//放个音乐
		//初始化按钮一类的
		start_button.left = 580;
		start_button.right = start_button.left + start_button_x;
		start_button.top = 400;
		start_button.bottom = start_button.top + start_button_y;
		startgame = StartGame(start_button, _T("resources/start_idle.png"), _T("resources/start_hovered.png"), _T("resources/start_pushed.png"), start_button_x, start_button_y);
		
		set_button.left = start_button.left;
		set_button.right = set_button.left + set_button_x;
		set_button.top = start_button.bottom + distance;
		set_button.bottom = set_button.top + set_button_y;
		set = Set(set_button, _T("resources/set_idle.jpg"), _T("resources/set_hovered.jpg"), _T("resources/set_pushed.jpg"), set_button_x, set_button_y);

		exit_button.left = start_button.left;
		exit_button.right= exit_button.left + exit_button_x;
		exit_button.top = set_button.bottom + distance;
		exit_button.bottom = exit_button.top + exit_button_y;
		exit = Exit(exit_button, _T("resources/exit_idle.png"), _T("resources/exit_hovered.png"), _T("resources/exit_pushed.png"), exit_button_x, exit_button_y);
	
	}

	void data_input(const ExMessage& msg) {
		//按钮信息处理
		set.Button_input(msg);
		exit.Button_input(msg);
		startgame.Button_input(msg);

		//处理按键信息
	}

	void data_update(int delta) {
		//数据更新
		if (flag != 1) {
			scene_manager.switch_to(flag);
		}
	}

	void picture_draw() {
		putimage(0, 0, &img_menu_background);

		//按钮绘制
		set.Button_draw();
		exit.Button_draw();
		startgame.Button_draw();

	}

	void scene_exit() {
		//退出逻辑，如恢复按钮状态机
	}

private:
	//此处定义按钮
	class StartGame :public Button {
	public:
		StartGame() = default;
		~StartGame() = default;

		StartGame(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int x, int y)
			:Button(rect, path_img_idle, path_img_hovered, path_img_pushed, x, y) {}

	protected:
		void OnClick() {
			flag = 2;	//角色选择界面
		}
	};

	class Set :public Button {
	public:
		Set() = default;
		~Set() = default;

		Set(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int x, int y)
			:Button(rect, path_img_idle, path_img_hovered, path_img_pushed, x, y) {}

	protected:
		void OnClick() {
			flag = 5;	//设置界面
		}
	};

	class Exit :public Button {
	public:
		Exit() = default;
		~Exit() = default;

		Exit(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int x, int y)
			: Button(rect, path_img_idle, path_img_hovered, path_img_pushed, x, y) {}

	protected:
		void OnClick() {
			flag = 6;	//退出游戏界面
		}
	};
	
	
private:
	int distance = 30;								//不同按钮y间距

	RECT start_button;								//定义开始游戏矩形
	int start_button_x = 100,
		start_button_y = 50;						//按钮的长宽
	StartGame startgame;							//定义按钮

	RECT set_button;								//定义设置矩形
	int set_button_x = 100,
		set_button_y = 50;							//矩形长宽
	Set set;										//定义按钮

	RECT exit_button;								//定义退出游戏矩形
	int exit_button_x = 100,
		exit_button_y = 50;							//按钮长宽
	Exit exit;										//定义按钮


};

#endif // !_MENU_SCENE_H_
