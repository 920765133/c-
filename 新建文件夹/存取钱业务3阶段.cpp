//第一阶段，goto+switch
//第二阶段，实现单账户存钱，取钱业务。
//第三阶段，使用结构体实现存、取钱，转账业务
//第四阶段，增加实现开户、销户业务。
#include<stdio.h>
#include<string.h>
#include<windows.h>				//需使用延时函数
struct account
{
	char id[6];
	char name[8];
	double balance;
};

int save(struct account*);//存钱函数
int draw(struct account*);//取钱函数
int transfer(struct account*,struct account*);   ///转账函数
void show(struct account);						////新增显示功能
void main()
{
	int sel;
	struct account acc1,acc2;
	strcpy(acc1.id,"10001");
	strcpy(acc1.name,"张三");
	acc1.balance=acc2.balance=0;
	strcpy(acc2.id,"10002");
	strcpy(acc2.name,"李四");
	while(1)			///////使用循环结构完成菜单循环
	{//菜单不显示隐藏功能。
		printf("---------------功能菜单--------------\n");
		printf("\t1:存钱\n");
		printf("\t2:取钱\n");
		printf("\t3:转账\n");
		printf("\t4:账户信息显示\n");    
		printf("\t0:退出\n");
		printf("\t请输入您的选择0~4:");
		scanf("%d",&sel);
		switch(sel)
		{
		case 1: save(&acc1);break;
		case 2: draw(&acc1);break;
		case 3: transfer(&acc1,&acc2);break;
		case 4: show(acc1);break;		///////		新增账户浏览功能。
		case 99:printf("开户完毕  \n");break;//      隐藏功能99
		case 999:printf("销户完毕 \n");break;//      隐藏功能999
		case 0: printf("退出成功！\n");return;
		default:printf("输入错误!请重新输入!\n");break;
		}
	}
	
}

int save(struct account *acc)//存钱函数
{
	double n;
	printf("当前账户余额为：%0.2f元。\n",(*acc).balance);
	printf("请输入您要存款数额:");
	scanf("%lf",&n);
	(*acc).balance+=n;
	printf("存钱成功！最新余额为：%0.2f元。\n",(*acc).balance);
	return 1;
}

int draw(struct account *acc)
{
	int errn=0;
	float n;
	printf("当前账户余额为：%0.2f元。\n",(*acc).balance);
	printf("请输入您要取款数额:");
	while(1)
	{
		scanf("%f",&n);
		if(n>=(*acc).balance || (int)n%100!=0)//取钱不能超额，只能取100面值。
		{
			printf("输入金额有误！请重新输入！");
			errn++;
			if(errn>=5)
			{
				printf("输入错误过多！谢谢使用，再见！\n");
				return 0;
			}
		}
		else
		{
			(*acc).balance-=n;
			printf("取钱成功！最新余额为：%0.2f元。\n",(*acc).balance);
			return 1;
		}
	}

}

int transfer(struct account *acc1,struct account *acc2)  ///转账函数 acc1-->acc2.    暂时实现指定的两个账户的转账。
{
	double money;
	char ok;
	printf("请输入转入金额：");
	scanf("%lf",&money);
	if(money>(*acc1).balance)
	{	
		printf("账户余额不够！\n");
		return 0;
	}
	printf("请再次核对你要转入的账号信息：\n");
	printf("账户号码：%s\n",(*acc2).id);
	printf("账户名称：%s\n",(*acc2).name);
	Sleep(5000);								//需要转出者观察5秒
	printf("确认转入账户信息：Y OR N :");
	getchar();
	scanf("%c",&ok);
	if(ok!='Y' && ok!='y')
	{
		printf("取消转账！\n");
		return 0;
	}
	(*acc1).balance-=money;
	(*acc2).balance+=money;
	printf("转账成功！\n");
	return 1;
}

void show(struct account acc)
{
	printf("账号信息如下：\n");
	printf("账户号码：%s\n",acc.id);
	printf("账户名称：%s\n",acc.name);
	printf("账户余额：%lf\n",acc.balance);
	Sleep(3000);
}