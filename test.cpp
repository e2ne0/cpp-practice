#include <iostream>
#include <cstdlib>
int *pos;
int a = 0;
int b = 1;
int main()
{
	pos = (int*)malloc(sizeof(int)*2);
	*(pos) = a;
	*(pos+1) = b;
	printf("%d,%d",*pos,*pos + 1);
}
