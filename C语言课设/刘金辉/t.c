#include<stdio.h>
int main()
{	
/*	char ch[]="hello";
	int i=0;
	int n=0;//n表示个数
//	while(ch[i]!='\0')
//		i++;

	for(i=0;ch[i]!='\0';i++)//遍历整个字符组
		n++;
	printf("长度是：%d\n",n);
*/

	char ch[100];
	int i=0;
	gets(ch);
	printf("原始字符数组是：");
	puts(ch);
	printf("开始大写转换：");
	while(ch[i]!='\0')
	{
		if(ch[i]>='a' && ch[i]<='z')
		ch[i]=ch[i]-32;
		i++;
	}
	puts(ch);

	return 0;
}