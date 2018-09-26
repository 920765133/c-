#include <stdio.h>
int main()
{
	int i,j;
	for(i=0;i<10;i++)
	{
		for(j=0;j<=5;j++)
		{
			printf(" ");
		}
		for(j=0;j<=20;j++)		
		{
			printf("*");
		}
		printf("\n");
	}
}