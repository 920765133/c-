#include<stdio.h>
void main()
{
	int max,a,b,c;
	int fun(int x,int y);//��������
	
	printf("������3��������");
	scanf("%d%d%d",&a,&b,&c);
	
	max=fun(fun(a,b),c);  //����fun����ʵ��a,b,c�����������ֵ����

	printf("max=%d\n",max);
}
//�����Ǻ�������
int fun(int x,int y)
{
	return (x>y?x:y);
}