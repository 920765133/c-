#include<stdio.h>
#include<windows.h>
int main()
{
	int sel;	
	while(1)
	{
		printf("\t\t\t\t\t�˵�\n\n\n");
		printf("\t\t\t1.ȡǮ \t\t\t2.��Ǯ\n\n\n");
		printf("\t\t\t3.ת�� \t\t\t4.��ѯ\n\n\n");
		printf("\t\t\t0.�˳�\n\n\n");
		printf("\t\t����������ѡ��");
		scanf("%d",&sel);
	switch(sel)
	{
	case 1:printf("\t\t��ȡ�㣡\n");break;
	case 2:printf("\t\t���㣡\n");break;
	case 3:printf("\t\t���ʵ�Է���Ϣ��\n");break;
	case 4:printf("\t\t��ע���ܱ߰�ȫ��\n");break;
	case 0:printf("\t\t�˳���\n");exit(0);break;
	}
	Sleep(1000);
	system("CLS");
	}
	getch();
}