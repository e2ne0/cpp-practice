// 第二次上機考試 ------- 第 5 題 2 分 -------
//
// 宣告一個 cCircle 類別，裡面包含
//  私有包含(都是整數型別)
//     圓的 x/y 座標與 半徑 radius (都是 int 型別)
//  公有包含
//     顏色 r g b (都是 int 型別) 
//     init()  函式，設定座標在 100, 100, 半徑為 50 顏色為白色 255 255 255
//     setRadius() 函式，有 1個 int 引數型別，傳入圓的半徑 
//     setColor() 函式，有 3 個 int 引數型別，傳入圓的顏色 r g b
//	   draw()  為友誼函式，將傳入的 cCircle 物件，畫在螢幕上
//     這三個函式都不用回傳值
//
//  根據主程式的註解，完成所需的程式碼，並畫出 ex2-5.jpg 的結果
// 
//  要求: 友誼函式 draw() 與 setRadius() 函式的實體必須寫在類別外
//

//#define EX5
#ifdef EX5

#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include "functions.h"

// 宣告 cCircle 類別
class cCircle
{
private:
	int x,y,radius;
public:
	int r,g,b;
	void init()
	{
		x = y = 100;
		radius = 50;
		r = g = b = 255;
	}
	void setRadius(int _radius);
	
	void setColor(int _r, int _g, int _b)
	{
		r = _r;
		g = _g;
		b = _b;
	}
	friend void draw(cCircle& _cCircle);
};


// draw() 友誼函式
void draw(cCircle& _cCircle)
{
	setcolor(COLOR(_cCircle.r,_cCircle.g,_cCircle.b));
	circle(X(_cCircle.x), Y(_cCircle.y), _cCircle.radius);
}

void cCircle::setRadius(int _radius)
{
	radius = _radius;
}

int main()
{
	int i;
	initwindow(SCREENWIDTH, SCREENWIDTH, "EX2");
	registermousehandler(WM_MOUSEMOVE, move_handler);		// 註冊滑鼠移動的處理函式
	registermousehandler(WM_LBUTTONDOWN, lbDown_handler);   // 註冊滑鼠左鍵按下的處理函式
	registermousehandler(WM_LBUTTONUP, lbUp_handler);		// 註冊滑鼠左鍵釋放的處理函式
	srand(time(NULL));

	cCircle c1, c2, c3, c4;		// 以 cCircle 宣告四個物件 c1, c2, c3, c4
	// c1 呼叫 init, 然後呼叫 draw 畫出 c1
	c1.init();
	draw(c1);
	printf("%d",c1.b);
	// c2 呼叫 init, 然後呼叫 setRadius 設定半徑為 150, 呼叫 setColor 設定顏色為 255, 0, 0, 呼叫 draw 畫出 c2
	c2.init();
	c2.setRadius(150);
	c2.setColor(255,0,0);
	draw(c2);
	// c3 呼叫 init, 然後呼叫 setRadius 設定半徑為 100, 呼叫 setColor 設定顏色為 0, 255, 0, 呼叫 draw 畫出 c3
	c3.init();
	c3.setRadius(100);
	c3.setColor(0,255,0);
	draw(c3);
	// c4 呼叫 init, 然後呼叫 setRadius 設定半徑為 50, 呼叫 setColor 設定顏色為 0, 0, 255,  呼叫 draw 畫出 c4
	c4.init();
	c4.setRadius(50);
	c4.setColor(0,0,255);
	draw(c4);
	
	while (!kbhit())
	{
		delay(200);
	}
	return 0;
}

#endif
