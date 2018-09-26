/*
1.使用scanf方式为一个10个整数型元素的数组输入10个整数。
	程序能够把这10个数的平均值求出来，并且：
		能把高于平均值的所有值逐一地打印出来！
*/
#include<stdio.h>
#define N 10
int main()
{
	int n[N],i;
	float ave=0.0;
	for(i=0;i<N;i++)//使用scanf方式输入10个数，边输入、边求和，你懂得。
	{
		printf("请输入第%d个数：",i+1);
		scanf("%d",&n[i]);//输入
		ave=ave+n[i];		//求和，先认定ave为和变量
	}
	ave=ave/N;
	printf("这些数的平均值是：%f\n",ave);//打印平均数
	//遍历数组，把高于平均分的值打印出来
	printf("比平均数：%f的数有以下几个：\n",ave);//喊一喊，壮壮胆
	for(i=0;i<N;i++)
	{
		if(n[i]>ave)  //只要比ave大，就打印。
			printf("%6d",n[i]);
	}
	printf("\n");

	return 0;
}