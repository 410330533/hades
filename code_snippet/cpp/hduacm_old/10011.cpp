////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: fengzishen
////Nickname: shen
////Run ID: 
////Submit time: 2008-02-15 23:59:14
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1001
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main ()
{
	int i,j,n,sum;
	i=0;
	while(cin>>n)
	{	
		sum=0;
		for (j=1;j<=n;j++)
		{
			sum=sum+j;
		}
		cout<<sum<<endl<<endl;
		i++;
	}
	return 0;
}