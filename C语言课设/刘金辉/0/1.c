
#include<stdio.h>
int jdz(int x);
int main()
{

	int n;
	printf("������һ��������");
	scanf("%d",&n);
	printf("%d\n",jdz(n));
}

int jdz(int x)
{
	if(x>=0)
		return x;
	else
		return -x;
}