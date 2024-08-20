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
		//按钮输入
		game_reset.Button_input(msg);
		game_pause.Button_input(msg);
		game_voice.Button_input(msg);
	}

	void data_update(int delta) {
		//更新数据

	}

	void picture_draw() {
		putimage(0, 0, &img_menu_background);
		game_reset.Button_draw();
		game_pause.Button_draw();
		game_voice.Button_draw();
	}

	void scene_exit() {
		//退出场景，释放资源
	}

private:
	//class Menu :public Button {
	//public:
	//	Menu() = default;
	//	~Menu() = default;

	//	Menu(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int x, int y)
	//		:Button(rect, path_img_idle, path_img_hovered, path_img_pushed, x, y) {}

	//protected:
	//	void OnClick() {
	//		flag = 1;
	//	}
	//};

	class Game_Reset :public Button {
	public:
		Game_Reset() = default;
		~Game_Reset() = default;

		Game_Reset(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int x, int y) {}

	protected:
		void OnClick() {

		}

	};

	class Game_Pause :public Button {
	public:
		Game_Pause() = default;
		~Game_Pause() = default;
		Game_Pause(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int x, int y) {
		}

	protected:
		void OnClick() {
			flag = 9;//跳转暂停场景game_scene_pause
		}
	};

	class Game_Voice :public Button {
	public:
		Game_Voice() = default;
		~Game_Voice() = default;

		//Game_Voice(RECT rect, LPCTSTR path_img_on, LPCTSTR path_img_off, LPCTSTR path_img_  , int x, int y) {}
		Game_Voice(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int x, int y){
			game_voice = rect;
			loadimage(&img_idle, path_img_idle, x, y);
			loadimage(&img_hovered, path_img_hovered, x, y);
			loadimage(&img_pushed, path_img_pushed, x, y);
		}
	protected:
		void Onclick() {

		}
	};



private:

	RECT game_reset;
	int game_reset_x = 50,
		game_reset_y = 50;
	Game_Reset game_reset;

	RECT game_pause;
	int game_pause_x = 50,
		game_pause_y = 50;
	Game_Pause game_pause;

	RECT game_voice;
	int game_voice_x = 50,
		game_voice_y = 50;
	Game_Voice game_voice;

	int x_distance = 30;//按钮间距

};


#endif // !_GAME_SCENE_H_
