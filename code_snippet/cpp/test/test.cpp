/************************************************************************/
/* 冒泡排序                                                             */
/************************************************************************/
#if 0
#include <iostream>
using namespace std;
int main()
{
	int n;
	int num[81];
	cin>>n;
	for (int i=0; i<n; i++)
	{
		cin>>num[i];
	}
	for (int i=0; i<n-1; i++)
	{
		for (int j=0; j<n-i-1; j++)
		{
			if (num[j] > num[j+1])
			{
				int temp = num[j+1];
				num[j+1] = num[j];
				num[j] = temp;
			}
		}
	}
	for (int i=0; i<n; i++)
	{
		cout<<num[i]<<" ";
	}
	return 0;
}
#endif

/************************************************************************/
/* 选择排序                                                             */
/************************************************************************/
#if 0
#include <iostream>
using namespace std;
int main()
{
	int n;
	int num[81];
	cin>>n;
	for (int i=0; i<n; i++)
	{
		cin>>num[i];
	}
	for (int i=0; i<n-1; i++)
	{
		int k = i;
		for (int j=i+1; j<n; j++)
		{
			if (num[j] < num[k])
			{
				k = j;
			}
		}
		int temp = num[k];
		num[k] = num[i];
		num[i] = temp;
	}
	for (int i=0; i<n; i++)
	{
		cout<<num[i]<<" ";
	}
	return 0;
}
#endif

/************************************************************************/
/* 取出字符串中的汉字                                                   */
/************************************************************************/
#if 0
#include <iostream>
using namespace std;
int main()
{
	char s[81] = "Microsoft 微软公司 Computer\n 杭州分公司";
	char c[81];
	int i,j = 0;
	for (i=0; s[i] != '\0'; i++)
	{
		if ((s[i] & 0xff80) == 0xff80)	//汉字由两个字符组成，每个字符的最高位为1，而西文字符的最高位为0
		{
			c[j++] = s[i];
		}
	}
	c[j] = '\0';
	puts(c);
	return 0;
}
#endif

/************************************************************************/
/* Map Example                                                          */
/************************************************************************/
#if 0
#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int main()
{
	map<int,string> ages; 
	map<int,string>::iterator iter;
	ages[1] = "help"; 
	ages[2] = "print"; 
	ages[3] = "exit";  
	ages[4] = "insert"; 
	ages[5] = "copy"; 
	ages[6] = "modify"; 
	ages[7] = "query"; 
	ages[8] = "delete"; 
	//cout << "Bart is " << ages["Bart"] << " years old" << endl;
	for (iter = ages.begin(); iter != ages.end(); iter++)
	{
		cout<<"int = "<<iter->first<<" , const char* = "<<iter->second<<endl;
	}
	ages.insert(map<int,string>::value_type(9,"jacky"));
	ages.insert(make_pair(10,"makepair"));
	cout<<"=============================="<<endl;
	for (iter = ages.begin(); iter != ages.end(); iter++)
	{
		cout<<"int = "<<iter->first<<" , const char* = "<<iter->second<<endl;
	}
	cout<<"=============================="<<endl;
	iter--;
	cout<<"now iter = "<<iter->first<<" "<<iter->second<<endl;
	cout<<"ages size = "<<ages.size()<<endl;
	iter = ages.upper_bound(5);
	cout<<iter->first<<" "<<iter->second<<endl;

	return 0;
}
#endif

/************************************************************************/
/* Map Example                                                          */
/************************************************************************/
#if 0
#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

int iArray[5] = { 1, 2, 3, 4, 5 };

void Display(list<int>& v, const char* s);

int main()
{
	list<int> iList;

	// Copy iArray backwards into iList
	copy(iArray, iArray + 5, back_inserter(iList));
	Display(iList, "Before find and copy");

	// Locate value 3 in iList
	list<int>::iterator p =
		find(iList.begin(), iList.end(), 3);

	// Copy first two iArray values to iList ahead of p
	copy(iArray, iArray + 2, inserter(iList, p));
	Display(iList, "After find and copy");

	return 0;
}

void Display(list<int>& a, const char* s)
{
	cout << s << endl;
	copy(a.begin(), a.end(),
		ostream_iterator<int>(cout, " "));
	cout << endl;
}
#endif

