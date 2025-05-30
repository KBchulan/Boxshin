#ifndef __TEAM_INTRODUCTION_SCENE_H__
#define __TEAM_INTRODUCTION_SCENE_H__

#include"scene.h"
#include"button.h"
#include"scene_manager.h"

int team_draw = 1;
int team_draw_sum = 4;
int team_draw_min = 1;

extern int flag;
extern IMAGE img_team_one;
extern IMAGE img_team_two;
extern IMAGE img_team_three;
extern IMAGE img_team_four;
extern IMAGE img_team_five;
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
        
        nextpage_button.right = 1150;
        nextpage_button.top = 580;
        nextpage_button.left = nextpage_button.right - nextpage_button_x;
        nextpage_button.bottom = nextpage_button_y + nextpage_button.top;
        nextpage = NextPage(nextpage_button, _T("resources/next_two.png"), _T("resources/next_one.png"), _T("resources/next_three.png"), nextpage_button_x, nextpage_button_y);

        previouspage_button.right = 200;
        previouspage_button.top = 580;
        previouspage_button.left = previouspage_button.right - previouspage_button_x;
        previouspage_button.bottom = previouspage_button_y + previouspage_button.top;
        previouspage = PreviousPage(previouspage_button, _T("resources/previous_two.png"), _T("resources/previous_one.png"), _T("resources/previous_three.png"), previouspage_button_x, previouspage_button_y);

    
    }

    void data_input(const ExMessage& msg) {
        //按钮输入
        menu.Button_input(msg);
        nextpage.Button_input(msg);
        previouspage.Button_input(msg);
    }

    void data_update(int delta) {
        //更新按钮
        if (flag != 8) {
            scene_manager.switch_to(flag);
        }
    }

    void picture_draw() {
        if (team_draw == 1) {
            putimage(0, 0, &img_team_one);
        }
        if (team_draw == 2) {
            putimage(0, 0, &img_team_two);
        }
        if (team_draw == 3) {
            putimage(0, 0, &img_team_three);
        }
        if (team_draw == 4) {
            putimage(0, 0, &img_team_four);
        }
        if (team_draw == 5) {
            putimage(0, 0, &img_team_five);
        }
        //绘制按钮
        menu.Button_draw(menu_button.left, menu_button.top);
        nextpage.Button_draw(nextpage_button.left, nextpage_button.top, WHITE);
        previouspage.Button_draw(previouspage_button.left, previouspage_button.top, WHITE);
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

    class NextPage :public Button {
    public:
        NextPage() = default;
        ~NextPage() = default;

        NextPage(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int x, int y)
            :Button(rect, path_img_idle, path_img_hovered, path_img_pushed, x, y) {}

    protected:
        void OnClick() {
            if (team_draw <= team_draw_sum) {
                team_draw++;
            }
        }
    };

    class PreviousPage :public Button {
    public:
        PreviousPage() = default;
        ~PreviousPage() = default;

        PreviousPage(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int x, int y)
            :Button(rect, path_img_idle, path_img_hovered, path_img_pushed, x, y) {}

    protected:
        void OnClick() {
            if (team_draw > team_draw_min) {
                team_draw--;
            }
        }
    };

private:
    RECT menu_button;								//定义按钮矩形
    int menu_button_x = 50,
        menu_button_y = 50;							//按钮的长宽
    Menu menu;										//定义按钮

    RECT nextpage_button;							//定义按钮矩形
    int nextpage_button_x = 80,
        nextpage_button_y = 50;						//按钮的长宽
    NextPage nextpage;								//定义按钮

    RECT previouspage_button;						//定义按钮矩形
    int previouspage_button_x = 80,
        previouspage_button_y = 50;					//按钮的长宽
    PreviousPage previouspage;						//定义按钮


};

#endif // !_TEAM_INTRODUCTION_SCENE_H_
