#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

#define BOX_SIZE 20

void move_handler(int x, int y)
{
	int sx, sy;
	sx = x - SCREENWIDTH / 2; // 轉換到 2D 平面座標
	sy = SCREENHEIGHT / 2 - y;
	//cleardevice();
	//drawRect(sx, sy, 200, 100); // 長方形，給中心點與邊長
	//swapbuffers();
}

void lbDown_handler(int x, int y)
{
	int sx, sy;
	sx = x - SCREENWIDTH / 2; // 轉換到 2D 平面座標
	sy = SCREENHEIGHT / 2 - y;
	//cleardevice();
	//drawRect(sx, sy, 200, 100); // 長方形，給中心點與邊長
	//swapbuffers();
}

void lbUp_handler(int x, int y)
{
	int sx, sy;
	sx = x - SCREENWIDTH / 2; // 轉換到 2D 平面座標
	sy = SCREENHEIGHT / 2 - y;
	//cleardevice();
	//circle(X(sx), Y(sy), 100); // 長方形，給中心點與邊長
	//swapbuffers();
}


void drawSquare(int cx, int cy, int length)
{
	float x1, y1, x2, y2, x3, y3, x4, y4;
	x1 = X(cx - length*0.5f); y1 = Y(cy + length*0.5f);
	x2 = X(cx + length*0.5f); y2 = Y(cy + length*0.5f);
	x3 = X(cx + length*0.5f); y3 = Y(cy - length*0.5f);
	x4 = X(cx - length*0.5f); y4 = Y(cy - length*0.5f);

	moveto((int)x1, (int)y1);
	lineto((int)x2, (int)y2);
	lineto((int)x3, (int)y3);
	lineto((int)x4, (int)y4);
	lineto((int)x1, (int)y1);
}

void drawSizeBox(int cx, int cy, int color, int size)
{
	int box[8];
	box[0] = X(cx - size*0.5f); box[1] = Y(cy + size*0.5f);
	box[2] = X(cx + size*0.5f); box[3] = Y(cy + size*0.5f);
	box[4] = X(cx + size*0.5f); box[5] = Y(cy - size*0.5f);
	box[6] = X(cx - size*0.5f); box[7] = Y(cy - size*0.5f);

	setcolor(color);
	setfillstyle(1, color);
	fillpoly(4, box);
}


void drawBoxMan(int cx, int cy, int bodycolor, int eyecolor, int mouthcolor)
{
	drawSizeBox(cx, cy, bodycolor, 100);
	drawSizeBox(cx-20, cy+20, eyecolor, 16); // 左眼睛
	drawSizeBox(cx+20, cy+20, eyecolor, 16); // 右眼睛	
	drawSizeBox(cx + 20, cy - 25, mouthcolor, 10); // 嘴巴
	drawSizeBox(cx + 10, cy - 25, mouthcolor, 10); // 嘴巴
	drawSizeBox(cx , cy - 25, mouthcolor, 10); // 嘴巴
	drawSizeBox(cx - 10, cy - 25, mouthcolor, 10); // 嘴巴
	drawSizeBox(cx - 20, cy - 25, mouthcolor, 10); // 嘴巴
}

void drawColorBox(int cx, int cy, int color)
{
	int box[8];
	box[0] = X(cx - BOX_SIZE*0.5f); box[1] = Y(cy + BOX_SIZE*0.5f);
	box[2] = X(cx + BOX_SIZE*0.5f); box[3] = Y(cy + BOX_SIZE*0.5f);
	box[4] = X(cx + BOX_SIZE*0.5f); box[5] = Y(cy - BOX_SIZE*0.5f);
	box[6] = X(cx - BOX_SIZE*0.5f); box[7] = Y(cy - BOX_SIZE*0.5f);

	setcolor(color);
	setfillstyle(1, color);
	fillpoly(4, box);
}

void drawSquRot(int cx, int cy, int length, float angle)
{
	float x1, y1, x2, y2, x3, y3, x4, y4;
	float rx1, ry1, rx2, ry2, rx3, ry3, rx4, ry4;
	float cosA, sinA;
	cosA = cosf(ATOR(angle)); sinA = sinf(ATOR(angle));

	x1 = -length*0.5f; y1 = length*0.5f;
	x2 = length*0.5f; y2 = length*0.5f;
	x3 = length*0.5f; y3 = -length*0.5f;
	x4 = -length*0.5f; y4 = -length*0.5f;

	rx1 = cosA*x1 - sinA *y1; ry1 = sinA*x1 + cosA*y1;
	rx2 = cosA*x2 - sinA *y2; ry2 = sinA*x2 + cosA*y2;
	rx3 = cosA*x3 - sinA *y3; ry3 = sinA*x3 + cosA*y3;
	rx4 = cosA*x4 - sinA *y4; ry4 = sinA*x4 + cosA*y4;

	x1 = X(cx + rx1); y1 = Y(cy + ry1);
	x2 = X(cx + rx2); y2 = Y(cy + ry2);
	x3 = X(cx + rx3); y3 = Y(cy + ry3);
	x4 = X(cx + rx4); y4 = Y(cy + ry4);

	moveto((int)x1, (int)y1);
	lineto((int)x2, (int)y2);
	lineto((int)x3, (int)y3);
	lineto((int)x4, (int)y4);
	lineto((int)x1, (int)y1);
}

