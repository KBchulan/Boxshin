#ifndef _RESOURCES_H_
#define _RESOURCES_H_

#include<easyx.h>

#include"atlas.h"
#include"util.h"

#pragma comment(lib,"Winmm.lib")

//背景图类
IMAGE img_team_one;
IMAGE img_team_two;
IMAGE img_team_three;
IMAGE img_team_four;
IMAGE img_team_five;
IMAGE img_selector_box;
IMAGE img_game_pause_box;
IMAGE img_map_background;
IMAGE img_set_background;
IMAGE img_menu_background;
IMAGE img_game_background;
IMAGE img_exit_background;
IMAGE img_game_introduction;
IMAGE img_selector_background;
IMAGE img_game_pause_background;
IMAGE img_game_introduction_background;
IMAGE img_team_introduction_background;


//角色类加载


//字体类加载


//素材类加载

Atlas atlas_bubble;					//气泡
Atlas atlas_flow;					//水流
Atlas atlas_star;					//胜利星
Atlas atlas_coral;					//珊瑚
IMAGE img_wall;						//墙
IMAGE img_penetration_wall;			//穿透墙
IMAGE img_mechanics_0;				//
IMAGE img_mechanics_1;				//


//图集类加载
Atlas atlas_gamer_diver;
Atlas atlas_gamer_lypo;
Atlas atlas_enemy_fish;

Atlas game_atlas_gamer_diver_left;
Atlas game_atlas_gamer_diver_right;
Atlas game_atlas_gamer_lypo_left;
Atlas game_atlas_gamer_lypo_right;





void load_game_resources() {
	//背景图类加载
	loadimage(&img_team_one, _T("resources/team_one.png"), 1280, 720);
	loadimage(&img_team_two, _T("resources/team_two.png"), 1280, 720);
	loadimage(&img_team_four, _T("resources/team_four.png"), 1280, 720);
	loadimage(&img_team_five, _T("resources/team_five.png"), 1280, 720);
	loadimage(&img_team_three, _T("resources/team_three.png"), 1280, 720);
	loadimage(&img_selector_box, _T("resources/img_game_pause_box.png"), 400, 220);
	loadimage(&img_map_background, _T("resources/game_introduction.jpg"), 1280, 720);
	loadimage(&img_set_background, _T("resources/img_set_background.png"), 1280, 720);
	loadimage(&img_game_pause_box, _T("resources/img_game_pause_box.png"), 1045, 585);
	loadimage(&img_game_background, _T("resources/img_game_background.jpg"), 1280, 720);
	loadimage(&img_menu_background, _T("resources/img_menu_background.png"), 1280, 720);
	loadimage(&img_exit_background, _T("resources/img_exit_background.png"), 1045, 585);
	loadimage(&img_game_introduction, _T("resources/game_interdoction.png"), 1280, 720);
	loadimage(&img_selector_background, _T("resources/img_selector_background.png"), 1280, 720);
	loadimage(&img_game_pause_background, _T("resources/img_game_pause_background.png"), 1280, 720);	
	loadimage(&img_game_introduction_background, _T("resources/img_game_introduction_background.png"), 1280, 720);
	loadimage(&img_team_introduction_background, _T("resources/img_team_introduction_background.png"), 1280, 720);
	

	//角色类加载


	//字体类加载


	//素材类加载
	loadimage(&img_wall, _T("resources/img_wall"), 40, 40);
	loadimage(&img_penetration_wall, _T("resources/img_penetration_wall"), 40, 40);
	atlas_coral.load_from_file(_T("resources/img_coral.png"), 1, 76, 48);
	loadimage(&img_mechanics_0, _T("img_mechanics_0"), 40, 40);
	loadimage(&img_mechanics_1, _T("img_mechanics_1"), 40, 40);
	atlas_star.load_from_file(_T("resources/img_star.png"), 1, 45, 45);


	//图集类加载
	atlas_gamer_diver.load_from_file(_T("resources/diver_gamer_%d.png"), 9, 200, 100);
	atlas_gamer_lypo.load_from_file(_T("resources/lypo_gamer_%d.png"), 9, 220, 100);
	
	//游戏内图集
	game_atlas_gamer_diver_right.load_from_file(_T("resources/diver_gamer_%d.png"), 9, 80, 50);
	flip_atlas(game_atlas_gamer_diver_right, game_atlas_gamer_diver_left);
	game_atlas_gamer_lypo_right.load_from_file(_T("resources/lypo_gamer_%d.png"), 9, 80, 50);
	flip_atlas(game_atlas_gamer_lypo_right, game_atlas_gamer_lypo_left);
	atlas_enemy_fish.load_from_file(_T("resources/enemy_fish_%d.png"),9,40, 40);

	//音效类加载
	mciSendString(_T("open resources/confirm.mp3 alias confirm"), NULL, 0, NULL);
	mciSendString(_T("open resources/hovered.mp3 alias hovered"), NULL, 0, NULL);
	mciSendString(_T("open resources/test.mp3 alias menu_bgm"), NULL, 0, NULL);

}



#endif // !_RESOURCES_H_
