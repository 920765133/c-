#include<stdio.h>
int main ()
{
	char ch [200];
	int i ;
	printf("������һ���ַ�����");
	gets (ch);
	puts (ch);
	for (i =0;ch[i]>=97&& ch[i]<=122;i++);
	
}