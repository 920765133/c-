#include <stdio.h>
int main()
{
	char ch[200];
	int i;
	printf("������һ���ַ����飺");
	gets(ch);
	puts(ch);
	for(i=0;ch[i]!='\0';i++);
	printf("%d",i);
	
}
