#include<stdio.h>
main()
{
	int H,F,J,T;
	printf("Please enter the number of heardes and legs:");
	scanf("%d%d",&H,&F);
	printf("The number of headers and legs you enter is:%d%d\n",H,F);
	
	if (F%2==0&&2*H<=F&&F<=4*H)
	{
	T=F/2-H;
	J=2*H-F/2;
	printf("The number of chickens an is :%dThe number of rabbits is :%d\n",J,T);
	
	}
	else
		printf("You have incorrect input!\n");
}