#include "functions.h"
#include "CMouse.h"
#include <stdlib.h>
#define NORMAL_COLOR COLOR_YELLOW
#define DANGER_COLOR COLOR_RED
CMouse ::CMouse()
{
	x = 0;
	y = 0;
	status = 1;
	mcolor[0] = NORMAL_COLOR;
	mcolor[1] = DANGER_COLOR;
	color = mcolor[0];
}

void CMouse ::setColor(int nc, int dc)
{
	mcolor[0] = nc;
	mcolor[1] = dc;
}

void CMouse ::setPos(int _x, int _y)
{
	x = _x;
	y = _y;
}

void CMouse ::draw()
{
	drawColorBox(x,y,color);
}

int CMouse ::update(char cIn)
{
	switch (cIn) {
		case 'w': // 往上. 更改老鼠位置,並根據新的位置,更新老鼠的狀態
			setPos(x , y + 20);
			break;
		case 's': // 往下
			setPos(x , y - 20);
			break;
		case 'a': // 往左
			setPos(x - 20, y);
			break;
		case 'd': // 往右
			setPos(x + 20, y);
			break;
	}

	if (abs(x) < 200 && abs(y) < 200) { // 安全區域內
		status = 1;
		color = mcolor[0];
	}
	else if (abs(x) > 200 || abs(y) > 200) {// 移除邊界 老鼠死亡 遊戲結束
		status = 0;
	}
	else {	// 在邊界上
		status = 2;
		color = mcolor[1];
	}
	return status;
}