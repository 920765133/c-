				/*Chinese Beta*/
#include <conio.h>
#include <stdio.h>

#include <dos.h>  /*call the dos interrupt*/
#include <string.h>
#include <stdlib.h>
#include "define.h"
char *menu[]={"学生数据管理程序",
		  "主 菜 单","数据修改",
		  "修改密码","帮    助",
		  "退    出"};
int count; /*record item count*/
Student *head=NULL;/*link table head*/
char name[8];       /*at find*/
unsigned long num;
int year,month,day;
void main()
{
    Set_Cursor(3,0);  /*dissemble the cursor*/
    Validation();     /*identify the user module*/
    Set_Cursor(3,3);
}
/*-------------------------------Start_Tableau_part_begin----------------------------------------------------*/
void Validation()
{
	FILE *fp;
	char temp,pwd[N];
	int i,l=1;
	if((fp=fopen("cpool.ep","r"))!=NULL)
		{
			while(l<=3)
			{
				textcolor(GREEN);
				clrscr();
				i=0;
				MessageBox(25,12,2,30);
				gotoxy(26,13);
				printf("请输入密码:");
				temp=GetKey();
				while(temp!=RETURN)        /*13-->Enter ASCII for getch getting it*/
	       			{
		       			if(temp!=Backspace)
		       				{
		       					Encipher(&temp);
		       					pwd[i]=temp;
		       					putchar('*');
                                                        i++;
		       				}
					else    if(i!=0) {i--;gotoxy(37+i,13);putchar(' ');gotoxy(37+i,13);}
	       	   			if(i>12) {while((temp=getch())!=13) ;} /*the max passwords length is 12*/
					if(temp!=RETURN) temp=GetKey();
					}
				pwd[i]=0;
				if(!TelPas(pwd,fp))
					{
						textcolor(RED);
						clrscr();
						printf("密码错误!");
						getch();
					}
				else {fclose(fp);MainMenu();}
				l++;
			}
		}
	else MainMenu();   /*if passwords correct then enter main menu*/
}
int TelPas(char *p,FILE *fp)  /*passwords identify module*/
{
   char pas[N],temp;
   int i=0;
   rewind(fp);
   while(!feof(fp))
	{
	    temp=fgetc(fp);
	    pas[i]=temp;
	    i++;
	}
   pas[i-1]=0;
   if(strcmp(p,pas)==0) return 1;
   else return 0;
}
void MainMenu()
{
    int i;
    textmode(C80);
    textcolor(GREEN);
    clrscr();
    MessageBox(29,10,2,strlen(menu[0])+3);
    gotoxy(31,11);
    printf(menu[0]);
    gotoxy(35,13);
    printf(menu[1]);
    MessageBox(33,14,5,strlen(menu[3])+3);
    textcolor(GREEN);
    for(i=2;i<6;i++)
       {
	   gotoxy(35,13+i);
	   printf(menu[i]);
       }
   gotoxy(1,1);
   ShowBar(35,15,strlen(menu[2]),1);
   Choice(35,15);
}
void DataEditTool()
{
	textmode(C80);
	textcolor(GREEN);
	clrscr();
	Headbar();
	Helpbar();
	window(2,3,79,19);
	clrscr();
	DataAccess();
}
void ChangePassword()
{
    FILE *fp;
    char paswd[N],temp;
    int i=0,retvalue=1;
    fp=fopen("cpool.ep","r");
    fgetc(fp);    /*let fp add one in order to tell whether cpool.ep empty or not*/
    if(!feof(fp)&&fp!=NULL)
      {
          window(1,1,40,5);
	  	  MessageBox(2,1,2,30);
	  	  gotoxy(3,2);
	      printf("旧密码:");
	      temp=GetKey();
	  while(temp!=13)        /*13-->Enter ASCII for getch getting it*/
	       {
		       if(temp!=Backspace)
		       		{
		       			Encipher(&temp);
		       			paswd[i]=temp;
		       			putchar('*');
                        i++;
		       		}
		       else	if(i!=0) {i--;gotoxy(10+i,2);putchar(' ');gotoxy(10+i,2);}
	       	   if(i>12) {while((temp=getch())!=13) ;}   /*password length must <=12 word*/
	       	   if(temp!=13) temp=GetKey();
	       }
	      paswd[i]=0;
	      retvalue=TelPas(paswd,fp);
	      fclose(fp);
      }
    if(retvalue)
      {
          if((fp=fopen("cpool.ep","w+"))==NULL)
	    {
		gotoxy(2,1);printf("Password file open failed!");
		getch();exit(1);
	    }
	  textcolor(GREEN);
	  window(1,1,40,5);
	  clrscr();
	  MessageBox(2,1,2,30);
	  gotoxy(3,2);
	  printf("新密码:");
	  temp=GetKey();
	  i=0;/*count length of password*/
	  while(temp!=13)
	       {
		   		if(temp!=Backspace)
		       		{
		       			Encipher(&temp);
		       			paswd[i]=temp;
		       			i++;
		   				putchar('*');
		   			}
                else if(i!=0) {i--;gotoxy(10+i,2);putchar(' ');gotoxy(10+i,2);}
	       		if(i>12) {while((temp=getch())!=13) ;}
	       		if(temp!=13) temp=GetKey();
	       }
	  paswd[i]=0;
          fprintf(fp,"%s",paswd);
	  clrscr();
      }
    else {
	     textcolor(RED);
	     clrscr();
	     printf("密码错误!");
	     getch();
	     textcolor(GREEN);
	     clrscr();
	 }
    fclose(fp);
}
void Help()
{
	system("edit readme.txt");
}
void Quit()
{
	textmode(C80);
	textcolor(RED);
	clrscr();
	gotoxy(23,13);cprintf("Thank you for using this program!");
	getch();
	Set_Cursor(2,2);
	clrscr();
	exit(0);
}
void Encipher(char *original)    /*lock module*/
{
    *original+=(*original-K)*(K+M);
}
void MessageBox(int startx,int starty,int height,int width)   /*draw box module*/
{
    int i;
    gotoxy(startx,starty);
    putch(201);
    for(i=1;i<width;i++) putch(205);
    putch(187);
    for(i=1;i<height;i++)
       {
	   gotoxy(startx,starty+i);putch(186);
	   gotoxy(startx+width,starty+i);putch(186);
       }
    gotoxy(startx,starty+i);
    putch(200);
    for(i=1;i<width;i++) putch(205);
    putch(188);
}
int GetKey()
{
    int key;
    key=bioskey(0);
    if(key<<8) key=key&0x00ff;
    return key;
}
void Choice(int menustartx,int menustarty)
{
    int i=2,access_mark=0;
    while(1)
	 {
	     switch(GetKey())
		  {
		      case UP: ShowBar(menustartx,menustarty,strlen(menu[i]),0);
			       if(menustarty==15) {menustarty+=3;i=5;}
			       else {menustarty--;i--;}
			       ShowBar(menustartx,menustarty,strlen(menu[i]),1);
			       break;
		      case DOWN: ShowBar(menustartx,menustarty,strlen(menu[i]),0);
				 if(menustarty==18) {menustarty-=3;i=2;}
				 else {menustarty++;i++;}
				 ShowBar(menustartx,menustarty,strlen(menu[i]),1);
				 break;
		      case RETURN: if(i==2) {DataEditTool();access_mark=1;}
				   if(i==3) ChangePassword();
				   if(i==4) {Help();}
				   if(i==5) Quit();
				   break;
		  }
	if(access_mark) break;
	 }
}
void ShowBar(int x,int y,int w,int mark)
{
    typedef struct text{unsigned char ch;
			unsigned char attr;
		       }text;
    text str;
    int i;
    for(i=x;i<x+w;i++)
    {
	gettext(i,y,i,y,&str);
	if(mark==0) str.attr=(GREEN+(BLACK<<4));
	if(mark==1) str.attr=(RED+(GREEN<<4));
	puttext(i,y,i,y,&str);
    }
}


