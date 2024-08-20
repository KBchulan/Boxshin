#ifndef __GAME_PAUSE_SCENE_H__
#define __GAME_PAUSE_SCENE_H__

#include"game_scene.h"

class GamePauseScene :public Scene {
public:
	GamePauseScene() = default;
	~GamePauseScene() = default;

	//���볡��
	void scene_enter() {
		//��ť��ʼ��
		continue_button.right = 1280;
		continue_button.top = 0;
		continue_button.left = continue_button.right - pause_button_x;
		continue_button.bottom = pause_button_y;
		pausecontinue = PauseContinue(continue_button, _T("resources/pause_continue_idle.png"), _T("resources/pause_continue_hovered.png"), _T("resources/pause_continue_pushed.png"), pause_button_x, pause_button_y);

		menu_button.right = 1280;
		menu_button.top = pause_button_y;
		menu_button.left = menu_button.right - pause_button_x;
		menu_button.bottom = menu_button.top + pause_button_y;
		pausemenu = PauseMenu(menu_button, _T("resources/pause_menu_idle.png"), _T("resources/pause_menu_hovered.png"), _T("resources/pause_menu_pushed.png"), pause_button_x, pause_button_y);
	}

	//��������
	void data_input(const ExMessage& msg) { 
		pausecontinue.Button_input(msg);
		pausemenu.Button_input(msg);
	}

	//���ݸ���
	void data_update(int delta) {
		if (flag != 9) {
			scene_manager.switch_to(flag);
		}
	}

	//ͼ�λ���
	void picture_draw() {
		pausecontinue.Button_draw();
		pausemenu.Button_draw();
	}

	//�˳�����
	void scene_exit() { }


private:
	class PauseContinue :public Button {
	public:
		PauseContinue() = default;
		~PauseContinue() = default;

		PauseContinue(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int x, int y) :
			Button(rect, path_img_idle, path_img_hovered, path_img_pushed, x, y) {}
	protected:
		void OnClick() {
			//������Ϸ
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
			flag = 1;
		}
	};
private:
	int pause_button_x = 50,
		pause_button_y = 50;

	RECT continue_button;
	PauseContinue pausecontinue;

	RECT menu_button;
	PauseMenu pausemenu;
};

#endif // !__GAME_SCENE_PAUSE_H__