#include<iostream>	
using namespace std;
void ugly(int n)
{
	int *uglynumbers;
	uglynumbers=new int [n];
	uglynumbers[0]=1;
	int next2=2,next3=3,next5=5,i2=1,i3=1,i5=1;
	for(int i=1;i<n;i++)
	{
		uglynumbers[i]=min(next2,min(next3,next5));			
		if(uglynumbers[i]==next2)
		{
			next2=uglynumbers[i2]*2;
			i2++;
		}
		if(uglynumbers[i]==next3)
		{
			next3=uglynumbers[i3]*3;
			i3++;
		}
		if(uglynumbers[i]==next5)
		{
			next5=uglynumbers[i5]*5;
			i5++;
		}
		
	}
	for(int i=0;i<n;i++)
	{
		cout<<uglynumbers[i]<<endl;
	}
}
int main()
{
	int n;
	cin>>n;
	ugly(n);
}