#include<stdio.h>
float average(int a[],int len);  //������գ����Զ��庯��average�ĺ���������

int main()
{
	int n[]={12,34,42,16,20,15,33,25,10,20};
	float ave;
	ave=average(n,sizeof(n)/sizeof(int)); //����average����������n��ƽ��ֵ��
	printf("%f\n",ave);
	return 0;	
}

//����main�������·��������е��·���ʼ����average������ʵ�֡�

float average(int a[],int len)
{
	float sum=0.0;
	int i;
	for(i=0;i<len;i++)
		sum=sum+a[i];//������±������һ��Ҫ��int  �ͣ�һ��������float ,double �� ��
	
	return sum/len;
}