// 第二次上機考試 ------- 第 6 題 3 分 -------
//
// 宣告一個 cMouse 類別，裡面包含
//   私有包含(都是整數型別)  
//     座標 pos 為 int 型別的指標變數
//     顏色 color 為 int 型別的指標變數
// 公有包含 
//     建構元: 為 pos 取得兩個儲存空間，為 color 取得一個儲存空間
//	           設定座標在 0,0, 顏色為 COLOR_WHITE
//     解構元: 釋放建構元取得的 pos 與 color
//     draw 函式，畫出自己，沒有回傳值
//
//     swap 函式，有兩個引數 ix 與 iy , int 型別, 以【傳參照】的方式傳入
//          功能是先交換 ix 與 iy 的內容
//			然後設定 ix 與 iy 為老鼠的新座標
//			沒有回傳值
//
// 參考主程式的註解說明，完成 ex2-6.jpg 的畫面
//
// 要求 :
//		1. 建構元的空間取得與解構元的空間釋放，必須完全正確才算分
//      2. 建構元、解構元與 swap 函式 寫在 類別外面
//    
//

#define EX6
#ifdef EX6

#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include "functions.h"

// 宣告 cMouse 類別
class cMouse
{
private:
	int *pos, *color;
public:
	cMouse();
	~cMouse();
	void draw()
	{
		drawColorBox(*pos,*(pos + 1), *color);
	}
	void swap(int& ix, int& iy);
};
// draw()函式 會用到
// drawColorBox(, , ); // 三個引數分別是 x, y ,color

// 建構元, 結構元, swap 函式寫在外面
cMouse::cMouse()
{
	pos = (int*)malloc(sizeof(int)*2);
	*(pos) = 0;
	*(pos + 1) = 0;
	color = new int;
	*color = COLOR_WHITE;
}

cMouse::~cMouse()
{
	free(pos);
	free(color);
}

void cMouse ::swap(int &ix, int &iy)
{
	int temp = ix;
	ix = iy;
	iy = temp;
	*(pos) = ix;
	*(pos + 1) = iy;
}

int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "EX2-6");
	registermousehandler(WM_MOUSEMOVE, move_handler);		// 註冊滑鼠移動的處理函式
	registermousehandler(WM_LBUTTONDOWN, lbDown_handler);   // 註冊滑鼠左鍵按下的處理函式
	registermousehandler(WM_LBUTTONUP, lbUp_handler);		// 註冊滑鼠左鍵釋放的處理函式
	srand(time(NULL));

	int x = 100, y = -100;
	cMouse mx;				// 宣告 mx
	mx.draw();				// mx 呼叫 draw
	mx.swap(x,y);				// mx 呼叫 swap 並將 x 與 y 傳入
	mx.draw();				// mx 呼叫 draw

	outtextxy(X(x), Y(y), "SWAP");

	while (!kbhit())
	{
		delay(200);
	}
	return 0;
}

#endif
