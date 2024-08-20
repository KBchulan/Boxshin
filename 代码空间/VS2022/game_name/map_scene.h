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
        //��ť��ʼ��
        
    }

    void data_input(const ExMessage& msg) {
        //��ť����
    }

    void data_update(int delta) {
        //���°�ť
    }

    void picture_draw() {
        //���ư�ť
        //background_draw();
    }

    void scene_exit() {
        //�˳�����
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
