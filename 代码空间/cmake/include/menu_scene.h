#ifndef _MENU_SCENE_H_
#define _MENU_SCENE_H_

#include"scene.h"
#include"button.h"
#include"scene_manager.h"

extern int flag;
extern SceneManager scene_manager;


class MenuScene :public Scene {
public:
	MenuScene() = default;
	~MenuScene() = default;

	void scene_enter() {
		//�Ÿ�����
		//��ʼ����ťһ���
	}

	void data_input(const ExMessage& msg) {
		if (msg.message == WM_LBUTTONDOWN) {
			flag = 2;
		}
		scene_manager.switch_to(flag);
		//��������Ϣ
	}

	void data_update(int delta) {
		//���ݸ���
	}

	void picture_draw() {
		std::cout << "1111" << std::endl;
		//����һЩ��ťһ���
	}

	void scene_exit() {
		//�˳��߼�����ָ���ť״̬��
	}

public:
	//�˴����尴ť
	/*class StartGame:public Button{
	public:
		Setbutton(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed,int x,int y)
		:Button(rect, path_img_idle, path_img_hovered, path_img_pushed, x, y) {}
		~Setbutton() = default;
	protected:
		void OnClick() {
			flag = 4;
		}
	}
	
	*/

};

#endif // !_MENU_SCENE_H_
