#ifndef GAME_PAUSE_SCENE_H
#define GAME_PAUSE_SCENE_H

#include"scene.h"
#include"button.h"
#include"scene_manager.h"

class GamePauseScene : public Scene {
public:
	GamePauseScene() = default;
	~GamePauseScene() = default;

	void scene_enter() {
		//���볡��
	}

	void data_input(const ExMessage& msg) {
		//��������
	}

	void data_update(int delta) {
		//��������
	}

	void picture_draw() {
		//����ͼƬ
	}

	void scene_exit() {
		//�˳�����
	}

private:



};


#endif // !GAME_PAUSE_SCENE_H