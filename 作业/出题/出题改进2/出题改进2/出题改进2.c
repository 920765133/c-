#include<stdio.h>
#include<time.h>
#include<windows.h>
main()
{
	int a,b,res=0,ans=0,op;
	while(ans==res)
	{
		do
	{srand(time(NULL));
	a=rand()%10;
	b=rand()%10;
	op=rand()%3;}
	while(b==0);
	printf("���ڳ������Ե�:\n");
	Sleep(1000);
	system("CLS");
	switch(op)
	{
	case 0:res=a+b;printf("%d+%d=",a,b);break;
    case 1:res=a-b;printf("%d-%d=",a,b);break;
	case 2:res=a*b;printf("%d*%d=",a,b);break;
    case 3:res=a/b;printf("%d/%d=",a,b);break;
	}
	scanf("%d",&ans);
	printf("��ϲ������!\n");
    }
	printf("��Ĵ�����������Ŭ��!\n");
	}