#ifndef _GAME_SCENE_H_
#define _GAME_SCENE_H_
//此处为主要内容

#include"scene.h"
#include"button.h"
#include"scene_manager.h"

extern int flag;
extern IMAGE img_game_background;
extern SceneManager scene_manager;

class GameScene :public Scene {
public:
	GameScene() = default;
	~GameScene() = default;
		/*
	负责人：
	功能：初始化按钮位置
	参数：void
	返回值：void
	*/
	void scene_enter() {
		//初始化
		voice_button.right = 1280;
		voice_button.top = 0;
		voice_button.left = voice_button.right - voice_button_x;
		voice_button.bottom = pause_button_y;
		gamevoice = GameVoice(voice_button, _T("resources/voice_button_idle.png"), _T("resources/voice_button_hovered.png"), _T("resources/voice_button_pushed.png"), voice_button_x, voice_button_y);

		pause_button.right = 1280;
		pause_button.top = 0;
		pause_button.left = pause_button.right - pause_button_x;
		pause_button.bottom = pause_button_y;
		gamepause = GamePause(pause_button, _T("resources/pause_button_idle.png"), _T("resources/pause_button_hovered.png"), _T("resources/pause_button_pushed.png"), pause_button_x, pause_button_y);


		reset_button.right = 1280;
		reset_button.top = 0;
		reset_button.left = reset_button.right - reset_button_x;
		reset_button.bottom = reset_button_y;
		gamereset = GameReset(reset_button, _T("resources/reset_button_idle.png"), _T("resources/reset_button_hovered.png"), _T("resources/reset_button_pushed.png"), reset_button_x, reset_button_y);
	}
		/*
	负责人：
	功能：接受用户点击
	参数：用户点击
	返回值：void
	*/
	 void data_input(const ExMessage& msg) {
		//按钮输入
		gamereset.Button_input(msg);
		gamepause.Button_input(msg);
		gamevoice.Button_input(msg);
	}
		/*
	负责人：
	功能：根据改变的flag值进行匹配并且进行相应操作
	参数：
	返回值：void
	*/
	void data_update(int delta) {
		//更新数据
		
	}
		/*
	负责人：
	功能：渲染按钮
	参数：void
	返回值：void
	*/
	 void picture_draw() {
		putimage(0, 0, &img_game_background);
		gamereset.Button_draw();
		gamepause.Button_draw();
		gamevoice.Button_draw();
	}
		/*
	负责人：
	功能：退出当前页面
	参数：void
	返回值：void
	*/
	void scene_exit() {
		//退出场景，释放资源
	}

private:
	class GameReset:public Button {
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
			flag = 9;						//跳转暂停场景game_scene_pause
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

	int x_distance = 30;			//按钮间距

};


#endif // !_GAME_SCENE_H
