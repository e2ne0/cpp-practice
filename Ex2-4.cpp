// �ĤG���W���Ҹ� ------- �� 4 �D 2 �� -------
//
//  ���D�����ϥ� cout�A�B���i�H�ϥ� for �A�B���禡���쫬�ŧi�H�Τ޼ƪ��w�]�Ȥ~������
//
// �H��ܦh�����覡�ŧi�T�� pchar �禡
// �Ĥ@�Ө禡���@�Ӥ޼� ch (char ���O)�A�S���w�]�ȡA�L�X 5 �� ch �r��
// �ĤG�Ө禡���@�Ӥ޼� b (bool ���O)�A�w�]�Ȭ� true 
//        �� b �� true �ɡA�L�X 5 �� #�C �� b �� false �ɡA�L�X 5 �� * �r���C
// �ĤT�Ө禡����Ӥ޼ơA�Ĥ@�Ӭ� n (int ���O) �ĤG�Ӭ� ch (char ���O)
//     �u���ĤG�Ӥ޼� ch ���w�]�Ȭ�  *  �r��
//      �\��O�L�X n �� ch �r��
//
// �ѦҥH�U����X
//
// �I�s pchar(),       #####
// �I�s pchar(false)   *****
// �I�s pchar(5, '+')  +++++
// �I�s pchar('@')     @@@@@
// �I�s pchar(7)       *******
//

//#define EX4
#ifdef EX4
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

// pchar ���쫬�ŧi�g�b�o��


int main(void)
{
	cout << "�I�s pchar(),      "; pchar();
	cout << "�I�s pchar(false)  "; pchar(false);
	cout << "�I�s pchar(5,'+')  "; pchar(5, '+');
	cout << "�I�s pchar('@')    "; pchar('@');
	cout << "�I�s pchar(7)      "; pchar(7);
	
	system("pause"); return(0);
}

// pchar �D��g�b�o��


#endif