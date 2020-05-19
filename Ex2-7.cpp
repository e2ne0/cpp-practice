// �ĤG���W���Ҹ� ------- �� 7 �D 5 + 1 �� -------
//
// �p���覡 :  �����g�b ex2-7.cpp ���A�B����楿�` 5 ��
//             �N CMouse ���O���ŧi�P�����禡������A���O�g�b CMouse.h CMouse.cpp
//             ex2-7.cpp �u���D�{�� main, �B�ॿ�`����h�O 6 ��
//			   ���� : drawColorBox() �w�q�b functions.h ��
//
// �ŧi CMouse ���O�̭��]�t
//   �p���]�t(���O��ƫ��O)
//      �y�� x/y�A�C�� color, �@���}�C mcolor �]�t��Ӥ����A���O�x�s�ѹ� ���`���A �P �b��ɤW���C��
//      ���A status;  1:���`���A, 2:�b��ɤW, 0: ���`
//   �����]�t
//      �غc��(�]�w�ѹ�����l���A)
//			�]�w ��m�b (0,0), ���A�� ���`���A
//			mcolor ���C����O�O  NORMAL_COLOR �P DANGER_COLOR�A�� color ���]�w�����`�C�� [0]
//      setColor() �禡�A��Ӥ޼ơA�ǤJ�ѹ����`���A�P�M�I���A���C��, ���O���O int
//			�\��O�]�w mcolor[0] �P  mcolor[1] ���o����C��
//      setPos �禡�A��Ӥ޼ơA�ǤJ�ѹ��� x/y �y�СA���O���O int
//			�\��O�]�w�ѹ����y��
//		draw �禡�A�e�X�ѹ�
//      update() �禡�A�^�ǭȬ���ơA�Ǧ^�ѹ������A�A�޼Ƭ���J���r�� 
//               �\��O�̷ӿ�J�� wasd �|�ӫ���A���ѹ��W�U���k�Ӳ��� 20 �ӳ��
//               �P�ɧP�_ �ѹ��O�_�b X/Y ���t 200 ���d��(���t)
//					���A�]�w�� ���`���A �C�⬰  mcolor[0]
//				 ��n�b X/Y ���t 200 ����m�W
//					���A�]�w�� �b��ɤW �C�⬰  mcolor[1]
//				�H�ζW�X X/Y ���t 200 ���d��~  ���A�]�w�����`
//
// �ھڥD�{�����ݨD�A�����i�Q����L w s a d �|�ӫ���A����ѹ������ʡA������ɧ����C��A��������ܦ��`
// ���N���� : ���n�N�ǤJ���޼��ܼƦW�٫ŧi���򦨭��ܼƤ@��
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

#define NORMAL_COLOR COLOR_YELLOW
#define DANGER_COLOR COLOR_RED

#define X_MAX 200	// �w�q�i���ʪ��d��
#define Y_MAX 200	// �w�q�i���ʪ��d��
using namespace std;
void drawFence();

// draw() �禡�|�Ψ�
//	drawColorBox( ); // �e�X�ѹ�,  x  y �y�лP�C��


// update() �禡�|�Ψ�

	//switch () {
	//case 'w': // ���W. ���ѹ���m,�îھڷs����m,��s�ѹ������A
	//	break;
	//case 's': // ���U
	//	break;
	//case 'a': // ����
	//	break;
	//case 'd': // ���k
	//	 break;
	//}

	//if ( ) { // �w���ϰ줺
	//	
	//}
	//else if () {// ������� �ѹ����` �C������

	//}
	//else {	// �b��ɤW

	//}

	

int main()
{
	char cIn;
	int status;
	initwindow(SCREENWIDTH, SCREENWIDTH, "EX2 ��7�D");
							// �ŧi mx �إ߮ɴN�|�۰ʩI�s CMouse �غc
							// �I�s setPos ��m�]�w�b (-120, 120)
							// �I�s setColor�A�C��]�w�� COLOR_WHITE, COLOR_BLACK
	do {
		cleardevice();
		drawFence();	// �e�X�d��
						// �e�X�ѹ�
		swapbuffers();
		getch();		// ��J
						// ���ѹ��ۤv��s���A
		rewind(stdin);
	} while (	);

	cleardevice();
	drawFence();
	setcolor(COLOR_WHITE);
	outtextxy(X(-100), Y(0), "!! �ѹ����F GG �����N�䵲��!! ");
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