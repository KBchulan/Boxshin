#include<easyx.h>
#include<Windows.h>
#include<conio.h>
#include<time.h>

#include"scene.h"
#include"button.h"
#include"menu_scene.h"
#include"game_scene.h"
#include"scene_manager.h"
#include"selector_scene.h"

SceneManager scene_manager;

Scene* menu_scene = nullptr;
Scene* game_scene = nullptr;
Scene* selector_scene = nullptr;

bool running = true;
int flag = 1;
	/*
	   flag用于判定场景类型
	   1:menu_scene
	   2:selector_scene
	   3:game_scene
	*/

int main() {
	srand(time(NULL));
	ExMessage msg;
	const int FPS = 165;

	initgraph(1280, 720, EX_SHOWCONSOLE);

	BeginBatchDraw();

	menu_scene = new MenuScene();
	game_scene = new GameScene();
	selector_scene = new SelectorScene();
	scene_manager.set_start_scene(menu_scene);

	while (running)
	{
		DWORD frame_start = GetTickCount();

		//处理输入
		while (peekmessage(&msg))
		{
			scene_manager.data_input(msg);
		}

		//更新数据
		static DWORD last_tick_time = GetTickCount();
		DWORD current_tick_time = GetTickCount();
		DWORD delta = current_tick_time - last_tick_time;
		scene_manager.data_update(delta);
		last_tick_time = current_tick_time;

		//绘图
		cleardevice();
		scene_manager.picture_draw();
		FlushBatchDraw();

		//动态延时
		DWORD frame_end = GetTickCount();
		DWORD frame_delta = frame_end - frame_start;
		if (frame_delta < 1000 / FPS) {
			Sleep(1000 / FPS - frame_delta);
		}
	}

	EndBatchDraw();
	return 0;

}