#include<stdio.h>
main()
{
	int H,F,J,T;
	printf("please enter the number of heardes:");
	scanf("%d",&H);
	printf("The number of headers you enter is:%d\n",H);
	printf("please enter the number of leg:");
	scanf("%d",&F);
	printf("The number of legs you enter is:%d\n",F);
	if (F%2==0&&2*H<=F&&F<=4*H)
	{
	T=F/2-H;
	J=2*H-F/2;
	printf("The number of chickens is :%d\n",J);
	printf("The number of rabbits is :%d\n",T);
	}
	else
		printf("You have incorrect input!\n");
}