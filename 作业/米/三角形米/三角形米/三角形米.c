#include<stdio.h>
int main()
{
	int i,j;
	for(j=1;j<=7;j++)
	{   
	    for(i=0;i<7-j;i++)
		printf(" ");
		for(i=0;i<2*j-1;i++)
		{
			printf("*");
		}
		printf("\n");
	}

}