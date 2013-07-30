#if 0
// date: 2012-07-30 20:41:00
#include <stdio.h>

int main()
{
	int n, tmp, sum;
	while (scanf("%d", &n) != EOF)
	{
		sum = 0;
		for (int i=0; i<n; i++)
		{
			scanf("%d", &tmp);
			sum += tmp;
		}
		printf("%d\n", sum);
	}
}
#endif