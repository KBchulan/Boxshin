#ifndef _SELECTOR_SCENE_H_
#define _SELECTOR_SCENE_H_

#include"scene.h"
#include"button.h"
#include"scene_manager.h"

extern int flag;
extern SceneManager scene_manager;

class SelectorScene :public Scene {
public:
	SelectorScene() = default;
	~SelectorScene() = default;

	void scene_enter() {
		//���ְ�ťλ�ó�ʼ��
	}

	void data_input(const ExMessage& msg) {
		if (msg.message == WM_LBUTTONDOWN) {
			flag = 3;
		}
		scene_manager.switch_to(flag);
		//�����������
	}

	void data_update(int delta) {
		//���¸�����Ϣ
	}

	void picture_draw() {
		std::cout << "22222" << std::endl;
		//����ͼƬ
	}

	void scene_exit() {
		//�˳��������ͷ���Դ
	}

private:
	
};



#endif // !_SELECTOR_SCENE_H_
