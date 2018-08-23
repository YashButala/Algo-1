#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    int n;
    char* s[20];
}cell;
void sort(cell* a,int n)
{
    int tmp[100],i;
    for(i=0;i<100;i++)
    {
        tmp[i]=0;
    }
    for(i=0;i<n;i++)
        tmp[a[i].n]++;
    int sum=0;
    for(i=0;i<100;i++)
    {
        sum+=tmp[i];
        tmp[i]=sum;
    }
    cell b[n];printf("hi\n");
    for(i=n-1;i>=0;i--)
    {
        b[tmp[a[i].n]].n=a[i].n;
        strcpy(b[tmp[a[i].n]].s,a[i].s);
        tmp[a[i].n]--;
    }
    for(i=0;i<n;i++)
        printf("%s ",b[i].s);
    return b;
}
int main()
{
    int n;
    scanf("%d",&n);
    cell a[n];
    int t,i;
    char* s;
    for( i=0;i<n;i++)
    {
        scanf("%d%s",&t,s);
        if(i<n/2)
        {
            a[i].n=t;
            strcpy(a[i].s,"-");    
        }
        else
        {    
            a[i].n=t;
            strcpy(a[i].s,s);
        }    
    }
    sort(a,n);
    return 0;
}