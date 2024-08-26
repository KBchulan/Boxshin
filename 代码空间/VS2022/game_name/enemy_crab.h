#ifndef _ENEMY_CRAB_H_
#define _ENEMY_CRAB_H_
#include"enemy.h"
#include"player.h"

extern int game_map[26][16];

class Enemy_crab
{
public:
	Enemy_crab() = default;
	~Enemy_crab() = default;


	void set_atlas(Atlas* atlas) {
		this->atlas_enemy_crab_idle = atlas;
	}

	void set_animation(const Animation& animation) {
		this->animation_enemy_idle = animation;
	}

	Animation& animation() {
		return this->animation_enemy_idle;
	}

	POINT& position() {
		return this->enemy_crab_position;
	}


	void set_position(int x, int y)
	{
		this->x = x;
		this->y = y;
		this->target_x = x;
		this->target_y = y;
		enemy_crab_position.x = 120 + x * 40;
		enemy_crab_position.y = 40 + y * 40;
	}

	void set_ismoving(bool is_moving)
	{
		this->is_moving = is_moving;
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

		// 更新player位置
		if (is_moving) {
			int target_position_x = 120 + target_x * 40;
			int target_position_y = 40 + target_y * 40;
			if (enemy_crab_position.x < target_position_x) {
				enemy_crab_position.x += speed * delta;
				if (enemy_crab_position.x > target_position_x) enemy_crab_position.x = target_position_x;
			}
			else if (enemy_crab_position.x > target_position_x) {
				enemy_crab_position.x -= speed * delta;
				if (enemy_crab_position.x < target_position_x) enemy_crab_position.x = target_position_x;
			}
			else if (enemy_crab_position.y < target_position_y) {
				enemy_crab_position.y += speed * delta;
				if (enemy_crab_position.y > target_position_y) enemy_crab_position.y = target_position_y;
			}
			else if (enemy_crab_position.y > target_position_y) {
				enemy_crab_position.y -= speed * delta;
				if (enemy_crab_position.y < target_position_y) enemy_crab_position.y = target_position_y;
			}

			//如果到达目标位置，停止移动
			if (enemy_crab_position.x == target_position_x && enemy_crab_position.y == target_position_y) {
				is_moving = false;
				x = target_x;
				y = target_y;
				game_map[x][y] = 2;			//更新新位置
			}
		}
	}

private:
	int target_x, target_y;				//目标位置
	int x, y;							//当前位置
	int speed = 15;						//标定移动速度
	bool is_moving=false;				//标定是否在移动
	bool pushed_moving = false;			//标定被推动

	Direction move_direction;			//设定初始位移方向为下

private:
	Animation animation_enemy_idle;
	Atlas* atlas_enemy_crab_idle;
	POINT enemy_crab_position;
};


#endif // _ENEMY_CRAB_H_
