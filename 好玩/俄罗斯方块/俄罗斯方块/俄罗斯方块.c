#include <windows.h>
#include <ctime>
#include <conio.h>
#include <cstdio>
const int back=30;
const int speed[]={0,12,9,6,3,1};
const int number[]={0,2,3,5,7,11,15};
const int col[]={11,15,12,12,13,13,14};
int rank=1;
int level=0; //0表示既不是向右也不是向左，1表示向左，2表示向右
int kind;     
int pri_kind;  // 7大类，颜色标记，调用col[col_kind];
int revolve=0; // 旋转状态标记
struct
{
    int x;
    int y;
}current,before;
struct
{
    int x;
    int y;
    int color;
    bool having;
}board[15][25];
struct
{
    int vary_x[4];
    int vary_y[4];
} vary[]={
    {{0, 2, 4, 6},{0, 0, 0, 0}},{{0, 0, 0, 0},{0,-1,-2,-3}},
    {{0, 2, 2, 0},{0, 0,-1,-1}},{{0,-2,-2,-4},{0 ,0,-1,-1}},
    {{0, 0, 2, 2},{0,-1,-1,-2}},{{0, 2, 2, 4},{0, 0,-1,-1}},
    {{0, 0,-2,-2},{0,-1,-1,-2}},{{0, 0, 2, 4},{0,-1, 0, 0}},
    {{0, 0, 0, 2},{0,-1,-2,-2}},{{0, 0,-2,-4},{0,-1,-1,-1}},
    {{0, 2, 2, 2},{0, 0,-1,-2}},{{0, 2, 4, 4},{0, 0, 0,-1}},
    {{0,-2,-2,-2},{0, 0,-1,-2}},{{0, 0, 2, 4},{0,-1,-1,-1}},
    {{0, 0, 0,-2},{0,-1,-2,-2}},{{0 ,2, 4, 2},{0, 0, 0,-1}},
    {{0, 0, 2, 0},{0,-1,-1,-2}},{{0,-2, 0, 2},{0,-1,-1,-1}},
    {{0, 0,-2, 0},{0,-1,-1,-2}},
};
struct
{
    int sum;
    int connection_x[5];
    int connection_y[5];
}connection[]={
    {2,{-2,2},{0,1}},
    {1,{0},{0}},
    {2,{2,-2},{0,0}},
    {2,{-2,2},{0,0}},
    {4,{-2,0,4,-2},{0,0,-1,1}},
    {4,{-4,2,-2,4},{0,0,-1,1}},
    {4,{-2,2,0,0},{0,0,0,0}},
};
void gotoxy(int x, int y)
{
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void color(int b)
{
    HANDLE hConsole = GetStdHandle((STD_OUTPUT_HANDLE)) ;
    SetConsoleTextAttribute(hConsole, b) ;
}
void PrintGarphy()
{
    color(1593);
    int i,j;
    gotoxy(2,2);
    for(i=0;i<26;i++)
        printf("▓");
    gotoxy(2,28);
    for(i=0;i<26;i++)
        printf("▓");
    for(i=0;i<26;i++)
    {
        gotoxy(2,2+i);
        printf("▓");
        gotoxy(34,2+i);
        if(i==8||i==16)
            printf("▓▓▓▓▓▓▓▓▓");
        else
            printf("▓");
        gotoxy(52,2+i);
        printf("▓");
    }
    int t;
    FILE *fp=fopen("C:\\els.txt","r");
    fscanf (fp,"%d",&t);
    fclose(fp);
    color(43);
    gotoxy(37,12);
    printf("最高纪录: %d",t);
    color(46);
    gotoxy(37,14);
    printf("当前得分: 0");
    color(44);
    gotoxy(37,16);
    printf("级数  ");
    color(39);
    gotoxy(37,20);
    printf(" ↑ ↓ ←  →");
    gotoxy(37,22);
    printf(" 按空格  暂停");
    gotoxy(37,24);
    printf(" 按 ESC  退出");
    gotoxy(37,26);
    printf(" 编写人  张祺");
    color(back);
    for(i=0;i<25;i++)
    {
        gotoxy(4,3+i);
        for(j=0;j<15;j++)
        printf("  ");
    }
}
void GameOver()
{
    color(391);
    for(int i=24;i>=0;i--)
        for(int j=0;j<15;j++)
        {
            gotoxy(32-j*2,3+i);
            printf("▆");
            Sleep(10);
        }
    color(back);
    for(int j=0;j<25;j++)
        for(int i=0;i<15;i++)
        {
            board[i][j].having=0;
            gotoxy(4+2*i,j+3);
            printf("  ");
            Sleep(10);
        }
    color(34);
    gotoxy(42,16);
    while(rank--)
        printf("  ");
    color(46);
    gotoxy(47,14);
    printf("   ");
}
void GetDepth(int *pdepth)
{
    (*pdepth)=24;
    for(int j=0;j<4;j++)
    {
        int sum=0;
        int n=(current.x+vary[kind].vary_x[j]-4)/2;
        int m=current.y+vary[kind].vary_y[j]-3;
        if(m<0) m=0;
        for(++m;m<25;m++)
            if(board[n][m].having==0&&n>=0&&n<15&&m>=0&&m<25)
                sum++;
            else
                break;
        if(sum<(*pdepth))
            (*pdepth)=sum;
    }
}
void CheckFull(int *pscore)
{
    int i,j;
    int sum=0;
    int s[]={0,1,3,6,10};
    for(i=0;i<25;i++)
    {
        bool mark=1;
        for(j=0;j<15;j++)
        {
            if(board[j][i].having==0)
            {
                mark=0;
                board[j][i].color=back;
            }
        }
        if(mark)
        {
            sum++;
            for(int t=i;t>0;t--)
            {
                gotoxy(4,3+t);
                for(j=0;j<15;j++)
                {
                    if(board[j][t-1].having)
                    {
                        color(board[j][t-1].color);
                        printf("▆");
                        board[j][t].color=board[j][t-1].color;
                        board[j][t].having=1;
                        board[j][t-1].having=0;
                    }
                    else
                    {
                        color(back);
                        printf("  ");
                        board[j][t].color=board[j][t].color;
                        board[j][t].having=0;
                        board[j][t-1].having=0;
                    }
                }
            }
        }
    }
    (*pscore)+=s[sum];
    color(46);
    gotoxy(47,14);
    printf("%d",*pscore);
    if(*pscore>=140) rank=5;
    else if(*pscore>=90) rank=4;
    else if(*pscore>=50) rank=3;
    else if(*pscore>=20) rank=2;
    else if(*pscore>=1)  rank=1;
    color(44);
    gotoxy(42,16);
    for(i=0;i<rank&&*pscore;i++)
        printf("★");
    int t;
    FILE *fp=fopen("C:\\els.txt","r");
    fscanf (fp,"%d",&t);
    fclose(fp);
    if(*pscore>t)
    {
        fp=fopen("C:\\els.txt","w");
        fprintf (fp,"%d",*pscore);
        fclose(fp);
        color(43);
        gotoxy(47,12);
        printf("%d",*pscore);
    }
    fclose(fp);
}
void PrintNext(int pkind)
{
    int i;
    int x=43,y=6;
    color(34);
    for(i=0;i<4;i++)
    {
        gotoxy(x-3,y+i-2);
        printf("        ");
    }
    pri_kind=pkind;
    if(pkind==6) pkind=15,x--;
    else if(pkind==5) pkind=11,x--;
    else if(pkind==4) pkind=7,x--;
    else if(pkind==3) pkind=5,x-=2;
    else if(pkind==2) pkind=3,x+=2;
    else if(pkind==1) pkind=2,x--;
    else  pkind=0,x-=3;
    color(col[pri_kind]);
    for(i=0;i<4;i++)
    {
        gotoxy(x+vary[pkind].vary_x[i],y+vary[pkind].vary_y[i]);
        printf("▆");
    }
}
void CheckBoundary()
{
    int i,n,m;
    for(i=0;i<4;i++)
    {
        m=current.x+vary[kind].vary_x[i];
        if(m<4||m>32)
        {
            current.x+=(m<4?2:-2);
            i=-1;
        }
    }
    for(i=0;i<4;i++) // 对四个方块分别检查
    {
        m=current.x+vary[kind].vary_x[i];
        n=current.y+vary[kind].vary_y[i];
        m=(m-4)/2;
        n-=3;
        if(n<0||n>24||board[m][n].having)
        {
            if(level==1)        // 左移
                current.x+=2;   //复原
            else if(level==2)    // 右移
                current.x-=2;  //复原
            level=0;
            break;
        }
    }
}
void LevelMove()
{
    CheckBoundary();
    if(level==0) return;
    int i;
    color(back);
    for(i=0;i<4;i++)
    {
        if(current.y+vary[kind].vary_y[i]>2)
        {
            gotoxy(before.x+vary[kind].vary_x[i],before.y+vary[kind].vary_y[i]);
            puts("  ");
        }
    }
    color(col[pri_kind]);
    for(i=0;i<4;i++)
    {
        if(current.y+vary[kind].vary_y[i]>2)
        {
            gotoxy(current.x+vary[kind].vary_x[i],current.y+vary[kind].vary_y[i]);
            puts("▆");
        }
    }
    before.x=current.x;
}
void Revolve(int **prev_count)  //旋转函数
{
    int i;
    before.x=current.x;
    before.y=current.y;
    (**prev_count)++;
    (**prev_count)%=connection[pri_kind].sum;
    current.x=current.x+connection[pri_kind].connection_x[**prev_count];
    current.y=current.y+connection[pri_kind].connection_y[**prev_count];
    CheckBoundary();
    for(i=0;i<4;i++)
    {
        int m=(current.x-4+vary[number[pri_kind]+**prev_count].vary_x[i])/2;
        int n=current.y+vary[number[pri_kind]+**prev_count].vary_y[i]-3;
        if(board[m][n].having||m>14||m<0||n>24)
        {
            current.x=current.x-connection[pri_kind].connection_x[**prev_count];
            current.y=current.y-connection[pri_kind].connection_y[**prev_count];
            revolve=0;
            (**prev_count)--;
            before.x=current.x;
            before.y=current.y;
            return ;
        }
    }
    color(back);
    for(i=0;i<4;i++)
    {
        if(before.y+vary[kind].vary_y[i]>2)
        {
            gotoxy(before.x+vary[kind].vary_x[i],before.y+vary[kind].vary_y[i]);
            puts("  ");
        }
    }
    kind=number[pri_kind]+**prev_count;
    color(col[pri_kind]);
    for(i=0;i<4;i++)
    {
        if(current.y+vary[kind].vary_y[i]>2)
        {
            gotoxy(current.x+vary[kind].vary_x[i],current.y+vary[kind].vary_y[i]);
            puts("▆");
        }
    }
    Sleep(speed[rank]);
    before.x=current.x;
    before.y=current.y;
}
void ChoiceDirection(int *prev_count)
{
    int t=50/rank;
    while(t--)
    {
        if(_kbhit())
        {
            char c=_getch();
            switch(c)
            {
            case 0x48:// up
                revolve=1;
                Revolve(&prev_count);
                break;
            case 0x50: //down
                level=0;
                return;
            case 0x4b: //left
                before.x=current.x;
                current.x-=2;
                level=1;
                LevelMove();
                break;
            case 0x4d:  //right
                before.x=current.x;
                current.x+=2;
                level=2;
                LevelMove();
                break;
            case ' ':
                _getch();
                break;
            case 27:
                color(back);
                exit(1);
            default:break;
            }
        }
        Sleep(speed[rank]);
    }
}
void StraightFall(int depth)
{
    int i;
    int rev_count=0;
    before.x=current.x;
    before.y=current.y;
    while(GetDepth(&depth),depth--)
    {
        ChoiceDirection(&rev_count);
        GetDepth(&depth);
        if(depth==0)
        {
            revolve=0;
            before.x=current.x;
            before.y=current.y;
            break;
        }
        color(back);
        for(i=0;i<4;i++)
        {
            if(before.y+vary[kind].vary_y[i]>2)
            {
                gotoxy(before.x+vary[kind].vary_x[i],before.y+vary[kind].vary_y[i]);
                puts("  ");
            }
        }
        current.y++;
        color(col[pri_kind]);
        for(i=0;i<4;i++)
        {
            if(current.y+vary[kind].vary_y[i]>2)
            {
                gotoxy(current.x+vary[kind].vary_x[i],current.y+vary[kind].vary_y[i]);
                puts("▆");
            }
        }
        revolve=0;
        before.x=current.x;
        before.y=current.y;
    }    
    ChoiceDirection(&rev_count);
    if(level||revolve)
    {
        level=0;
        revolve=0;
        ChoiceDirection(&rev_count);
        StraightFall(depth);  //递归调用
    }
}
int main()
{
    FILE *fp=fopen("c:\\123s\\a.c","w");
    srand((unsigned long)time(0));
    system("mode con cols=56 lines=30");
    system("color 24");
    int score=0;
    //FILE *
    fp=fopen("C:\\els.txt","r");
    if(fp==NULL)
    {
        fp=fopen("C:\\els.txt","w");
        fprintf (fp,"%d",score);
        fclose(fp);
    }
    PrintGarphy();
    kind=rand()%7;
    int depth;
    while(1)
    {
        int pkind=rand()%7;
        PrintNext(pkind);
        current.x=18;
        current.y=2;   // 方块初始出现的坐标
        GetDepth(&depth);   // 初始深度
        if(depth==0)
        {
            GameOver();
            score=0;
            rank=1;
        }
        pri_kind=kind;
        if(kind==6) kind=15,current.x-=2;
        else if(kind==5) kind=11;
        else if(kind==4) kind=7;
        else if(kind==3)  kind=5;
        else if(kind==2) kind=3,current.x+=2;
        else if(kind==1) kind=2;
        else  kind=0,current.x-=2;
        StraightFall(depth);
        for(int i=0;i<4;i++)
        {
            int m=(current.x-4+vary[kind].vary_x[i])/2;
            int n=current.y-3+vary[kind].vary_y[i];
            board[m][n].having=1;
            board[m][n].color=col[pri_kind];
        }
        CheckFull(&score);
        kind=pkind;
    }
    return 0;
} 