#include<stdio.h>
int main (void)
{
	int a[6]={54,85,65,35,14,45}, i, s=0,  m, min = a[0];
	for(i=0;i<6;i++)
	{	
		printf("��%d�����ǣ�%d\n",i+1,a[i]);
		s = s + a[i];
	}
	for(i=1;i<6;i++)
	{
		if(min>a[i])
		{
			m = i;
			min = a[i];

		}
	}
	printf("����ĺ�Ϊ��%d\n",s);
	printf("�������С��Ϊ%d���±�Ϊ%d\n",min,m);

	return 0;
}