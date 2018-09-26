#include<stdio.h>
#include<windows.h>
int main()
	
{
	int i=0;
	printf("\t\t\t");
	while(i<200)
	{
		Sleep(10);
		printf("*");
		i=i++;
		if(i%20==0)
			printf("\n\t\t\t");
		}
	getch();
    return 0;
}