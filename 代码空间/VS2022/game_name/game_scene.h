#ifndef _GAME_SCENE_H_
#define _GAME_SCENE_H_
//�˴�Ϊ��Ҫ����

#include"scene.h"
#include"button.h"
#include"scene_manager.h"

int play_num = 1;
int music_num = 1;

extern int flag;
extern IMAGE img_game_background;
extern SceneManager scene_manager;

class GameScene :public Scene {
public:
	GameScene() = default;
	~GameScene() = default;
	/*
	�����ˣ�
	���ܣ���ʼ����ťλ��
	������void
	����ֵ��void
	*/
	void scene_enter() {
		//��ʼ��
		voice_button.right = 1180;
		voice_button.top = 0;
		voice_button.left = voice_button.right - voice_button_x;
		voice_button.bottom = pause_button_y;
		gamevoice = GameVoice(voice_button, _T("resources/sound_idle.png"), _T("resources/sound_hovered.png"), _T("resources/sound_pushed.png"), voice_button_x, voice_button_y);

		voice_open_button.right = 1180;
		voice_open_button.top = 0;
		voice_open_button.left = voice_open_button.right - voice_open_button_x;
		voice_open_button.bottom = voice_open_button_y;
		gamevoiceopen = GameVoiceOpen(voice_open_button, _T("resources/sound_off_idle.png"), _T("resources/sound_off_hovered.png"), _T("resources/sound_off_pushed.png"), voice_open_button_x, voice_open_button_y);
		
		pause_button.right = 1280;
		pause_button.top = 0;
		pause_button.left = pause_button.right - pause_button_x;
		pause_button.bottom = pause_button_y;
		gamepause = GamePause(pause_button, _T("resources/pause_idle.png"), _T("resources/pause_hovered.png"), _T("resources/pause_pushed.png"), pause_button_x, pause_button_y);

		game_start_button.right = 1280;
		game_start_button.top = 0;
		game_start_button.left = game_start_button.right - game_start_button_x;
		game_start_button.bottom = game_start_button_y;
		gamerestart = GameStart(game_start_button, _T("resources/play_idle.png"), _T("resources/play_hovered.png"), _T("resources/play_pushed.png"), game_start_button_x, game_start_button_y);

		reset_button.right = 1230;
		reset_button.top = 0;
		reset_button.left = reset_button.right - reset_button_x;
		reset_button.bottom = reset_button_y;
		gamereset = GameReset(reset_button, _T("resources/replay_idle.png"), _T("resources/replay_hovered.png"), _T("resources/replay_pushed.png"), reset_button_x, reset_button_y);
	
		replay_button.left = 0;
		replay_button.right = replay_button.left + replay_button_x;
		replay_button.top = 0;
		replay_button.bottom = replay_button.top + replay_button_y;
		replay = Replay(replay_button, _T("resources/replay_idle.png"), _T("resources/replay_hovered.png"), _T("resources/replay_pushed.png"), replay_button_x, replay_button_y);
	}
	/*
	�����ˣ�
	���ܣ������û����
	�������û����
	����ֵ��void
	*/
	 void data_input(const ExMessage& msg) {
		//��ť����
		gamereset.Button_input(msg);
		replay.Button_input(msg);
		if (play_num == 1)
			gamepause.Button_input(msg);
		else if (play_num == 0)
			gamerestart.Button_input(msg);
		if (music_num == 1)
			gamevoice.Button_input(msg);
		else if (music_num == 0)
			gamevoiceopen.Button_input(msg);
	}
		/*
	�����ˣ�
	���ܣ����ݸı��flagֵ����ƥ�䲢�ҽ�����Ӧ����
	������
	����ֵ��void
	*/
	void data_update(int delta) {
		//��������
		if (flag <= 60) {
			scene_manager.switch_to(flag);
		}
	}
		/*
	�����ˣ�
	���ܣ���Ⱦ��ť
	������void
	����ֵ��void
	*/
	 void picture_draw() {
		putimage(0, 0, &img_game_background);
		gamereset.Button_draw();
		replay.Button_draw();
		if (play_num == 1)
			gamepause.Button_draw();
		else if (play_num == 0)
			gamerestart.Button_draw();
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
		//�˳��������ͷ���Դ
	}

private:
	class GameReset:public Button {
	public:
		GameReset() = default;
		~GameReset() = default;

		GameReset(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int x, int y) :
			Button(rect, path_img_idle, path_img_hovered, path_img_pushed, x, y) {}

	protected:
		void OnClick() {
			flag = 0;
		}

	};

	class GamePause :public Button {
	public:
		GamePause() = default;
		~GamePause() = default;

		GamePause(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int x, int y) :
			Button(rect, path_img_idle, path_img_hovered, path_img_pushed, x, y) {}

	protected:
		void OnClick() {
			play_num = 0;
		}
	};

	class GameStart :public Button {
	public:
		GameStart() = default;
		~GameStart() = default;

		GameStart(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int x, int y) :
			Button(rect, path_img_idle, path_img_hovered, path_img_pushed, x, y) {}

	protected:
		void OnClick() {
			play_num = 1;
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

	class Replay :public Button {
	public:
		Replay() = default;
		~Replay() = default;

		Replay(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int x, int y)
			:Button(rect, path_img_idle, path_img_hovered, path_img_pushed, x, y) {}

	protected:
		void OnClick() {
			flag = 4;			//��ͼ����
		}
	};

private:

	RECT reset_button;
	int reset_button_x = 50,
		reset_button_y = 50;
	GameReset gamereset;

	RECT pause_button;
	int pause_button_x = 50,
		pause_button_y = 50;
	GamePause gamepause;

	RECT game_start_button;
	int game_start_button_x = 50,
		game_start_button_y = 50;
	GameStart gamerestart;

	RECT voice_button;
	int voice_button_x = 50,
		voice_button_y = 50;
	GameVoice gamevoice;

	RECT voice_open_button;
	int voice_open_button_x = 50,
		voice_open_button_y = 50;
	GameVoiceOpen gamevoiceopen;

	RECT replay_button;
	int replay_button_x = 50,
		replay_button_y = 50;
	Replay replay;

	int x_distance = 30;			//��ť���

};


#endif // !_GAME_SCENE_H
