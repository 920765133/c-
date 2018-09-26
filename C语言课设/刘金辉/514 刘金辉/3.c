#include <stdio.h>

int main ()
{
	float a ,b ,s;
	float mianji(float a,float b);
      printf("ÇëÊäÈëa,b  µÄÖµ\n");
	  scanf("%d%d",&a,&b);
	  s=mianji(a,b);
	  printf("%f",s);
}
float mianji(float a,float b)
{   int s;
	s=a*b/2;
	return s ;
}