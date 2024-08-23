#ifndef __EXIT_SCENE_H__
#define __EXIT_SCENE_H__

#include"scene.h"
#include"button.h"
#include"scene_manager.h"

extern int flag;
extern bool running;
extern IMAGE img_exit_background;
extern IMAGE img_menu_background;
extern SceneManager scene_manager;

class ExitScene : public Scene {
public:
    ExitScene() = default;
    ~ExitScene() = default;

    void scene_enter() {
        //初始化按钮
        confirm_button.right = 560;
        confirm_button.top = 550;
        confirm_button.left = confirm_button.right - confirm_button_x;
        confirm_button.bottom = confirm_button.top + confirm_button_y;
        confirm = Confirm(confirm_button, _T("resources/confirm_idle.png"), _T("resources/confirm_hovered.png"), _T("resources/UI/menu/confirm_pushed.png"), confirm_button_x, confirm_button_y);

        concel_button.left = 720;
        concel_button.top = 550;
        concel_button.right = concel_button.left + concel_button_x;
        concel_button.bottom = concel_button.top + concel_button_y;
        concel = Concel(concel_button, _T("resources/canel_idle.png"), _T("resources/canel_hovered.png"), _T("resources/canel_pushed.png"), concel_button_x, concel_button_y);
    }

    void data_input(const ExMessage& msg) {
        //按钮输入
        confirm.Button_input(msg);
        concel.Button_input(msg);
    }

    void data_update(int delta) {
        //更新按钮
        if (flag != 6) {
            scene_manager.switch_to(flag);
        }
    }

    void picture_draw() {
        putimage(0, 0, &img_menu_background);
        putimage(120, 67.5, &img_exit_background);
        //绘制按钮
        confirm.Button_draw(confirm_button.left, confirm_button.top);
        concel.Button_draw(concel_button.left, concel_button.top);
    }

    void scene_exit() {
        //退出场景
    }

private:
    class Confirm : public Button {
    public:
        Confirm() = default;
        ~Confirm() = default;

        Confirm(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int x, int y)
            :Button(rect, path_img_idle, path_img_hovered, path_img_pushed, x, y) {}

    protected:
        void OnClick() {
            running=false;
        }
    };

    class Concel : public Button {
    public:
        Concel() = default;
        ~Concel() = default;

        Concel(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int x, int y)
            :Button(rect, path_img_idle, path_img_hovered, path_img_pushed, x, y) {}

    protected:
        void OnClick() {
            flag = 1;
        }
    };

private:
    RECT confirm_button;
    int confirm_button_x = 275,
        confirm_button_y = 90;
    Confirm confirm;

    RECT concel_button;
    int concel_button_x = 275,
        concel_button_y = 90;
    Concel concel;

};

#endif // !
