

#include<easyx.h>
#include<vector>
#include"enemy.h"
#include"animation.h"
#include"timer.h"
#include"scene_manager.h"
#include"player.h"
extern Atlas atlas_enemy_fish;

extern int game_map[26][16];

class enemy_fish :public Enemy {

public:
	enemy_fish() = default;
	~enemy_fish() = default;

	void init() {
		//敌对鱼动画初始化
		animation_enemy_fish.set_atlas(&atlas_enemy_fish);
		animation_enemy_fish.set_interval(75);
		animation_enemy_fish.set_loop(true);
		//定时器初始化
		timer_test.set_wait_time(1000);
		timer_test.set_one_shot(false);
		timer_test.set_callback(
			[&]() {
				//std::cout << "timer_test" << std::endl;
			}
		);
	}
	//设置初始位置
	void set_position(int x, int y) {
		this->x = x;
		this->y = y;
		this->target_x = x;
		this->target_y = y;
		enemy_fish_position.x = 160 + x * 40;
		enemy_fish_position.y = 40 + y * 40;
	}


	void draw() {
		//帧显示图集
		if (is_alive) {
			animation_enemy_fish.picture_draw(enemy_fish_position.x,enemy_fish_position.y);
		  }
		}
	//来回移动三格，遇到墙壁不移动
	void move() {
		int time = 3;
		while(time--) {
			if (game_map[x + 1][y] != 3) {
				enemy_fish_position.x++;
				x += 1;
				game_map[x + 1][y] = 2;//去到的地方有怪
				game_map[x][y] = 0;//离开的地方没怪
			}
		}
		time += 6;
		while (time--) {
			if (game_map[x-1][y] != 3) {
				enemy_fish_position.x--;
				x -= 1;
				game_map[x-1][y] = 2;//去到的地方有怪
				game_map[x][y] = 0;//离开的地方没怪
			}
		}
		
		
	}

private:
	enum class Direction {
		DOWN,
		LEFT,
		RIGHT,
		NONE,
		UP
	};

	void set_direction(Direction direction)
	{
		move_direction = direction;
	}

	void data_update(int delta) {
		//更新input内容的映射
		if (move_direction != Direction::NONE && game_map[x][y] != 3) {
			target_x = x;
			target_y = y;
			switch (move_direction) {
			case Direction::UP:
				target_y--;
				break;
			case Direction::DOWN:
				target_y++;
				break;
			case Direction::LEFT:
				target_x--;
				break;
			case Direction::RIGHT:
				target_x++;
				break;
			}
			move_direction = Direction::DOWN;
			is_moving = true;
			pushed_moving = false;
		}
		if (is_moving) {
			int target_position_x = 160 + target_x * 40;
			int target_position_y = 40 + target_y * 40;
			if (enemy_fish_position.x < target_position_x) {
				enemy_fish_position.x += speed * delta;
				if (enemy_fish_position.x > target_position_x) enemy_fish_position.x = target_position_x;
			}
			else if (enemy_fish_position.x > target_position_x) {
				enemy_fish_position.x -= speed * delta;
				if (enemy_fish_position.x < target_position_x) enemy_fish_position.x = target_position_x;
			}
			else if (enemy_fish_position.y < target_position_y) {
				enemy_fish_position.y += speed * delta;
				if (enemy_fish_position.y > target_position_y) enemy_fish_position.y = target_position_y;
			}
			else if (enemy_fish_position.y > target_position_y) {
				enemy_fish_position.y -= speed * delta;
				if (enemy_fish_position.y < target_position_y) enemy_fish_position.y = target_position_y;
			}

			//如果到达目标位置，停止移动
			if (enemy_fish_position.x == target_position_x && enemy_fish_position.y == target_position_y) {
				//被推到位置后还是会移动   is_moving = false;
				//不断移动，所以直接在哪那里就是2
				game_map[x][y] = 2;			//更新新位置
			}
		}
	}


private:
	Animation animation_enemy_fish;

	//定时器
	Timer timer_test;
	bool is_alive;//判断是否活着
	int x, y;//刷新的位置
	POINT enemy_fish_position;
	Direction move_direction;//设定初始位移方向为左
	bool is_moving = false;//标定是否在移动
	bool pushed_moving = false;//标定被推动
	int speed = 20;//移动速度
	int target_x; int target_y;
};