#ifndef _SELECTOR_SCENE_H_
#define _SELECTOR_SCENE_H_

#include"scene.h"
#include"button.h"
#include"player_diver.h"
#include"scene_manager.h"

int number;					//玩家序号,我们选用此进行不同角色的确认
int gamer_sum;				//角色总数

extern int flag;
extern Player* player;
extern Atlas atlas_gamer_lypo;
extern Atlas atlas_gamer_diver;
extern SceneManager scene_manager;
extern IMAGE img_selector_background;

class SelectorScene :public Scene {
public:
	SelectorScene() = default;
	~SelectorScene() = default;

	void scene_enter() {
		//玩家种类定义
		number = 1;
		gamer_sum = 2;

		//各种按钮位置初始化
		last_button.right = 590;
		last_button.left = last_button.right - last_button_x;
		last_button.top = 360;
		last_button.bottom = last_button.top + last_button_y;
		lastgamer = LastGamer(last_button, _T("resources/prev_idle.png"), _T("resources/prev_hovered.png"), _T("resources/prev_pushed.png"), last_button_x, last_button_y);

		next_button.left = last_button.right + distance_x;
		next_button.right = next_button.left + next_button_x;
		next_button.top = last_button.top;
		next_button.bottom = next_button.top + next_button_y;
		nextgamer = NextGamer(next_button, _T("resources/next_idle.png"), _T("resources/next_hovered.png"), _T("resources/next_pushed.png"), next_button_x, next_button_y);

		enter_button.left = 515;
		enter_button.right = enter_button.left + enter_button_x;
		enter_button.top = last_button.bottom + distance_y;
		enter_button.bottom = enter_button.top + enter_button_y;
		entermap = EnterMap(enter_button, _T("resources/confirm_idle.png"), _T("resources/confirm_hovered.png"), _T("resources/confirm_pushed.png"), enter_button_x, enter_button_y);

		replay_button.left = 0;
		replay_button.right = replay_button.left + replay_button_x;
		replay_button.top = 0;
		replay_button.bottom = replay_button.top + replay_button_y;
		replay = Replay(replay_button, _T("resources/replay_idle.png"), _T("resources/replay_hovered.png"), _T("resources/replay_pushed.png"), replay_button_x, replay_button_y);

		//角色动画初始化
		animation_gamer_diver.set_atlas(&atlas_gamer_diver);
		animation_gamer_diver.set_interval(75);
		animation_gamer_diver.set_loop(true);

		animation_gamer_lypo.set_atlas(&atlas_gamer_lypo);
		animation_gamer_lypo.set_interval(75);
		animation_gamer_lypo.set_loop(true);

		//定时器初始化
		timer_test.set_wait_time(1000);
		timer_test.set_one_shot(false);
		timer_test.set_callback(
			[&]() {
				std::cout << "timer_test" << std::endl;
			}
		);

	}

	void data_input(const ExMessage& msg) {
		//处理玩家输入
		replay.Button_input(msg);
		entermap.Button_input(msg);
		lastgamer.Button_input(msg);
		nextgamer.Button_input(msg);
	}

	void data_update(int delta) {
		//更新各种信息
		animation_gamer_diver.data_update(delta);
		animation_gamer_lypo.data_update(delta);
		timer_test.data_update(delta);

		if (flag != 2) {
			scene_manager.switch_to(flag);
		}
	}

	void picture_draw() {
		//绘制图片
		putimage(0, 0, &img_selector_background);
		//绘制按钮
		replay.Button_draw(replay_button.left,replay_button.top);
		entermap.Button_draw(enter_button.left,enter_button.top);
		nextgamer.Button_draw(next_button.left,next_button.top);
		lastgamer.Button_draw(last_button.left,last_button.top);
		//绘制角色动画
		switch (number) {
		case 1:
			animation_gamer_diver.picture_draw(520, 150);
			break;
		case 2:
			animation_gamer_lypo.picture_draw(525, 170);
			break;
		default:
			break;
		}


	}

	void scene_exit() {
		//退出场景，释放资源
		switch (number) {
		case 1:
			player = new PlayerDive();
			break;
		case 2:
			
			break;
		default:
			break;
		}
	}

private:
	//角色动画
	Animation animation_gamer_diver;
	Animation animation_gamer_lypo;

	//定时器
	Timer timer_test;

private:
	class LastGamer :public Button {
	public:
		LastGamer() = default;
		~LastGamer() = default;

		LastGamer(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int x, int y)
			:Button(rect, path_img_idle, path_img_hovered, path_img_pushed, x, y) {}
		
	protected:
		void OnClick() {
			number--;
			number = number <= 0 ? number += gamer_sum : number;
		}

	};
	
	class NextGamer :public Button {
	public:
		NextGamer() = default;
		~NextGamer() = default;

		NextGamer(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int x, int y)
			:Button(rect, path_img_idle, path_img_hovered, path_img_pushed, x, y) {}
		
	protected:
		void OnClick() {
			number++;
			number = number > gamer_sum ? number -= gamer_sum : number;
		}
	};

	class EnterMap :public Button {
	public:
		EnterMap() = default;
		~EnterMap() = default;

		EnterMap(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int x, int y)
			:Button(rect, path_img_idle, path_img_hovered, path_img_pushed, x, y) {}

	protected:
		void OnClick() {
			flag = 4;			//地图界面
		}
	};

	class Replay :public Button {
	public:
		Replay() = default;
		~Replay() = default;

		Replay(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int x, int y)
			:Button(rect, path_img_idle, path_img_hovered, path_img_pushed, x, y) {}

	protected:
		void OnClick() {
			flag = 1;			//地图界面
		}
	};

private:
	int distance_x = 100;
	int distance_y = 60;

	RECT last_button;
	int last_button_x = 130,
		last_button_y = 50;
	LastGamer lastgamer;
	
	RECT next_button;
	int next_button_x = 130,
		next_button_y = 50;
	NextGamer nextgamer;

	RECT enter_button;
	int enter_button_x = 250,
		enter_button_y = 85;
	EnterMap entermap;

	RECT replay_button;
	int replay_button_x=50,
		replay_button_y=50;
	Replay replay;

};



#endif // !_SELECTOR_SCENE_H_
