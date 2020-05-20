// 第二次上機考試 ------- 第 1 題 3 分 -------
// 
// 宣告一個結構 sCircle 裡面包含一個圓的基本資料如下：
//    名稱 char(10)、座標 x/y、半徑 radius 與顏色 r/g/b  ，除了名稱外，其他都是 int
// 文字檔 circles.txt 裡面儲存了 10 個圓的資料 , 利用 fopen/fclose/fscanf等指令
//    將  circles.txt  讀入，並將資料儲存到 sCircle 所宣告的一維結構陣列 cx 中
//  
// 另外以 sCircle 宣告一個變數 boss 程式必須分成兩段
//  第一個部分 : 讀取  circles.txt ，並將資料儲存到一維結構陣列  cx  中
//  第二部分 : 以迴圈在畫面上劃出這10個圓
//               同時計算 boss 座標與半徑，座標是這 10個圓座標的平均值
//     				           半徑是這 10 個圓半徑的總和 * 0.35
//               顏色是白色
//             最後劃出 boss 的圓
//
//  參考 ex2-1.jpg
// 

//#define EX1
#ifdef EX1

#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"


// �ŧi ���c sCircle 
struct sCircle
{
	char Name[10];
	int x, y, radius, r, g, b;
};


int main()
{
	int i;
	initwindow(SCREENWIDTH, SCREENWIDTH, "EX2 ��1�D");
	registermousehandler(WM_MOUSEMOVE, move_handler);		// 註冊滑鼠移動的處理函式
	registermousehandler(WM_LBUTTONDOWN, lbDown_handler);   // 註冊滑鼠左鍵按下的處理函式
	registermousehandler(WM_LBUTTONUP, lbUp_handler);		// 註冊滑鼠左鍵釋放的處理函式
	srand(time(NULL));

	FILE *sCircle;		// 宣告指向檔案的結構指標
	sCircle = fopen("circles.txt", "r");		// 開啟檔案
	if (sCircle == NULL) {
		printf("�ɮ׵L�k�}��");
	}
	struct	sCircle cx[10], boss = { "boss",0,0,0,255,255,255 };// 宣告結構陣列 cx 與 boss，在宣告 boss 時, 設定初始值為 "boss",0,0,0,255,255,255

	// 產生10個圓，並輸出
	for (i = 0; i < 10; i++) // 以迴圈讀取 circles.txt 的內容
	{
		fscanf(sCircle,"%s %d %d %d %d %d %d\n",cx[i].Name,&cx[i].x,&cx[i].y,&cx[i].radius,&cx[i].r,&cx[i].g,&cx[i].b); //以 fscanf() 讀取
	}
	fclose(sCircle);			// 關閉檔案

	for (i = 0; i < 10; i++ )	// 以迴圈顯示內容
	{
		printf("%s %d %d %d %d %d %d\n", cx[i].Name, cx[i].x, cx[i].y, cx[i].radius, cx[i].r, cx[i].g, cx[i].b);
		setcolor(COLOR(cx[i].r,cx[i].g,cx[i].b));	// 設定顏色
		outtextxy(X(cx[i].x),Y(cx[i].y), cx[i].Name);  // 顯示文字
		circle(X(cx[i].x), Y(cx[i].y), cx[i].radius);		// 畫出圓
		boss.x = boss.x + cx[i].x;
		boss.y = boss.y + cx[i].y;
		boss.radius = boss.radius + cx[i].radius;
	}
	boss.x = boss.x / 10;
	boss.y = boss.y / 10;
	boss.radius = boss.radius * 0.35f;

	// 畫出 boss
	setcolor(COLOR(255,255,255));  // 設定顏色
	outtextxy(X(boss.x), Y(boss.y), boss.Name);
	circle(X(boss.x), Y(boss.y), boss.radius);

	while (!kbhit())
	{
		delay(200);
	}
	return 0;
}

#endif