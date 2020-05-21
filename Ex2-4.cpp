// 第二次上機考試 ------- 第 4 題 2 分 -------
//
//  本題必須使用 cout，且不可以使用 for ，且有函式的原型宣告以及引數的預設值才有分數
//
// 以函示多載的方式宣告三個 pchar 函式
// 第一個函式有一個引數 ch (char 型別)，沒有預設值，印出 5 個 ch 字元
// 第二個函式有一個引數 b (bool 型別)，預設值為 true
//        當 b 為 true 時，印出 5 個 #。 當 b 為 false 時，印出 5 個 * 字元。
// 第三個函式有兩個引數，第一個為 n (int 型別) 第二個為 ch (char 型別)
//     只有第二個引數 ch 有預設值為  *  字元
//      功能是印出 n 個 ch 字元
//
// 參考以下的輸出
//
// 呼叫 pchar(),       #####
// 呼叫 pchar(false)   *****
// 呼叫 pchar(5, '+')  +++++
// 呼叫 pchar('@')     @@@@@
// 呼叫 pchar(7)       *******

//#define EX4
#ifdef EX4
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

// pchar 的原型宣告寫在這裡

int pchar(char ch);

int pchar(bool b = true);
int pchar(int n, char ch = '*');
int main(void)
{
	cout << "呼叫 pchar(),      ";
	pchar();
	cout << "呼叫 pchar(false)  ";
	pchar(false);
	cout << "呼叫 pchar(5,'+')  ";
	pchar(5, '+');
	cout << "呼叫 pchar('@')    ";
	pchar('@');
	cout << "呼叫 pchar(7)      ";
	pchar(7);

	system("pause");
	return (0);
}

// pchar 主體寫在這裡
int pchar(char ch)
{
	cout.fill(ch);
	cout << setw(5) << ch << endl;
	return cout.good();
}
int pchar(bool b)
{
	if (b)
	{
		cout << "#####" << endl;
	}
	else
	{

		cout << "*****" << endl;
	}
	return cout.good();
}
int pchar(int n, char ch)
{
	cout.fill(ch);
	cout << setw(n) << ch << endl;
	return cout.good();
}

#endif
