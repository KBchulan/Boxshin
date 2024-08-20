#ifndef _SELECTOR_SCENE_H_
#define _SELECTOR_SCENE_H_

#include"scene.h"
#include"button.h"
#include"scene_manager.h"

int number;			//������,����ѡ�ô˽��в�ͬ��ɫ��ȷ��
int gamer_sum;		//�����������

extern int flag;
extern IMAGE img_selector_background;
extern SceneManager scene_manager;

class SelectorScene :public Scene {
public:
	SelectorScene() = default;
	~SelectorScene() = default;

	void scene_enter() {
		//���ְ�ťλ�ó�ʼ��
		last_button.right = 565;
		last_button.left = last_button.right - last_button_x;
		last_button.top = 450;
		last_button.bottom = last_button.top + last_button_y;
		lastgamer = LastGamer(last_button, _T("resources/lastgamer_idle.png"), _T("resources/lastgamer_hovered.png"), _T("resources/lastgamer_pushed.png"), last_button_x, last_button_y);
		
		next_button.left = 715;
		next_button.right = next_button.left + next_button_x;
		next_button.top = 450;
		next_button.bottom = next_button.top + next_button_y;
		nextgamer = NextGamer(last_button, _T("resources/nextgamer_idle.png"), _T("resources/nextgamer_hovered.png"), _T("resources/nextgamer_pushed.png"), next_button_x, next_button_y);
	
		enter_button.left = 540;
		enter_button.right = enter_button.left + enter_button_x;
		enter_button.top = last_button.bottom + 50;
		enter_button.bottom = enter_button.top + enter_button_y;
		entermap = EnterMap(enter_button, _T("resources/entermap_idle.png"), _T("resources/entermap_hovered.png"), _T("resources/entermap_pushed.png"), enter_button_x, enter_button_y);
	}

	void data_input(const ExMessage& msg) {
		//�����������
		if (msg.message == WM_LBUTTONDOWN) {
			flag = 3;
		}
		entermap.Button_input(msg);
		lastgamer.Button_input(msg);
		nextgamer.Button_input(msg);
	}

	void data_update(int delta) {
		//���¸�����Ϣ
		scene_manager.switch_to(flag);
	}

	void picture_draw() {
		//����ͼƬ
		std::cout << flag << std::endl;
		putimage(0, 0, &img_selector_background);

		entermap.Button_draw();
		lastgamer.Button_draw();
		nextgamer.Button_draw();

		/*
		*����1��
		* ����number��Ⱦ��ͬ�Ľ�ɫ����ͽ�ɫ˵������
		*/


	}

	void scene_exit() {
		//�˳��������ͷ���Դ
	}

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
			number = number < 0 ? number += gamer_sum : number;
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
			number = number >= gamer_sum ? number -= gamer_sum : number;
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
			flag = 3;			//��Ϸ����
		}

	};

private:
	RECT last_button;
	int last_button_x = 100,
		last_button_y = 50;
	LastGamer lastgamer;
	
	RECT next_button;
	int next_button_x = 100,
		next_button_y = 50;
	NextGamer nextgamer;

	RECT enter_button;
	int enter_button_x = 100,
		enter_button_y = 50;
	EnterMap entermap;

};



#endif // !_SELECTOR_SCENE_H_
