
//1.ʹ�ú���ģʽʵ����һ��һά������������������ƽ�������㷨����������Ĵ���Ϊ׼��������д��
#include<stdio.h>

float average(int a[8]);   //������գ����Զ��庯��average�ĺ���������

int main()
{
	int n[8]={12,34,42,16,20,15,33,25};
	float ave;
	ave=average(n); //����average����������n��ƽ��ֵ��
	printf("%f\n",ave);
	return 0;	
}

//����main�������·��������е��·���ʼ����average������ʵ�֡�

float average(int a[8])
{
	int sum=0,i;
	for(i=0;i<8;i++)
		sum+=a[i];
	return (float)sum/8;
}
