// �ĤG���W���Ҹ� ------- �� 6 �D 3 �� -------
//
// �ŧi�@�� cMouse ���O�A�̭��]�t
//   �p���]�t(���O��ƫ��O)  
//     �y�� pos �� int ���O�������ܼ�
//     �C�� color �� int ���O�������ܼ�
// �����]�t 
//     �غc��: �� pos ���o����x�s�Ŷ��A�� color ���o�@���x�s�Ŷ�
//	           �]�w�y�Цb 0,0, �C�⬰ COLOR_WHITE
//     �Ѻc��: ����غc�����o�� pos �P color
//     draw �禡�A�e�X�ۤv�A�S���^�ǭ�
//
//     swap �禡�A����Ӥ޼� ix �P iy , int ���O, �H�i�ǰѷӡj���覡�ǤJ
//          �\��O���洫 ix �P iy �����e
//			�M��]�w ix �P iy ���ѹ����s�y��
//			�S���^�ǭ�
//
// �ѦҥD�{�������ѻ����A���� ex2-6.jpg ���e��
//
// �n�D :
//		1. �غc�����Ŷ����o�P�Ѻc�����Ŷ�����A�����������T�~���
//      2. �غc���B�Ѻc���P swap �禡 �g�b ���O�~��
//    
//

//#define EX6
#ifdef EX6

#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include "functions.h"


// �ŧi CMouse ���O


// draw()�禡 �|�Ψ�
// drawColorBox(, , ); // �T�Ӥ޼Ƥ��O�O x, y ,color

// �غc��, ���c��, swap �禡�g�b�~��


int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "EX2 �� 6 �D");
	registermousehandler(WM_MOUSEMOVE, move_handler);		// ���U�ƹ����ʪ��B�z�禡
	registermousehandler(WM_LBUTTONDOWN, lbDown_handler);   // ���U�ƹ�������U���B�z�禡
	registermousehandler(WM_LBUTTONUP, lbUp_handler);		// ���U�ƹ��������񪺳B�z�禡
	srand(time(NULL));

	int x = 100, y = -100;
					// �ŧi mx
					// mx �I�s draw
					// mx �I�s swap �ñN x �P y �ǤJ
					// mx �I�s draw

	outtextxy(X(x), Y(y), "SWAP");

	while (!kbhit())
	{
		delay(200);
	}
	return 0;
}

#endif