#include<easyx.h>
#include<Windows.h>
#include<conio.h>
#include<time.h>

#include"scene.h"
#include"button.h"
#include"resources.h"
#include"set_scene.h"
#include"exit_scene.h"
#include"menu_scene.h"
#include"game_scene.h"
#include"scene_manager.h"
#include"selector_scene.h"
#include"game_introduction_scene.h"
#include"team_introduction_scene.h"

SceneManager scene_manager;

Scene* set_scene = nullptr;
Scene* exit_scene = nullptr;
Scene* menu_scene = nullptr;
Scene* game_scene = nullptr;
Scene* selector_scene = nullptr;
Scene* game_introduction_scene = nullptr;
Scene* team_introduction_scene = nullptr;

bool running = true;
int flag = 1;
	/*
	   flag用于判定场景类型
	   1:menu_scene
	   2:selector_scene
	   3:game_scene
	   4:map_scene
	   5:set_scene
	   6:exit_scenes
	   7:game_introduction_scene
	   8:team_introduction_scene
	*/

int main() {
	srand(time(NULL));
	ExMessage msg;
	const int FPS = 165;

	load_game_resources();
	initgraph(1280, 720, EX_SHOWCONSOLE);

	BeginBatchDraw();

	set_scene = new SetScene();
	exit_scene = new ExitScene();
	menu_scene = new MenuScene();
	game_scene = new GameScene();
	selector_scene = new SelectorScene();
	game_introduction_scene = new GameIntroductionScene();
	team_introduction_scene = new TeamIntroductionScene();

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