#if 0
// date: 2012-07-29 21:19:00
#include <stdio.h>

int main()
{
	int n, sum;
	int num[80];
	scanf("%d", &n);
	while (n != 0)
	{
		int i;
		for (i=0; i<n; i++)
		{
			scanf("%d", &num[i]);
		}
		sum = 0;
		for (i=0; i<n; i++)
		{
			sum += num[i];
		}
		printf("%d\n", sum);
		
		scanf("%d", &n);
	}
}
#endif