/*------------------------------------Start_tableau_part_end------------------------------------------*/

/*------------------------------------Data_Processing_part_start--------------------------------------*/
void Headbar()
{
	textcolor(GREEN);
	gotoxy(2,1);
	printf("号码");
	gotoxy(20,1);
	printf("姓名");
	gotoxy(40,1);
	printf("性别");
	gotoxy(60,1);
	printf("出生年月");
}
void Helpbar()
{
	DrawRim(24,20,5,55);
	gotoxy(25,21);cprintf("F1:关于...");
	gotoxy(25,22);cprintf("F2:创建新记录");
	gotoxy(25,23);cprintf("F3:刷新记录");
	gotoxy(25,24);cprintf("ESC:返回主菜单");
	gotoxy(44,21);cprintf("F4:以名字查询");
	gotoxy(44,22);cprintf("F5:以号码查询");
	gotoxy(44,23);cprintf("F6:以生日查询");
	gotoxy(44,24);cprintf("Del:删除记录");
	gotoxy(66,21);cprintf("修 改");
	gotoxy(63,22);cprintf("Enter:开始修改");
	gotoxy(63,23);cprintf("Tab:选择修改项");
	gotoxy(63,24);cprintf("Esc:修改完毕");
}
void DataAccess()
{
	FILE *fp;
	Student *mp1,*mp2;
	int state=0;
	count=0;
	head=mp1=(Student *)malloc(sizeof(Student));
	VerMessage();
	window(2,3,79,19);
	fp=fopen("student.dat","rb");
	fgetc(fp);
	if(feof(fp))
		{
			textcolor(RED);
			clrscr();
			gotoxy(30,10);
			cprintf("当前数据库中没有数据!");
			gotoxy(30,12);
			cprintf("你可以按F2输入数据...");
			getch();
			state=0;
			textcolor(GREEN);
			clrscr();
		}
	else
		{
			state=1;count=1;
			textcolor(GREEN);
			clrscr();
			rewind(fp);
			fscanf(fp,"%s %lu %s %d.%d.%d\r\n",head->name,&head->num,head->sex,&head->birthday.year,&head->birthday.month,&head->birthday.day);
			head->node=NULL;
			while(!feof(fp))
				{
					mp2=(Student *)malloc(sizeof(Student));
					fscanf(fp,"%s %lu %s %d.%d.%d\r\n",mp2->name,&mp2->num,mp2->sex,&mp2->birthday.year,&mp2->birthday.month,&mp2->birthday.day);
					mp1->node=mp2;mp2->node=NULL;
					mp1=mp2;
					count++;
				}
			ShowData(1);
		}
	fclose(fp);
	DataProcess(state);
}
void DataProcess(int state)
{
	int key,barstartx=2,barstarty=3,i=0;
	if(!state)
		{
			while(1)
			{
				key=GetKey();
				if(key==ESC) MainMenu();
				if(key==F1) Help();
				if(key==F2) {CreatData();VerMessage();}
				if(key==F3)
					{       FreeMem();
						DataAccess();
					}
			}
		}
	else
		{
			ShowBar(barstartx,barstarty,76,1);
			while(1)
				{
					switch(GetKey())
					{
						case UP: ShowBar(barstartx,barstarty,76,0);
						if(barstarty!=3) barstarty--;
						else if(count/16>0&&i>0) {clrscr();ShowData((--i)*16+1);barstarty=3;}
						ShowBar(barstartx,barstarty,76,1);
						break;
						case DOWN: ShowBar(barstartx,barstarty,76,0);
						if(barstarty!=18&&(barstarty-2)!=count-i*16) barstarty++;
						else if(count/16>0&&i<count/16) {clrscr();ShowData((++i)*16+1);barstarty=3;}
						ShowBar(barstartx,barstarty,76,1);
						break;
						case RETURN: Modify(i*16+barstarty-2);FreeMem();DataAccess();
						break;
						case F1: Help();
						break;
						case F2: CreatData();VerMessage();
						break;
						case F3: FreeMem();DataAccess();
						break;
						case F4: Find(1);  /*find by name*/
						break;
						case F5: Find(2);  /*find by number*/
						break;
						case F6: Find(3);  /*find by birthday*/
						break;
						case Del: Delete(i*16+barstarty-2);/*delete the element whose number is i*16+barstarty-3+1.*/
						break;
						case ESC: MainMenu();
						break;

					}
				}
		}

}
void DataBox()
{
	window(1,20,23,25);
        textcolor(GREEN);
        clrscr();
	DrawRim(1,1,5,20);
	gotoxy(2,2);cprintf("姓名:");
	gotoxy(2,3);cprintf("号码:");
	gotoxy(2,4);cprintf("性别:");
	gotoxy(2,5);cprintf("出生年月:");
}
void CreatData()
{
	FILE *fp;
	Student data;
	Set_Cursor(3,3);
	window(1,20,23,25);
	if((fp=fopen("student.dat","ab"))==NULL)
		{
			textcolor(RED);
			clrscr();
			gotoxy(4,3);cprintf("File Failed!");
		}
	else
		{
			DataBox();
			gotoxy(7,2);window(7,21,13,21);clrscr();Input_chinese(data.name);fprintf(fp,"%s",data.name);fprintf(fp," ");
			gotoxy(7,3);window(7,22,16,22);clrscr();Input_lonint(&data.num);fprintf(fp,"%lu",data.num);fprintf(fp," ");
                        gotoxy(7,4);window(7,23,9,23);clrscr();Input_chinese(data.sex);fprintf(fp,"%s",data.sex);fprintf(fp," ");
			gotoxy(11,5);window(11,24,20,24);clrscr();Input_int(&data.birthday.year);putchar('.');Input_int(&data.birthday.month);putchar('.');
			Input_int(&data.birthday.day);fprintf(fp,"%d.%d.%d",data.birthday.year,data.birthday.month,data.birthday.day);fprintf(fp,"\r\n");
		}
	fclose(fp);
	Set_Cursor(3,0);
	FreeMem();DataAccess();
}
void DrawRim(int startx,int starty,int height,int width)
{
    int i;
    gotoxy(startx,starty);
    putch(0xda);
    for(i=1;i<width;i++) putch(0xc4);
    putch(0xbf);
    for(i=1;i<height;i++)
       {
	   gotoxy(startx,starty+i);putch(0xb3);
	   gotoxy(startx+width,starty+i);putch(0xb3);
       }
    gotoxy(startx,starty+i);
    putch(0xc0);
    for(i=1;i<width;i++) putch(0xc4);
    putch(0xd9);
}
void VerMessage()
{
	window(1,20,23,25);
	textcolor(RED);
	clrscr();
	gotoxy(2,3);cprintf("学生数据管理程序中文版");
	gotoxy(2,4);cprintf("       Ver 1.2       ");
	gotoxy(2,5);cprintf("  By Lodger In SCNU  ");
}
void ShowData(int i)
{
	int k;
	Student *mp1,*mp2;
	mp1=mp2=head;
	for(k=1;k<i;k++)
		{
			mp1=mp2->node;mp2=mp1;
		}
	for(k=i;(k<16+i)&&(mp1!=NULL);k++)
		{
			cprintf("%-17lu %-20s %c%-18c %d.%d.%d\r\n",mp1->num,mp1->name,mp1->sex[0],mp1->sex[1],mp1->birthday.year,mp1->birthday.month,mp1->birthday.day);
			mp1=mp2->node;mp2=mp1;
		}
}
void Find(int agv)
{
	Set_Cursor(1,1);
	DataBox();
	if(agv==1)
		{
			gotoxy(7,2);Input_chinese(name);Search(agv);
		}
	if(agv==2)
		{
			gotoxy(7,3);Input_lonint(&num);Search(agv);
		}
	if(agv==3)
		{
			gotoxy(11,5);Input_int(&year);putchar('.');Input_int(&month);putchar('.');Input_int(&day);Search(agv);
		}
	Set_Cursor(3,0);
}
void Search(int agv)
{
	Student *mp1,*mp2;
	int hd=0;
	mp1=mp2=head;
	if(agv==1)
		{
			while(mp1!=NULL)
				{
					if(!strcmp(mp1->name,name)) {hd=1;Message1();DataBox();Result(mp1);getch();}
					mp2=mp1->node;mp1=mp2;
				}
		}
	if(agv==2)
		{
			while(mp1!=NULL)
				{
					if(mp1->num==num) {hd=1;Message1();DataBox();Result(mp1);getch();}
					mp2=mp1->node;mp1=mp2;
				}
		}
	if(agv==3)
		{
			while(mp1!=NULL)
				{
					if(mp1->birthday.year==year&&mp1->birthday.month==month&&mp1->birthday.day==day) {hd=1;Message1();DataBox();Result(mp1);getch();}
					mp2=mp1->node;mp1=mp2;
				}
		}
	if(hd==0) Message2();
	VerMessage();
}

