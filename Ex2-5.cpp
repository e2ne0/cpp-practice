// �ĤG���W���Ҹ� ------- �� 5 �D 2 �� -------
//
// �ŧi�@�� cCircle ���O�A�̭��]�t
//  �p���]�t(���O��ƫ��O)
//     �ꪺ x/y �y�лP �b�| radius (���O int ���O)
//  �����]�t
//     �C�� r g b (���O int ���O) 
//     init()  �禡�A�]�w�y�Цb 100, 100, �b�|�� 50 �C�⬰�զ� 255 255 255
//     setRadius() �禡�A�� 1�� int �޼ƫ��O�A�ǤJ�ꪺ�b�| 
//     setColor() �禡�A�� 3 �� int �޼ƫ��O�A�ǤJ�ꪺ�C�� r g b
//	   draw()  ���ͽ˨禡�A�N�ǤJ�� cCircle ����A�e�b�ù��W
//     �o�T�Ө禡�����Φ^�ǭ�
//
//  �ھڥD�{�������ѡA�����һݪ��{���X�A�õe�X ex2-5.jpg �����G
// 
//  �n�D: �ͽ˨禡 draw() �P setRadius() �禡�����饲���g�b���O�~
//

//#define EX5
#ifdef EX5

#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include "functions.h"

// �ŧi cCircle ���O


// draw() �ͽ˨禡

int main()
{
	int i;
	initwindow(SCREENWIDTH, SCREENWIDTH, "EX2 �� 5 �D");
	registermousehandler(WM_MOUSEMOVE, move_handler);		// ���U�ƹ����ʪ��B�z�禡
	registermousehandler(WM_LBUTTONDOWN, lbDown_handler);   // ���U�ƹ�������U���B�z�禡
	registermousehandler(WM_LBUTTONUP, lbUp_handler);		// ���U�ƹ��������񪺳B�z�禡
	srand(time(NULL));

	cCircle c1, c2, c3, c4;		// �H cCircle �ŧi�|�Ӫ��� c1, c2, c3, c4
	// c1 �I�s init, �M��I�s draw �e�X c1
	
	// c2 �I�s init, �M��I�s setRadius �]�w�b�|�� 150, �I�s setColor �]�w�C�⬰ 255, 0, 0, �I�s draw �e�X c2
	
	// c3 �I�s init, �M��I�s setRadius �]�w�b�|�� 100, �I�s setColor �]�w�C�⬰ 0, 255, 0, �I�s draw �e�X c3
	
	// c4 �I�s init, �M��I�s setRadius �]�w�b�|�� 50, �I�s setColor �]�w�C�⬰ 0, 0, 255,  �I�s draw �e�X c4
	
	
	while (!kbhit())
	{
		delay(200);
	}
	return 0;
}

#endif