#include<stdio.h>
int main()
{
	int i=1,s=0;
	do
	{
		s=s+i;
		i=i++;
	}
	while(i<=100);
	printf("s=%d\n",s);
}