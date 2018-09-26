#include <stdio.h>
 void main()
{
	int a,b,c;
	int i;
	for(i=100;i<=999;i++)
	{
		a=i%10;
		b=(i-c*100)/10;
		c=i/100;
		if(a*a*a+b*b*b+c*c*c==i)
		{
			printf("%d",i);
			printf("\n");
		}
	}
}