

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
		//�ж��㶯����ʼ��
		animation_enemy_fish.set_atlas(&atlas_enemy_fish);
		animation_enemy_fish.set_interval(75);
		animation_enemy_fish.set_loop(true);
		//��ʱ����ʼ��
		timer_test.set_wait_time(1000);
		timer_test.set_one_shot(false);
		timer_test.set_callback(
			[&]() {
				//std::cout << "timer_test" << std::endl;
			}
		);
	}
	//���ó�ʼλ��
	void set_position(int x, int y) {
		this->x = x;
		this->y = y;
		this->target_x = x;
		this->target_y = y;
		enemy_fish_position.x = 160 + x * 40;
		enemy_fish_position.y = 40 + y * 40;
	}


	void draw() {
		//֡��ʾͼ��
		if (is_alive) {
			animation_enemy_fish.picture_draw(enemy_fish_position.x,enemy_fish_position.y);
		  }
		}
	//�����ƶ���������ǽ�ڲ��ƶ�
	void move() {
		int time = 3;
		while(time--) {
			if (game_map[x + 1][y] != 3) {
				enemy_fish_position.x++;
				x += 1;
				game_map[x + 1][y] = 2;//ȥ���ĵط��й�
				game_map[x][y] = 0;//�뿪�ĵط�û��
			}
		}
		time += 6;
		while (time--) {
			if (game_map[x-1][y] != 3) {
				enemy_fish_position.x--;
				x -= 1;
				game_map[x-1][y] = 2;//ȥ���ĵط��й�
				game_map[x][y] = 0;//�뿪�ĵط�û��
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
		//����input���ݵ�ӳ��
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

			//�������Ŀ��λ�ã�ֹͣ�ƶ�
			if (enemy_fish_position.x == target_position_x && enemy_fish_position.y == target_position_y) {
				//���Ƶ�λ�ú��ǻ��ƶ�   is_moving = false;
				//�����ƶ�������ֱ�������������2
				game_map[x][y] = 2;			//������λ��
			}
		}
	}


private:
	Animation animation_enemy_fish;

	//��ʱ��
	Timer timer_test;
	bool is_alive;//�ж��Ƿ����
	int x, y;//ˢ�µ�λ��
	POINT enemy_fish_position;
	Direction move_direction;//�趨��ʼλ�Ʒ���Ϊ��
	bool is_moving = false;//�궨�Ƿ����ƶ�
	bool pushed_moving = false;//�궨���ƶ�
	int speed = 20;//�ƶ��ٶ�
	int target_x; int target_y;
};