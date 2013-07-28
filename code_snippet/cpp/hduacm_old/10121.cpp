////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: fengzishen
////Nickname: shen
////Run ID: 
////Submit time: 2008-02-15 23:46:37
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
	cout<<"n e"<<endl;
	cout<<"- -----------"<<endl;
	for( int n = 0; n < 10; n++ )
	{
		if( 0 == n )
		{
			e = 1;
			cout<<n<<" "<<e<<endl;
		}
		else if( 1 == n)
		{
			temp *= n;
			e += 1.0/temp;
			cout<<n<<" "<<e<<endl;
		}
		else if( 2 == n )
		{
			temp *= n;
			e += 1.0/temp;
			cout<<n<<" "<<e<<endl;
		}
		else
		{
			temp *= n;
			e += 1.0/temp;
			cout<<n<<" ";
			cout.setf(ios::fixed);
			cout.precision(9);
			cout<<e<<endl;
		}
	}
	return 0;
}