void drawRect(int cx, int cy, int width, int height)
{
	rectangle(X(cx - width / 2), Y(cy + height / 2), X(cx + width / 2), Y(cy - height / 2));
}

void drawRectRot(int cx, int cy, int width, int height, float angle)
{
	float x1, y1, x2, y2, x3, y3, x4, y4;
	float rx1, ry1, rx2, ry2, rx3, ry3, rx4, ry4;
	float cosA, sinA;
	cosA = cosf(ATOR(angle)); sinA = sinf(ATOR(angle));

	x1 = -width*0.5f;  y1 = height*0.5f;
	x2 = width*0.5f;  y2 = height*0.5f;
	x3 = width*0.5f;  y3 = -height*0.5f;
	x4 = -width*0.5f;  y4 = -height*0.5f;

	rx1 = cosA*x1 - sinA *y1; ry1 = sinA*x1 + cosA*y1;
	rx2 = cosA*x2 - sinA *y2; ry2 = sinA*x2 + cosA*y2;
	rx3 = cosA*x3 - sinA *y3; ry3 = sinA*x3 + cosA*y3;
	rx4 = cosA*x4 - sinA *y4; ry4 = sinA*x4 + cosA*y4;

	x1 = X(cx + rx1); y1 = Y(cy + ry1);
	x2 = X(cx + rx2); y2 = Y(cy + ry2);
	x3 = X(cx + rx3); y3 = Y(cy + ry3);
	x4 = X(cx + rx4); y4 = Y(cy + ry4);

	moveto((int)x1, (int)y1);
	lineto((int)x2, (int)y2);
	lineto((int)x3, (int)y3);
	lineto((int)x4, (int)y4);
	lineto((int)x1, (int)y1);
}

void drawTri(int cx, int cy, int length)
{
	float x1, y1, x2, y2, x3, y3;
	float sqrt3;
	sqrt3 = sqrtf(3);
	x1 = (float)X(cx); y1 = (float)Y(cy + length / sqrt3);
	x2 = X(cx - length*0.5f); y2 = Y(cy - 0.5f*length / sqrt3);
	x3 = X(cx + length*0.5f); y3 = Y(cy - 0.5f*length / sqrt3);
	// 方法一：lineto 不會變更 current point 的位置
	//line(x1, y1, x2, y2);
	//line(x2, y2, x3, y3);
	//line(x3, y3, x1, y1);

	// 方法二：moveto 設定 current point 的位置
	moveto((int)x1, (int)y1);
	lineto((int)x2, (int)y2);
	lineto((int)x3, (int)y3);
	lineto((int)x1, (int)y1);
}

void drawTriRot(int cx, int cy, int length, float angle)
{
	float x1, y1, x2, y2, x3, y3;
	float rx1, ry1, rx2, ry2, rx3, ry3;
	float sqrt3;
	float cosA, sinA;
	sqrt3 = sqrtf(3);
	x1 = 0; y1 = length / sqrt3;
	x2 = -length*0.5f; y2 = -0.5f*length / sqrt3;
	x3 = length*0.5f; y3 = -0.5f*length / sqrt3;
	cosA = cosf(ATOR(angle)); sinA = sinf(ATOR(angle));
	rx1 = cosA*x1 - sinA *y1; ry1 = sinA*x1 + cosA*y1;
	rx2 = cosA*x2 - sinA *y2; ry2 = sinA*x2 + cosA*y2;
	rx3 = cosA*x3 - sinA *y3; ry3 = sinA*x3 + cosA*y3;

	x1 = X(cx + rx1); y1 = Y(cy + ry1);
	x2 = X(cx + rx2); y2 = Y(cy + ry2);
	x3 = X(cx + rx3); y3 = Y(cy + ry3);

	moveto((int)x1, (int)y1);
	lineto((int)x2, (int)y2);
	lineto((int)x3, (int)y3);
	lineto((int)x1, (int)y1);
}