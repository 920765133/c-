#include<stdio.h>
#include<windows.h>
void run();
void menu();
/******************************������*****************************/
void main()
{
	run();
}

void menu()
{
		system("cls");
		printf("\t|--------��ǮȡǮ����˵�-------|\n");
		printf("\t|\t1:��Ǯ\t\t\t|\n");
		printf("\t|\t2:ȡǮ\t\t\t|\n");
		printf("\t|\t0:�˳�\t\t\t|\n");
		printf("\t|-------------------------------|\n");
		printf("\t����������ѡ��0~2:");
}

void run()
{
	int sel;
	while(1)							/*ʹ��ѭ���ṹ��ɲ˵�ѭ��*/
	{								
		menu();
		scanf("%d",&sel);	
		switch(sel)
		{
		case 1: printf("��Ǯ\n");;break;
		case 2: printf("ȡǮ\n");;break;
		case 0:
			printf("ллʹ�ã��ټ�!\n");
			Sleep(1500);				/*�ȴ�1.5��*/
			return 0;
		default:printf("�������!����������:\n");break;
		}
	}
}