void Result(Student *p)
{
	gotoxy(7,2);cprintf("%s",p->name);
	gotoxy(7,3);cprintf("%lu",p->num);
	gotoxy(7,4);cprintf("%s",p->sex);
	gotoxy(11,5);cprintf("%d.%d.%d",p->birthday.year,p->birthday.month,p->birthday.day);
}
void Message1()
{
	textcolor(RED);
	clrscr();
	gotoxy(2,4);cprintf("搜索数据...找到");
	getch();
	clrscr();
}
void Message2()
{
	textcolor(RED);
	clrscr();
	gotoxy(2,4);cprintf("对不起,数据没找到!");
	getch();
	clrscr();
}
void Delete(int i)
{
	int k;
	Student *mp1,*mp2;
	mp2=mp1=head;
	if(i==1) head=mp1->node;
	else{
		for(k=1;k<i-1;k++) 	mp1=mp1->node;
		mp2=mp1->node;
		mp1->node=(mp1->node)->node;
	    }
	free(mp2);
	FreshFile();
	FreeMem();
	DataAccess();
}
void Modify(int i)
{
	int k,j=0,mark=0;
	Student *mp1;
	mp1=head;
	Set_Cursor(3,3);
	for(k=1;k<i;k++) mp1=mp1->node;
	DataBox();
	Result(mp1);
	gotoxy(1,1);
	while(1)
	{
		switch(GetKey())
		{
			case ESC: VerMessage();mark=1;
			break;
			case TAB:
				if(j==4) j=1;
				else j++;
				switch(j)
				{
					case 1: gotoxy(7,2);break;
					case 2: gotoxy(7,3);break;
					case 3:	gotoxy(7,4);break;
					case 4: gotoxy(11,5);break;
				}
			break;
			case Del:
				switch(j)
				{
					case 1: window(7,21,13,21);clrscr();Input_chinese(mp1->name);break;
					case 2: window(7,22,16,22);clrscr();Input_lonint(&mp1->num);break;
					case 3: window(7,23,9,23);clrscr();Input_chinese(mp1->sex);break;
					case 4: window(11,24,20,24);clrscr();Input_int(&mp1->birthday.year);putchar('.');Input_int(&mp1->birthday.month);putchar('.');Input_int(&mp1->birthday.day);break;
				}
			DataBox();
			Result(mp1);
			gotoxy(1,1);
			j=0;
		}
	if(mark) break;
	}
	FreshFile();
	Set_Cursor(3,0);
	FreeMem();DataAccess();
}
void FreeMem()
{
	Student *mp1,*mp2;
	mp1=head;
	while(mp1)
	{
		mp2=mp1->node;free(mp1);
		if(!mp2) break;
		mp1=mp2->node;free(mp2);
	}
}
void FreshFile()
{
	FILE *fp;
	Student *mp1;
	mp1=head;
	fp=fopen("student.dat","wb");
	if(fp==NULL) exit(1);
	while(mp1)
		{
			fprintf(fp,"%s %lu %s %d.%d.%d\r\n",mp1->name,mp1->num,mp1->sex,mp1->birthday.year,mp1->birthday.month,mp1->birthday.day);
			mp1=mp1->node;
		}
	fclose(fp);
}
void Set_Cursor(int ch,int cl)  /*hide or display the cursor*/
{
	union REGS regs;
	regs.h.ah=1;
	regs.h.ch=ch;
	regs.h.cl=cl;
	int86(0x10,&regs,&regs);
}
void Input_int(int *parameter)
{
	char tmp[20];
	int i=0;
        do
		{
			tmp[i]=GetKey();
                        if(tmp[i]==Backspace&&i!=0) {i--;gotoxy(wherex()-1,wherey());putchar(' ');gotoxy(wherex()-1,wherey());}
			else if(tmp[i]>=0x30&&tmp[i]<=0x39) putchar(tmp[i++]);
		}while(tmp[i]!=RETURN);
	 tmp[i]=0;
	 *parameter=atoi(tmp);
}
void Input_lonint(unsigned long *parameter)
{
	char tmp[20];
	int i=0;
        do
		{
			tmp[i]=GetKey();
                        if(tmp[i]==Backspace&&i!=0) {i--;gotoxy(wherex()-1,wherey());putchar(' ');gotoxy(wherex()-1,wherey());}
                        else if(tmp[i]>=0x30&&tmp[i]<=0x39) putchar(tmp[i++]);
		}while(tmp[i]!=RETURN);
	 tmp[i]=0;
	 *parameter=atol(tmp);
}
void Input_chinese(char *parameter)
{
        char tmp[20];
	int i=0;
	do
		{
                    tmp[i]=GetKey();
                    if(tmp[i]!=ESC&&tmp[i]!=TAB)
                          {
								if(tmp[i]==RETURN) break;
								if(tmp[i]==Backspace && i!=0)
									{
										if (!(i%2))
										      {i=i-2;gotoxy(wherex()-2,wherey());putchar(' ');putchar(' ');gotoxy(wherex()-2,wherey());}
										else{i--;gotoxy(wherex()-1,wherey());putchar(' ');gotoxy(wherex()-1,wherey());}
									}
								else if(tmp[i]!=Backspace){
									 tmp[++i]=GetKey();
									 if(tmp[i]!=ESC && tmp[i]!=TAB && tmp[i]!=Backspace && tmp[i]!=RETURN)	{putchar(tmp[i-1]);putchar(tmp[i++]);}
									 else if(tmp[i]==RETURN) break;
										else if(tmp[i]==Backspace) {i=i-1;gotoxy(wherex()-1,wherey());putchar(' ');gotoxy(wherex()-1,wherey());}
								}

                          }

		}while(tmp[i]!=RETURN);
         tmp[i]=0;
	strcpy(parameter,tmp);
}