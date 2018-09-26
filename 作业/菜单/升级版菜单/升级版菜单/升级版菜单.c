#include<stdio.h>
#include<windows.h>
int main()
{
	int sel;	
	while(1)
	{
		printf("\t\t\t\t\t菜单\n\n\n");
		printf("\t\t\t1.取钱 \t\t\t2.存钱\n\n\n");
		printf("\t\t\t3.转账 \t\t\t4.查询\n\n\n");
		printf("\t\t\t0.退出\n\n\n");
		printf("\t\t请输入您的选择：");
		scanf("%d",&sel);
	switch(sel)
	{
	case 1:printf("\t\t少取点！\n");break;
	case 2:printf("\t\t多存点！\n");break;
	case 3:printf("\t\t请核实对方信息！\n");break;
	case 4:printf("\t\t请注意周边安全！\n");break;
	case 0:printf("\t\t退出！\n");exit(0);break;
	}
	Sleep(1000);
	system("CLS");
	}
	getch();
}