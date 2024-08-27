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



class Coral :public Item {
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

};

class Penetration_wall :public Item {
public:
    Penetration_wall() {
        animation_item_idle.set_interval(1000);
        animation_item_idle.set_atlas(&atlas_penetration_wall);

    }
    ~Penetration_wall() = default;

    void data_update(int delta) {
        Item::date_update(delta);
    }

    void picture_draw(int x, int y) {
        Item::picture_draw(x, y);
    }

};

class Bubble :public Item {
public:
    Bubble() {
        animation_item_idle.set_atlas(&atlas_bubble);
        animation_item_idle.set_interval(200);
        animation_item_idle.set_loop(true);
    }
    ~Bubble() = default;

    void data_update(int delta) {
        Item::date_update(delta);
    }

    void picture_draw(int x, int y) {
        Item::picture_draw(x, y);
    }


};


class CoralBullle :public Item {                //吐泡泡的珊瑚
public:
    CoralBullle() {
        animation_item_idle.set_atlas(&atlas_coral_bubble);
        animation_item_idle.set_interval(200);
        animation_item_idle.set_loop(true);

    }
    ~CoralBullle() = default;


    void data_update(int delta) {
        Item::date_update(delta);
    }

    void picture_draw(int x, int y) {
        animation_item_idle.picture_draw(x * 80 + 80, y * 50 + 35);
    }

};



#endif // !_ITEM_H_
