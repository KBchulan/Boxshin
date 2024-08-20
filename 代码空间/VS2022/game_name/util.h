#ifndef _GAME_NAME_UTIL_H
#define _GAME_NAME_UTIL_H

#include<easyx.h>

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


#endif // _GAME_NAME_UTIL_H