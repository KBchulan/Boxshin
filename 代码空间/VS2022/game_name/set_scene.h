#ifndef _SET_SCENE_H_
#define _SET_SCENE_H_

#include"scene.h"
#include"button.h"
#include"scene_manager.h"

extern int flag;
extern int sound_num;
extern ExMessage msg;
extern int music_num;
extern IMAGE img_set_background;
extern SceneManager scene_manager;

int music_drawflag = 0;
int sound_drawflag = 0;
int music_drawx;
int sound_drawx;

class SetScene :public Scene {
public:
	SetScene() = default;
	~SetScene() = default;
	 
	void scene_enter() {
		//初始化按钮
		Music_button.right = 450;
		Music_button.left = Music_button.right - Music_button_x;
		Music_button.top = 120;
		Music_button.bottom = Music_button.top + Music_button_y;
		music = Music(Music_button, _T("resources/music_idle.png"), _T("resources/music_hovered.png"), _T("resources/music_pushed.png"), Music_button_x, Music_button_y);

		Sound_button.right = Music_button.right;
		Sound_button.left = Sound_button.right - Sound_button_x;
		Sound_button.top = Music_button.bottom + distance_y;
		Sound_button.bottom = Sound_button.top + Sound_button_y;
		soundeffects = SoundEffects(Sound_button, _T("resources/audio_idle.png"), _T("resources/audio_hovered.png"), _T("resources/audio_pushed.png"), Sound_button_x, Sound_button_y);

		GameInt_button.right = 500;
		GameInt_button.left = GameInt_button.right - GameInt_button_x;
		GameInt_button.top = Sound_button.bottom + distance_y+20;
		GameInt_button.bottom = GameInt_button.top + GameInt_button_y;
		gameintroduction = GameIntroduction(GameInt_button, _T("resources/gameintroduction_idle.png"), _T("resources/gameintroduction_hovered.png"), _T("resources/gameintroduction_pushed.png"), GameInt_button_x, GameInt_button_y);

		TeamInt_button.left = GameInt_button.right + distance_x;
		TeamInt_button.right = TeamInt_button.left + TeamInt_button_x;
		TeamInt_button.top = GameInt_button.top;
		TeamInt_button.bottom = TeamInt_button.top + TeamInt_button_y;
		teamintroduction = TeamIntroduction(TeamInt_button, _T("resources/teamintroduction_idle.png"), _T("resources/teamintroduction_hovered.png"), _T("resources/teamintroduction_pushed.png"), TeamInt_button_x, TeamInt_button_y);
	
		menu_button.right = 1280;
		menu_button.top = 0;
		menu_button.left = menu_button.right - menu_button_x;
		menu_button.bottom = menu_button_y;
		menu = Menu(menu_button, _T("resources/menu_idle.png"), _T("resources/menu_hovered.png"), _T("resources/menu_pushed.png"), menu_button_x, menu_button_y);
		
		MusicControl_button.right = 898;
		MusicControl_button.left = MusicControl_button.right - MusicControl_button_x;
		MusicControl_button.top = 150;
		MusicControl_button.bottom = MusicControl_button.top + MusicControl_button_y;
		musiccontrol = MusicControl(MusicControl_button, _T("resources/music_control_line.png"), _T("resources/music_control_line.png"), _T("resources/music_control_line.png"), MusicControl_button_x, MusicControl_button_y);

		SoundControl_button.right = 898;
		SoundControl_button.left = SoundControl_button.right - SoundControl_button_x;
		SoundControl_button.top = 335;
		SoundControl_button.bottom = SoundControl_button.top + SoundControl_button_y;
		soundcontrol = SoundControl(SoundControl_button, _T("resources/music_control_line.png"), _T("resources/music_control_line.png"), _T("resources/music_control_line.png"), SoundControl_button_x, SoundControl_button_y);
		

	}

	void data_input(const ExMessage& msg) {
		//处理输入数据
		menu.Button_input(msg);
		music.Button_input(msg);
		soundeffects.Button_input(msg);
		gameintroduction.Button_input(msg);
		teamintroduction.Button_input(msg);
		soundcontrol.Button_input(msg);
		musiccontrol.Button_input(msg);
	}
	
	void data_update(int delta) {
		//数据更新
		if (flag != 5) {
			scene_manager.switch_to(flag);
		}
		music_control();
		sound_control();
	}
	
	void picture_draw() {
		//渲染图片
		putimage(0, 0, &img_set_background);
		menu.Button_draw(menu_button.left, menu_button.top);
		music.Button_draw(Music_button.left, Music_button.top);
		soundeffects.Button_draw(Sound_button.left, Sound_button.top);
		gameintroduction.Button_draw(GameInt_button.left, GameInt_button.top);
		teamintroduction.Button_draw(TeamInt_button.left, TeamInt_button.top);
		music_control_draw();
		sound_control_draw();
	}
	