/************************************************************************/
/* Map Example                                                          */
/************************************************************************/
#if 0
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	string a = "spoon";
	map<string,int> stringCounts;  
	string str;  
	while(cin>>str) 
	{
		stringCounts[str]++;  
	}
	map<string,int>::iterator iter = stringCounts.find(a); 
	if( iter != stringCounts.end() ) 
	{  
		cout << "You typed '" << iter->first << "' " << iter->second << " time(s)" << endl; 
	}
	for (iter = stringCounts.begin(); iter != stringCounts.end(); iter++)
	{
		cout<<iter->first<<" , "<<iter->second<<endl;
	}

	return 0;
}
#endif

/************************************************************************/
/* Factory Mode                                                         */
/************************************************************************/
#if 0
#include <iostream>
#include <string>
using namespace std;

class People
{
public:
	string sex;
	virtual ~People() {}
	virtual void say() 
	{
		cout<<"I'm a people..."<<endl;
	}
};

class Boy : public People
{
public:
	Boy() { sex = "male"; }
	void say()
	{
		cout<<"I'm a boy..."<<endl;
	}
};

class Girl : public People
{
public:
	Girl() { sex = "female"; };
	void say()
	{
		cout<<"I'm a girl..."<<endl;
	}
};

class Factory
{
public:
	string people;
	People* ppeople;
	People* ProducePeople()
	{
		cout<<"============================================="<<endl;
		cout<<"What do you want?"<<endl<<"a boy or a girl?...[quit] to quit"<<endl;
		while (cin>>people)
		{
			if (!this->people.compare("boy"))
			{
				ppeople = new Boy();
				return ppeople;
			}
			else if (!this->people.compare("girl"))
			{
				ppeople = new Girl();
				return ppeople;
			}
			else if (!this->people.compare("quit"))
			{
				ppeople = NULL;
				return NULL;
			}
			else
			{
				cout<<"you enter wrong..."<<endl;
				ppeople = NULL;
				return NULL;
			}	
		}
		return NULL;
	}
};

int main()
{
	Factory fac;
	while (true)
	{
		fac.ProducePeople();
		if (fac.ppeople != NULL)
		{
			fac.ppeople->say();
		}
		if (!fac.people.compare("quit"))
		{
			break;
		}
		fac.ppeople = NULL;
	}

	return 0;
};
#endif

/************************************************************************/
/* Builder Mode                                                         */
/************************************************************************/
#if 0
#include <iostream>
#include <string>
#include <map>
using namespace std;
class MmCommon
{
public:
	virtual void say()
	{
		cout<<"common language..."<<endl;
	}
};

class MmChina : public MmCommon
{
public:
	void say()
	{
		cout<<"我爱你..."<<endl;
	}
};

class MmAmerica : public MmCommon
{
	void say()
	{
		cout<<"I love you..."<<endl;
	}
};

int main()
{
	map<string,MmCommon*> mmlist;
	map<string,MmCommon*>::iterator mmlist_iter;
	MmCommon mmcommon;
	MmAmerica mmamerica;
	MmChina mmchina;
	mmlist["commonlanguage"] = &mmcommon;
	mmlist["china"] = &mmchina;
	mmlist["america"] = &mmamerica;

	cout<<"please enter the nationality...[quit] to quit..."<<endl;
	string country;
	while (cin>>country)
	{
		bool flag = true;
		if (!country.compare("quit"))
		{
			flag = false;
		}
		if (flag == false)
		{
			break;
		}
		mmlist_iter = mmlist.find(country);
		if (mmlist_iter != mmlist.end())
		{
			mmlist_iter->second->say();
		}
		else
		{
			cout<<"not this nationality found..."<<endl<<"common language..."<<endl;
			mmlist_iter = mmlist.begin();
			mmlist_iter->second->say();
		}
	}
	return 0;
}
#endif

/************************************************************************/
/* Singleton Mode                                                       */
/************************************************************************/
#if 0
#include <iostream>
using namespace std;
class Singleton
{
private:
	int n;
	Singleton(int n) { this->n = n; }
public:
	int GetN() { return n; }
	void SetN(int n) { this->n = n; }
	static Singleton* GetInstance();
	void Display()
	{
		cout<<"n = "<<n<<endl;
	}
	void Connection()
	{
		cout<<"Connection...Connected..."<<endl;
	}
	void DisConnection()
	{
		cout<<"Disconnection..."<<endl;
	}
};

class SingletonConn
{
public:
	SingletonConn()
	{
		Singleton::GetInstance()->Connection();
	}
	~SingletonConn()
	{
		Singleton::GetInstance()->DisConnection();
	}
	void DisplaySingleton()
	{
		Singleton::GetInstance()->Display();
	}
};

