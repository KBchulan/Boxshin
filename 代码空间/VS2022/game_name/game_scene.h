#ifndef _GAME_SCENE_H_
#define _GAME_SCENE_H_
//�˴�Ϊ��Ҫ����

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
		//��ʼ��
	}

	void data_input(const ExMessage& msg) {
		//��ť����
		gamereset.Button_input(msg);
		gamepause.Button_input(msg);
		gamevoice.Button_input(msg);
	}

	void data_update(int delta) {
		//��������
		
	}

	void picture_draw() {
		putimage(0, 0, &img_menu_background);
		gamereset.Button_draw();
		gamepause.Button_draw();
		gamevoice.Button_draw();
	}

	void scene_exit() {
		//�˳��������ͷ���Դ
	}

private:
	class GameReset :public Button {
	public:
		GameReset() = default;
		~GameReset() = default;

		GameReset(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int x, int y) :
			Button(rect, path_img_idle, path_img_hovered, path_img_pushed, x, y) {}

	protected:
		void OnClick() {
			//
		}

	};

	class GamePause :public Button {
	public:
		GamePause() = default;
		~GamePause() = default;

		GamePause(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int x, int y) :
			Button(rect, path_img_idle, path_img_hovered, path_img_pushed, x, y) {}

	protected:
		void OnClick() {
			flag = 9;						//��ת��ͣ����game_scene_pause
		}
	};

	class GameVoice :public Button {
	public:
		GameVoice() = default;
		~GameVoice() = default;

		GameVoice(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int x, int y) :
			Button(rect, path_img_idle, path_img_hovered, path_img_pushed, x, y) {}

	protected:
		void OnClick() {
			//
		}
	};



private:

	RECT reset_button;
	int reset_button_x = 50,
		reset_button_y = 50;
	GameReset gamereset;

	RECT pause_button;
	int pause_button_x = 50,
		pause_button_y = 50;
	GamePause gamepause;

	RECT voice_button;
	int voice_button_x = 50,
		voice_button_y = 50;
	GameVoice gamevoice;

	int x_distance = 30;			//��ť���

};


#endif // !_GAME_SCENE_H
