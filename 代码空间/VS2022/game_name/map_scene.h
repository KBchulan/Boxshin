#ifndef _MAP_SCENE_H_
#define _MAP_SCENE_H_

#include"scene.h"
#include"button.h"
#include"scene_manager.h"

extern int flag;
extern SceneManager scene_manager;

class MapScene : public Scene {
public:
	MapScene() = default;;
	~MapScene() = default;

    void scene_enter() {
        //按钮初始化
        
    }

    void data_input(const ExMessage& msg) {
        //按钮输入
    }

    void data_update(int delta) {
        //更新按钮
    }

    void picture_draw() {
        //绘制按钮
        //background_draw();
    }

    void scene_exit() {
        //退出场景
    }


private:
    class Map61:public Button {
    public:
        Map61() = default;
        ~Map61() = default;

        Map61(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int x, int y)
            :Button(rect, path_img_idle, path_img_hovered, path_img_pushed, x, y) {}

    protected:
        void OnClick() {
            flag = 61;
        }
    };



};

#endif // !_MAP_SCENE_H_
