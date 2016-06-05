////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: fengzishen
////Nickname: shen
////Run ID: 
////Submit time: 2008-02-15 19:36:41
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1012
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;

int main()
{
	long temp = 1;
	double e = 0;
	cout<<"n e"<<endl<<"- -----------"<<endl;
	for(int i = 0;i <=9;i++)
	{
		if(i == 0)
		{
			e = 1;
			cout<<i<<" "<<e<<endl;
		}
		else if(i < 2)
		{
			e+=1.0/i;
			cout<<i<<" "<<e<<endl;
		}
		else if(i < 3)
		{
			e+=1.0/i;
			cout<<i<<" "<<e<<endl;
			temp *=i;
		}
		else
		{
			temp *= i;
			e+=1.0/temp;
			cout<<i<<" ";
			cout.setf(ios::fixed);
			cout.precision(9);
			cout<<e<<endl;
		}
	}
	return 0;
}
