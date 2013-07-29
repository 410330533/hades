#if 0
// date: 2012-07-28 23:41:00
#include <stdio.h>

int main()
{
	int n = 0, sum = 0;
	while (scanf("%d", &n) != EOF)
	{
		sum = 0;
		for (int i=1; i<=n; i++)
		{
			sum += i;
		}
		printf("%d\n\n", sum);
	}
}
#endif