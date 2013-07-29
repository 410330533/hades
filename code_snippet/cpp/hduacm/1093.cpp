#if 0
// date: 2012-07-29 21:26:00
#include <stdio.h>

int main()
{
	int lines, n, num[80], sum;
	scanf("%d", &lines);
	while (lines-- > 0)
	{
		scanf("%d", &n);
		sum = 0;
		for (int i=0; i<n; i++)
		{
			scanf("%d", &num[i]);
			sum += num[i];
		}
		printf("%d\n", sum);
	}
}
#endif