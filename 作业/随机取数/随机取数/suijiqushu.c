#include<stdio.h>
#include<time.h>
#include<windows.h>
main()
{
	int n;
	srand(time(NULL));
	n=rand()%10;//随机函数， 【0，32767】随机整数
	printf("%d\n",n);
}