#include<stdio.h>
#include<windows.h>
void run();
void menu();
/******************************主函数*****************************/
void main()
{
	run();
}

void menu()
{
		system("cls");
		printf("\t|--------存钱取钱程序菜单-------|\n");
		printf("\t|\t1:存钱\t\t\t|\n");
		printf("\t|\t2:取钱\t\t\t|\n");
		printf("\t|\t0:退出\t\t\t|\n");
		printf("\t|-------------------------------|\n");
		printf("\t请输入您的选择0~2:");
}

void run()
{
	int sel;
	while(1)							/*使用循环结构完成菜单循环*/
	{								
		menu();
		scanf("%d",&sel);	
		switch(sel)
		{
		case 1: printf("存钱\n");;break;
		case 2: printf("取钱\n");;break;
		case 0:
			printf("谢谢使用，再见!\n");
			Sleep(1500);				/*等待1.5秒*/
			return 0;
		default:printf("输入错误!请重新输入:\n");break;
		}
	}
}