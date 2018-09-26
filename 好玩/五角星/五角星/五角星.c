#include <stdio.h>
int main()
{
int a[15][37]={0};
int i,j;
a[0][18]=1;
for(j=17;j<20;j++)
a[1][j]=1;
for(j=16;j<21;j++)
a[2][j]=1;
for(j=15;j<22;j++)
a[3][j]=1;
for(j=14;j<23;j++)
a[4][j]=1;
for(j=1;j<36;j++)
a[5][j]=1;
for(j=4;j<33;j++)
a[6][j]=1;
for(j=7;j<30;j++)
a[7][j]=1;
for(j=10;j<27;j++)
a[8][j]=1;
for(j=12;j<25;j++)
a[9][j]=1;
for(j=11;j<26;j++)
a[10][j]=1;
for(j=10;j<18;j++)
a[11][j]=1;
for(j=19;j<27;j++)
a[11][j]=1;
for(j=9;j<15;j++)
a[12][j]=1;
for(j=22;j<28;j++)
a[12][j]=1;
for(j=8;j<12;j++)
a[13][j]=1;
for(j=25;j<29;j++)
a[13][j]=1;
for(j=7;j<9;j++)
a[14][j]=1;
for(j=28;j<30;j++)
a[14][j]=1;
a[15][6]=1,a[15][31]=1;
for(i=0;i<15;i++)
{
for(j=0;j<37;j++)
if(a[i][j]==1) printf("*");
else printf(" ");
printf("\n");
}
return 0; 
}