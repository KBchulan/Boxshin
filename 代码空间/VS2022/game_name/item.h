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
extern Atlas atlas_mechanic_trigger; // 机关触发器
extern Atlas atlas_mechanic_gate; // 机关门
extern Atlas atlas_penetration_wall; // 可穿越墙壁

extern Direction move_direction;     //标定移动方向，用于传入enemy和item中使用
extern int player_map_x, player_map_y;					//标定玩家在map[player_map_x][player_map_y]的位置
extern bool is_big;							//标定是否为无敌状态,用于传入enemy使用
extern bool is_moving;							//标定是否在移动,用于传入item中

bool operator==(POINT A, POINT B) {
  return A.x == B.x && A.y == B.y;
}

class Item {
public:
  Item() = default;
  ~Item() = default;

  virtual void date_update(int delta) {

  }

  virtual void picture_draw(int x, int y) {

  }

  virtual void picture_draw() {}

  void set_map_position(POINT point) {
    map_position = point;
  }


protected:
  Animation  animation_item_idle;			//动画对象
  POINT map_position;

};

class Coral :public Item {
public:
  Coral(POINT map_position) {
    this->map_position = map_position;
    animation_item_idle.set_atlas(&atlas_coral);


  }
  ~Coral() = default;

  void picture_draw(int x, int y) {
    animation_item_idle.picture_draw(80 * x + 80, y * 50 + 60);
  }

  void picture_draw() {
    animation_item_idle.picture_draw(80 * map_position.x + 80, 50 * map_position.y + 60);
  }



};

class Star :public Item {
public:
  Star(POINT map_position) {
    this->map_position = map_position;
    animation_item_idle.set_atlas(&atlas_star);


  }
  ~Star() = default;

  void picture_draw(int x, int y) {
    animation_item_idle.picture_draw(80 * x + 95, 50 * y + 58);
  }

  void picture_draw() {
    animation_item_idle.picture_draw(80 * map_position.x + 95, 50 * map_position.y + 58);
  }



};

class Bubble :public Item {
public:
  Bubble(POINT map_position) {
    this->map_position = map_position;
    animation_item_idle.set_atlas(&atlas_bubble);
    animation_item_idle.set_interval(100);
    animation_item_idle.set_loop(true);
  }
  ~Bubble() = default;

  void data_update(int delta) {
    animation_item_idle.data_update(delta);
    if (map_position.x == player_map_x && map_position.y == player_map_y) is_big = true;
  }

  void picture_draw() {
    animation_item_idle.picture_draw(80 * map_position.x, 50 * map_position.y);
  }

  void picture_draw(int x, int y) {
    animation_item_idle.picture_draw(80 * x + 80, 50 * y + 40);
  }

  

};

class Penetration_wall :public Item {
public:
  Penetration_wall(POINT map_position) {
    this->map_position = map_position;
    animation_item_idle.set_atlas(&atlas_penetration_wall);
  }
  ~Penetration_wall() = default;

  void picture_draw(int x, int y) {
    animation_item_idle.picture_draw(80 * x + 80, 50 * y + 40);
  }
};

class Mechanic_trigger :public Item {
public:
  Mechanic_trigger(POINT map_position) {
    this->map_position = map_position;
    animation_item_idle.set_atlas(&atlas_mechanic_trigger);
  }
  ~Mechanic_trigger() = default;

  void data_update(int delta) {
    if (map_position.x == player_map_x && map_position.y == player_map_y) {
      animation_item_idle.set_idx_frame(1);
      // 机制
    }
    else {
      animation_item_idle.set_idx_frame(0);
    }
  }

  void picture_draw(int x, int y) {
    animation_item_idle.picture_draw(80 * x + 80, 50 * y + 40);
  }
};

class Mechanic_gate :public Item {};

class Flow :public Item {};



#endif // !_ITEM_H_
