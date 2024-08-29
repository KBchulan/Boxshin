#ifndef _MAP_RANDOM_CREATE_H_
#define _MAP_RANDOM_CREATE_H_

#include <chrono>
#include <easyx.h>


#define LOGICAL_SCREEN_WIDTH 1280                                               // 逻辑屏幕宽度
#define LOGICAL_SCREEN_HEIGHT 720                                               // 逻辑屏幕高度

#define MAP_BLOCK_SIZE 40                                                       // 单元大小

const int MAP_BLOCK_ROWS = (LOGICAL_SCREEN_HEIGHT - 80 / MAP_BLOCK_SIZE);       //二维数组的行数
const int MAP_BLOCK_COLS = (LOGICAL_SCREEN_WIDTH / MAP_BLOCK_SIZE);             //二维数组的列数

const int BLOCK_THICK = (MAP_BLOCK_SIZE / 10);                                  //方块厚度
const int BLOCK_LENGTH = MAP_BLOCK_SIZE + (BLOCK_THICK / 2);                    //方块长度

enum BlockType {
    BLOCK_EMPTY = 0,        //空白
    BLOCK_HORIZ = 1,        //水平
    BLOCK_VERTI = 2         //垂直
};

#define abs(x) (((x) > 0) ? (x) : (-(x)))
#define positive(x) (((x) > 0) ? (x) : 0)
#define random(x) ((rand() % (x)) - ((x) / 2))


struct Map {
    char data[MAP_BLOCK_ROWS][MAP_BLOCK_COLS];                  //每个单元格状态
    RECT rects[MAP_BLOCK_ROWS * MAP_BLOCK_COLS + 4];            //存储所有矩形块的位置信息
    RECT collide_rects[MAP_BLOCK_ROWS][MAP_BLOCK_COLS];         //每个单元格的碰撞信息
    int rects_size = 0;                                         //跟踪 rects 数组中当前存储的矩形块的数量

    void translate() {
        rects_size = 0;
        for (int y = 3; y <= MAP_BLOCK_ROWS; y++) {
            for (int x = 1; x <= MAP_BLOCK_COLS; x++) {
                if (data[y - 1][x - 1] == BLOCK_HORIZ) {
                    RECT block_rect = { MAP_BLOCK_SIZE * (x - 1),MAP_BLOCK_SIZE * y,block_rect.left + BLOCK_LENGTH,block_rect.top + BLOCK_THICK };
                    rects[rects_size++] = block_rect;
                    collide_rects[y - 1][x - 1] = block_rect;
                }
                else if (data[y - 1][x - 1] == BLOCK_VERTI) {
                    RECT block_rect = { MAP_BLOCK_SIZE * x,MAP_BLOCK_SIZE * (y - 1),block_rect.left + BLOCK_THICK,block_rect.top + BLOCK_LENGTH };
                    rects[rects_size++] = block_rect;
                    collide_rects[y - 1][x - 1] = block_rect;
                }
            }
        }
        RECT block_rect_l = { 0,MAP_BLOCK_SIZE * 2,BLOCK_THICK,LOGICAL_SCREEN_HEIGHT };
        rects[rects_size++] = block_rect_l;
        RECT block_rect_t = { 0,MAP_BLOCK_SIZE * 2,LOGICAL_SCREEN_WIDTH,BLOCK_THICK+block_rect_t.top };
        rects[rects_size++] = block_rect_t;
        RECT block_rect_r{ LOGICAL_SCREEN_WIDTH - BLOCK_THICK,MAP_BLOCK_SIZE * 2,LOGICAL_SCREEN_WIDTH,LOGICAL_SCREEN_HEIGHT };
        rects[rects_size++] = block_rect_r;
        RECT block_rect_b{ 0,LOGICAL_SCREEN_HEIGHT - BLOCK_THICK,LOGICAL_SCREEN_WIDTH, LOGICAL_SCREEN_HEIGHT };
        rects[rects_size++] = block_rect_b;
    }


