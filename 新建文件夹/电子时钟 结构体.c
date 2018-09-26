#include<stdio.h>
#include<windows.h>
void setDateTime(struct Date*);
void runDateTime(struct Date*);
void runDateTime(struct Date*);
int get(struct Date);
int isLeap(struct Date );
struct Time
{
	int hour,minute,sec;
};
struct Date
{
	int year,month,day;
	struct Time time;

};
void setDateTime(struct Date*d)
{
	printf("请输入年，月，日，时，分 秒 顺序输入:");
	scanf("%d%d%d%d%d%d",&(d->year),&(d->month),&(d->day),&(d->time.hour),&(d->time.minute),&(d->time.sec));
}
void showDateTime(struct Date d)
{
	printf("\n\n\n\t\t——————————————————————————\n");
	printf("\t\t      %4d年%02d月%02d日  %02d点%02d分%02d秒|\n",d.year,d.month,d.day,d.time.hour,d.time.minute,d.time.sec);
	printf("\t\t——————————————————————————\n");
}
void runDateTime(struct Date *d)
{
	d->time.sec++;
	if(d->time.sec>=60)
	{
		d->time.minute++;
		d->time.sec=0;
		if(d->time.minute>=60)
		{
			d->time.minute=0;
			d->time.hour++;
			if(d->time.hour>=24)
			{	d->time.hour=0;
				d->day++;
				if(d->day>get(*d))//break
				{
					d->month++;
					d->day=1;
					if(d->month>12)
					{
						d->year++;
						d->month=1;
					}
					
				}
			}
		
		}
		
	}
}

int get(struct Date d)
{
	switch(d.month)
	{
	case 1:case 3:case 5:case 7:case 8:case 10:case 12:
		return 31;
	case 4:case 6:case 9:case 11:
		return 30;
	case 2:
		if(isLeap(d)==1)
			return 29;
		else
			return 28;
	}
}
int isLeap(struct Date d)
{
	if(d.year%4==0 && d.year%100!=0 || d.year%400==0)//如果是闰年
		return 1;
	return 0;
}
void main()
{
	struct Date d;
	setDateTime(&d);
	while(1)
	{
		runDateTime(&d);
		showDateTime(d);
		Sleep(1000);
		system("CLS");
	}/**/

}