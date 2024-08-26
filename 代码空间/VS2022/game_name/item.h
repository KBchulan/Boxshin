#pragma once
// 两个分类方式：是否互动、是否动态
// 一、单纯的静图； 二、单纯的动图； 三、互动类的

#include <easyx.h>
#include <vector>

#include "animation.h" 
#include "scene_manager.h"
#include <functional>
#include "util.h"

extern int flag;
extern int game_map[26][16];
extern POINT player_position;
extern SceneManager scene_manager;

extern Atlas atlas_bubble;
extern Atlas atlas_flow;

extern IMAGE img_wall;
extern IMAGE img_penetration_wall;
extern IMAGE img_coral;
extern IMAGE img_mechanics_0;
extern IMAGE img_mechanics_1;
extern IMAGE img_star;

bool operator==(POINT A, POINT B) {
  return A.x == B.x && A.y == B.y;
}

class Item {
public:
  Item() = default;
  ~Item() = default;

  void set_atlas(Atlas* atlas) {
    this->atlas_item = atlas;
  }

  void set_position(POINT position) {
    this->item_position = position;
  }

  void set_animation(const Animation& animation) {
    this->animation_item = animation;
  }

  void set_visibility(bool flag) {
    this->is_visible = flag;
  }

  void set_callback(std::function<int()> callback) {
    this->callback = callback;
  }

  void set_img(IMAGE img) {
    this->img = img;
  }

  void picture_draw() {
    putimage_alpha(item_position.x, item_position.y, &img);
  }

  Animation& animation() {
    return this->animation_item;
  }

  virtual int interact(POINT player_position) { }


protected:
  Atlas* atlas_item = nullptr;
  Animation animation_item;
  IMAGE img;
  POINT item_position;
  bool is_visible = true;
  std::function<int()> callback;
};




/*
  气泡
*/
class Item_bubble : Item {
public:
  Item_bubble() {
    this->atlas_item = &atlas_bubble;
    this->animation_item.set_atlas(&atlas_bubble);
    this->animation_item.set_interval(100);
    this->animation_item.set_loop(true);
  }
  ~Item_bubble() = default;

  // callback
  int interact(POINT player_position) {
    if (player_position == this->item_position) {
      return 1; // 告诉player该膨胀了
    }
  }
};



/*
  可穿越的墙壁
*/
class Item_penetration_wall : Item {
  Item_penetration_wall() {
    // read picture
    this->img = img_penetration_wall;
  }
  ~Item_penetration_wall() = default;
  // 交互方式需结合碰撞逻辑讨论
};



/*
  机关
*/
class Item_mechanics : Item {
public:
  Item_mechanics(int type) : type(type) {
    this->img = type == 0 ? img_mechanics_0 : img_mechanics_1;
  }
  ~Item_mechanics() = default;

  int get_type() const {
    return this->type;
  }

  void link(Item_mechanics* linking) {
    if (this->type == 0)
      this->linked = linking;
  }

  void trigger(bool flag) {
    if (this->type == 0) {
      this->linked->set_visibility(flag);
    }
  }

  int interact(POINT player_position) {
    if (this->type != 0) return 0;
    if (player_position == this->item_position) {
      this->trigger(false);
    }
    else {
      this->trigger(true);
    }
    return 0;
  }


private:
  int type; // 0 for trigger, 1 for gate
  Item_mechanics* linked = nullptr;
};



/*
  水流
*/
class Item_flow : Item {
  Item_flow() {
    this->atlas_item = &atlas_flow;
    this->animation_item.set_atlas(&atlas_flow);
    this->animation_item.set_interval(100);
    this->animation_item.set_loop(true);

  }
  int interact(POINT player_position) {
    // player_position == this->position && player moving && 上方未遮挡 -> player move up -> return 2
    // player_position == this->position && player moving && 上方遮挡 && not moving down -> player move left or right -> return 3
    // player_position == this->position && player moving && 上方遮挡 && moving down -> player still -> return 4
  }
};
