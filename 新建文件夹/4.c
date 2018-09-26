#include<stdio.h>
int fn(int n);
void main()
{
	int i,s=0;
	for(i=1;i<=4;i++)	//求1！+2! +3！+4!
		s=s+fn(i);
	printf("%d\n",s);
}

int fn(int n)
{
	static int t=1;
	t=t*n;	//此行填空
	printf("t=%d,",t);	//测试语句，当n=3时，t 的值需要表达出3! 的值
	return t;
}
