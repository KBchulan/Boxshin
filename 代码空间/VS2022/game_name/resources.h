#ifndef _RESOURCES_H_
#define _RESOURCES_H_

#include<easyx.h>

#pragma comment(lib,"Winmm.lib")

IMAGE img_menu_background;
IMAGE img_selector_background;

IMAGE start_idle;
IMAGE start_hovered;
IMAGE start_pushed;

IMAGE set_idle;
IMAGE set_hovered;
IMAGE set_pushed;

IMAGE exit_idle;
IMAGE exit_hovered;
IMAGE exit_pushed;


void load_game_resources() {
	//����ͼ�����
	loadimage(&img_menu_background, _T("resources/img_menu_background.png"));
	loadimage(&img_selector_background, _T("resources/img_selector_background.png"));

	//��ťͼ�����
	loadimage(&start_idle, _T("resources/start_idle.png"));
	loadimage(&start_hovered, _T("resources/start_hovered.png"));
	loadimage(&start_pushed, _T("resources/start_pushed.png"));

	loadimage(&set_idle, _T("resources/set_idle.jpg"));
	loadimage(&set_hovered, _T("resources/set_hovered.jpg"));
	loadimage(&set_pushed, _T("resources/set_pushed.jpg"));
	
	loadimage(&exit_idle, _T("resources/exit_idle.png"));
	loadimage(&exit_hovered, _T("resources/exit_hovered.png"));
	loadimage(&exit_pushed, _T("resources/exit_pushed.png"));

	//��Ч�����
	mciSendString(_T("open resources/confirm.mp3 alias confirm"), NULL, 0, NULL);
	mciSendString(_T("open resources/hovered.mp3 alias hovered"), NULL, 0, NULL);

}



#endif // !_RESOURCES_H_
