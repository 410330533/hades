////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: fengzishen
////Nickname: shen
////Run ID: 
////Submit time: 2007-10-16 21:11:47
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1008
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	int time,up,down,pos,n,list[100];
	cin>>n;
	while(n!=0)
	{
		for(int i=0;i<n;i++)
		{
			cin>>list[i];
		}

		time=0;
		pos=0;
		for(int i=0;i<n;i++)
		{
			if(list[i]>pos)
			{
				up=list[i]-pos;
				time=time+up*6+5;
				pos=list[i];
			}
			else if(list[i]<pos)
			{
				down=pos-list[i];
				time=time+down*4+5;
				pos=list[i];
			}
			else
			{
				time=time+5;
			}
		}
		cout<<time<<endl;
		cin>>n;
	}
	return true;
}