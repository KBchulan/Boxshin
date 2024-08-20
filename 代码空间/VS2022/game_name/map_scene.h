#ifndef _MAP_SCENE_H_
#define _MAP_SCENE_H_

#include"scene.h"
#include"button.h"
#include"scene_manager.h"

extern int flag;
extern IMAGE img_map_background;
extern SceneManager scene_manager;

class MapScene : public Scene {
public:
    MapScene() = default;;
    ~MapScene() = default;

    void scene_enter() {
        first_button.left = 580;
        first_button.right = first_button.left + first_button_x;
        first_button.top = 400;
        first_button.bottom = first_button.top + first_button_y;
        firstMap = Map61(first_button, _T("resources/map61_idle.png.png"), _T("resources/map61_hovered.png"), _T("resources/map61_pushed.png"), first_button_x, first_button_y);

        second_button.left = first_button.left;
        second_button.right = second_button.left + second_button_x;
        second_button.top = first_button.bottom + distance;
        second_button.bottom = second_button.top + second_button_y;
        secondMap = Map62(second_button, _T("resources/map62_idle.jpg"), _T("resources/map62_hovered.jpg"), _T("resources/map62_pushed.jpg"), second_button_x, second_button_y);

    }

    void data_input(const ExMessage& msg) {
        firstMap.Button_input(msg);
        secondMap.Button_input(msg);
    }


    void data_update(int delta) {
        if (flag != 4) {
            scene_manager.switch_to(flag);
        }
        
    }
    void picture_draw() {
        //background_draw();
        putimage(0, 0, &img_map_background);
        firstMap.Button_draw();
        secondMap.Button_draw();
    }

    void scene_exit() {
        //background_exit();
    }


private:
    class Map61 :public Button {
    public:
        Map61() = default;
        ~Map61() = default;

        Map61(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int x, int y)
            :Button(rect, path_img_idle, path_img_hovered, path_img_pushed, x, y) {}

    protected:
        void OnClick() {
            flag = 61;          //¹Ø¿¨1
        }
    };

    class Map62 :public Button {
    public:
        Map62() = default;
        ~Map62() = default;

        Map62(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int x, int y)
            :Button(rect, path_img_idle, path_img_hovered, path_img_pushed, x, y) {}

    protected:
        void OnClick() {
            flag = 62;          //¹Ø¿¨2
        }
    };

private:
    int distance = 50;      

    RECT first_button;							
    int first_button_x = 100,
        first_button_y = 50;						
    Map61 firstMap;							

    RECT second_button;							
    int second_button_x = 100,
        second_button_y = 50;						
    Map62 secondMap;						

};

#endif // !_MAP_SCENE_H_
