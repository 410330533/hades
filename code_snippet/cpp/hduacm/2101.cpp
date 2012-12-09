////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: fengzishen
////Nickname: shen
////Run ID: 
////Submit time: 2007-10-18 01:41:52
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2101
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:100KB
//////////////////System Comment End//////////////////
#include"iostream"
using namespace std;
int main()
{
	int a,b,sum;
	sum=0;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		sum=a+b;
		if(sum%86==0)
		{
			cout<<"yes"<<endl;
		}
		else
		{
			cout<<"no"<<endl;
		}
		sum=0;
	}
	return true;
}