    void getConnected() {
        char reigon[MAP_BLOCK_ROWS][MAP_BLOCK_COLS] = { 0 };
        reigon[0][0] = 1;
        int connect = 1;
    next:
        bool opera = true;
        while (opera) {
            opera = false;
            for (int y = 0; y < MAP_BLOCK_ROWS; y++) {
                for (int x = 0; x < MAP_BLOCK_COLS; x++) if (!reigon[y][x]) {
                    if ((y > 0 && data[y - 1][x] != BLOCK_HORIZ && reigon[y - 1][x])
                        || (x > 0 && data[y][x - 1] != BLOCK_VERTI && reigon[y][x - 1])
                        || (y < MAP_BLOCK_ROWS - 1 && data[y][x] != BLOCK_HORIZ && reigon[y + 1][x])
                        || (x < MAP_BLOCK_COLS - 1 && data[y][x] != BLOCK_VERTI && reigon[y][x + 1])) {
                        reigon[y][x] = 1;
                        connect++;
                        opera = true;
                    }
                }
            }
        }
        if (connect < MAP_BLOCK_ROWS * MAP_BLOCK_COLS) {
            for (int y = 0; y < MAP_BLOCK_ROWS; y++) {
                for (int x = 0; x < MAP_BLOCK_COLS; x++) if (reigon[y][x]) {
                    if (y < MAP_BLOCK_ROWS - 1 && data[y][x] == BLOCK_HORIZ && !reigon[y + 1][x]) {
                        data[y][x] = BLOCK_EMPTY;
                        reigon[y + 1][x] = 1;
                        connect++;
                        goto next;
                    }
                    else if (x < MAP_BLOCK_COLS - 1 && data[y][x] == BLOCK_VERTI && !reigon[y][x + 1]) {
                        data[y][x] = BLOCK_EMPTY;
                        reigon[y][x + 1] = 1;
                        connect++;
                        goto next;
                    }
                }
            }
        }
    }


    void generate() {
        uint64_t ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        srand(ms);
        for (int i = 0; i < MAP_BLOCK_ROWS - 1; i++) {
            for (int j = 0; j < MAP_BLOCK_COLS - 1; j++) {
                data[i][j] = rand() % 3;
            }
        }
        bool is_in_turnnel = false; int turnnel_start = 0;
        ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        for (int i = 0; i < MAP_BLOCK_ROWS; i++) {
            if (i < MAP_BLOCK_COLS - 1 && data[i][MAP_BLOCK_COLS - 2] == BLOCK_EMPTY && data[i + 1][MAP_BLOCK_COLS - 2] != BLOCK_VERTI)
                data[i][MAP_BLOCK_COLS - 1] = BLOCK_HORIZ;
            else
                data[i][MAP_BLOCK_COLS - 1] = BLOCK_EMPTY;
            if (data[i][MAP_BLOCK_COLS - 2] == BLOCK_VERTI && !is_in_turnnel) {
                is_in_turnnel = true;
                turnnel_start = i;
            }
            else if (data[i][MAP_BLOCK_COLS - 2] != BLOCK_VERTI && is_in_turnnel) {
                is_in_turnnel = false;
                data[positive(turnnel_start - 1) + rand() % (i - turnnel_start + 1)][MAP_BLOCK_COLS - 1] = BLOCK_HORIZ;
            }

        }
        is_in_turnnel = false;
        ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        for (int j = 0; j < MAP_BLOCK_COLS; j++) {
            if (j < MAP_BLOCK_COLS - 1 && data[MAP_BLOCK_ROWS - 2][j] == BLOCK_EMPTY && data[MAP_BLOCK_ROWS - 2][j + 1] != BLOCK_HORIZ)
                data[MAP_BLOCK_ROWS - 1][j] = BLOCK_VERTI;
            else
                data[MAP_BLOCK_ROWS - 1][j] = BLOCK_EMPTY;
            if (data[MAP_BLOCK_ROWS - 2][j] == BLOCK_HORIZ && !is_in_turnnel) {
                is_in_turnnel = true;
                turnnel_start = j;
            }
            else if (data[MAP_BLOCK_ROWS - 2][j] != BLOCK_HORIZ && is_in_turnnel) {
                is_in_turnnel = false;
                data[MAP_BLOCK_ROWS - 1][positive(turnnel_start - 1) + rand() % (j - turnnel_start + 1)] = BLOCK_VERTI;
            }
        }
        getConnected();
        translate();
    }


    Map() {
        generate();

    }

    void data_input(const ExMessage& msg) {

    }

    void data_update(int delta) {

    }

    void draw() {
        setfillcolor(WHITE); // 设置填充颜色为白色
        for (int i = 0; i < rects_size; ++i) {
            fillrectangle(rects[i].left, rects[i].top, rects[i].right, rects[i].bottom); // 绘制矩形
        }
    }


};

#endif // !_MAP_RANDOM_CREATE_H_
