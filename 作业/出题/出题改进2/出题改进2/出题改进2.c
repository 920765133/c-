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
	printf("正在出题请稍等:\n");
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
	printf("恭喜你答对了!\n");
    }
	printf("你的答案有误，望继续努力!\n");
	}