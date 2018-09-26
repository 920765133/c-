#include<stdio.h>
int main()
{
	int a,b,c,d;
	a=1;
	b=1;
	printf("%d\n%d\n",a,b);
	for(d=0;d<20;d++)
	{
		c=a+b;
		a=b;
		b=c;
		printf("%d\n",c);
	}
}