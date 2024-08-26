#ifndef __GAME_PAUSE_SCENE_H__
#define __GAME_PAUSE_SCENE_H__

#include"game_scene.h"

extern int play_num;
extern int previous_flag;

class GamePauseScene :public Scene {
public:
	GamePauseScene() = default;
	~GamePauseScene() = default;

	//进入场景
	void scene_enter() {
		//按钮初始化
		continue_button.right = 760;
		continue_button.top = 240;
		continue_button.left = continue_button.right - pause_button_x;
		continue_button.bottom = continue_button.top + pause_button_y;
		pausecontinue = PauseContinue(continue_button, _T("resources/pause_continue_idle.png"), _T("resources/pause_continue_hovered.png"), _T("resources/pause_continue_pushed.png"), pause_button_x, pause_button_y);

		map_button.right = 730;
		map_button.top = 369;
		map_button.left = map_button.right - map_button_x;
		map_button.bottom = map_button.top + map_button_y;
		pausemap = PauseMap(map_button, _T("resources/map_idle.png"), _T("resources/map_hovered.png"), _T("resources/map_pushed.png"), map_button_x, map_button_y);

		menu_button.right = 760;
		menu_button.top = 480;
		menu_button.left = menu_button.right - menu_button_x;
		menu_button.bottom = menu_button.top + menu_button_y;
		pausemenu = PauseMenu(menu_button, _T("resources/pause_menu_idle.png"), _T("resources/pause_menu_hovered.png"), _T("resources/pause_menu_pushed.png"), menu_button_x, menu_button_y);
	}

	//处理数据
	void data_input(const ExMessage& msg) { 
		pausecontinue.Button_input(msg);
		pausemenu.Button_input(msg);
		pausemap.Button_input(msg);
	}

	//数据更新
	void data_update(int delta) {
		if (flag != 9) {
			scene_manager.switch_to(flag);
		}
	}

	//图形绘制
	void picture_draw() {
		putimage(0, 0, &img_game_pause_background);
		putimage(120, 67.5, &img_game_pause_box);
		pausecontinue.Button_draw(continue_button.left, continue_button.top);
		pausemenu.Button_draw(menu_button.left, menu_button.top);
		pausemap.Button_draw(map_button.left, map_button.top);
	}

	//退出场景
	void scene_exit() { 
	
	}


private:
	class PauseContinue :public Button {
	public:
		PauseContinue() = default;
		~PauseContinue() = default;

		PauseContinue(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int x, int y) :
			Button(rect, path_img_idle, path_img_hovered, path_img_pushed, x, y) {}
	protected:
		void OnClick() {
			play_num = 1;
			flag = previous_flag;
		}
	};

	class PauseMap :public Button {
	public:
		PauseMap() = default;
		~PauseMap() = default;

		PauseMap(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int x, int y) :
			Button(rect, path_img_idle, path_img_hovered, path_img_pushed, x, y) {}
	protected:
		void OnClick() {
			play_num = 1;
			flag = 4;
		}
	};
	class PauseMenu :public Button {
	public:
		PauseMenu() = default;
		~PauseMenu() = default;

		PauseMenu(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int x, int y) :
			Button(rect, path_img_idle, path_img_hovered, path_img_pushed, x, y) {}
	protected:
		void OnClick() {
			play_num = 1;
			flag = 1;
		}
	};


private:
	int pause_button_x = 240, pause_button_y = 75;
	int menu_button_x = 240, menu_button_y = 75;
	int map_button_x = 180, map_button_y = 57;

	RECT continue_button;
	PauseContinue pausecontinue;

	RECT menu_button;
	PauseMenu pausemenu;

	RECT map_button;
	PauseMap pausemap;
};

#endif // !__GAME_PAUSE_SCENE_H__