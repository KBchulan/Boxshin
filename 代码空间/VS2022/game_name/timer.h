#ifndef _TIMER_H_
#define _TIMER_H_

//��ʱ����д���˴����ûص���˼·����Ϊ��ͬ�Ķ�ʱ����ֻ��Ҫдһ��lambda

#include<functional>

class Timer {
public:
	Timer() = default;
	~Timer() = default;

	//��ʼ��
	void restart() {
		pass_time = 0;
		shotted = false;
	}

	//���øü�ʱ���ĳ���ʱ��
	void set_wait_time(int x) {
		wait_time = x;
	}

	//��Ƽ�ʱ�������������Ƿ�Ϊһ��
	void set_one_shot(bool flag) {
		one_shot = flag;
	}

	void set_callback(std::function<void()> callback) {
		this->callback = callback;
	}

	//ֹͣ��ʱ��
	void pause() {
		paused = true;
	}

	//�ָ���ʱ��
	void resume() {
		paused = false;
	}

	//���ݸ���
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
	int pass_time = 0;					//�ѹ�ʱ��
	int wait_time = 0;					//�ȴ�ʱ��
	bool paused = false;				//�Ƿ���ͣ
	bool shotted = false;				//�Ƿ񴥷�
	bool one_shot = false;				//���δ���
	std::function<void()> callback;		//�����ص�
};


#endif // !_TIMER_H_