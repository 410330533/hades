////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: fengzishen
////Nickname: shen
////Run ID: 
////Submit time: 2007-10-17 00:50:05
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1094
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include"iostream"
using namespace std;
int main()
{
	int n,list[100],sum;
	sum=0;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
		{
			cin>>list[i];
			sum=sum+list[i];
		}
		cout<<sum<<endl;
		sum=0;
	}
	return true;
}