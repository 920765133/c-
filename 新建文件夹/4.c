#include<stdio.h>
int fn(int n);
void main()
{
	int i,s=0;
	for(i=1;i<=4;i++)	//��1��+2! +3��+4!
		s=s+fn(i);
	printf("%d\n",s);
}

int fn(int n)
{
	static int t=1;
	t=t*n;	//�������
	printf("t=%d,",t);	//������䣬��n=3ʱ��t ��ֵ��Ҫ����3! ��ֵ
	return t;
}
