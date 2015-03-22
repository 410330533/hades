////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: fengzishen
////Nickname: shen
////Run ID: 
////Submit time: 2008-02-16 22:36:45
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1021
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;

int main()
{
	int n;   
	while(cin>>n)
	{
		n = (n + 1) % 4;
		if(n == 3)
		{
			cout<<"yes"<<endl;
		}
		else
		{
			cout<<"no"<<endl;
		}
	}
	return 0;
}