//��һ�׶Σ�goto+switch
//�ڶ��׶Σ�ʵ�ֵ��˻���Ǯ��ȡǮҵ��
//�����׶Σ�ʹ�ýṹ��ʵ�ִ桢ȡǮ��ת��ҵ��
//���Ľ׶Σ�����ʵ�ֿ���������ҵ��
#include<stdio.h>
#include<string.h>
#include<windows.h>				//��ʹ����ʱ����
struct account
{
	char id[6];
	char name[8];
	double balance;
};

int save(struct account*);//��Ǯ����
int draw(struct account*);//ȡǮ����
int transfer(struct account*,struct account*);   ///ת�˺���
void show(struct account);						////������ʾ����
void main()
{
	int sel;
	struct account acc1,acc2;
	strcpy(acc1.id,"10001");
	strcpy(acc1.name,"����");
	acc1.balance=acc2.balance=0;
	strcpy(acc2.id,"10002");
	strcpy(acc2.name,"����");
	while(1)			///////ʹ��ѭ���ṹ��ɲ˵�ѭ��
	{//�˵�����ʾ���ع��ܡ�
		printf("---------------���ܲ˵�--------------\n");
		printf("\t1:��Ǯ\n");
		printf("\t2:ȡǮ\n");
		printf("\t3:ת��\n");
		printf("\t4:�˻���Ϣ��ʾ\n");    
		printf("\t0:�˳�\n");
		printf("\t����������ѡ��0~4:");
		scanf("%d",&sel);
		switch(sel)
		{
		case 1: save(&acc1);break;
		case 2: draw(&acc1);break;
		case 3: transfer(&acc1,&acc2);break;
		case 4: show(acc1);break;		///////		�����˻�������ܡ�
		case 99:printf("�������  \n");break;//      ���ع���99
		case 999:printf("������� \n");break;//      ���ع���999
		case 0: printf("�˳��ɹ���\n");return;
		default:printf("�������!����������!\n");break;
		}
	}
	
}

int save(struct account *acc)//��Ǯ����
{
	double n;
	printf("��ǰ�˻����Ϊ��%0.2fԪ��\n",(*acc).balance);
	printf("��������Ҫ�������:");
	scanf("%lf",&n);
	(*acc).balance+=n;
	printf("��Ǯ�ɹ����������Ϊ��%0.2fԪ��\n",(*acc).balance);
	return 1;
}

int draw(struct account *acc)
{
	int errn=0;
	float n;
	printf("��ǰ�˻����Ϊ��%0.2fԪ��\n",(*acc).balance);
	printf("��������Ҫȡ������:");
	while(1)
	{
		scanf("%f",&n);
		if(n>=(*acc).balance || (int)n%100!=0)//ȡǮ���ܳ��ֻ��ȡ100��ֵ��
		{
			printf("�������������������룡");
			errn++;
			if(errn>=5)
			{
				printf("���������࣡ллʹ�ã��ټ���\n");
				return 0;
			}
		}
		else
		{
			(*acc).balance-=n;
			printf("ȡǮ�ɹ����������Ϊ��%0.2fԪ��\n",(*acc).balance);
			return 1;
		}
	}

}

int transfer(struct account *acc1,struct account *acc2)  ///ת�˺��� acc1-->acc2.    ��ʱʵ��ָ���������˻���ת�ˡ�
{
	double money;
	char ok;
	printf("������ת���");
	scanf("%lf",&money);
	if(money>(*acc1).balance)
	{	
		printf("�˻�������\n");
		return 0;
	}
	printf("���ٴκ˶���Ҫת����˺���Ϣ��\n");
	printf("�˻����룺%s\n",(*acc2).id);
	printf("�˻����ƣ�%s\n",(*acc2).name);
	Sleep(5000);								//��Ҫת���߹۲�5��
	printf("ȷ��ת���˻���Ϣ��Y OR N :");
	getchar();
	scanf("%c",&ok);
	if(ok!='Y' && ok!='y')
	{
		printf("ȡ��ת�ˣ�\n");
		return 0;
	}
	(*acc1).balance-=money;
	(*acc2).balance+=money;
	printf("ת�˳ɹ���\n");
	return 1;
}

void show(struct account acc)
{
	printf("�˺���Ϣ���£�\n");
	printf("�˻����룺%s\n",acc.id);
	printf("�˻����ƣ�%s\n",acc.name);
	printf("�˻���%lf\n",acc.balance);
	Sleep(3000);
}