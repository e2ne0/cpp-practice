// 第二次上機考試 ------- 第 2 題 2 分 -------
//
// 利用 C++ 的 cout 與相關的參數設定完成以下的輸出
//
//  Apple          1.1
//  Orange       12.21
//  Pear       123.321
//  ###Apple1.1*******
//  ##Orange12.21*****
//  ####Pear123.321***
//
// 你會用到的 cout 功能
// setiosflags(ios::left)、resetiosflags(ios::left)、setfill()、
// cout.width()、cout.fill()、setw()

//#define EX2
#ifdef EX2

#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;
int main()
{
	char *cName[] = {"Apple", "Orange", "Pear"};
	float fVal[] = {1.1f, 12.21f, 123.321f};

	for (int i = 0; i < 3; i++)
	{
		cout << setiosflags(ios::left) << setw(8) << cName[i];
		cout << resetiosflags(ios::left) << setw(10) << fVal[i];
		cout << endl;
	}
	for (int i = 0; i < 3; i++)
	{
		cout << resetiosflags(ios::left) << setw(8) << setfill('#') << cName[i];
		cout << setiosflags(ios::left) << setw(10) << setfill('*') << fVal[i];
		cout << endl;
	}
	system("pause");
	return (0);
}

#endif