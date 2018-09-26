
#include<stdio.h>
#include<math.h>
float mj(float x,float y,float z);
float judge(float u,float v,float w);
float main()
{
	float a,b,c,s;
	scanf("%f%f%f",&a,&b,&c);
	s=mj(a,b,c);
	printf("面积是:%f\n",s);
}

float mj(float x,float y,float z)
{
	float p,S;
	if(judge(x,y,z)==1)
	{
		p=(x+y+z)/2;
		S=sqrt(p*(p-x)*(p-y)*(p-z));
		return S;
	}
	else
	{
		printf("不能构成三角形\n");
		return 0;
	}

}

float judge(float u,float v,float w)
{
	if(u+v>w && u+w>v && v+w>u)
		return 1;
	else
		return 0;
}