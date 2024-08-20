#ifndef __TEAM_INTRODUCTION_SCENE_H__
#define __TEAM_INTRODUCTION_SCENE_H__

#include"scene.h"
#include"button.h"
#include"scene_manager.h"

extern int flag;
extern SceneManager scene_manager;

class TeamIntroductionScene : public Scene {
public:
	TeamIntroductionScene() = default;
	~TeamIntroductionScene() = default;

    void scene_enter() {
        //��ť��ʼ��
        menu_button.right = 1280;
        menu_button.top = 0;
        menu_button.left = menu_button.right - menu_button_x;
        menu_button.bottom = menu_button_y;
        menu = Menu(menu_button, _T("resources/menu_idle.png"), _T("resources/menu_hovered.png"), _T("resources/menu_pushed.png"), menu_button_x, menu_button_y);
    }

    void data_input(const ExMessage& msg) {
        //��ť����
        menu.Button_input(msg);
    }

    void data_update(int delta) {
        //���°�ť
        if (flag != 8) {
            scene_manager.switch_to(flag);
        }
    }

    void picture_draw() {
        //���ư�ť
        menu.Button_draw();
    }

    void scene_exit() {
        //�˳�����
    }

private:
    class Menu :public Button {
    public:
        Menu() = default;
        ~Menu() = default;

        Menu(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int x, int y)
            :Button(rect, path_img_idle, path_img_hovered, path_img_pushed, x, y) {}

    protected:
        void OnClick() {
            flag = 1;
        }
    };

private:
    RECT menu_button;								//���尴ť����
    int menu_button_x = 50,
        menu_button_y = 50;							//��ť�ĳ���
    Menu menu;										//���尴ť



};

#endif // !_TEAM_INTRODUCTION_SCENE_H_
