#include<stdio.h>
int main()
{
	int h1,m1,h2,m2,h,m;
	printf("please enter the fist time:");
	scanf("%d%d",&h1,&m1);
	printf("The fist time you enterd is :%d  o'oclock %d\n",h1,m1);
	printf("please enter the second time:");
	scanf("%d%d",&h2,&m2);
	printf("The second time you enterd is :%d  o'oclock %d\n",h2,m2);
	h=h2-h1;
	m=m2-m1;
	if (m<0)
	{
		h=h--;
		m+=60;
	}
	printf("The diffference in time is:%d O'olcok  %d\n",h,m);
}