#include<stdio.h>
#include<windows.h>
#include<time.h>
int main()
{
	int a,b,count=0;
	do
	{
		count++;
		srand(time(NULL));
		a=rand()%100;
		printf("请输入一个数：");
		scanf("%d",&b);
		if(a!=b)
		{
			if(a<b)
				printf("大了");
			else
				printf("小了");
			Sleep(1000);
			system("CLS");
		}
		else
			printf("你猜对了！你猜了%d次",count);
	}
	while(a!=b);
	

}