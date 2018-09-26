#include<stdio.h>
int main()
{
	int c,f;
	printf("please enter a Fahernheit temperature:");
	scanf("%d",&f);
	printf("The Fahernheit temperature you type is:%d\n",f);
	c=5*(f-32)/9;
	printf("Celsius=%dc\n",c);
}