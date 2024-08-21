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
	    
	  	/*
	负责人：
	功能：按钮初始化，贴图
	参数：void
	返回值：void
	*/
	void scene_enter() {
		//初始化按钮
		Music_button.right = 300;
		Music_button.left = Music_button.right - Music_button_x;
		Music_button.top = 100;
		Music_button.bottom = Music_button.top + Music_button_y;
		music = Music(Music_button, _T("resources/music_idle.png"), _T("resources/music_hovered.png"), _T("resources/music_pushed.png"), Music_button_x, Music_button_y);

		Sound_button.left = 300;
		Sound_button.right = Sound_button.left + Sound_button_x;
		Sound_button.top = 200;
		Sound_button.bottom = Sound_button.top + Sound_button_y;
		soundeffects = SoundEffects(Sound_button, _T("resources/sound_idle.png"), _T("resources/sound_hovered.png"), _T("resources/sound_pushed.png"), Sound_button_x, Sound_button_y);

		GameInt_button.left = 300;
		GameInt_button.right = GameInt_button.left + GameInt_button_x;
		GameInt_button.top = 300;
		GameInt_button.bottom = GameInt_button.top + GameInt_button_y;
		gameintroduction = GameIntroduction(GameInt_button, _T("resources/gameintroduction_idle.png"), _T("resources/gameintroduction_hovered.png"), _T("resources/gameintroduction_pushed.png"), GameInt_button_x, GameInt_button_y);

		TeamInt_button.right = 500;
		TeamInt_button.left = TeamInt_button.right - TeamInt_button_x;
		TeamInt_button.top = 300;
		TeamInt_button.bottom = TeamInt_button.top + TeamInt_button_y;
		teamintroduction = TeamIntroduction(TeamInt_button, _T("resources/teamintroduction_idle.png"), _T("resources/teamintroduction_hovered.png"), _T("resources/teamintroduction_pushed.png"), TeamInt_button_x, TeamInt_button_y);
	}

	/*
  负责人：
  功能：接受按钮信息
  参数：用户鼠标的点击
  返回值：void
  */
	void data_input(const ExMessage& msg) {
		//处理输入数据
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
		music.Button_draw();
		soundeffects.Button_draw();
		gameintroduction.Button_draw();
		teamintroduction.Button_draw();
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



private:
	RECT Music_button;
	int Music_button_x = 100,
		Music_button_y = 50;
	Music music;

	RECT Sound_button;
	int Sound_button_x = 100,
		Sound_button_y = 50;
	SoundEffects soundeffects;

	RECT GameInt_button;
	int GameInt_button_x = 100,
		GameInt_button_y = 50;
	GameIntroduction gameintroduction;

	RECT TeamInt_button;
	int TeamInt_button_x = 100,
		TeamInt_button_y = 50;
	TeamIntroduction teamintroduction;
};


#endif // !_SET_SCENE_H_