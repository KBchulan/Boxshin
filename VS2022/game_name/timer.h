#ifndef _TIMER_H_
#define _TIMER_H_

//定时器编写，此处采用回调的思路，因为不同的定时器都只需要写一种lambda

#include<functional>

class Timer {
public:
	Timer() = default;
	~Timer() = default;

	//初始化
	void restart() {
		pass_time = 0;
		shotted = false;
	}

	//设置该计时器的持续时间
	void set_wait_time(int x) {
		wait_time = x;
	}

	//设计计时器存在轮数，是否为一轮
	void set_one_shot(bool flag) {
		one_shot = flag;
	}

	void set_callback(std::function<void()> callback) {
		this->callback = callback;
	}

	//停止计时器
	void pause() {
		paused = true;
	}

	//恢复计时器
	void resume() {
		paused = false;
	}

	//数据更新
	void data_update(int delta) {
		if (paused)
			return;
		pass_time += delta;
		if (pass_time >= wait_time) {
			if ((!one_shot || (one_shot && !shotted)) && callback) {
				callback();
			}
			shotted = true;
			pass_time = 0;
		}
	}


private:
	int pass_time = 0;					//已过时间
	int wait_time = 0;					//等待时间
	bool paused = false;				//是否暂停
	bool shotted = false;				//是否触发
	bool one_shot = false;				//单次触发
	std::function<void()> callback;		//触发回调
};


#endif // !_TIMER_H_