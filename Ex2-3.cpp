// �ĤG���W���Ҹ� ------- �� 3 �D 2 �� -------
//
// �ŧi�@�� sCircle ���c�A�̭��]�t
//     �ꪺ x/y �y�� �C�� r, g, b �P�b�| radius (���O��ƫ��O)
//     gen() �禡�A����Ӥ޼ơA ix �P ir �A ���O int ���O�A�S���^�ǭ�
//			 �\�� : �]�w�ꪺ�y�ЬO (ix, ix) �b�|�O ir�A�C���H���ͦ�
//
//     draw()�禡�A�S���^�ǭȨS���޼ơA�t�d�N��e�b�ù��W
//
// ����:�C��� rand() % 155 + 100 
//
// �b�D�{���H sCircle ���c�]�t10�Ӥ������@�����c�}�C�ھڥH�U�����ѧ����һݭn���{���X�A
// �n�D�G�D�{�H�j��z�L���c�}�C�����C�@�Ӥ����I�s gen() �禡 �P draw()�禡 �ӵe�X�o10�Ӷ�
//    ���� ex2-3.jpg
// 
//  draw �|�Ψ쪺�禡 
// 	setcolor(COLOR( , ,));  // �]�w�C��
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



// �ŧi sCircle ���c
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
	initwindow(SCREENWIDTH, SCREENWIDTH, "EX2 ��3�D");
	registermousehandler(WM_MOUSEMOVE, move_handler);		// ���U�ƹ����ʪ��B�z�禡
	registermousehandler(WM_LBUTTONDOWN, lbDown_handler);   // ���U�ƹ�������U���B�z�禡
	registermousehandler(WM_LBUTTONUP, lbUp_handler);		// ���U�ƹ��������񪺳B�z�禡
	srand(time(NULL));

	struct sCircle cx[10];				// �ŧi sCircle ���c�}�C �]�t 10 �Ӥ���

	for (i = 0; i < 10; i++) //�ΰj��
	{
		cx[i].gen(-300 + i * 60, -300 + i * 60, i * 6 + 10);		// �I�s gen �ɡA�ǤJ  -300+i*60, i*6+10
		cx[i].draw() ;		// �I�s draw �e�X�ۤv
	}
	while (!kbhit())
	{
		delay(200);
	}
	return 0;
}

#endif
