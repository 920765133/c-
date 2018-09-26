
#include<stdio.h>
void show(int x);
int main()
{
	show(4);
	show(20);
	return 0;
}

void show(int x)
{
	int i,j;
	for(i=1;i<=x;i++)
	{
		for(j=1;j<=i;j++)
			printf("*");
		printf("\n");
	}
}