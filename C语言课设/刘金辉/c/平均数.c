#include<stdio.h>
int main (void)
{
	int i, n[10], s = 0;
	double ave;
	for(i=0; i<10; i++)
	{
		printf("�������%d������ֵ:",i+1);
		scanf("%d",&n[i]);
		s = s + n[i];
	}
	ave = s/10.0;
	printf("ƽ����Ϊ%f\n",ave);
	printf("����ƽ��������\n");
	for(i=0; i<10; i++)
	{
	
		if(ave < n[i])
			printf("%5d",n[i]);
		

	}
	printf("\n");
}	