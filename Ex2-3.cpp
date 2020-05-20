// 第二次上機考試 ------- 第 3 題 2 分 -------
//
// 宣告一個 sCircle 結構，裡面包含
//     圓的 x/y 座標 顏色 r, g, b 與半徑 radius (都是整數型別)
//     gen() 函式，有兩個引數， ix 與 ir ， 都是 int 型別，沒有回傳值
//			 功能 : 設定圓的座標是 (ix, ix) 半徑是 ir，顏色隨機生成
//
//     draw()函式，沒有回傳值沒有引數，負責將圓畫在螢幕上
//
// 提示:顏色用 rand() % 155 + 100 
//
// 在主程式以 sCircle 結構包含10個元素的一維結構陣列根據以下的註解完成所需要的程式碼，
// 要求：主程以迴圈透過結構陣列中的每一個元素呼叫 gen() 函式 與 draw()函式 來畫出這10個圓
//    完成 ex2-3.jpg
// 
//  draw 會用到的函式 
// 	setcolor(COLOR( , ,));  // 設定顏色
//  circle(X(), Y(), );

//#define EX3
#ifdef EX3

#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include "functions.h"



// 宣告 sCircle 結構
struct sCircle
{
	int x, y, radius, r, g, b;

	void gen(int ix, int iy,int ir){
		x = ix;
		y = iy;
		radius = ir;
	}

	void draw() {
		r = rand() % 155 + 100;
		g = rand() % 155 + 100;
		b = rand() % 155 + 100;
		setcolor(COLOR(r, g, b));
		circle(X(x), Y(y), radius);
	}
};


int main()
{
	int i;
	initwindow(SCREENWIDTH, SCREENWIDTH, "EX2-3");
	registermousehandler(WM_MOUSEMOVE, move_handler);		// 註冊滑鼠移動的處理函式
	registermousehandler(WM_LBUTTONDOWN, lbDown_handler);   // 註冊滑鼠左鍵按下的處理函式
	registermousehandler(WM_LBUTTONUP, lbUp_handler);		// 註冊滑鼠左鍵釋放的處理函式
	srand(time(NULL));

	struct sCircle cx[10];				// 宣告 sCircle 結構陣列 包含 10 個元素

	for (i = 0; i < 10; i++) //用迴圈
	{
		cx[i].gen(-300 + i * 60, -300 + i * 60, i * 6 + 10);		// 呼叫 gen 時，傳入  -300+i*60, i*6+10
		cx[i].draw() ;		// 呼叫 draw 畫出自己
	}
	while (!kbhit())
	{
		delay(200);
	}
	return 0;
}

#endif
