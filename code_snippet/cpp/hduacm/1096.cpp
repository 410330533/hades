////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: fengzishen
////Nickname: shen
////Run ID: 
////Submit time: 2007-10-17 01:13:41
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1096
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include"iostream"
using namespace std;
int main()
{
	int n,m,list[100],sum;
	sum=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>m;
		for(int j=0;j<m;j++)
		{
			cin>>list[i];
			sum=sum+list[i];
		}
		if(i==n-1)
		{
			cout<<sum<<endl;
		}
		else
		{
			cout<<sum<<endl<<endl;
		}
		sum=0;
	}
	return true;
}