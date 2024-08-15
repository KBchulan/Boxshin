#ifndef _GAME_SCENE_H_
#define _GAME_SCENE_H_
//�˴�Ϊ��Ҫ����

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
		//��ʼ��
	}

	void data_input(const ExMessage& msg) {
		if (msg.message == WM_LBUTTONDOWN) {
			flag = 1;
		}
		scene_manager.switch_to(flag);
		//������������
	}

	void data_update(int delta) {
		//��������
	}

	void picture_draw() {
		std::cout << "33333" << std::endl;
		//����ͼ��
	}

	void scene_exit() {
		//�˳��������ͷ���Դ
	}

private:

};


#endif // !_GAME_SCENE_H_
