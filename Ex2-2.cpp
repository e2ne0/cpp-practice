// �ĤG���W���Ҹ� ------- �� 2 �D 2 �� -------
// 
// �Q�� C++ �� cout �P�������ѼƳ]�w�����H�U����X
//
//  Apple          1.1
//  Orange       12.21
//  Pear       123.321
//  ###Apple1.1*******
//  ##Orange12.21*****
//  ####Pear123.321***
//
// �A�|�Ψ쪺 cout �\��
// setiosflags(ios::left)�Bresetiosflags(ios::left)�Bsetfill()�B
// cout.width()�Bcout.fill()�Bsetw()


//#define EX2
#ifdef EX2

#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;
int main()
{
	char *cName[] = { "Apple", "Orange", "Pear" };
	float fVal[] = { 1.1f, 12.21f, 123.321f };

	for (int i = 0; i < 3; i++) {
		cout << setiosflags(ios::left) << setw(8) << cName[i];
		cout << resetiosflags(ios::left) << setw(10) << fVal[i];
		cout << endl;
	}
	for (int i = 0; i < 3; i++) {
		cout << resetiosflags(ios::left) << setw(8) << setfill('#') << cName[i];
		cout << setiosflags(ios::left) << setw(10) << setfill('*') << fVal[i];
		cout << endl;
	}
	system("pause"); return(0);
}

#endif