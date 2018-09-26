#include <stdio.h>
int show(int n);
int main()
{
	show(4);
	printf("n");
}
int show(int n )
{
	int i ,j;
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=i;j++)
			printf("*");
		printf("\n");
	}
	
	return n;
}