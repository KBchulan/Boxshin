#ifndef _MENU_SCENE_H_
#define _MENU_SCENE_H_

#include"scene.h"
#include"button.h"
#include"scene_manager.h"


extern int flag;
extern int music_num;
extern IMAGE img_menu_background;
extern SceneManager scene_manager;

class MenuScene :public Scene {
public:
	MenuScene() = default;
	~MenuScene() = default;
	/*
	�����ˣ�
	���ܣ���ʼ������λ�ã���ͼ,�������
	������void
	����ֵ��void
	*/
	void scene_enter() {
		//�Ÿ�����
		//��ʼ����ťһ���
		start_button.left = 530;
		start_button.right = start_button.left + start_button_x;
		start_button.top = 350;
		start_button.bottom = start_button.top + start_button_y;
		startgame = StartGame(start_button, _T("resources/start_idle.png"), _T("resources/start_hovered.png"), _T("resources/start_pushed.png"), start_button_x, start_button_y);
		
		set_button.left = start_button.left;
		set_button.right = set_button.left + set_button_x;
		set_button.top = start_button.bottom + distance;
		set_button.bottom = set_button.top + set_button_y;
		set = Set(set_button, _T("resources/set_idle.png"), _T("resources/set_hovered.png"), _T("resources/set_pushed.png"), set_button_x, set_button_y);

		exit_button.left = start_button.left;
		exit_button.right= exit_button.left + exit_button_x;
		exit_button.top = set_button.bottom + distance;
		exit_button.bottom = exit_button.top + exit_button_y;
		exit = Exit(exit_button, _T("resources/exit_idle.png"), _T("resources/exit_hovered.png"), _T("resources/exit_pushed.png"), exit_button_x, exit_button_y);
		
		voice_button.right = 1280;
		voice_button.top = 0;
		voice_button.left = voice_button.right - voice_button_x;
		voice_button.bottom = voice_button_y;
		gamevoice = GameVoice(voice_button, _T("resources/sound_idle.png"), _T("resources/sound_hovered.png"), _T("resources/sound_pushed.png"), voice_button_x, voice_button_y);

		voice_open_button.right = 1280;
		voice_open_button.top = 0;
		voice_open_button.left = voice_open_button.right - voice_open_button_x;
		voice_open_button.bottom = voice_open_button_y;
		gamevoiceopen = GameVoiceOpen(voice_open_button, _T("resources/sound_off_idle.png"), _T("resources/sound_off_hovered.png"), _T("resources/sound_off_pushed.png"), voice_open_button_x, voice_open_button_y);

		mciSendString(_T("play menu_bgm repeat from 0"), NULL, 0, NULL);
	}

	void data_input(const ExMessage& msg) {
		//��ť��Ϣ����
		set.Button_input(msg);
		exit.Button_input(msg);
		startgame.Button_input(msg);

		if (music_num == 1)
			gamevoice.Button_input(msg);
		else if (music_num == 0)
			gamevoiceopen.Button_input(msg);

		//��������Ϣ
	}
	
	void data_update(int delta) {
		//���ݸ���
		if (flag != 1) {
			scene_manager.switch_to(flag);
		}
	}
	/*
	�����ˣ�
	���ܣ���ť��ͼ��Ⱦ
	������void
	����ֵ��void
	*/
	void picture_draw() {
		putimage(0, 0, &img_menu_background);

		//��ť����
		set.Button_draw(set_button.left,set_button.top);
		exit.Button_draw(exit_button.left,exit_button.top);
		startgame.Button_draw(start_button.left,start_button.top);

		if (music_num == 1)
			gamevoice.Button_draw();
		else if (music_num == 0)
			gamevoiceopen.Button_draw();

	}
		/*
	�����ˣ�
	���ܣ��˳���ǰҳ��
	������void
	����ֵ��void
	*/
	void scene_exit() {
		//�˳��߼�����ָ���ť״̬��
	}

private:
	//�˴����尴ť
	class StartGame :public Button {
	public:
		StartGame() = default;
		~StartGame() = default;

		StartGame(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int x, int y)
			:Button(rect, path_img_idle, path_img_hovered, path_img_pushed, x, y) {}

	protected:
		void OnClick() {
			flag = 2;			//��ɫѡ�����
		}
	};

	class Set :public Button {
	public:
		Set() = default;
		~Set() = default;

		Set(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int x, int y)
			:Button(rect, path_img_idle, path_img_hovered, path_img_pushed, x, y) {}

	protected:
		void OnClick() {
			flag = 5;			//���ý���
		}
	};

	class Exit :public Button {
	public:
		Exit() = default;
		~Exit() = default;

		Exit(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int x, int y)
			: Button(rect, path_img_idle, path_img_hovered, path_img_pushed, x, y) {}

	protected:
		void OnClick() {
			flag = 6;			//�˳���Ϸ����
		}
	};

	class GameVoice :public Button {
	public:
		GameVoice() = default;
		~GameVoice() = default;

		GameVoice(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int x, int y) :
			Button(rect, path_img_idle, path_img_hovered, path_img_pushed, x, y) {}

	protected:
		void OnClick() {
			music_num = 0;
		}
	};

	class GameVoiceOpen :public Button {
	public:
		GameVoiceOpen() = default;
		~GameVoiceOpen() = default;

		GameVoiceOpen(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int x, int y) :
			Button(rect, path_img_idle, path_img_hovered, path_img_pushed, x, y) {}

	protected:
		void OnClick() {
			music_num = 1;
		}
	};
	
	
private:
	int distance = 30;								//��ͬ��ťy���

	RECT start_button;								//���忪ʼ��Ϸ����
	int start_button_x = 220,
		start_button_y = 80;						//��ť�ĳ���
	StartGame startgame;							//���尴ť

	RECT set_button;								//�������þ���
	int set_button_x = 220,
		set_button_y = 80;							//���γ���
	Set set;										//���尴ť

	RECT exit_button;								//�����˳���Ϸ����
	int exit_button_x = 220,
		exit_button_y = 80;							//��ť����
	Exit exit;										//���尴ť

	RECT voice_button;
	int voice_button_x = 50,
		voice_button_y = 50;
	GameVoice gamevoice;

	RECT voice_open_button;
	int voice_open_button_x = 50,
		voice_open_button_y = 50;
	GameVoiceOpen gamevoiceopen;


};

#endif // !_MENU_SCENE_H_