Singleton* Singleton::GetInstance()
{
	static Singleton* instance = NULL;
	if (instance != NULL)
	{
		return instance;
	}
	instance = new Singleton(5);
	return instance;
}

int main()
{
	Singleton::GetInstance()->Display();
	//Singleton::GetInstance()->Display();
	SingletonConn sc;
	sc.DisplaySingleton();
	return 0;
}
#endif

/************************************************************************/
/* 深度遍历                                                             */
/************************************************************************/
#if 0
#include <iostream>
using namespace std;

int MAXDEPTH;
int num[100];

int G(int dep)
{
	int i;
	if (dep == M)
	{
		for (i=0; i<MAXDEPTH; i++)
		{
			printf("%d", num[i]);
		}
		printf("\n");
	}
	else
	{
		for (i=0; i<=9; i++)
		{
			num[dep] = i;
			G(dep+1);
		}
	}
	return 0;
}

int main()
{
	scanf("%d",&M);//M = 3;
	G(0);
	return 0;
}
#endif

/************************************************************************/
/* struct                                                               */
/************************************************************************/
#if 0
#include <iostream>
using namespace std;
typedef struct Google
{
	int x;
	int y;
	int pos;
}google, *pgoogle;
int main()
{
	Google g;
	g.pos = 5;
	g.x = 3;
	g.y = 4;
	google g1;
	g1.pos = 1;
	g1.x = 2;
	g1.y = 3;
	pgoogle pg = &g;
	pg->pos = 7;
	pg->x = 8;
	pg->y = 9;
	cout<<g.pos<<endl<<g.x<<endl<<g.y<<endl;
	return 0;
}
#endif

/************************************************************************/
/* getopt处理命令行参数                                                 */
/************************************************************************/
#if 0
#include "getopt.h"
#include <iostream>
using namespace std;

int main(int argc,char** argv)
{
	int c = 0;
	if (argc < 2)
	{
		return 0;
	}

	while ((c = getopt(argc,argv,"hd")) != EOF)
	{
		switch (c)
		{
		case 'h':
			cout << "帮助信息" << endl;
			cout << endl;
			cout << "	-h			命令行选项说明" << endl;
			cout << "	-d			以诊断模式运行" << endl;
			continue;

		case 'd':
			cout << "正在以诊断模式运行" << endl;
			break;

		default:
			cout<<endl<< "命令行选项错误，请使用 -h 选项获取帮助信息" << endl;
			continue;
		}
	}

	return 0;
}
#endif

/************************************************************************/
/* 函数参数缺省值                                                       */
/************************************************************************/
#if 0
#include <iostream>
using namespace std;

void sayHello(int x, int n = 5);

void sayHello(int x,int n)
{
	for (int i=0; i<n; i++)
	{
		cout<<"hello : "<<x<<endl;
	}
}

int main()
{
	sayHello(3,3);
	return 0;
}
#endif

/************************************************************************/
/* 函数内联                                                             */
/************************************************************************/
#if 0
/** 关键字inline必须和函数定义体放在一起才能使函数成为内联，仅将inline放在函数声明前面不起任何作用 */
/** 定义在类声明之中的成员函数将自动地成为内联函数 */
void Foo(int x, int y);
inline void Foo(int x, int y)
{
	/** ... */
}
#endif

/************************************************************************/
/* va_list使用                                                          */
/************************************************************************/
#if 0
#include <iostream>
#include <string>
#include <stdarg.h>
using namespace std;

string Format(const char* fmt,...)
{
	char buffer[1024];
	va_list ap;

	va_start(ap,fmt);
	vsnprintf(buffer,sizeof(buffer),fmt,ap);
	va_end(ap);

	return buffer;
}

int main()
{
	string str = Format("%s = %d","zhejiang",15);
	cout<<"str = "<<str<<endl;
	return 0;
}
#endif

/************************************************************************/
/* va_list                                                              */
/************************************************************************/
#if 0
#include <stdio.h>
#include <stdarg.h>
double sum(int,...);
int main()
{
	double s = sum(3,1.1,2.5,13.3);
	double t = sum(6,1.1,2.1,13.1,4.1,5.1,6.1);
	printf("return value for ""sum(3,1.1,2.5,13.3): %g\n",s);
	printf("return value for ""sum(6,1.1,2.1,13.1,4.1,5.1,6.1): %g\n",t);
	return 0;
}
double sum(int lim,...)
{
	va_list ap;				//va_list类型数据可以保存函数的所有参数，作为一个列表一样保存
	double total = 0;
	va_start(ap,lim);		//设置列表的起始位置
	for (int i = 0; i < lim; i++)
	{
		total += va_arg(ap,double);		//返回maker列表的当前值，并指向列表的下一位置
	}
	va_end(ap);
	return total;
}
#endif

