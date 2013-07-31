#if 0
// date: 2012-07-31 20:55:00
#include <stdio.h>

#define TRUE 1
#define FALSE 0

int is_leap_year(int year)
{
	if ((year % 4 ==0 && year % 100 != 0 ) || year % 400 == 0)
	{
		return TRUE;
	}

	return FALSE;
}

int main()
{
	int lines, y, n;
	scanf("%d", &lines);
	while (lines-- > 0){
		scanf("%d %d", &y, &n);

		if (TRUE == is_leap_year(y))
		{
			n--;
		}
		while(n > 0)
		{
			y++;
			if (TRUE == is_leap_year(y))
			{
				n--;
			}
		}
		printf("%d\n", y);
	}
}
#endif