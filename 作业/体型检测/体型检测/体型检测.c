#include<stdio.h>
int main()
{
	float s,w,h;
	printf("«ÁPlease input your weight:");
	scanf("%f",&w);
	printf("The weight you enterd is :%0.2fkg\n",w);
	printf("Please input your height:");
	scanf("%f",&h);
	printf("The height you enterd is :%0.2fm\n",w);
	s=w/(h*h);
	if (s<18)
		printf("You're a little thin!\n");
	else if(18<=s  &&  s<25 )
		printf("You body size standard!\n");
	else if(s>=25  &&  s<27)
		printf("You're a little fat!\n");
	else 
		printf("You are too fat!\n");
	return 0;




}