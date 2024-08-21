#ifndef _UTIL_H
#define _UTIL_H

#include<easyx.h>

#pragma comment(lib,"Msimg32.lib")

//Í¼Æ¬Ëõ·Å
void resizeImage(IMAGE* src, IMAGE* dst, int newWidth, int newHeight) {
    dst->Resize(newWidth, newHeight);
    DWORD* pSrc = GetImageBuffer(src);
    DWORD* pDst = GetImageBuffer(dst);
    int srcWidth = src->getwidth();
    int srcHeight = src->getheight();
    for (int y = 0; y < newHeight; ++y) {
        for (int x = 0; x < newWidth; ++x) {
            int srcX = x * srcWidth / newWidth;
            int srcY = y * srcHeight / newHeight;
            pDst[y * newWidth + x] = pSrc[srcY * srcWidth + srcX];
        }
    }
}

inline void putimage_alpha(int dst_x, int dst_y, IMAGE* img) {
	int w = img->getwidth();
	int h = img->getheight();
	AlphaBlend(GetImageHDC(GetWorkingImage()), dst_x, dst_y, w, h, GetImageHDC(img), 0, 0, w, h, { AC_SRC_OVER,0,255,AC_SRC_ALPHA });
}

inline void putimage_alpha(int dst_x, int dst_y, int width, int height, IMAGE* img, int src_x, int src_y) {
	int w = width > 0 ? width : img->getwidth();
	int h = height > 0 ? height : img->getheight();
	AlphaBlend(GetImageHDC(GetWorkingImage()), dst_x, dst_y, w, h, GetImageHDC(img), src_x, src_y, w, h, { AC_SRC_OVER,0,255,AC_SRC_ALPHA });
}

inline void putimage_alpha(int dst_x, int dst_y, IMAGE* img, COLORREF backgroundColor) {
	int w = img->getwidth();
	int h = img->getheight();
	DWORD* pSrc = GetImageBuffer(img);
	DWORD* pDst = GetImageBuffer(GetWorkingImage());
	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			int srcIndex = y * w + x;
			COLORREF color = pSrc[srcIndex];

			if (color != backgroundColor) {
				pDst[(dst_y + y) * getwidth() + (dst_x + x)] = color;
			}
		}
	}
}

inline void putimage_alpha(IMAGE* dst, int x, int y, IMAGE* src, UINT transparentcolor) {
	HDC dstDC = GetImageHDC(dst);
	HDC srcDC = GetImageHDC(src);
	int w = src->getwidth();
	int h = src->getheight();
	TransparentBlt(dstDC, x, y, w, h, srcDC, 0, 0, w, h, transparentcolor);
}

inline void sketch_image(IMAGE* src, IMAGE* dst) {
	int w = src->getwidth();
	int h = src->getheight();
	Resize(dst, w, h);
	DWORD* src_buffer = GetImageBuffer(src);
	DWORD* dst_buffer = GetImageBuffer(dst);
	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			int idx = y * w + x;
			dst_buffer[idx] = BGR(RGB(255, 255, 255)) | (src_buffer[idx] & 0xFF000000);
		}
	}
}

inline void flip_image(IMAGE* src, IMAGE* dst) {
	int w = src->getwidth();
	int h = src->getheight();
	Resize(dst, w, h);
	DWORD* src_buffer = GetImageBuffer(src);
	DWORD* dst_buffer = GetImageBuffer(dst);
	for (auto y = 0; y < h; y++) {
		for (auto x = 0; x < w; x++) {
			int idx_src = y * w + x;
			int idx_dst = y * w + (w - x - 1);
			dst_buffer[idx_dst] = src_buffer[idx_src];
		}
	}
}


#endif // _GAME_NAME_UTIL_H