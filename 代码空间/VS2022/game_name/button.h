#ifndef _BUTTON_H_
#define _BUTTON_H_

#include<iostream>
#include<easyx.h>

//按钮的属性包括矩形和三张图片
class Button {
public:
	Button() = default;
	Button(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int x, int y) {
		region = rect;
		loadimage(&img_idle, path_img_idle, x, y);
		loadimage(&img_hovered, path_img_hovered, x, y);
		loadimage(&img_pushed, path_img_pushed, x, y);
	}
	~Button() = default;

	void Button_input(const ExMessage& msg) {
		switch (msg.message)
		{
		case WM_MOUSEMOVE:
			if (status == Status::Idle && checkcursorhit(msg.x, msg.y)) {
				status = Status::Hovered;
				//mciSendString(_T("play hovered"), NULL, 0, NULL);
			}
			else if (status == Status::Hovered && !checkcursorhit(msg.x, msg.y)) {
				status = Status::Idle;
			}
			break;
		case WM_LBUTTONDOWN:
			if (status == Status::Hovered && checkcursorhit(msg.x, msg.y)) {
				mciSendString(_T("play confirm"), NULL, 0, NULL);
				status = Status::Pushed;
			}
			break;
		case WM_LBUTTONUP:
			if (status == Status::Pushed && checkcursorhit(msg.x, msg.y)) {
				OnClick();
			}
			status = Status::Idle;
			break;
		}
	}

	void Button_draw() {
		switch (status) {
		case Status::Idle:
			putimage(region.left, region.top, &img_idle);
			break;
		case Status::Hovered:
			putimage(region.left, region.top, &img_hovered);
			break;
		case Status::Pushed:
			putimage(region.left, region.top, &img_pushed);
			break;
		}
	}

public:
	virtual void OnClick() = 0;

private:
	enum class Status {
		Idle = 0,
		Hovered,
		Pushed
	};

private:
	RECT region;
	IMAGE img_idle;
	IMAGE img_hovered;
	IMAGE img_pushed;
	Status status = Status::Idle;

private:
	bool checkcursorhit(int x, int y) {
		return x >= region.left && x <= region.right && y >= region.top && y <= region.bottom;
	}
};

#endif // !_BUTTON_H_
