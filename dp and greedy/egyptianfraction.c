#include<stdio.h>
#include<math.h>
void frac(int nr,int dr)
{
	if(nr==0)
	{
		return ;
	}
	if(nr>dr)
	{
		printf("%d+",nr/dr);
		nr=nr-(nr/dr)*dr;
		return frac(nr,dr);
	}
	if(dr%nr==0)
	{	
		printf("1/%d",dr/nr);
		return ;
	}
/*	if(nr%dr==0)
	{
		printf("%d",nr/dr);
		return ;
	}*/
	else
	{
		int t=ceil((double)dr/(double)nr);
		printf("1/%d+",t);
		int tnr=nr*t-dr;
		int tdr=dr*t; 
		return frac(tnr,tdr);
	}
	
}
int main()
{
	int nr,dr;
	printf("enter numerator\n");
	scanf("%d",&nr);
	printf("enter denominater\n");
	scanf("%d",&dr);
	frac(nr,dr);
	return 0;
	
}
