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
		printf("������һ������");
		scanf("%d",&b);
		if(a!=b)
		{
			if(a<b)
				printf("����");
			else
				printf("С��");
			Sleep(1000);
			system("CLS");
		}
		else
			printf("��¶��ˣ������%d��",count);
	}
	while(a!=b);
	

}