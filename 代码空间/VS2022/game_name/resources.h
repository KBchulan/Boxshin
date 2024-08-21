#ifndef _RESOURCES_H_
#define _RESOURCES_H_

#include<easyx.h>

#pragma comment(lib,"Winmm.lib")

//����ͼ��
IMAGE img_menu_background;
IMAGE img_selector_background;
IMAGE img_map_background;
IMAGE img_set_background;
IMAGE img_exit_background;
IMAGE img_game_introduction_background;
IMAGE img_team_introduction_background;
IMAGE img_game_pause_background;

//��ɫ�����


//���������


//�ز������


void load_game_resources() {
	//����ͼ�����
	loadimage(&img_menu_background, _T("resources/img_menu_background.png"), 1280, 720);
	loadimage(&img_selector_background, _T("resources/img_selector_background.png"), 1280, 720);
	loadimage(&img_map_background, _T("resources/img_map_background.png"), 1280, 720);
	loadimage(&img_set_background, _T("resources/img_set_background.png"), 1280, 720);
	loadimage(&img_exit_background, _T("resources/img_exit_background.png"), 1280, 720);
	loadimage(&img_game_introduction_background, _T("resources/img_game_introduction_background.png"), 1280, 720);
	loadimage(&img_team_introduction_background, _T("resources/img_team_introduction_background.png"), 1280, 720);
	loadimage(&img_game_pause_background, _T("resources/img_game_pause_background.png"), 1280, 720);

	//��ɫ�����


	//���������


	//�ز������



	//��Ч�����
	mciSendString(_T("open resources/confirm.mp3 alias confirm"), NULL, 0, NULL);
	mciSendString(_T("open resources/hovered.mp3 alias hovered"), NULL, 0, NULL);

}



#endif // !_RESOURCES_H_
