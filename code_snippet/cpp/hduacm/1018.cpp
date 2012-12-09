////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: fengzishen
////Nickname: shen
////Run ID: 
////Submit time: 2008-02-16 01:54:48
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1018
////Problem Title: 
////Run result: Accept
////Run time:437MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n,num;
	cin>>n;
	for(int i = 0; i < n; i++)
	{
		cin>>num;
		double bits = 0;
		for(float j = 1; j <= num; j++)
		{
			bits += log10(j);
		}
		cout<<(int)(bits)+1<<endl;
	}

	return 0;
}