/************************************************************************/
/* macro                                                                */
/************************************************************************/
#if 0
#include <iostream>
using namespace std;

#define P(A) cout<<#A<<":"<<(A)<<endl;

int main()
{
	int a = 1, b = 2, c = 3;
	P(a);
	P(b);
	P(c);
	P((c-a)/b);
	return 0;
}
#endif

/************************************************************************/
/* 位字段                                                               */
/************************************************************************/
#if 0
#include <iostream>
#include <string.h>
using namespace std;

enum STATUS { FullTime, PartTime };
enum GRADLEVEL { UnderGrad, Grad };
enum HOUSING { Dorm, offCampus };
enum FOODPLAN { OneMeal, AllMeals, WeekEnds, NoMeals };

class student
{
public:
	student():
	  myStatus(FullTime),myGradLevel(UnderGrad),myHousing(Dorm),myFoodPlan(NoMeals)
	  {
	  }
	  ~student()
	  {
	  }
	  STATUS GetStatus();
	  void SetStatus(STATUS);
	  unsigned GetPlan() { return myFoodPlan; }

private:
	unsigned myStatus : 1;
	unsigned myGradLevel : 1;
	unsigned myHousing : 1;
	unsigned myFoodPlan : 2;	
};

STATUS student::GetStatus()
{
	if (myStatus)
		return FullTime;
	else
		return PartTime;
}

void student::SetStatus(STATUS theStatus)
{
	myStatus = theStatus;
}

int main()
{
	student Jim;

	if (Jim.GetStatus() == PartTime)
		cout<<"Jim is Part-Time"<<endl;
	else
		cout<<"Jim is Full-Time"<<endl;

	Jim.SetStatus(PartTime);

	if (Jim.GetStatus())
		cout<<"Jim is Part-Time"<<endl;
	else
		cout<<"Jim is Full-Time"<<endl;

	cout<<"Jim is on the ";

	char Plan[80];
	switch (Jim.GetPlan())
	{
	case OneMeal: strcpy(Plan, "One Meal"); break;
	case AllMeals: strcpy(Plan, "All Meals"); break;
	case WeekEnds: strcpy(Plan, "Weekend Meals"); break;
	case NoMeals: strcpy(Plan, "No Meals"); break;
	default:cout<<"Something bad went wrong!"<<endl; break;
	}

	cout<<Plan<<" food plan."<<endl;
	return 0;
}
#endif

/************************************************************************/
/* operator类类型自动转换                                               */
/************************************************************************/
#if 0
#include <iostream>
using namespace std;

class Jacky
{
public:
	Jacky(int data)
	{
		this->data = data;
	}
	operator int()
	{
		return data;
	}
	int data;
};

int main()
{
	Jacky j(12);
	cout<<"class = "<<j<<endl;
	
	return 0;
}
#endif

/************************************************************************/
/* 辗转相除法(欧几里德算法)--最大公约数                                 */
/************************************************************************/
#if 0
#include <iostream>
using namespace std;

int euclid(int m, int n)
{
    int r;
    do{
        r=m%n;
        m=n;
        n=r;
    } while(r);
    return m;
}

int main()
{
	int ret = euclid(9,12);
	cout<<"公约数 = "<<ret<<endl;

	cout<<"end..."<<endl;
	return 0;
}
#endif

/************************************************************************/
/* 更相减损术--最大公约数                                               */
/************************************************************************/
#if 0
#include <iostream>
using namespace std;

int gcd(int m, int n)
{
	int temp = 0;
	int min = 0;
	while(m != n)
	{
		temp = abs(m - n);
		min = m<n ? m : n;
		m = temp;
		n = min;
	}
	return m;
}

int main()
{
	int ret = gcd(9,12);
	cout<<"公约数 = "<<ret<<endl;

	cout<<"end..."<<endl;
	return 0;
}
#endif

