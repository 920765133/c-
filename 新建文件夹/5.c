
#include<stdio.h>


//全局变量只能被“最多初始化1次”。


int y=6;
int x;
x=6;


void main()
{
	printf("x=%d\n",x);
}
