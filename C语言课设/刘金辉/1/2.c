#include <stdio.h>
int main()
{
	char ch[200];
	int i;
	printf("请输入一个字符数组：");
	gets(ch);
	puts(ch);
	for(i=0;ch[i]!='\0';i++);
	printf("%d",i);
	
}
