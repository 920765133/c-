#include<stdio.h>
int main()
{	
/*	char ch[]="hello";
	int i=0;
	int n=0;//n��ʾ����
//	while(ch[i]!='\0')
//		i++;

	for(i=0;ch[i]!='\0';i++)//���������ַ���
		n++;
	printf("�����ǣ�%d\n",n);
*/

	char ch[100];
	int i=0;
	gets(ch);
	printf("ԭʼ�ַ������ǣ�");
	puts(ch);
	printf("��ʼ��дת����");
	while(ch[i]!='\0')
	{
		if(ch[i]>='a' && ch[i]<='z')
		ch[i]=ch[i]-32;
		i++;
	}
	puts(ch);

	return 0;
}