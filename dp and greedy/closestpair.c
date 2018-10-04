#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct _point
{
	float x,y;
}point;
void mergex(point a[],int low ,int mid,int high)
{
    int i=low,j=mid+1;
    int k=0;
    point b[high-low+1];
    while(i<=mid&&j<=high)
    {
        if(a[i].x>a[j].x)
        {
            b[k]=a[j];
            j++;
            k++;
        }
        else
        {
            b[k]=a[i];
            i++;
            k++;
        }
    }
    while(i<=mid)
    {
        b[k]=a[i];
        i++;
        k++;
    }
    while(j<=high)
    {
        b[k]=a[j];
        j++;
        k++;
    }
    for(i=low,k=0;i<=high;i++,k++)
    {
        a[i]=b[k];
    }
    return ;
}
void xsort(point a[],int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        xsort(a,low,mid);
        xsort(a,mid+1,high);
        mergex(a,low,mid,high);
    }
}
void mergey(point a[],int low ,int mid,int high)
{
    int i=low,j=mid+1;
    int k=0;
    point b[high-low+1];
    while(i<=mid&&j<=high)
    {
        if(a[i].y>a[j].y)
        {
            b[k]=a[j];
            j++;
            k++;
        }
        else
        {
            b[k]=a[i];
            i++;
            k++;
        }
    }
    while(i<=mid)
    {
        b[k]=a[i];
        i++;
        k++;
    }
    while(j<=high)
    {
        b[k]=a[j];
        j++;
        k++;
    }
    for(i=low,k=0;i<=high;i++,k++)
    {
        a[i]=b[k];
    }
    return ;
}
void ysort(point a[],int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        ysort(a,low,mid);
        ysort(a,mid+1,high);
        mergey(a,low,mid,high);
    }
}
float dist(point a,point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
float closestrlpair(point strip[],int n,int d)
{
	int i,j;
	float min=d;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n&&strip[j].y-strip[i].y<d;j++)
		{
			if(dist(strip[i],strip[j])<min)
			
				min=dist(strip[i],strip[j]);
			printf("%f\n",dist(strip[i],strip[j]));	
		}
	}
	return min;
}
float closestpair(point x[],point y[],int l,int r)
{
	if (r-l==1)
	{
		return dist(x[l],x[r]);
	}
	else if(r-l==2)
	{
		float d1,d2,d3;
		d1=dist(x[l],x[l+1]);
		d2=dist(x[l+2],x[l+1]);
		d3=dist(x[l],x[l+2]);
		d1=(d1<d2?d1:d2);
		d1=(d1<d3?d1:d3);
		return d3;
				
	}
	else
	{
		int i,mid=(l+r)/2,yl=0,yr=0;
		float X=x[mid].x;
		point *y_l,*y_r;
		y_l=(point*)malloc((mid-l+1)*sizeof(point));
		y_r=(point*)malloc((r-mid)*sizeof(point));
		for( i=0;i<=r-l;i++)
		{
			if(y[i].x<=X)
			{
				y_l[yl]=y[i];
				yl++;	
			}
			else
			{
				y_r[yr]=y[i];
				yr++;
			}
			
		}
		float d1=closestpair(x,y_l,l,mid);
		float d2=closestpair(x,y_r,mid+1,r);
		float d=(d1>d2?d2:d1);
		int n=0,j=0;
		for(i=0;i<=r-l;i++)
		{
			if(abs(y[i].x-X)<=d)
				n++;
		}
		point *strip=(point*)malloc(sizeof(point)*n);
		for(i=0;i<=r-l;i++)
		{
			if(abs(y[i].x-X)<=d)
			{
				strip[j]=x[i];
				j++;
			}
		}		
		float d3=closestrlpair(strip,n,d);
		d3=(d3>d?d:d3);
		return d3;
	}
}
int main()
{ 
    point P[] = {{2.0, 3.0}, {12.0, 30.0}, {40, 50}, {5, 1}, {12, 10}, {3, 4}}; 
    point Q[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}}; 
    int n = sizeof(P) / sizeof(P[0]); 
    xsort(P,0,5);
    ysort(Q,0,5);
    printf("The smallest distance is %f", closestpair(P,Q,0,5)); 
    return 0; 
 
}
