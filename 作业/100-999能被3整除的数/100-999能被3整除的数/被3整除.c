#include<stdio.h>
int main()
{
	int i,count=0;
	for(i=100;i<999;i++)
	{
		if(i%3==0)
		{
			count++;
			printf("%d",i);
			if(count%20==0)
				printf("\n");
			else
			printf(",");

		}
	}

}