/************************************************************************/
/* CPU一直50%                                                           */
/************************************************************************/
#if 0
#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
	int i = 0;
	while (true)
	{
		if (i < 5000000)
		{
			i++;
		}
		else
		{
			i = 0;
			Sleep(10);
		}
	}
	return 0;
}
#endif

#if 0
#include <iostream>
#include <Windows.h>
using namespace std;
int main()
{
	int busyTime = 10;
	int idleTime = busyTime;

	INT64 startTime = 0;
	while (true)
	{
		startTime = GetTickCount();
		while (GetTickCount() - startTime <= busyTime)
		{
			;
		}
		Sleep(idleTime);
	}
	return 0;
}
#endif

/************************************************************************/
/* CPU正弦曲线                                                          */
/************************************************************************/
#if 0
#include <iostream>
#include <windows.h>
#include <math.h>
using namespace std;

const double SPLIT = 0.01;
const int COUNT = 200;
const double PI = 3.14159265;
const int INTERVAL = 300;

int main()
{
	DWORD busySpan[COUNT];
	DWORD idleSpan[COUNT];
	int half = INTERVAL / 2;
	double radian = 0.0;
	for (int i=0; i<COUNT; i++)
	{
		busySpan[i] = (DWORD)(half + (sin(PI * radian) * half));
		idleSpan[i] = INTERVAL - busySpan[i];
		radian += SPLIT;
	}

	DWORD startTime = 0;
	int j = 0;
	while (true)
	{
		j = j % COUNT;
		startTime = GetTickCount();
		while ((GetTickCount() - startTime) <= busySpan[j])
		{
			;
		}
		Sleep(idleSpan[j]);
		j++;
	}
	return 0;
}
#endif

/************************************************************************/
/* Longest-Common-Subsequence(LCS最长公共子串)                          */
/************************************************************************/
#if 0
#include <iostream>
using namespace std;

void print_LCS(char b[][7], char p1[], int p1_len, int p2_len);

int main()     
{ 
	char p1[8] = "0BDCABA";
	char p2[9] = "0ABCBDAB";

	char c[8][7] = {};
	char b[8][7] = {};

	for (int j=0; j<7; j++)
	{
		c[0][j] = '0';
	}
	for (int i=0; i<8; i++)
	{
		c[i][0] = '0';
	}

	for (int i=1; i<8; i++)
	{
		for (int j=1; j<7; j++)
		{
			if (p1[j] == p2[i])
			{
				c[i][j] = c[i-1][j-1] + 1;
				b[i][j] = '*';
			}
			else
			{
				if (c[i-1][j] >=  c[i][j-1])
				{
					c[i][j] = c[i-1][j];
					b[i][j] = '|';
				}
				else if (c[i-1][j] < c[i][j-1])
				{
					c[i][j] = c[i][j-1];
					b[i][j] = '-';
				}
			}
		}
	}

	cout<<"c[i][j]:"<<endl;
	for (int i=0; i<8; i++)
	{
		for (int j=0; j<7; j++)
		{
			cout<<c[i][j]<<"    ";
		}
		cout<<endl;
	}
	cout<<"b[i][j]:"<<endl;
	for (int i=0; i<8; i++)
	{
		for (int j=0; j<7; j++)
		{
			cout<<b[i][j]<<"    ";
		}
		cout<<endl;
	}

	/** 输出LCS(逆序输出) */
	//int i = 7, j = 6;
	//while (i != 0 && j != 0)
	//{
	//	if (b[i][j] == '*')
	//	{
	//		cout<<p1[j]<<" ";
	//		i--;
	//		j--;
	//	}
	//	else if (b[i][j] == '|')
	//	{
	//		i--;
	//	}
	//	else if (b[i][j] == '-')
	//	{
	//		j--;
	//	}
	//}

	/** 输出LCS(递归，顺序输出) */
	print_LCS(b,p1,7,6);

	return   0; 
} 

void print_LCS(char b[][7], char p1[], int p1_len, int p2_len)
{
	if (p1_len == 0 || p2_len == 0)
	{
		return;
	}
	if (b[p1_len][p2_len] == '*')
	{
		print_LCS(b,p1,p1_len - 1,p2_len - 1);
		cout<<p1[p2_len]<<" ";
	}
	else if (b[p1_len][p2_len] == '|')
	{
		print_LCS(b,p1,p1_len-1,p2_len);
	}
	else if (b[p1_len][p2_len] == '-')
	{
		print_LCS(b,p1,p1_len,p2_len-1);
	}
}

#endif

