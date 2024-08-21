#ifndef _SCENE_H_
#define _SCENE_H_

#include<easyx.h>

#include"util.h"

class Scene {
public:
	Scene() = default;
	~Scene() = default;

	//���볡��
	virtual void scene_enter(){ }

	//��������
	virtual void data_input(const ExMessage& msg){ }

	//���ݸ���
	virtual void data_update(int delta){ }

	//ͼ�λ���
	virtual void picture_draw(){ }

	//�˳�����
	virtual void scene_exit(){ }

private:

};

#endif // !_SCENE_H_
