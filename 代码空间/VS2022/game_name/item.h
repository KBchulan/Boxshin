#ifndef _ITEM_H_
#define _ITEM_H_

#include <easyx.h>

#include "util.h"
#include "animation.h"

extern int game_map[14][12];

extern Atlas atlas_coral;
extern Atlas atlas_star;
extern Atlas atlas_bubble;
extern Atlas atlas_coral_bubble;
extern Atlas atlas_crossed_wall;
extern Atlas atlas_button_idle;
extern Atlas atlas_button_down;
extern Atlas atlas_door;

extern bool is_big;						//标定是否为无敌状态,用于传入enemy使用
extern int flag;


class Item {
public:
    Item() {
        animation_item_idle.set_loop(true);
    }
    ~Item() = default;

    virtual void date_update(int delta) {
        animation_item_idle.data_update(delta);
    }

    virtual void picture_draw(int x, int y) {
        animation_item_idle.picture_draw(x * 80 + 80, y * 50 + 60);
    }


protected:
    Animation animation_item_idle;			//动画对象

};



class Coral :public Item {                  //珊瑚墙壁
public:
    Coral() {
        animation_item_idle.set_interval(1000);
        animation_item_idle.set_atlas(&atlas_coral);

    }
    ~Coral() = default;


    void data_update(int delta) {
        Item::date_update(delta);
    }

    void picture_draw(int x, int y) {
        Item::picture_draw(x, y);
    }

private:

};

class Star :public Item {
public:
    Star() {
        animation_item_idle.set_interval(1000);
        animation_item_idle.set_atlas(&atlas_star);


    }
    ~Star() = default;

    void data_update(int delta) {
        Item::date_update(delta);
    }

    void picture_draw(int x, int y) {
        Item::picture_draw(x, y);
    }

private:


};

class Penetration_wall :public Item {
public:
    Penetration_wall() {
        animation_item_idle.set_interval(200);
        animation_item_idle.set_atlas(&atlas_crossed_wall);
    }
    ~Penetration_wall() = default;

    void data_update(int delta) {
        Item::date_update(delta);
    }

    void picture_draw(int x, int y){
        Item::picture_draw(x, y);
    }

private:
};

class Bubble :public Item {
public:
    Bubble() {
        animation_item_idle.set_interval(200);
        animation_item_idle.set_atlas(&atlas_bubble);
    }
    ~Bubble() = default;

    void data_update(int delta) {
        Item::date_update(delta);
    }

    void picture_draw(int x, int y) {
        if(is_draw)
            Item::picture_draw(x, y);
    }

private:
    bool is_draw = true;
};

class CoralBullle :public Item {                //吐泡泡的珊瑚
public:
    CoralBullle() {
        animation_item_idle.set_atlas(&atlas_coral_bubble);
        animation_item_idle.set_interval(200);

    }
    ~CoralBullle() = default;


    void data_update(int delta) {
        Item::date_update(delta);
    }

    void picture_draw(int x, int y) {
        Item::picture_draw(x, y);
    }

private:


};

class GameButton :public Item {
public:
    GameButton() {
        animation_item_idle.set_interval(1000);
        animation_item_idle.set_atlas(&atlas_button_idle);
        switch (flag)
        {
        case 63:
            button_pos = { 6,7 };
            break;
        default:
            break;
        }
    }
    ~GameButton() = default;

    void data_update(int delta) {
        Item::date_update(delta);
        if (game_map[button_pos.x][button_pos.y] != 8) {
            is_down = true;
        }
        else {
            is_down = false;
        }
    }

    void picture_draw(int x, int y) {
        if(is_down)
            animation_item_idle.set_atlas(&atlas_button_down);
        else
            animation_item_idle.set_atlas(&atlas_button_idle);
        animation_item_idle.picture_draw(button_pos.x * 80 + 80, button_pos.y * 50 + 60);
    }

    bool is_button_down() {
        return is_down;
    }

private:
    bool is_down = false;
    POINT button_pos;

};

class Door :public Item {                  //门
public:
    Door() {
        animation_item_idle.set_interval(1000);
        animation_item_idle.set_atlas(&atlas_door);

    }
    ~Door() = default;

    void data_update(int delta) {
        Item::date_update(delta);
    }

    void picture_draw(int x, int y) {
        Item::picture_draw(x, y);
    }

private:

};



#endif // !_ITEM_H_
