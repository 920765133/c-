#include <stdio.h>
int main ()
{
	int a,x ;
	int jdz(int a );
	printf("ÇëÊäÈëaµÄÖµ:\n");
	scanf("%d",&a);
	x=jdz(a);
	printf("%d\n",x);
}
int jdz(int a )
{
	if(a>=0)
		return a ;
	else
		
	return -a ;
}
