#include<stdio.h>
#include<time.h>
#include<windows.h>
main()
{
	int a,b,res,ans;
	srand(time(NULL));
	a=rand()%10;
	b=rand()%10;
	res=a+b;
	printf("Let me write:\n");
	Sleep(1000);
	printf("%d+%d=",a,b);
	scanf("%d",&ans);
	if(ans==res)
		printf("yuo're right!\n");
	else 
		printf("you're worng!");
	

}