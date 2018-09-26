#include<stdio.h>
int main()
{
	int a,b,c;
	for(a=1;a<=7;a++)
	{
		for(b=1;b<=7-a;b++)
		{
			printf(" ");
		}
		for(c=1;c<=2*a-1;c++)
		{
			printf("*");
		}
		printf("\n");
	}
}