/************************************************************************/
/*strcpy                                                                */
/************************************************************************/
#if 0
char* customeStrcpy(char* strDest, char* strSrc)
{
	if (strDest == NULL || strSrc == NULL)
	{
		return NULL;
	}
	char* address = strDest;
	while ((*strDest = *strSrc) != '\0')
	{
		strDest++;
		strSrc++;
	}
	return address;
}
#endif

/************************************************************************/
/* CustomeString                                                        */
/************************************************************************/
#if 0

class CustomeString
{
public:
	CustomeString(const char* str = NULL);
	CustomeString(const CustomeString& other);
	~CustomeString();
	CustomeString& operator=(const CustomeString& other);
private:
	char* m_data;
};

CustomeString::CustomeString(const char *str)
{
	if (str == NULL)
	{
		m_data = new char[1];
		*m_data = '\0';
	}
	else
	{
		int len = strlen(str);
		m_data = new char[len + 1];
		strcpy(m_data,str);
		m_data[len] = '\0';
	}
}

CustomeString::CustomeString(const CustomeString& other)
{
	int len = strlen(other.m_data);
	m_data = new  char[len + 1];
	strcpy(m_data,other.m_data);
	m_data[len] = '\0';
}

CustomeString& CustomeString::operator = (const CustomeString& other)
{
	if (this == &other)
	{
		return *this;
	}
	delete [] m_data;
	int len = strlen(other.m_data);
	m_data = new char[len + 1];
	strcpy(m_data,other.m_data);
	return *this;
}

CustomeString::~CustomeString()
{
	delete [] m_data;
}

#endif

/************************************************************************/
/* 0-1背包问题(枚举法)                                                  */
/************************************************************************/
#if 0
#include <iostream>
#include <math.h>
using namespace std;
#define MAX 100

void conversion(int num, int ret[MAX])
{
	for (int i=0; i<MAX; i++)
	{
		ret[i] = num % 2;
		num /= 2;
		if (num == 0)
		{
			break;
		}
	}
}

int main()
{
	int temp_weight = 0;
	int temp_value = 0;
	int n = 10;//物品个数
	int limitWeight = 124;//限重
	int weight[MAX] = {21,23,12,23,12,78,45,33,123,23};//重量
	int value[MAX] = {23,24,45,4,54,5,65,6,5,76};//价值
	int binaryNum[MAX];
	int temp[MAX];
	for (int i=0; i<MAX; i++)
	{
		binaryNum[i] = 0;
		temp[i] = 0;
	}
	int maxWeight = 0;
	int maxValue = 0;
	for (int i=0; i<pow(2.0,n); i++)
	{
		temp_weight = 0;
		temp_value = 0;
		conversion(i,binaryNum);
		for (int j=0; j<n; j++)
		{
			if (binaryNum[j] == 1)
			{
				temp_weight += weight[j];
				temp_value += value[j];
			}
		}
		if (temp_weight <= limitWeight && temp_value > maxValue)
		{
			maxValue = temp_value;
			for (int j=0; j<n; j++)
			{
				temp[j] = binaryNum[j];
			}
		}
	}

	for (int i=0; i<n; i++)
	{
		if (temp[i] == 1)
		{
			maxWeight += weight[i];
		}
	}
	cout<<"the max weight = "<<maxWeight<<endl;
	cout<<"the max value = "<<maxValue<<endl;
	
	for (int i=0; i<n; i++)
	{
		cout<<temp[i]<<" , ";
	}
	cout<<endl;

	return 0;
}
#endif

/************************************************************************/
/* 0-1背包问题(贪婪算法)                                                  */
/************************************************************************/
#if 0
#include <iostream>
using namespace std;
#define MAX 100
int main()
{
	int n = 10;//物品个数
	int limitWeight = 124;//限重
	int weight[MAX] = {21,23,12,23,12,78,45,33,123,23};//重量
	int value[MAX] = {23,24,45,4,54,5,65,6,5,76};//价值
	int valueDivWeight[MAX] = {0};
	//算出性价比最高的
	for (int i=0; i<n; i++)
	{
		valueDivWeight[i] = value[i] / weight[i];
	}
	//1.0-1背包
	//2.部分背包

	return 0;
}
#endif

/************************************************************************/
/* test                                                                 */
/************************************************************************/
#if 1
#include "test.h"
#include "animal.h"
#include <stdio.h>

int main(int argc, char** argv)
{
	printf("hell world \n");
	return 0;
}

#endif