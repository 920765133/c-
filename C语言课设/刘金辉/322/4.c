#include<stdio.h>
int main()
{
	int a,b,c,i;
	int count=2;
	a=b=1;
	printf("%d\t%d\t",a,b);
	for(i=3;i<=20;i++)
	{
		c=a+b;
		count++;
		printf("%d\t",c);
		if(count%5==0)
			printf("\n");
		a=b;
		b=c;
	}
}