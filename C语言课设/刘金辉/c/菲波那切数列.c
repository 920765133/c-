#include<stdio.h>
int main (void)
{
	int n[20], i;
	n[0] = n[1] = 1;
	for(i=2; i<20; i++)
		n[i] = n[i-1] + n[i-2];
	for(i=0; i<20; i++)
	{
		printf("%6d",n[i]);
		if((i+1)%5 == 0)
			printf("\n");
	}

	return 0;
}