	void scene_exit() {
		//退出场景
	}

private:

	class Music :public Button {
	public:
		Music() = default;
		~Music() = default;

		Music(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int x, int y)
			:Button(rect, path_img_idle, path_img_hovered, path_img_pushed, x, y) {}

	protected:
		void OnClick() {
			if (music_num)
				music_num = 0;
			else 
				music_num = 1;
		}
	};

	class SoundEffects :public Button {
	public:
		SoundEffects() = default;
		~SoundEffects() = default;

		SoundEffects(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int x, int y)
			:Button(rect, path_img_idle, path_img_hovered, path_img_pushed, x, y) {}

	protected:
		void OnClick() {
			if (sound_num)
				sound_num = 0;
			else 
				sound_num = 1;
		}

	};

	class GameIntroduction :public Button {
	public:
		GameIntroduction() = default;
		~GameIntroduction() = default;

		GameIntroduction(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int x, int y)
			:Button(rect, path_img_idle, path_img_hovered, path_img_pushed, x, y) {}

	protected:
		void OnClick() {
			flag = 7;				//游戏玩法介绍
		}
	};

	class TeamIntroduction :public Button {
	public:
		TeamIntroduction() = default;
		~TeamIntroduction() = default;

		TeamIntroduction(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int x, int y)
			:Button(rect, path_img_idle, path_img_hovered, path_img_pushed, x, y) {}

	protected:
		void OnClick() {
			flag = 8;				//队伍介绍
		}

	};

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

	class MusicControl :public Button {
	public:
		MusicControl() = default;
		~MusicControl() = default;

		MusicControl(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int x, int y)
			:Button(rect, path_img_idle, path_img_hovered, path_img_pushed, x, y) {}

	protected:
		void OnClick() {
			music_drawflag = 1;
			music_drawx = msg.x;
		}
	};

	class SoundControl :public Button {
	public:
		SoundControl() = default;
		~SoundControl() = default;

		SoundControl(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int x, int y)
			:Button(rect, path_img_idle, path_img_hovered, path_img_pushed, x, y) {}

	protected:
		void OnClick() {
			sound_drawflag = 1;
			sound_drawx = msg.x;
		}
	};

private:
		void music_control_draw() {
			setlinecolor(BLACK);				//设置线的颜色
			setfillcolor(RGB(0, 0, 230));
			fillroundrect(600, 150, 900, 170, 10, 10);
			setfillcolor(WHITE);
			if (music_drawflag == 1)
				fillroundrect(music_drawx - 10, 150, music_drawx + 10, 170, 20, 20);
			else 
				fillroundrect(740, 150, 760, 170, 20, 20);
		}

		void sound_control_draw() {
			setlinecolor(BLACK);				//设置线的颜色
			setfillcolor(RGB(0, 0, 230));
			fillroundrect(600, 335, 900, 355, 10, 10);
			setfillcolor(WHITE);
			if (sound_drawflag == 1)
				fillroundrect(sound_drawx - 10, 335, sound_drawx + 10, 355, 20, 20);
			else 
				fillroundrect(740, 335, 760, 355, 20, 20);
		}

		void music_control() {
			DWORD control;
			control = ((music_drawx - 600) * 65535) / 300;
			char command[256];
			sprintf_s(command, sizeof(command), "setaudio menu_bgm volume to %u", control);
			wchar_t wcommand[256];
			MultiByteToWideChar(CP_ACP, 0, command, -1, wcommand, 256);
			mciSendStringW(wcommand, NULL, 0, NULL);
		}

		void sound_control() {

		}


private:
	int distance_x = 200,
		distance_y = 100;

	RECT Music_button;
	int Music_button_x = 180,
		Music_button_y = 80;
	Music music;

	RECT Sound_button;
	int Sound_button_x = 180,
		Sound_button_y = 80;
	SoundEffects soundeffects;

	RECT GameInt_button;
	int GameInt_button_x = 250,
		GameInt_button_y = 80;
	GameIntroduction gameintroduction;

	RECT TeamInt_button;
	int TeamInt_button_x = 250,
		TeamInt_button_y = 80;
	TeamIntroduction teamintroduction;

	RECT menu_button;
	int menu_button_x = 75,
		menu_button_y = 50;
	Menu menu;

	RECT SoundControl_button;
	int SoundControl_button_x = 295,
		SoundControl_button_y = 20;
	SoundControl soundcontrol;

	RECT MusicControl_button;
	int MusicControl_button_x = 295,
		MusicControl_button_y = 20;
	MusicControl musiccontrol;

};


#endif // !_SET_SCENE_H_