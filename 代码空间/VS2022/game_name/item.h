#ifndef _ITEM_H_
#define _ITEM_H_

#include <easyx.h>

#include "util.h"
#include "animation.h"

//根据map绘图
extern int game_map[14][12];
extern Atlas atlas_coral;
extern Atlas atlas_star;

class Item {
public:
	Item()=default;
	~Item()=default;

	virtual void date_update(int delta) {

	}

	virtual void picture_draw(int x,int y) {

	}

protected:
	Animation  animation_item_idle;			//动画对象

};

class Coral :public Item {
public:
	Coral() {
		animation_item_idle.set_atlas(&atlas_coral);
		

	}
	~Coral()=default;

	void picture_draw(int x,int y) {
		animation_item_idle.picture_draw(80 * x + 80, y * 50 + 60);
	}
};

class Star :public Item {
public:
	Star() {
		animation_item_idle.set_atlas(&atlas_star);


	}
	~Star() = default;

	void picture_draw(int x, int y) {
		animation_item_idle.picture_draw(80 * x + 95, y * 50 + 58);
	}
};




#endif // !_ITEM_H_
