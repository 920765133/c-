#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<dos.h>
#include<string.h>
#include<windows.h>
#define LEN sizeof(struct student)
#define FORMAT "%-12d%-12s%-13.1f%-13.1f%-13.1f%-13.1f\n"
#define DATA stu[i].num,stu[i].name,stu[i].chinese,stu[i].math,stu[i].english,stu[i].sum
struct student 
{
	int num;
	char name[15];
	float chinese;
	float math;
	float english;
	float sum;
};
struct student stu[50];
void input();
void show();
void order();
void del();
void modify();
void menua();
void insert();
void total();
void search();
void menub();
void fun();
void cpassword();
void  word();
int main()
{
	int n;
	menub();
	printf("	������1-3:");
	scanf("%d",&n);
	switch(n)
	{
		case 1:word();fun();
		case 2:cpassword();break;
		case 3:word();break;
	}
}
void fun()
{
	
	int n;
	menua();
	printf("	������1-8:");
	scanf("%d",&n);
	while(n)
	{
		switch(n)
		{
			case 0:return;
			case 1:input();break;
			case 2:search();break;
			case 3:del();break;
			case 4:modify();break;
			case 5:insert();break;
			case 6:order();break;
			case 7:total();break;
			case 8:show();break;
			default:printf("�����������������룺");break;
		}
		getch();
		menua();
		scanf("%d",&n);
	}
	return 0;
}
void menua()
{
	system("cls");
	printf("\t\t|----------------ѧ����Ϣ����ϵͳ-------|\n");
	printf("\t\t|                                       |\n");
	printf("\t\t|\t0.�˳�ϵͳ\t\t\t|\n");
	printf("\t\t|\t1.�����¼\t\t\t|\n");
	printf("\t\t|\t2.���Ҽ�¼\t\t\t|\n");
	printf("\t\t|\t3.ɾ����¼\t\t\t|\n");
	printf("\t\t|\t4.�޸ļ�¼\t\t\t|\n");
	printf("\t\t|\t5.�����¼\t\t\t|\n");
	printf("\t\t|\t6.��¼����\t\t\t|\n");
	printf("\t\t|\t7.��¼����\t\t\t|\n");
	printf("\t\t|\t8.��ʾ��¼\t\t\t|\n");
	printf("\t\t|---------------------------------------|\n\n");
	printf("\t\t���������Ĳ���(0-8):");

}
void menub()
{
	printf("\t\t--------------------------------\n");
	printf("\t\t|    ѧ����Ϣ����ϵͳ\t\t|\n");
	printf("\t\t|1.��½\t\t\t\t|\n");
    printf("\t\t|2.�޸�����\t\t\t|\n");
    printf("\t\t|3.����\t\t\t\t|\n");
	printf("\t\t--------------------------------\n");
}
void input()
{
	int i,m=0;
	char ch[2];
	FILE *fp;
	if((fp=fopen("stuData.txt","a+"))==NULL)
	{
		printf("���ļ�ʧ��\n");
		return;
	}
	while(!feof(fp))
	{
		if(fread(&stu[m],LEN,1,fp)==1)
			m++;
	}
	fclose(fp);
	if(m==0)
		printf("û������!\n");
	else
	{
		system("cls");
		show();
	}
	if((fp=fopen("stuData.txt","wb"))==NULL)
	{
		printf("���ļ�ʧ��\n");
		return;
	}
	for(i=0;i<m;i++)
	{
		fwrite(&stu[i],LEN,1,fp);
	}
	printf("��ȷ��(y/n):");
	scanf("%s",ch);
	while(strcmp(ch,"Y")==0||strcmp(ch,"y")==0)
	{
		printf("ѧ�ţ�");
		scanf("%d",&stu[m].num);
		for(i=0;i<m;i++)
			if(stu[i].num==stu[m].num)
			{
				printf("��ѧ���Ѵ���!");
				getch();
				fclose(fp);
				return;
			}
			printf("����:");
			scanf("%s",stu[m].name);
				printf("���ĳɼ�:");
			scanf("%f",&stu[m].chinese);
				printf("��ѧ�ɼ�:");
			scanf("%f",&stu[m].math);
				printf("Ӣ��ɼ�:");
			scanf("%f",&stu[m].english);
			stu[m].sum=stu[m].chinese+stu[m].math+stu[m].english;
			if(fwrite(&stu[m],LEN,1,fp)!=1)
			{
				printf("����ʧ�ܣ�");
				getch();
			}
			else
			{
				printf("%s �ѱ��棡\n",stu[m].name);
				m++;
			}
			printf("�Ƿ������(y/n):");
			scanf("%s",ch);
	}
	fclose(fp);
	printf("�����ɹ���\n");
}
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
		printf("��������Ҫ���ҵ�ѧ��ѧ�ţ�");
		scanf("%d",&snum);
		for(i=0;i<m;i++)
			if(snum==stu[i].num )
			{
				printf("ѧ���������ҵ���ȷ����ʾ��(y/n)");
				scanf("%s",ch);
				if(strcmp(ch,"Y")==0||strcmp(ch,"y")==0)
				{
					printf("ѧ��  ����          ���� ��ѧ Ӣ��  �ܷ�\t\n");
					printf("FORMAT,DATA");
					break;
				}
			}
			if(i==m)
				printf("����ʧ�ܣ�\n");
}
void del()
{
	FILE *fp;
	int snum,i,j,m=0;
	char ch[2];
	if((fp=fopen("stuData.txt","r+"))==NULL)
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
		show();
		printf("��������Ҫɾ����ѧ����ѧ�ţ�");
		scanf("%d",&snum);
		for(i=0;i<m;i++)
		{
			if(snum==stu[i].num )
			{
				printf("�������ҵ����Ƿ�ȷ��ɾ����(y/n)");
				scanf("%s",ch);
				if(strcmp(ch,"Y")==0||strcmp(ch,"y")==0)
				{
					for(j=i;j<m;j++)
						stu[j]=stu[j+1];
					m--;
					if((fp=fopen("stuData.txt","wb"))==NULL)
					{
						printf("���ļ�ʧ��\n");
						return;
					}
					for(j=0;j<m;j++)
						if(fwrite(&stu[j],LEN,1,fp)!=1)
						{
							printf("�Բ��𣬱���ʧ�ܣ�\n");
							getch();
						}
						fclose(fp);
						printf("ɾ���ɹ�!\n");
						return;
				}
				else
				{
					printf("ȡ��ɾ����\n");
					return;
				}
			}
		}
printf("û���ҵ�Ҫɾ������Ϣ��\n");
}
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
			printf("�ļ��޼�¼��\n");
			fclose(fp);
			return;
		}
		show();
		printf("��������Ҫ�޸ĵ�ѧ����ѧ�ţ�\n");
		printf("ѧ���ǣ�");
		scanf("%d",&snum);
		for(i=0;i<m;i++)
		{
			if(snum==stu[i].num)
			{
				printf("ѧ���������ҵ������޸ģ�\n");
				printf("name:");
				scanf("%s",stu[i].name);
				printf("chinese:");
				scanf("%f",&stu[i].chinese);
				printf("math:");
				scanf("%f",&stu[i].math);
				printf("english:");
				scanf("%f",&stu[i].english);
				printf("modify successful!");
				stu[i].sum=stu[i].chinese+stu[i].math+stu[i].english;
				if((fp=fopen("stuData.txt","wb"))==NULL)
				{
					printf("���ļ�ʧ��\n");
					return;
				}
				for(j=0;j<m;j++)
					if(fwrite(&stu[j],LEN,1,fp)!=1)
					{
						printf("����ʧ��!");
						getch();
					}
					fclose(fp);
					return;
			}
		}
		printf("û���ҵ�ƥ����Ϣ��\n");
}
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
		if(fread(&stu[m],LEN,1,fp)==1)
			m++;
		if(m==0)
		{
			printf("û�����ݣ�\n");
			fclose(fp);
			return;
		}
		printf("����������λ�ã�\n");
		scanf("%d",&snum);
		for(i=0;i<m;i++)
			if(snum==stu[i].num )
				break;
			for(j=m-1;j>i;j--)
				stu[j+1]=stu[j];
			printf("�����������������Ϣ��\n");
			printf("ѧ�ţ�");
			scanf("%d",&stu[i+1].num );
			for(k=0;k<m;k++)
				if(stu[k].num==stu[m].num )
				{
					printf("ѧ���Ѵ��ڣ�");
					getch();
					fclose(fp);
					return;
				}
				printf("������");
				scanf("%s",stu[i+1].name );
				printf("���ĳɼ���");
				scanf("%f",&stu[i+1].chinese );
				printf("��ѧ�ɼ���");
				scanf("%f",&stu[i+1].math );
				printf("Ӣ��ɼ���");
				scanf("%f",&stu[i+1].english );
				stu[i+1].sum =stu[i+1].chinese +stu[i+1].math +stu[i].english ;
					if((fp=fopen("stuData.txt","wb"))==NULL)
				{
					printf("���ļ�ʧ��\n");
					return;
				}
				for(k=0;k<m;k++)
					if(fwrite(&stu[k],LEN,1,fp)!=1)
					{
						printf("����ʧ��!");
						getch();
						return;
					}
					printf("�������ݳɹ���");
					getch();
					fclose(fp);
}
void order()
{
	FILE *fp;
	struct student t;
	int i=0,j=0,m=0;
	if((fp=fopen("stuData.txt","r+"))==NULL)
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
			printf("û�����ݣ�\n");
			return;
		}
		if((fp=fopen("stuData.txt","wb"))==NULL)
		{
			printf("���ļ�ʧ��\n");
			return;
		}
		for(i=0;i<m-1;i++)
			for(j=i+1;j<m;j++)
				if(stu[i].sum <stu[j].sum )
				{
					t=stu[i];
					stu[i]=stu[j];
					stu[j]=t;
				}
				if((fp=fopen("stuData.txt","wb"))==NULL)
				{
					printf("���ļ�ʧ��\n");
					return;
				}
				for(i=0;i<m;i++)
					if(fwrite(&stu[i],LEN,1,fp)!=1)
					{
						printf("%s ����ʧ�ܣ�\n");
						getch();

					}
					fclose(fp);
					printf("�����ɹ�\n");
}
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
			m++;
		fclose(fp);
		if(m==0)
		{
			printf("���ļ���¼��\n");
			fclose(fp);
			return;
		}
		printf("ѧ������Ϊ%dλ��\n",m);
		fclose(fp);
}
void show()
{
	FILE *fp;
	int i,m=0;
	fp=fopen("stuData.txt","rb");
	while(!feof(fp))
	{
		if(fread(&stu[m],LEN,1,fp)==1)
			m++;
	}
		fclose(fp);
		printf("ѧ��   ����  ����  ��ѧ  Ӣ��  �ܷ�\t\n");
		for(i=0;i<m;i++)
		{
			printf(FORMAT,DATA);
		}
}
void  word()
{	
    char inputpw[20];
    char str[100];
	int password=962088;
    FILE *fp;
	fp=("����.txt","w");
	if(fp)
	{
		fprintf(fp , "%d" , password );
		
	}
	else
	{
		printf("open file error\n");
	}
	while(1)
    {
		system("color 02");
        memset(inputpw,0,20);
        printf("���������룺\n");
        scanf("%s",inputpw);
        if(strcmp(str,inputpw)==0 )
        {
            printf("��½�ɹ�!\n");
			Sleep(500);
            break;
        }
        else
        {
			system("color 04");
			Sleep(500);
            printf("�û���������������������룺\n");
			
        }
	}
   
   return 0;
}
void cpassword()
{ 
	char tmppw[20];
	char stb[15],*q=stb;
	FILE *fp;
	if((fp=fopen("����.txt","r+"))==NULL)
	{
		Sleep(500);
		printf("���ļ�ʧ��\n");
		exit(0);
	}
	    fgets(stb,7,fp);
		puts(stb);
	    printf("������ԭ���룺\n");
        scanf("%s",tmppw);
        if(strcmp(tmppw, stb)==0)
        {
            char newpw1[20],newpw2[20];
            printf("�����������룺\n");
            scanf("%s",newpw1);
            printf("���ٴ����������룺\n");
            scanf("%s",newpw2);
            if(strcmp(newpw1,newpw2)==0)
            {
				Sleep(500);
				while(*q!='\0')
				{
					fputc(*q,fp);
					q++;
				}
				puts(stb);
				fclose(fp);
                printf("�����޸ĳɹ���\n");
            }
            else
            {
				
                printf("��������������벻һ�£������޸�ʧ�ܣ�\n");
				Sleep(1000);
            }
                 
        }
        else
        {
			
            printf("�������ԭʼ���벻��ȷ��\n");
			Sleep(1000);
        }
    }



