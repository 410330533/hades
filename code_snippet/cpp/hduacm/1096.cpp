#if 0
// date: 2012-07-30 20:45:00
#include <stdio.h>

int main()
{
	int lines, n, tmp, sum;
	while (scanf("%d", &lines) != EOF)
	{
		for (int i=0; i<lines; i++)
		{
			sum = 0;
			scanf("%d", &n);
			for (int j=0; j<n; j++)
			{
				scanf("%d", &tmp);
				sum += tmp;
			}
			printf("%d\n", sum);
			if (i != lines - 1)
			{
				printf("\n");
			}
		}
	}
}
#endif