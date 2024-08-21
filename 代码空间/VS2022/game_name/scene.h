#ifndef _SCENE_H_
#define _SCENE_H_

#include<easyx.h>

#include"util.h"

class Scene {
public:
	Scene() = default;
	~Scene() = default;

	//进入场景
	virtual void scene_enter(){ }

	//处理数据
	virtual void data_input(const ExMessage& msg){ }

	//数据更新
	virtual void data_update(int delta){ }

	//图形绘制
	virtual void picture_draw(){ }

	//退出场景
	virtual void scene_exit(){ }

private:

};

#endif // !_SCENE_H_
