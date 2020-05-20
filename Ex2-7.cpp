// 第二次上機考試 ------- 第 7 題 5 + 1 分 -------
//
// 計分方式 :  全部寫在 ex2-7.cpp 內，且能執行正常 5 分
//             將 CMouse 類別的宣告與成員函式的實體，分別寫在 CMouse.h CMouse.cpp
//             ex2-7.cpp 只有主程式 main, 且能正常執行則是 6 分
//			   提示 : drawColorBox() 定義在 functions.h 中
//
// 宣告 CMouse 類別裡面包含
//   私有包含(都是整數型別)
//      座標 x/y，顏色 color, 一維陣列 mcolor 包含兩個元素，分別儲存老鼠 正常狀態 與 在邊界上的顏色
//      狀態 status;  1:正常狀態, 2:在邊界上, 0: 死亡
//   公有包含
//      建構元(設定老鼠的初始狀態)
//			設定 位置在 (0,0), 狀態為 正常狀態
//			mcolor 的顏色分別是  NORMAL_COLOR 與 DANGER_COLOR，而 color 為設定為正常顏色 [0]
//      setColor() 函式，兩個引數，傳入老鼠正常狀態與危險狀態的顏色, 型別都是 int
//			功能是設定 mcolor[0] 與  mcolor[1] 為這兩個顏色
//      setPos 函式，兩個引數，傳入老鼠的 x/y 座標，型別都是 int
//			功能是設定老鼠的座標
//		draw 函式，畫出老鼠
//      update() 函式，回傳值為整數，傳回老鼠的狀態，引數為輸入的字元 
//               功能是依照輸入的 wasd 四個按鍵，讓老鼠上下左右個移動 20 個單位
//               同時判斷 老鼠是否在 X/Y 正負 200 的範圍內(不含)
//					狀態設定成 正常狀態 顏色為  mcolor[0]
//				 剛好在 X/Y 正負 200 的位置上
//					狀態設定成 在邊界上 顏色為  mcolor[1]
//				以及超出 X/Y 正負 200 的範圍外  狀態設定成死亡
//
// 根據主程式的需求，完成可利用鍵盤 w s a d 四個按鍵，控制老鼠的移動，走到邊界改變顏色，移除並顯示死亡
// 善意提醒 : 不要將傳入的引數變數名稱宣告成跟成員變數一樣
//  
//

//#define EX7
#ifdef EX7

#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>
#include "functions.h"
#include "CMouse.h"

#define NORMAL_COLOR COLOR_YELLOW
#define DANGER_COLOR COLOR_RED

#define X_MAX 200	// 定義可活動的範圍
#define Y_MAX 200	// 定義可活動的範圍
using namespace std;
void drawFence();

// draw() 函式會用到
//	drawColorBox( ); // 畫出老鼠,  x  y 座標與顏色

// update() 函式會用到

	//switch () {
	//case 'w': // 往上. 更改老鼠位置,並根據新的位置,更新老鼠的狀態
	//	break;
	//case 's': // 往下
	//	break;
	//case 'a': // 往左
	//	break;
	//case 'd': // 往右
	//	 break;
	//}

	//if ( ) { // 安全區域內
	//	
	//}
	//else if () {// 移除邊界 老鼠死亡 遊戲結束

	//}
	//else {	// 在邊界上

	//}

	

int main()
{
	char cIn;
	int status;
	initwindow(SCREENWIDTH, SCREENWIDTH, "EX2-7");
	CMouse mx;						// 宣告 mx 建立時就會自動呼叫 CMouse 建構
	mx.setPos(-120, 120);						// 呼叫 setPos 位置設定在 (-120, 120)
	mx.setColor(COLOR_WHITE, COLOR_BLACK);						// 呼叫 setColor，顏色設定成 COLOR_WHITE, COLOR_BLACK
	do {
		cleardevice();
		drawFence();	// 畫出範圍
		mx.draw();				// 畫出老鼠
		swapbuffers();
		cIn = getch();		// 輸入
		status = mx.update(cIn);				// 讓老鼠自己更新狀態
		rewind(stdin);
	} while (status != 0);

	cleardevice();
	drawFence();
	setcolor(COLOR_WHITE);
	outtextxy(X(-100), Y(0), "!! mouse is die !! ");
	swapbuffers();
	while (!kbhit()) { delay(200); } return 0;
}

void drawFence()
{
	for (int i = -200; i <= 200; i += 20) {
		drawColorBox(i, 200, COLOR_LIGHTGREEN);
		drawColorBox(i, -200, COLOR_LIGHTGREEN);
	}
	for (int i = -180; i <= 180; i += 20) {
		drawColorBox(-200, i, COLOR_LIGHTGREEN);
		drawColorBox(200, i, COLOR_LIGHTGREEN);
	}
}

#endif
