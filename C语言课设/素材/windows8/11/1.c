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
	printf("	请输入1-4:");
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
	printf("	请输入0-8:");
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
			default:printf("输入有误，请重新输入：");break;
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
	
    printf("	 ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("	 ┃			学生信息管理系统	         ┃\n");
	printf("	 ┣━━━━━━━━━━━━━━┳");
	printf("━━━━━━━━━━━━┫\n");
	printf("	 ┃         1.输入记录         ┃");
	printf("        2.查找记录      ┃\n");
	printf("	 ┣━━━━━━━━━━━━━━╋");
	printf("━━━━━━━━━━━━┫\n");
	printf("	 ┃         3.删除记录         ┃");
	printf("        4.修改记录      ┃\n");
	printf("	 ┣━━━━━━━━━━━━━━╋");
	printf("━━━━━━━━━━━━┫\n");
	printf("	 ┃         5.插入记录         ┃");
	printf("        6.记录排序      ┃\n");
	printf("	 ┣━━━━━━━━━━━━━━╋");
	printf("━━━━━━━━━━━━┫\n");
	printf("	 ┃         7.记录个数         ┃");
	printf("        8.显示记录      ┃\n");
	printf("	 ┣━━━━━━━━━━━━━━┻");
	printf("━━━━━━━━━━━━┫\n");
	printf("	 ┃	                   0.退出系统	                 ┃\n");
	printf("	 ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
}
void menub()
{
	system("color 05");
	system("mode con  cols=120 lines=40");
	printf("	 \t┏━━━━━━━━━━━━━━━━┓\n");
	printf("	 \t┃\t学生信息管理系统	  ┃\n");
	printf("	 \t┗━━━━━━━━━━━━━━━━┛\n");
	printf("	 \t┏━━━━━━━━━━━━━━━━┓\n");
	printf("                ||1.登陆                          ||\n");
    printf("                ||2.修改密码                      ||\n");
    printf("                ||3.帮助                          ||\n");
	printf("                ||4.退出                          ||\n");
	printf("	 \t┗━━━━━━━━━━━━━━━━┛\n");
}
void input()
{
	int i,m=0;
	char ch[2];
	FILE *fp;
	if((fp=fopen("stuData.txt","a+"))==NULL)
	{
		printf("打开文件失败\n");
		return;
	}
	while(!feof(fp))
	{
		if(fread(&stu[m],LEN,1,fp)==1)
			m++;
	}
	fclose(fp);
	if(m==0)
		printf("没有数据!\n");
	else
	{
		system("cls");
		show();
	}
	if((fp=fopen("stuData.txt","wb"))==NULL)
	{
		printf("打开文件失败\n");
		return;
	}
	for(i=0;i<m;i++)
	{
		fwrite(&stu[i],LEN,1,fp);
	}
	printf("请确认(y/n):");
	scanf("%s",ch);
	while(strcmp(ch,"Y")==0||strcmp(ch,"y")==0)
	{
		printf("学号：");
		scanf("%d",&stu[m].num);
		for(i=0;i<m;i++)
			if(stu[i].num==stu[m].num)
			{
				printf("此学号已存在!");
				getch();
				fclose(fp);
				return;
			}
			printf("姓名:");
			scanf("%s",stu[m].name);
				printf("语文成绩:");
			scanf("%f",&stu[m].chinese);
				printf("数学成绩:");
			scanf("%f",&stu[m].math);
				printf("英语成绩:");
			scanf("%f",&stu[m].english);
			stu[m].sum=stu[m].chinese+stu[m].math+stu[m].english;
			if(fwrite(&stu[m],LEN,1,fp)!=1)
			{
				printf("保存失败！");
				getch();
			}
			else
			{
				printf("%s 已保存！\n",stu[m].name);
				m++;
			}
			
			printf("是否继续？(y/n):");
			scanf("%s",ch);
	}
	fclose(fp);
	printf("操作成功！\n");
}
void search()
{
	FILE *fp;
	int snum,i,m=0;
	char ch[2];
	if((fp=fopen("stuData.txt","rb"))==NULL)
	{
		printf("打开文件失败\n");
		return;
	}
	while(!feof(fp))
		if(fread(&stu[m],LEN,1,fp)==1)
			m++;
		fclose(fp);
		if(m==0)
		{
			printf("文件无记录!\n");
			return;
		}
		printf("请输入需要查找的学生学号：");
		scanf("%d",&snum);
		for(i=0;i<m;i++)
			if(snum==stu[i].num )
			{
				printf("学生数据已找到，确认显示？(y/n)");
				scanf("%s",ch);
				if(strcmp(ch,"Y")==0||strcmp(ch,"y")==0)
				{
					printf("学号        姓名        语文         数学         英语         总 分\t\n");
					printf(FORMAT,DATA);
					break;
				}
			}
			if(i==m)
				printf("查找失败！\n");
}
void del()
{
	FILE *fp;
	int snum,i,j,m=0;
	char ch[2];
	if((fp=fopen("stuData.txt","r+"))==NULL)
	{
		printf("打开文件失败\n");
		return;
	}
	while(!feof(fp))
		if(fread(&stu[m],LEN,1,fp)==1)
			m++;
		fclose(fp);
		if(m==0)
		{
			printf("文件无记录!\n");
			return;
		}
		show();
		printf("请输入需要删除的学生的学号：");
		scanf("%d",&snum);
		for(i=0;i<m;i++)
		{
			if(snum==stu[i].num )
			{
				printf("数据已找到，是否确认删除？(y/n)");
				scanf("%s",ch);
				if(strcmp(ch,"Y")==0||strcmp(ch,"y")==0)
				{
					for(j=i;j<m;j++)
						stu[j]=stu[j+1];
					m--;
					if((fp=fopen("stuData.txt","wb"))==NULL)
					{
						printf("打开文件失败\n");
						return;
					}
					for(j=0;j<m;j++)
						if(fwrite(&stu[j],LEN,1,fp)!=1)
						{
							printf("对不起，保存失败！\n");
							getch();
						}
						fclose(fp);
						printf("删除成功!\n");
						return;
				}
				else
				{
					printf("取消删除！\n");
					return;
				}
			}
		}
printf("没有找到要删除的信息！\n");
}
void modify()
{
	FILE *fp;
	int i,j,m=0,snum;
	if((fp=fopen("stuData.txt","r+"))==NULL)
	{
		printf("打开文件失败\n");
		return;
	}
	while(!feof(fp))
		if(fread(&stu[m],LEN,1,fp)==1)
			m++;
		if(m==0)
		{
			printf("文件无记录！\n");
			fclose(fp);
			return;
		}
		show();
		printf("请输入你要修改的学生的学号：\n");
		printf("学号是：");
		scanf("%d",&snum);
		for(i=0;i<m;i++)
		{
			if(snum==stu[i].num)
			{
				printf("学生数据已找到，请修改！\n");
				printf("姓名:");
				scanf("%s",stu[i].name);
				printf("语文:");
				scanf("%f",&stu[i].chinese);
				printf("数学:");
				scanf("%f",&stu[i].math);
				printf("英语:");
				scanf("%f",&stu[i].english);
				printf("修改成功!");
				stu[i].sum=stu[i].chinese+stu[i].math+stu[i].english;
				if((fp=fopen("stuData.txt","wb"))==NULL)
				{
					printf("打开文件失败\n");
					return;
				}
				for(j=0;j<m;j++)
					if(fwrite(&stu[j],LEN,1,fp)!=1)
					{
						printf("保存失败!");
						getch();
					}
					fclose(fp);
					return;
			}
		}
		printf("没有找到匹配信息！\n");
}
void insert()
{
	FILE *fp;
	int i,j,k,m=0,snum;
	if((fp=fopen("stuData.txt","r+"))==NULL)
	{
		printf("打开文件失败\n");
		return;
	}
	while(!feof(fp))
		if(fread(&stu[m],LEN,1,fp)==1)
			m++;
		if(m==0)
		{
			printf("没有数据！\n");
			fclose(fp);
			return;
		}
		printf("请输入插入的位置：\n");
		scanf("%d",&snum);
		for(i=0;i<m;i++)
			if(snum==stu[i].num )
				break;
			for(j=m-1;j>i;j--)
				stu[j+1]=stu[j];
			printf("请输入待插入数据信息：\n");
			printf("学号：");
			scanf("%d",&stu[i+1].num );
			for(k=0;k<m;k++)
				if(stu[k].num==stu[m].num )
				{
					printf("学号已存在！");
					getch();
					fclose(fp);
					return;
				}
				printf("姓名：");
				scanf("%s",stu[i+1].name );
				printf("语文成绩：");
				scanf("%f",&stu[i+1].chinese );
				printf("数学成绩：");
				scanf("%f",&stu[i+1].math );
				printf("英语成绩：");
				scanf("%f",&stu[i+1].english );
				stu[i+1].sum =stu[i+1].chinese +stu[i+1].math +stu[i].english ;
					if((fp=fopen("stuData.txt","wb"))==NULL)
				{
					printf("打开文件失败\n");
					return;
				}
				for(k=0;k<m;k++)
					if(fwrite(&stu[k],LEN,1,fp)!=1)
					{
						printf("保存失败!");
						getch();
						return;
					}
					printf("插入数据成功！");
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
		printf("打开文件失败\n");
		return;
	}
	while(!feof(fp))
		if(fread(&stu[m],LEN,1,fp)==1)
			m++;
		fclose(fp);
		if(m==0)
		{
			printf("没有数据！\n");
			return;
		}
		if((fp=fopen("stuData.txt","wb"))==NULL)
		{
			printf("打开文件失败\n");
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
					printf("打开文件失败\n");
					return;
				}
				for(i=0;i<m;i++)
					if(fwrite(&stu[i],LEN,1,fp)!=1)
					{
						printf("%s 保存失败！\n");
						getch();

					}
					fclose(fp);
					printf("操作成功\n");
}
void total()
{
	FILE *fp;
	int m=0;
	if((fp=fopen("stuData.txt","r+"))==NULL)
	{
		printf("打开文件失败\n");
		return;
	}
	while(!feof(fp))
		if(fread(&stu[m],LEN,1,fp)==1)
			m++;
		fclose(fp);
		if(m==0)
		{
			printf("无文件记录！\n");
			fclose(fp);
			return;
		}
		printf("学生总数为%d位！\n",m);
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
		printf("学号        姓名        语文         数学         英语         总 分\t\n");
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
	if((fp=fopen("密码.txt","r"))==NULL)
	{
		Sleep(500);
		printf("打开文件失败\n");
		exit(0);
	}
	 fp=fopen("密码.txt","r");
	while(fscanf(fp, "%d", &str[j]) != EOF) 
       j++;
	  while(1)
    {
		system("color 02");
        memset(inputpw,0,20);
        printf("请输入密码：\n");
        scanf("%s",inputpw);
        if(strcmp(str,inputpw)==0 )
        {
            printf("登陆成功!\n");
			Sleep(500);
            break;
        }
        else
        {
			system("color 04");
            printf("用户名或密码错误，请重新输入：\n");
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
	if((fp=fopen("密码.txt","r"))==NULL)
	{
		Sleep(500);
		printf("打开文件失败\n");
		exit(0);
	}	
	fclose(fp);
	 fp=fopen("密码.txt","r");
	while(fscanf(fp, "%d", &tmpppr[m]) != EOF) 
       m++;
	fclose(fp);
	
		printf("请输入原密码：\n");
        scanf("%s",tmppw);
        if(strcmp(tmppw, tmpppr)==0)
        {
            char newpw1[20],newpw2[20];
            printf("请输入新密码：\n");
            scanf("%s",newpw1);
            printf("请再次输入新密码：\n");
            scanf("%s",newpw2);
            if(strcmp(newpw1,newpw2)==0)
            {
				fp=fopen("密码.txt","w");
				for (i = 0; i < 7; i++) {  
	            fprintf(fp,"%d\n",newpw1[i]);}
			    fclose(fp);
				printf("密码修改成功！\n");
				Sleep(1000);
				system("cls");
            }
            else
            {
				
                printf("您两次输入的密码不一致，密码修改失败！\n");
				Sleep(1000);
            }
                 
        }
        else
        {
			
            printf("您输入的原始密码不正确！\n");
			Sleep(1000);
        }
    }
void help()
{
	int n;
    char buf[1000] = {0};  
	FILE *fp = fopen("指南.txt", "r");
    while (0 != fread(buf, 1, 999, fp))  
    {   
		system("cls");
		system("color 07");
		system("mode con  cols=80 lines=30");
        printf("%s",  buf);
        memset(buf, 0, 1000);  
		here:
		printf("输入0退出：");
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
				printf("输入有误，请再次输入：");
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
		printf("█");
		Gotoxy(21, 4);
		printf("已完成%d%%", 4 * len);
		Sleep(100);
    }
    Gotoxy(21, 4);
    printf("下载已完成");
    return 0;
}
void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor_info = {1, 0};//后边的0代表光标不可见
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void Gotoxy(int x, int y)
{
	HANDLE hout; //定义句柄变量hout
	COORD coord; //定义结构体coord
	coord.X = x;
	coord.Y = y;
	hout = GetStdHandle(STD_OUTPUT_HANDLE);//获得标准输出（屏幕）句柄
	SetConsoleCursorPosition(hout, coord);//移动光标
}
void DrawBox()
{
	printf("╔═════════════════════════╗");
	putchar('\n');
	printf("║                                                  ║");
	putchar('\n');
	printf("╚═════════════════════════╝");
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