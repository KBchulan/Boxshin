#ifndef _MENU_SCENE_H_
#define _MENU_SCENE_H_

#include"scene.h"
#include"button.h"
#include"scene_manager.h"


extern int flag;
extern int music_num;
extern IMAGE img_menu_background;
extern SceneManager scene_manager;

class MenuScene :public Scene {
public:
	MenuScene() = default;
	~MenuScene() = default;
	/*
	负责人：
	功能：初始化按键位置，贴图,添加音乐
	参数：void
	返回值：void
	*/
	void scene_enter() {
		//放个音乐
		//初始化按钮一类的
		start_button.left = 530;
		start_button.right = start_button.left + start_button_x;
		start_button.top = 350;
		start_button.bottom = start_button.top + start_button_y;
		startgame = StartGame(start_button, _T("resources/start_idle.png"), _T("resources/start_hovered.png"), _T("resources/start_pushed.png"), start_button_x, start_button_y);
		
		set_button.left = start_button.left;
		set_button.right = set_button.left + set_button_x;
		set_button.top = start_button.bottom + distance;
		set_button.bottom = set_button.top + set_button_y;
		set = Set(set_button, _T("resources/set_idle.png"), _T("resources/set_hovered.png"), _T("resources/set_pushed.png"), set_button_x, set_button_y);

		exit_button.left = start_button.left;
		exit_button.right= exit_button.left + exit_button_x;
		exit_button.top = set_button.bottom + distance;
		exit_button.bottom = exit_button.top + exit_button_y;
		exit = Exit(exit_button, _T("resources/exit_idle.png"), _T("resources/exit_hovered.png"), _T("resources/exit_pushed.png"), exit_button_x, exit_button_y);
		
		voice_button.right = 1280;
		voice_button.top = 0;
		voice_button.left = voice_button.right - voice_button_x;
		voice_button.bottom = voice_button_y;
		gamevoice = GameVoice(voice_button, _T("resources/sound_idle.png"), _T("resources/sound_hovered.png"), _T("resources/sound_pushed.png"), voice_button_x, voice_button_y);

		voice_open_button.right = 1280;
		voice_open_button.top = 0;
		voice_open_button.left = voice_open_button.right - voice_open_button_x;
		voice_open_button.bottom = voice_open_button_y;
		gamevoiceopen = GameVoiceOpen(voice_open_button, _T("resources/sound_off_idle.png"), _T("resources/sound_off_hovered.png"), _T("resources/sound_off_pushed.png"), voice_open_button_x, voice_open_button_y);

		mciSendString(_T("play menu_bgm repeat from 0"), NULL, 0, NULL);
	}

	void data_input(const ExMessage& msg) {
		//按钮信息处理
		set.Button_input(msg);
		exit.Button_input(msg);
		startgame.Button_input(msg);

		if (music_num == 1)
			gamevoice.Button_input(msg);
		else if (music_num == 0)
			gamevoiceopen.Button_input(msg);

		//处理按键信息
	}
	
	void data_update(int delta) {
		//数据更新
		if (flag != 1) {
			scene_manager.switch_to(flag);
		}
	}
	/*
	负责人：
	功能：按钮贴图渲染
	参数：void
	返回值：void
	*/
	void picture_draw() {
		putimage(0, 0, &img_menu_background);

		//按钮绘制
		set.Button_draw(set_button.left,set_button.top);
		exit.Button_draw(exit_button.left,exit_button.top);
		startgame.Button_draw(start_button.left,start_button.top);

		if (music_num == 1)
			gamevoice.Button_draw();
		else if (music_num == 0)
			gamevoiceopen.Button_draw();

	}
		/*
	负责人：
	功能：退出当前页面
	参数：void
	返回值：void
	*/
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
			flag = 2;			//角色选择界面
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
			flag = 5;			//设置界面
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
			flag = 6;			//退出游戏界面
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
			music_num = 0;
		}
	};

	class GameVoiceOpen :public Button {
	public:
		GameVoiceOpen() = default;
		~GameVoiceOpen() = default;

		GameVoiceOpen(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int x, int y) :
			Button(rect, path_img_idle, path_img_hovered, path_img_pushed, x, y) {}

	protected:
		void OnClick() {
			music_num = 1;
		}
	};
	
	
private:
	int distance = 30;								//不同按钮y间距

	RECT start_button;								//定义开始游戏矩形
	int start_button_x = 220,
		start_button_y = 80;						//按钮的长宽
	StartGame startgame;							//定义按钮

	RECT set_button;								//定义设置矩形
	int set_button_x = 220,
		set_button_y = 80;							//矩形长宽
	Set set;										//定义按钮

	RECT exit_button;								//定义退出游戏矩形
	int exit_button_x = 220,
		exit_button_y = 80;							//按钮长宽
	Exit exit;										//定义按钮

	RECT voice_button;
	int voice_button_x = 50,
		voice_button_y = 50;
	GameVoice gamevoice;

	RECT voice_open_button;
	int voice_open_button_x = 50,
		voice_open_button_y = 50;
	GameVoiceOpen gamevoiceopen;


};

#endif // !_MENU_SCENE_H_
