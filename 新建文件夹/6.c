#include<stdio.h>
int ishuiwen(char ch[]);
//�������������£�
void main()
{
	char s[]="abxcrcxba";
	if(ishuiwen(s)==1)    //�����������1���������ǻ��Ĵ����������0�����ʾ���ǻ��Ĵ�
		printf("�ַ�����%s �ǻ��ġ�\n",s);
	else
		printf("�ַ�����%s ���ǻ��ġ�\n",s);
}
//�Զ��庯�������벹�䣺
int ishuiwen(char ch[])
{
	int i,len;
	int yesorno=1;
	len=strlen(ch);
	for(i=0;i<len/2;i++)
		if(ch[i]!=ch[len-i-1])
		{
			yesorno=0;
			break;
		}
		

	return yesorno;
		

}







