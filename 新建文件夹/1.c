
//1.使用函数模式实现求一个一维整型数组中所有数的平均数的算法，请以下面的代码为准，继续编写：
#include<stdio.h>

float average(int a[8]);   //此行填空，填自定义函数average的函数申明。

int main()
{
	int n[8]={12,34,42,16,20,15,33,25};
	float ave;
	ave=average(n); //调用average函数求数组n的平均值。
	printf("%f\n",ave);
	return 0;	
}

//请在main函数的下方，即本行的下方开始定义average函数的实现。

float average(int a[8])
{
	int sum=0,i;
	for(i=0;i<8;i++)
		sum+=a[i];
	return (float)sum/8;
}
