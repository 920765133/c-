#include<stdio.h>
int main (void)
{
	int i, n[10], s = 0;
	double ave;
	for(i=0; i<10; i++)
	{
		printf("请输入第%d个数的值:",i+1);
		scanf("%d",&n[i]);
		s = s + n[i];
	}
	ave = s/10.0;
	printf("平均数为%f\n",ave);
	printf("大于平均数的有\n");
	for(i=0; i<10; i++)
	{
	
		if(ave < n[i])
			printf("%5d",n[i]);
		

	}
	printf("\n");
}	