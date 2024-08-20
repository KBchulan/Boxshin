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
        //按钮初始化
        menu_button.right = 1280;
        menu_button.top = 0;
        menu_button.left = menu_button.right - menu_button_x;
        menu_button.bottom = menu_button_y;
        menu = Menu(menu_button, _T("resources/menu_idle.png"), _T("resources/menu_hovered.png"), _T("resources/menu_pushed.png"), menu_button_x, menu_button_y);
    }

    void data_input(const ExMessage& msg) {
        //按钮输入
        menu.Button_input(msg);
    }

    void data_update(int delta) {
        //更新按钮
        if (flag != 8) {
            scene_manager.switch_to(flag);
        }
    }

    void picture_draw() {
        //绘制按钮
        menu.Button_draw();
    }

    void scene_exit() {
        //退出场景
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
    RECT menu_button;								//定义按钮矩形
    int menu_button_x = 50,
        menu_button_y = 50;							//按钮的长宽
    Menu menu;										//定义按钮



};

#endif // !_TEAM_INTRODUCTION_SCENE_H_
