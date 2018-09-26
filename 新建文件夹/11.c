#include<stdio.h>
float average(int a[],int len);  //此行填空，填自定义函数average的函数申明。

int main()
{
	int n[]={12,34,42,16,20,15,33,25,10,20};
	float ave;
	ave=average(n,sizeof(n)/sizeof(int)); //调用average函数求数组n的平均值。
	printf("%f\n",ave);
	return 0;	
}

//请在main函数的下方，即本行的下方开始定义average函数的实现。

float average(int a[],int len)
{
	float sum=0.0;
	int i;
	for(i=0;i<len;i++)
		sum=sum+a[i];//数组的下标变量，一定要是int  型，一定不能是float ,double 型 的
	
	return sum/len;
}