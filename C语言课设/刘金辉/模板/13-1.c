/******************Ԥ����ģ��ͽṹ��******************/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<dos.h>
#include<string.h>
#define LEN sizeof(struct student)//sizeof(char)
#define FORMAT "%-12d%-12s%-13.1f%-13.1f%-13.1f%-13.1f\n"
#define  DATA stu[i].num,stu[i].name, stu[i].chinese,stu[i].math,stu[i].english,stu[i].sum
/******************����ѧ���ɼ��ṹ��******************/
struct student		
{ 
	int num;			/*ѧ��*/ 
	char name[15];	/*����*/
	float chinese;	/*���Ŀ�*/
	float math;		/*��ѧ��*/
	float english;		/*Ӣ���*/
	float sum;		/*�ܷ�*/
};
struct student stu[50];	/*����ȫ�ֽṹ������*///���ڴ�����ģ��Ա�֤���ܴ�������桰�ڡ����ݽ��������û�����

/******************������������******************/
void input();	/*¼��ѧ���ɼ���Ϣ*/
void show();	/*��ʾѧ��������Ϣ*/
void order();	/*���ܷ�����*/
void del();		/*ɾ��ѧ���ɼ���Ϣ*/
void modify();	/*�޸�ѧ���ɼ���Ϣ*/
void menu();	/*�������˵�*/
void insert();	/*����ѧ����Ϣ*/
void total();	/*����������*/
void search();	/*����ѧ����Ϣ*/
/******************������******************/
int main()
{ 
	int n;
	menu();
	scanf("%d",&n);			/*����ѡ���ܵı��*/
	while(n)
	{ 
		switch(n)
		{ 
		case 0: exit(0);			/*�˳�����*/
		case 1: input();break;		/*¼���¼���ܺ�������*/
		case 2: search();break;		/*���Ҽ�¼���ܺ�������*/
		case 3: del();break;		/*ɾ����¼���ܺ�������*/
		case 4: modify();break;		/*�޸ļ�¼���ܺ�������*/
		case 5: insert();break;		/*�����¼���ܺ�������*/
		case 6: order();break;		/*��¼�����ܺ�������*/
		case 7: total();break;		/*����ͳ�ƹ��ܺ�������*/
		case 8: show();break;		/*���м�¼��ʾ���ܺ�������*/
		default:printf("������������������:");break;
		}
	getch();
	menu();							/*�˵�����ѭ����ʾ*/
	scanf("%d",&n);
	}
	return 0;
}
/******************�Զ��庯��ʵ�ֲ˵�����******************/
void menu()
{
	system("cls");
	printf("\t\t|-------------ѧ����Ϣ����ϵͳ----------|\n");
	printf("\t\t|\t 0. �˳�ϵͳ\t\t\t|\n");
	printf("\t\t|\t 1. �����¼\t\t\t|\n");
	printf("\t\t|\t 2. ���Ҽ�¼\t\t\t|\n");
	printf("\t\t|\t 3. ɾ����¼\t\t\t|\n");
	printf("\t\t|\t 4. �޸ļ�¼\t\t\t|\n");
	printf("\t\t|\t 5. �����¼\t\t\t|\n");
	printf("\t\t|\t 6. ��¼����\t\t\t|\n");
	printf("\t\t|\t 7. ��¼����\t\t\t|\n");
	printf("\t\t|\t 8. ��ʾ��¼\t\t\t|\n");
	printf("\t\t|---------------------------------------|\n");
	printf("\t\t���������Ĳ���(0-8):");
}
/******************¼��ѧ����Ϣ******************/
void input()
{ 
	int i,m=0;	/*����m��ʾ��¼������*/
	char ch[2];  
	FILE *fp;	/*�����ļ�ָ��*/
	if((fp=fopen("stuData.txt","a+"))==NULL)	/*��ָ���ļ�*/
	{ 
		printf("���ļ�ʧ��\n");
		return;
	}
	while(!feof(fp)) //  feof=>file end of file
	{
		if(fread(&stu[m] ,LEN,1,fp)==1)
			m++;	/*ͳ�Ƶ�ǰ��¼����*/
	}
	fclose(fp);
	if(m==0)
		printf("û������!\n");
	else
	{
		system("cls");   //����
		show();	/*����show��������ʾԭ����Ϣ*/
	}
	
	if((fp=fopen("stuData.txt","wb"))==NULL)
	{
		printf("���ļ�ʧ��\n");
		return;
	}
	for(i=0;i<m;i++)
	{
		fwrite(&stu[i] ,LEN,1,fp);	/*��ָ���Ĵ����ļ�д����Ϣ*/
	}

	printf("��ȷ��(y/n):");
	scanf("%s",ch);
	while(strcmp(ch,"Y")==0||strcmp(ch,"y")==0)	/*�ж��Ƿ�Ҫ¼������Ϣ*/
	{
		printf("ѧ��:");
		scanf("%d",&stu[m].num);	/*����ѧ��ѧ��*/
		for(i=0;i<m;i++)
			if(stu[i].num==stu[m].num)
			{
				printf("��ѧ���Ѵ��ڣ�");
				getch();
				fclose(fp);
				return;
			}
		/*���ѧ�ſ��ã������������������*/
		printf("����:");
		scanf("%s",stu[m].name);		/*����ѧ������*/
		printf("���ĳɼ�:");
		scanf("%f",&stu[m].chinese);	/*�������Ŀγɼ�*/
		printf("��ѧ�ɼ�:");
		scanf("%f",&stu[m].math);		/*������ѧ�γɼ�*/
		printf("Ӣ��ɼ�:");
		scanf("%f",&stu[m].english);	/*����Ӣ��γɼ�*/
		stu[m].sum=stu[m].chinese+stu[m].math+stu[m].english;	/*������ܳɼ�*/
		if(fwrite(&stu[m],LEN,1,fp)!=1)	/*����¼�����Ϣд��ָ���Ĵ����ļ�*/
		{
			printf("����ʧ��!");
			getch();
		}
		else
		{
			printf("%s �ѱ���!\n",stu[m].name);
			m++;
		}
		printf("�Ƿ����?(y/n):");	/*ѯ���Ƿ����*/
		scanf("%s",ch);
	}
	fclose(fp);
	printf("�����ɹ�!\n");
}
/******************�Զ�����Һ���******************/
void search()
{ 
	FILE *fp;
	int snum,i,m=0;
	char ch[2];
	if((fp=fopen("stuData.txt","rb"))==NULL)
	{ 
		printf("���ļ�ʧ��\n");
		return;
	}
	while(!feof(fp))  
		if(fread(&stu[m],LEN,1,fp)==1) 
			m++;
	fclose(fp);
	if(m==0) 
	{
		printf("�ļ��޼�¼!\n");
		return;
	}
	printf("��������Ҫ���ҵ�ѧ��ѧ��:");
	scanf("%d",&snum);
	for(i=0;i<m;i++)
		if(snum==stu[i].num)		/*���������ѧ���Ƿ��ڼ�¼��*/
		{ 
			printf("ѧ���������ҵ���ȷ����ʾ?(y/n)");
			scanf("%s",ch);
			if(strcmp(ch,"Y")==0||strcmp(ch,"y")==0) 
			{
				printf("ѧ��        ����          ����         ��ѧ         Ӣ��        �ܷ�\t\n");
				printf(FORMAT,DATA);	/*�����ҳ��Ľ����ָ����ʽ���*/
				break;
			}
		}   
	if(i==m) 
		printf("����ʧ��!\n");			/*δ�ҵ�Ҫ���ҵ���Ϣ*/
}
/******************�Զ���ɾ������******************/
void del()
{
	FILE *fp;
	int snum,i,j,m=0;
	char ch[2];
	if((fp=fopen("stuData.txt","r+"))==NULL)
	{
		printf("���ļ�ʧ��\n");return;
	}
	while( !feof(fp) )  
		if(fread(&stu[m],LEN,1,fp)==1) 
			m++;
		fclose(fp);
		if(m==0) 
		{
			printf("�ļ��޼�¼!\n");
			return;
		}
		show();									/*��ʾ��������*/
		printf("��������Ҫɾ����ѧ��ѧ��:");
		scanf("%d",&snum);	
		for(i=0;i<m;i++)
		{
			if(snum==stu[i].num)				/*���ҵ������ѧ��*/
			{    
				printf("�������ҵ����Ƿ�ȷ��ɾ��?(y/n)");
				scanf("%s",ch);
				if(strcmp(ch,"Y")==0||strcmp(ch,"y")==0)/*�ж��Ƿ�Ҫ����ɾ��*/
				{	
					for(j=i;j<m;j++)
						stu[j]=stu[j+1];		/*����¼�����Ƶ�ǰ���λ��*/
					m--;							/*��¼���ܸ�����1*/
					if((fp=fopen("stuData.txt","wb"))==NULL)
					{ 
						printf("���ļ�ʧ��\n");
						return;
					}
					for(j=0;j<m;j++)/*�����ĺ�ļ�¼����д��ָ���Ĵ����ļ���*/
						if(fwrite(&stu[j] ,LEN,1,fp)!=1)
						{ 
							printf("�Բ��𣬱���ʧ��!\n");
							getch();				/*������ͣ*/
						}
						fclose(fp);
						printf("ɾ���ɹ�!\n");
						return;
				}
				else				/*�û�������ַ�����y��Y����ʾȡ��ɾ��*/
				{
					printf("ȡ��ɾ��!\n");
					return;
				}
			}
		} 
printf("û���ҵ�Ҫɾ������Ϣ��\n");
}
/******************�Զ����޸ĺ���******************/
void modify()
{ 
	FILE *fp;
	int i,j,m=0,snum;
	if((fp=fopen("stuData.txt","r+"))==NULL)
	{ 
		printf("���ļ�ʧ��\n");
		return;
	}
	while(!feof(fp))  
		if(fread(&stu[m],LEN,1,fp)==1) 
			m++;
	if(m==0) 
	{
		printf("�ļ��޼�¼!\n");
		fclose(fp);
		return;
	}
	show();
	printf("��������Ҫ�޸ĵ�ѧ����ѧ��\n");
	printf("ѧ����:");
	scanf("%d",&snum);
	for(i=0;i<m;i++)
	{
		if(snum==stu[i].num)/*������¼���Ƿ���Ҫ�޸ĵ���Ϣ*/
		{
			printf("ѧ���������ҵ������޸�!\n");			
			printf("name:");
			scanf("%s",stu[i].name);/*��������*/
			printf("chinese:");
			scanf("%f",&stu[i].chinese);/*�������Ŀγɼ�*/
			printf("math:");
			scanf("%f",&stu[i].math);/*������ѧ�γɼ�*/
			printf("english:");
			scanf("%f",&stu[i].english);/*����Ӣ��γɼ�*/
			printf("modify successful!");			
			stu[i].sum=stu[i].chinese+stu[i].math+stu[i].english;
			if((fp=fopen("stuData.txt","wb"))==NULL)
			{ 
				printf("���ļ�ʧ��\n");
				return;
			}
			for(j=0;j<m;j++)/*�����޸ĵ���Ϣд��ָ���Ĵ����ļ���*/
				if(fwrite(&stu[j] ,LEN,1,fp)!=1)
				{ 
					printf("����ʧ��!");
					getch(); 
				}
			fclose(fp);
			return ;
		}	 
	}
	printf("û���ҵ�ƥ����Ϣ��\n");
}
/******************�Զ�����뺯��******************/
void insert()
{ 
	FILE *fp;
	int i,j,k,m=0,snum;
	if((fp=fopen("stuData.txt","r+"))==NULL)
	{ 
		printf("���ļ�ʧ��\n");
		return;
	}
	while(!feof(fp))  
		if(fread(&stu[m],LEN,1,fp)==1) m++;
	if(m==0) 
	{
		printf("û������!\n");
		fclose(fp);
		return;
	}
	printf("���������ݲ����λ�ã�\n");
	scanf("%d",&snum);/*����Ҫ�����λ��*/
	for(i=0;i<m;i++)
		if(snum==stu[i].num)
			break;
	for(j=m-1;j>i;j--)
		stu[j+1]=stu[j];		/*�����һ����¼��ʼ�������һλ*/
	printf("�����������������Ϣ.\n");
	printf("ѧ��:");	
	scanf("%d",&stu[i+1].num);
	for(k=0;k<m;k++)
		if(stu[k].num==stu[m].num)
		{
			printf("��ѧ���Ѵ��ڣ�");
			getch();
			fclose(fp);
			return;
		}
	printf("����:");
	scanf("%s",stu[i+1].name);
	printf("���ĳɼ�:");
	scanf("%f",&stu[i+1].chinese);
	printf("��ѧ�ɼ�:");
	scanf("%f",&stu[i+1].math);
	printf("Ӣ��ɼ�:");
	scanf("%f",&stu[i+1].english);
	stu[i+1].sum=stu[i+1].chinese+stu[i+1].math+stu[i+1].english;
	if((fp=fopen("stuData.txt","wb"))==NULL)
	{ 
		printf("���ļ�ʧ��\n");
		return;
	}
	for(k=0;k<=m;k++)
		if(fwrite(&stu[k] ,LEN,1,fp)!=1)		/*���޸ĺ�ļ�¼д������ļ���*/
		{ 
			printf("����ʧ��!"); 
			getch(); 
			return;
		}
	printf("�������ݳɹ�!");
	getch();
	fclose(fp);
}
/******************�Զ���������******************/
void order()
{ 
	FILE *fp;
	struct student t;
	int i=0,j=0,m=0;
	if((fp=fopen("stuData.txt","r+"))==NULL)
	{ 
		printf("���ļ�ʧ��!\n");
		return;
	}
	while(!feof(fp)) 
		if(fread(&stu[m] ,LEN,1,fp)==1) 
			m++;
	fclose(fp);
	if(m==0) 
	{
		printf("�޼�¼!\n");
		return;
	}
	if((fp=fopen("stuData.txt","wb"))==NULL)
	{
		printf("���ļ�ʧ��\n");
		return;
	}
	for(i=0;i<m-1;i++)
		for(j=i+1;j<m;j++)/*˫��ѭ��ʵ�ֳɼ��Ƚϲ�����*/
			if(stu[i].sum<stu[j].sum)
			{ 
				t=stu[i];stu[i]=stu[j];
				stu[j]=t;
			}
	if((fp=fopen("stuData.txt","wb"))==NULL)
	{ 
		printf("���ļ�ʧ��\n");
		return;
	}
	for(i=0;i<m;i++)	/*�������ź������������д��ָ���Ĵ����ļ���*/
		if(fwrite(&stu[i] ,LEN,1,fp)!=1)
		{ 
			printf("%s ����ʧ��!\n"); 
			getch();
		}
	fclose(fp);
	printf("�����ɹ�\n");
}
/******************��ʾѧ��������******************/
void total()
{ 
	FILE *fp;
	int m=0;
	if((fp=fopen("stuData.txt","r+"))==NULL)
	{ 
		printf("���ļ�ʧ��\n");
		return;
	}
	while(!feof(fp))  
		if(fread(&stu[m],LEN,1,fp)==1) 
			m++;/*ͳ�Ƽ�¼������ѧ������*/
	if(m==0)
	{
		printf("�ļ��޼�¼!\n");
		fclose(fp);
		return;
	}
	printf("ѧ������Ϊ %d λ!\n",m);/*��ͳ�Ƶĸ������*/
		fclose(fp);
}
/******************��ʾѧ����Ϣ******************/
void show()
{ 
	FILE *fp;
	int i,m=0;
	fp=fopen("stuData.txt","rb");
	while(!feof(fp))
	{
		if(fread(&stu[m] ,LEN,1,fp)==1) //����������=>�����ڴ����档
			m++;   //��o���ݵ�����
	}  
	fclose(fp);//������
	printf("ѧ ��      �� ��       �� ��        �� ѧ       Ӣ ��       �� ��\t\n");
	for(i=0;i<m;i++) //��һ��ӡѧ����Ϣ,��Ϣ�����ڴ�
	{ 
		printf(FORMAT,DATA);		/*��ѧ����Ϣ��ָ����ʽ��ӡ*/
	}
}
