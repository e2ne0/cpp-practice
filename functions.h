#pragma once

#define SCREENWIDTH  800
#define SCREENHEIGHT 800

#define M_PI 3.1415926f
#define ATOR(x)  ((x)*M_PI/180.f)
//
// 在畫圖時，使用小學所學的笛卡兒座標系(2D平面)，螢幕正中心點是 (0,0)
//
#define X(x) (SCREENWIDTH/2 + (x))  // 轉換到畫圖的座標
#define Y(y) (SCREENHEIGHT/2 - (y))

//------ Color

#define COLOR_BLACK 0
#define COLOR_BLUE 1
#define COLOR_GREEN 2
#define COLOR_CYAN 3
#define COLOR_RED 4
#define COLOR_MAGENTA 5
#define COLOR_BROWN 6
#define COLOR_LIGHTGRAY 7
#define COLOR_DARKGRAY 8
#define COLOR_LIGHTBLUE 9
#define COLOR_LIGHTGREEN 10
#define COLOR_LIGHTCYAN 11
#define COLOR_LIGHTRED 12
#define COLOR_LIGHTMAGENTA 13
#define COLOR_YELLOW 14
#define COLOR_WHITE 15

void drawRect(int cx, int cy, int width, int height);
void drawRectRot(int cx, int cy, int width, int height, float angle);

void drawTri(int cx, int cy, int length);
void drawTriRot(int cx, int cy, int length, float angle);

void drawSquare(int cx, int cy, int length);
void drawSquRot(int cx, int cy, int length, float angle);
void drawColorBox(int cx, int cy, int color);
void drawBoxMan(int cx, int cy, int bodycolor, int eyecolor= COLOR_BLUE, int mouthcolor= COLOR_LIGHTBLUE);
void drawSizeBox(int cx, int cy, int color, int size);

void move_handler(int x, int y);
void lbDown_handler(int x, int y);
void lbUp_handler(int x, int y);
