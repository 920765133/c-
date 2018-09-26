#include<stdio.h>
int ishuiwen(char ch[]);
//主函数定义如下：
void main()
{
	char s[]="abxcrcxba";
	if(ishuiwen(s)==1)    //如果函数返回1，表是它是回文串，如果返回0，则表示不是回文串
		printf("字符串：%s 是回文。\n",s);
	else
		printf("字符串：%s 不是回文。\n",s);
}
//自定义函数定义请补充：
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







