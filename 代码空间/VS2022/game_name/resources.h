#ifndef _RESOURCES_H_
#define _RESOURCES_H_

#include<easyx.h>

#include"atlas.h"

#pragma comment(lib,"Winmm.lib")

//背景图类
IMAGE img_map_background;
IMAGE img_set_background;
IMAGE img_menu_background;
IMAGE img_game_background;
IMAGE img_exit_background;
IMAGE img_selector_background;
IMAGE img_game_pause_background;
IMAGE img_game_introduction_background;
IMAGE img_team_introduction_background;


//角色类加载


//字体类加载


//素材类加载


//图集类加载
Atlas atlas_gamer_diver;
Atlas atlas_gamer_lypo;




void load_game_resources() {
	//背景图类加载
	loadimage(&img_map_background, _T("resources/img_map_background.png"), 1280, 720);
	loadimage(&img_set_background, _T("resources/img_set_background.png"), 1280, 720);
	loadimage(&img_game_background, _T("resources/img_game_background.jpg"), 1280, 720);
	loadimage(&img_menu_background, _T("resources/img_menu_background.png"), 1280, 720);
	loadimage(&img_exit_background, _T("resources/img_exit_background.png"), 1045, 585);
	loadimage(&img_selector_background, _T("resources/img_selector_background.png"), 1280, 720);
	loadimage(&img_game_pause_background, _T("resources/img_game_pause_background.png"), 1280, 720);
	loadimage(&img_game_introduction_background, _T("resources/img_game_introduction_background.png"), 1280, 720);
	loadimage(&img_team_introduction_background, _T("resources/img_team_introduction_background.png"), 1280, 720);
	

	//角色类加载


	//字体类加载


	//素材类加载


	//图集类加载
	atlas_gamer_diver.load_from_file(_T("resources/diver_gamer_%d.png"), 10);
	atlas_gamer_lypo.load_from_file(_T("resources/lypo_gamer_%d.png"), 6);

	//音效类加载
	mciSendString(_T("open resources/confirm.mp3 alias confirm"), NULL, 0, NULL);
	mciSendString(_T("open resources/hovered.mp3 alias hovered"), NULL, 0, NULL);

}



#endif // !_RESOURCES_H_
