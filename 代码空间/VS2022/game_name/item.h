#ifndef _ITEM_H_
#define _ITEM_H_

#include <easyx.h>

#include "util.h"
#include "animation.h"

//根据map绘图
extern int game_map[14][12];
extern Atlas atlas_coral;
extern Atlas atlas_star;
extern Atlas atlas_bubble;
extern Atlas atlas_flow;
extern Atlas atlas_machanic_trigger; // 机关触发器
extern Atlas atlas_machanic_gate; // 机关门
extern Atlas atlas_penetration_wall; // 可穿越墙壁

class Item {
public:
  Item() = default;
  ~Item() = default;

  virtual void date_update(int delta) {

  }

  virtual void picture_draw(int x, int y) {

  }

  virtual void picture_draw() {}

  void set_position(POINT point) {
    position = point;
  }


protected:
  Animation  animation_item_idle;			//动画对象
  POINT position;

};

class Coral :public Item {
public:
  Coral(POINT position) {
    this->position = position;
    animation_item_idle.set_atlas(&atlas_coral);


  }
  ~Coral() = default;

  void picture_draw(int x, int y) {
    animation_item_idle.picture_draw(80 * x + 80, y * 50 + 60);
  }

  void picture_draw() {
    animation_item_idle.picture_draw(80 * position.x + 80, 50 * position.y + 60);
  }



};

class Star :public Item {
public:
  Star(POINT position) {
    this->position = position;
    animation_item_idle.set_atlas(&atlas_star);


  }
  ~Star() = default;

  void picture_draw(int x, int y) {
    animation_item_idle.picture_draw(80 * x + 95, 50 * y + 58);
  }

  void picture_draw() {
    animation_item_idle.picture_draw(80 * position.x + 95, 50 * position.y + 58);
  }



};

class Bubble :public Item {
public:
  Bubble(POINT position) {
    this->position = position;
    animation_item_idle.set_atlas(&atlas_bubble);
  }
  ~Bubble() = default;

};

class Penetration_wall :public Item {
public:
  Penetration_wall(POINT position) {
    this->position = position;
    animation_item_idle.set_atlas(&atlas_penetration_wall);
  }
  ~Penetration_wall() = default;
};

class Mechanic_trigger :public Item {};

class Mechanic_gate :public Item {};

class Flow :public Item {};



#endif // !_ITEM_H_
