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
        first_button.left = 280;
        first_button.right = first_button.left + first_button_x;
        first_button.top = 100;
        first_button.bottom = first_button.top + first_button_y;
        firstMap = MapTo61(first_button, _T("resources/map61_idle.png.png"), _T("resources/map61_hovered.png"), _T("resources/map61_pushed.png"), first_button_x, first_button_y);

        second_button.left = first_button.right + distance_x;
        second_button.right = second_button.left + second_button_x;
        second_button.top = first_button.top;
        second_button.bottom = second_button.top + second_button_y;
        secondMap = MapTo62(second_button, _T("resources/map62_idle.jpg"), _T("resources/map62_hovered.jpg"), _T("resources/map62_pushed.jpg"), second_button_x, second_button_y);

        third_button.left = second_button.right + distance_x;
        third_button.right = third_button.left + third_button_x;
        third_button.top = second_button.top;
        third_button.bottom = third_button.top + third_button_y;
        thirdMap = MapTo63(third_button, _T("resources/map63_idle.jpg"), _T("resources/map63_hovered.jpg"), _T("resources/map63_pushed.jpg"), third_button_x, third_button_y);

        fourth_button.left = first_button.left;
        fourth_button.right = fourth_button.left + fourth_button_x;
        fourth_button.top = third_button.bottom + distance_y;
        fourth_button.bottom = fourth_button.top + fourth_button_y;
        fourthMap = MapTo64(fourth_button, _T("resources/map64_idle.jpg"), _T("resources/map64_hovered.jpg"), _T("resources/map64_pushed.jpg"), fourth_button_x, fourth_button_y);

        fifth_button.left = fourth_button.right + distance_x;
        fifth_button.right = fifth_button.left + fifth_button_x;
        fifth_button.top = fourth_button.top;
        fifth_button.bottom = fifth_button.top + fifth_button_y;
        fifthMap = MapTo65(fifth_button, _T("resources/map65_idle.jpg"), _T("resources/map65_hovered.jpg"), _T("resources/map65_pushed.jpg"), fifth_button_x, fifth_button_y);

        sixth_button.left = fifth_button.right + distance_x;
        sixth_button.right = sixth_button.left + sixth_button_x;
        sixth_button.top = fifth_button.top;
        sixth_button.bottom = sixth_button.top + sixth_button_y;
        sixthMap = MapTo66(sixth_button, _T("resources/map66_idle.jpg"), _T("resources/map66_hovered.jpg"), _T("resources/map66_pushed.jpg"), sixth_button_x, sixth_button_y);

        seventh_button.left = fourth_button.left;
        seventh_button.right = seventh_button.left + seventh_button_x;
        seventh_button.top = fourth_button.bottom + distance_y;
        seventh_button.bottom = seventh_button.top + seventh_button_y;
        seventhMap = MapTo67(seventh_button, _T("resources/map67_idle.jpg"), _T("resources/map67_hovered.jpg"), _T("resources/map67_pushed.jpg"), seventh_button_x, seventh_button_y);
    }

    void data_input(const ExMessage& msg) {
        firstMap.Button_input(msg);
        secondMap.Button_input(msg);
        thirdMap.Button_input(msg);
        fourthMap.Button_input(msg);
        fifthMap.Button_input(msg);
        sixthMap.Button_input(msg);
        seventhMap.Button_input(msg);
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
        thirdMap.Button_draw();
        fourthMap.Button_draw();
        fifthMap.Button_draw();
        sixthMap.Button_draw();
        seventhMap.Button_draw();
    }

    void scene_exit() {
        //background_exit();
    }


private:
    class MapTo61 :public Button {
    public:
        MapTo61() = default;
        ~MapTo61() = default;

        MapTo61(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int x, int y)
            :Button(rect, path_img_idle, path_img_hovered, path_img_pushed, x, y) {}

    protected:
        void OnClick() {
            flag = 61;          //关卡1
        }
    };

    class MapTo62 :public Button {
    public:
        MapTo62() = default;
        ~MapTo62() = default;

        MapTo62(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int x, int y)
            :Button(rect, path_img_idle, path_img_hovered, path_img_pushed, x, y) {}

    protected:
        void OnClick() {
            flag = 62;          //关卡2
        }
    };

    class MapTo63 :public Button {
    public:
        MapTo63() = default;
        ~MapTo63() = default;

        MapTo63(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int x, int y)
            :Button(rect, path_img_idle, path_img_hovered, path_img_pushed, x, y) {}

    protected:
        void OnClick() {
            flag = 63;          //关卡3
        }
    };

    class MapTo64 :public Button {
    public:
        MapTo64() = default;
        ~MapTo64() = default;

        MapTo64(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int x, int y)
            :Button(rect, path_img_idle, path_img_hovered, path_img_pushed, x, y) {}

    protected:
        void OnClick() {
            flag = 64;          //关卡4
        }
    };

    class MapTo65 :public Button {
    public:
        MapTo65() = default;
        ~MapTo65() = default;

        MapTo65(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int x, int y)
            :Button(rect, path_img_idle, path_img_hovered, path_img_pushed, x, y) {}

    protected:
        void OnClick() {
            flag = 65;          //关卡5
        }
    };

    class MapTo66 :public Button {
    public:
        MapTo66() = default;
        ~MapTo66() = default;

        MapTo66(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int x, int y)
            :Button(rect, path_img_idle, path_img_hovered, path_img_pushed, x, y) {}

    protected:
        void OnClick() {
            flag = 66;          //关卡6
        }
    };

    class MapTo67 :public Button {
    public:
        MapTo67() = default;
        ~MapTo67() = default;

        MapTo67(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int x, int y)
            :Button(rect, path_img_idle, path_img_hovered, path_img_pushed, x, y) {}

    protected:
        void OnClick() {
            flag = 67;          //关卡7
        }
    };

private:
    int distance_x = 220,
        distance_y = 100;


    RECT first_button;							
    int first_button_x = 100,
        first_button_y = 100;						
    MapTo61 firstMap;							

    RECT second_button;							
    int second_button_x = 100,
        second_button_y = 100;						
    MapTo62 secondMap;	

    RECT third_button;
    int third_button_x = 100,
        third_button_y = 100;
    MapTo63 thirdMap;

    RECT fourth_button;
    int fourth_button_x = 100,
        fourth_button_y = 100;
    MapTo64 fourthMap;

    RECT fifth_button;
    int fifth_button_x = 100,
        fifth_button_y = 100;
    MapTo65 fifthMap;

    RECT sixth_button;
    int sixth_button_x = 100,
        sixth_button_y = 100;
    MapTo66 sixthMap;

    RECT seventh_button;
    int seventh_button_x = 100,
        seventh_button_y = 100;
    MapTo67 seventhMap;   

};

#endif // !_MAP_SCENE_H_
