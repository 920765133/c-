#include<stdio.h>
#include<time.h>
#include<windows.h>
main()
{
	int a,b,res,ans,op;
	srand(time(NULL));
	a=rand()%10;
	b=rand()%10;
	op=rand()%4;
	printf("let me write:\n");
	Sleep(1000);
	switch(op)
	{
	case 0:res=a+b;printf("%d+%d=",a,b);break;
    case 1:res=a-b;printf("%d-%d=",a,b);break;
	case 2:res=a*b;printf("%d*%d=",a,b);break;
    case 3:res=a/b;printf("%d/%d=",a,b);break;
	}
	scanf("%d",&ans);
	if(ans==res)
		printf("yuo're right!\n");
	else 
		printf("you're worng!\n");
	

}