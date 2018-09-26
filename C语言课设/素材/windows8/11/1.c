#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<dos.h>
#include<string.h>
#include<windows.h>
#include <math.h>
#define LEN sizeof(struct student)
#define FORMAT "%-12d%-12s%-13.1f%-13.1f%-13.1f%-13.1f\n"
#define DATA stu[i].num,stu[i].name,stu[i].chinese,stu[i].math,stu[i].english,stu[i].sum
#define LE 25
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
void help();
void HideCursor();
void Gotoxy(int x, int y);
void DrawBox();
void jindutiao();
void tuichu();
float h();
float f();
int main()
{
	int n;
	here:
	menub();
	printf("	������1-4:");
	scanf("%d",&n);
	switch(n)
	{
		case 1: word();system("cls");jindutiao();fun();goto here;
		case 2:cpassword();goto here;
		case 3:help();goto here;
		case 4:exit(0);
	}
}
void fun()
{
	
	int n;
	menua();
	printf("	������0-8:");
	scanf("%d",&n);
	while(n)
	{
		switch(n)
		{
			case 0:main();
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
	
    printf("	 ����������������������������������������������������������\n");
	printf("	 ��			ѧ����Ϣ����ϵͳ	         ��\n");
	printf("	 �ǩ�����������������������������");
	printf("��������������������������\n");
	printf("	 ��         1.�����¼         ��");
	printf("        2.���Ҽ�¼      ��\n");
	printf("	 �ǩ�����������������������������");
	printf("��������������������������\n");
	printf("	 ��         3.ɾ����¼         ��");
	printf("        4.�޸ļ�¼      ��\n");
	printf("	 �ǩ�����������������������������");
	printf("��������������������������\n");
	printf("	 ��         5.�����¼         ��");
	printf("        6.��¼����      ��\n");
	printf("	 �ǩ�����������������������������");
	printf("��������������������������\n");
	printf("	 ��         7.��¼����         ��");
	printf("        8.��ʾ��¼      ��\n");
	printf("	 �ǩ�����������������������������");
	printf("��������������������������\n");
	printf("	 ��	                   0.�˳�ϵͳ	                 ��\n");
	printf("	 ����������������������������������������������������������\n");
}
void menub()
{
	system("color 05");
	system("mode con  cols=120 lines=40");
	printf("	 \t������������������������������������\n");
	printf("	 \t��\tѧ����Ϣ����ϵͳ	  ��\n");
	printf("	 \t������������������������������������\n");
	printf("	 \t������������������������������������\n");
	printf("                ||1.��½                          ||\n");
    printf("                ||2.�޸�����                      ||\n");
    printf("                ||3.����                          ||\n");
	printf("                ||4.�˳�                          ||\n");
	printf("	 \t������������������������������������\n");
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
					printf("ѧ��        ����        ����         ��ѧ         Ӣ��         �� ��\t\n");
					printf(FORMAT,DATA);
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
				printf("����:");
				scanf("%s",stu[i].name);
				printf("����:");
				scanf("%f",&stu[i].chinese);
				printf("��ѧ:");
				scanf("%f",&stu[i].math);
				printf("Ӣ��:");
				scanf("%f",&stu[i].english);
				printf("�޸ĳɹ�!");
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
		printf("ѧ��        ����        ����         ��ѧ         Ӣ��         �� ��\t\n");
		for(i=0;i<m;i++)
		{
			printf(FORMAT,DATA);
		}
}
void  word()
{	
	int i=0,j=0,n;
    char inputpw[20];
    char str[100];
	char password[10];
    FILE *fp;
	if((fp=fopen("����.txt","r"))==NULL)
	{
		Sleep(500);
		printf("���ļ�ʧ��\n");
		exit(0);
	}
	 fp=fopen("����.txt","r");
	while(fscanf(fp, "%d", &str[j]) != EOF) 
       j++;
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
            printf("�û���������������������룺\n");
			Sleep(500);
        }
	}
  
   return 0;
}
void cpassword()
{
	int m=0,i=0;
	char tmpppr[20];
	char tmppw[20];
	 FILE *fp;
	if((fp=fopen("����.txt","r"))==NULL)
	{
		Sleep(500);
		printf("���ļ�ʧ��\n");
		exit(0);
	}	
	fclose(fp);
	 fp=fopen("����.txt","r");
	while(fscanf(fp, "%d", &tmpppr[m]) != EOF) 
       m++;
	fclose(fp);
	
		printf("������ԭ���룺\n");
        scanf("%s",tmppw);
        if(strcmp(tmppw, tmpppr)==0)
        {
            char newpw1[20],newpw2[20];
            printf("�����������룺\n");
            scanf("%s",newpw1);
            printf("���ٴ����������룺\n");
            scanf("%s",newpw2);
            if(strcmp(newpw1,newpw2)==0)
            {
				fp=fopen("����.txt","w");
				for (i = 0; i < 7; i++) {  
	            fprintf(fp,"%d\n",newpw1[i]);}
			    fclose(fp);
				printf("�����޸ĳɹ���\n");
				Sleep(1000);
				system("cls");
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
void help()
{
	int n;
    char buf[1000] = {0};  
	FILE *fp = fopen("ָ��.txt", "r");
    while (0 != fread(buf, 1, 999, fp))  
    {   
		system("cls");
		system("color 07");
		system("mode con  cols=80 lines=30");
        printf("%s",  buf);
        memset(buf, 0, 1000);  
		here:
		printf("����0�˳���");
		scanf("%d",&n);
		if(n==0)
		{
				system("cls");
				return;
		 }
		else
			{
				system("cls");
				system("color 04");
				printf("�����������ٴ����룺");
				goto here;
		}
		}   
    fclose(fp);
	return 0;
    
}
void jindutiao()
{
	 int len;
	HideCursor();
	for(len = 1; len <= LE; len++)
	{
		Gotoxy(2 * len, 1    );
		printf("��");
		Gotoxy(21, 4);
		printf("�����%d%%", 4 * len);
		Sleep(100);
    }
    Gotoxy(21, 4);
    printf("���������");
    return 0;
}
void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor_info = {1, 0};//��ߵ�0�����겻�ɼ�
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void Gotoxy(int x, int y)
{
	HANDLE hout; //����������hout
	COORD coord; //����ṹ��coord
	coord.X = x;
	coord.Y = y;
	hout = GetStdHandle(STD_OUTPUT_HANDLE);//��ñ�׼�������Ļ�����
	SetConsoleCursorPosition(hout, coord);//�ƶ����
}
void DrawBox()
{
	printf("�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[");
	putchar('\n');
	printf("�U                                                  �U");
	putchar('\n');
	printf("�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a");
}
float f(float x, float y, float z) {
    float a;
a = x * x + 9.0f / 4.0f * y * y + z * z - 1;
    return a * a * a - x * x * z * z * z - 9.0f / 80.0f * y * y * z * z * z;
}
float h(float x, float z) {
float y;
    for ( y = 1.0f; y >= 0.0f; y -= 0.001f)
        if (f(x, y, z) <= 0.0f)
            return y;
    return 0.0f;
}
/*void tuichu()
{
	float z,x,v,y0,ny,nx,nz,nd,d;
    for ( z = 1.5f; z > -1.5f; z -= 0.05f) {
        for ( x = -1.5f; x < 1.5f; x += 0.025f) {
             v = f(x,0.1f, z);
            if (v <= 0.0f) {
                 y0 = h(x, z);
                 ny = 0.01f;
                 nx = h(x + ny, z) - y0;
                 nz = h(x, z + ny) - y0;
                 nd = 1.0f / sqrtf(nx * nx + ny * ny + nz * nz);
                 d = (nx + ny - nz) * nd * 0.5f + 0.5f;
                putchar(".:-=+*#%@"[(int)(d * 5.0f)]);
            }
            else
                putchar(' ');
        }
        putchar('\n');
		
    }
}*/