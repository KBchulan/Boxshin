#ifndef _SET_SCENE_H_
#define _SET_SCENE_H_

#include"scene.h"
#include"button.h"
#include"scene_manager.h"

extern int flag;
extern IMAGE img_set_background;
extern SceneManager scene_manager;

class SetScene :public Scene {
public:
	SetScene() = default;
	~SetScene() = default;
	 
	void scene_enter() {
		//初始化按钮
		Music_button.right = 540;
		Music_button.left = Music_button.right - Music_button_x;
		Music_button.top = 180;
		Music_button.bottom = Music_button.top + Music_button_y;
		music = Music(Music_button, _T("resources/music_idle.png"), _T("resources/music_hovered.png"), _T("resources/music_pushed.png"), Music_button_x, Music_button_y);

		Sound_button.right = Music_button.right;
		Sound_button.left = Sound_button.right - Sound_button_x;
		Sound_button.top = Music_button.bottom + distance_y;
		Sound_button.bottom = Sound_button.top + Sound_button_y;
		soundeffects = SoundEffects(Sound_button, _T("resources/sound_idle.png"), _T("resources/sound_hovered.png"), _T("resources/sound_pushed.png"), Sound_button_x, Sound_button_y);

		GameInt_button.right = Music_button.right;
		GameInt_button.left = GameInt_button.right - GameInt_button_x;
		GameInt_button.top = Sound_button.bottom + distance_y;
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
	}

	/*
  负责人：
  功能：接受按钮信息
  参数：用户鼠标的点击
  返回值：void
  */
	void data_input(const ExMessage& msg) {
		//处理输入数据
		menu.Button_input(msg);
		music.Button_input(msg);
		soundeffects.Button_input(msg);
		gameintroduction.Button_input(msg);
		teamintroduction.Button_input(msg);
	}
	/*
	负责人：
	功能：根据flag的定义进行相关操作
	参数：
	返回值：void
	*/
	void data_update(int delta) {
		//数据更新
		if (flag != 5) {
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
		//渲染图片
		putimage(0, 0, &img_set_background);
		menu.Button_draw(menu_button.left, menu_button.top);
		music.Button_draw(Music_button.left, Music_button.top);
		soundeffects.Button_draw(Sound_button.left, Sound_button.top);
		gameintroduction.Button_draw(GameInt_button.left, GameInt_button.top);
		teamintroduction.Button_draw(TeamInt_button.left, TeamInt_button.top);
	}
	/*
负责人：
功能：退出当前页面
参数：void
返回值：void
*/
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
		 	/*
	负责人：
	功能：改变flag的队友值，进行页面跳转
	参数：void
	返回值：void
	*/
		void OnClick() {
			//
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
			//
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


private:
	int distance_x = 200,
		distance_y = 50;

	RECT Music_button;
	int Music_button_x = 220,
		Music_button_y = 85;
	Music music;

	RECT Sound_button;
	int Sound_button_x = 220,
		Sound_button_y = 85;
	SoundEffects soundeffects;

	RECT GameInt_button;
	int GameInt_button_x = 220,
		GameInt_button_y = 85;
	GameIntroduction gameintroduction;

	RECT TeamInt_button;
	int TeamInt_button_x = 220,
		TeamInt_button_y = 85;
	TeamIntroduction teamintroduction;

	RECT menu_button;
	int menu_button_x = 75,
		menu_button_y = 50;
	Menu menu;
};


#endif // !_SET_SCENE_H_