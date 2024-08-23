#include<easyx.h>
#include<Windows.h>
#include<conio.h>
#include<time.h>

#include"util.h"
#include"timer.h"
#include"atlas.h"
#include"animation.h"

#include"scene.h"
#include"button.h"
#include"resources.h"
#include"set_scene.h"
#include"map_scene.h"
#include"exit_scene.h"
#include"menu_scene.h"
#include"game_scene.h"
#include"scene_manager.h"
#include"selector_scene.h"
#include"game_pause_scene.h"
#include"game_concrete_scene.h"
#include"game_introduction_scene.h"
#include"team_introduction_scene.h"

bool running = true;
SceneManager scene_manager;

//基本场景类如下
Scene* map_scene = nullptr;							//左巴阳   完成
Scene* set_scene = nullptr;							//刘昊	   完成一部分
Scene* exit_scene = nullptr;						//米饭	   完成
Scene* menu_scene = nullptr;						//极光	   完成
Scene* game_scene = nullptr;						//王怀玺   完成
Scene* selector_scene = nullptr;					//林	   完成一部分
Scene* game_pause_scene = nullptr;					//黑子	   未提交
Scene* game_introduction_scene = nullptr;			//九州	   完成一部分
Scene* team_introduction_scene = nullptr;			//九州	   完成一部分

//关卡类如下
Scene* map01 = nullptr;
Scene* map02 = nullptr;
Scene* map03 = nullptr;
Scene* map04 = nullptr;
Scene* map05 = nullptr;
Scene* map06 = nullptr;
Scene* map07 = nullptr;


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
	   9:game_pause_scene

	   以下是game_concrete_scene的场景类型
	   61:map01
	   62:map02
	   63:map03
	   64:map04
	   65:map05
	   66:map06
	   67:map07
	*/
int music_num = 1;					//控制音乐是否播放,1为播放，0为停止
int sound_num = 1;					//控制音效是否播放,1为播放，0为停止

int main() {
	srand(time(NULL));
	ExMessage msg;
	const int FPS = 165;

	load_game_resources();
	initgraph(1280, 720, EX_SHOWCONSOLE);

	BeginBatchDraw();

	//创建场景类
	map_scene = new MapScene();
	set_scene = new SetScene();
	exit_scene = new ExitScene();
	menu_scene = new MenuScene();
	game_scene = new GameScene();
	selector_scene = new SelectorScene();
	game_pause_scene = new GamePauseScene();
	game_introduction_scene = new GameIntroductionScene();
	team_introduction_scene = new TeamIntroductionScene();

	//关卡类
	map01 = new Map61();
	map02 = new Map62();
	map03 = new Map63();
	map04 = new Map64();
	map05 = new Map65();
	map06 = new Map66();
	map07 = new Map67();

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