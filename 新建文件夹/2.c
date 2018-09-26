#include<stdio.h>
void main()
{
	int max,a,b,c;
	int fun(int x,int y);//函数声明
	
	printf("请输入3个整数：");
	scanf("%d%d%d",&a,&b,&c);
	
	max=fun(fun(a,b),c);  //调用fun函数实现a,b,c三个变量最大值运算

	printf("max=%d\n",max);
}
//下面是函数定义
int fun(int x,int y)
{
	return (x>y?x:y);
}