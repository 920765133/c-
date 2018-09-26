#include<stdio.h>
int main()
{
	int i,j=0;
	for(i=100;i<=999;i++)
	{
		if(i%3==0)
		{
			if(i!=999)
			{
				printf("%d,",i);
				j++;
			}else
				printf("%d ",i);

		}
		if(j%20==0)
		{
			printf("\n");
		}
	}
}