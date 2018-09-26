#include<stdio.h>
int main()
{
	int n[8]={1,5,3,2,4,8,7,6};
	int i,max,j,ms,k;
	for(k=1;k<=7;k++)
	{   
		max=n[0];ms=0;
		for(i=1;i<=8-k;i++)
		{
			if(n[i]>max)
			{
				max=n[i];
				ms=i;
			}
		}
		printf("%d\n",ms);
		j=n[9-k];
		n[9-k]=n[ms];
		n[ms]=j;
	}
	for(i=0;i<=7;i++)
		printf("%d",n[i]);
	return 0;
}