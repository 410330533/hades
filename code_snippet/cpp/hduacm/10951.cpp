////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: fengzishen
////Nickname: shen
////Run ID: 
////Submit time: 2008-02-16 00:28:29
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1095
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;

int main()
{
	int a,b,sum;
	sum = 0;
	cin>>a>>b;
	do
	{
		sum = a + b;
		cout<<sum<<endl<<endl;
	}
	while(scanf("%d%d",&a,&b)!=EOF);

	return true;
}