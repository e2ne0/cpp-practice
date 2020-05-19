// �ĤG���W���Ҹ� ------- �� 1 �D 3 �� -------
// 
// �ŧi�@�ӵ��c sCircle �̭��]�t�@�Ӷꪺ�򥻸�Ʀp�U�G
//    �W�� char(10)�B�y�� x/y�B�b�| radius �P�C�� r/g/b  �A���F�W�٥~�A��L���O int
// ��r�� circles.txt �̭��x�s�F 10 �Ӷꪺ��� , �Q�� fopen/fclose/fscanf�����O
//    �N  circles.txt  Ū�J�A�ñN����x�s�� sCircle �ҫŧi���@�����c�}�C cx ��
//  
// �t�~�H sCircle �ŧi�@���ܼ� boss �{������������q
//  �Ĥ@�ӳ��� : Ū��  circles.txt �A�ñN����x�s��@�����c�}�C  cx  ��
//  �ĤG���� : �H�j��b�e���W���X�o10�Ӷ�
//               �P�ɭp�� boss �y�лP�b�|�A�y�ЬO�o 10�Ӷ�y�Ъ�������
//     				           �b�|�O�o 10 �Ӷ�b�|���`�M * 0.35
//               �C��O�զ�
//             �̫Ṻ�X boss ����
//
//  �Ѧ� ex2-1.jpg

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
	registermousehandler(WM_MOUSEMOVE, move_handler);		// ���U�ƹ����ʪ��B�z�禡
	registermousehandler(WM_LBUTTONDOWN, lbDown_handler);   // ���U�ƹ�������U���B�z�禡
	registermousehandler(WM_LBUTTONUP, lbUp_handler);		// ���U�ƹ��������񪺳B�z�禡
	srand(time(NULL));

	FILE *sCircle;		// �ŧi���V�ɮת����c����
	sCircle = fopen("circles.txt", "r");		// �}���ɮ�
	if (sCircle == NULL) {
		printf("�ɮ׵L�k�}��");
	}
	struct	sCircle cx[10], boss = { "boss",0,0,0,255,255,255 };// �ŧi���c�}�C cx �P boss�A�b�ŧi boss ��, �]�w��l�Ȭ� "boss",0,0,0,255,255,255

	// ����10�Ӷ�A�ÿ�X
	for (i = 0; i < 10; i++) // �H�j��Ū�� circles.txt �����e
	{
		fscanf(sCircle,"%s %d %d %d %d %d %d\n",cx[i].Name,&cx[i].x,&cx[i].y,&cx[i].radius,&cx[i].r,&cx[i].g,&cx[i].b); //�H fscanf() Ū��
			
	}
	fclose(sCircle);			// �����ɮ�

	for (i = 0; i < 10; i++ )	// �H�j����ܤ��e
	{
		printf("%s %d %d %d %d %d %d\n", cx[i].Name, cx[i].x, cx[i].y, cx[i].radius, cx[i].r, cx[i].g, cx[i].b);
		setcolor(COLOR(cx[i].r,cx[i].g,cx[i].b));	// �]�w�C��
		outtextxy(X(cx[i].x),Y(cx[i].y), cx[i].Name);  // ��ܤ�r
		circle(X(cx[i].x), Y(cx[i].y), cx[i].radius);		// �e�X��
		boss.x = boss.x + cx[i].x;
		boss.y = boss.y + cx[i].y;
		boss.radius = boss.radius + cx[i].radius;
	}
	boss.x = boss.x / 10;
	boss.y = boss.y / 10;
	boss.radius = boss.radius * 0.35f;

	// �e�X boss
	setcolor(COLOR(255,255,255));  // �]�w�C��
	outtextxy(X(boss.x), Y(boss.y), boss.Name);
	circle(X(boss.x), Y(boss.y), boss.radius);

	while (!kbhit())
	{
		delay(200);
	}
	return 0;
}

#endif