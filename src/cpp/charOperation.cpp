/*******************************************************************************
* Function   : char *strcpy(char *dst, const char *src);
* Author     : jhlicfoocbar@gmail.com, remove foobar for email
* Description: A user defined implementation of C library strcpy.
******************************************************************************/
char *strcpy(char *dst, const char *src)
{
	char *p = dst;

	while (*dst++ = *src++) ;
	return p;
}

/*******************************************************************************
* Function   : char *strncpy(char *dst, const char *src, size_t n);
* Author     : jhlicfoocbar@gmail.com, remove foobar for email
* Description: A user defined implementation of C library strncpy.
******************************************************************************/
#include <stddef.h>
char *strncpy(char *dst, const char *src, size_t n)
{
	char *p = dst;

	while (n && (*dst++ = *src++)) n--;
	if (!n) *dst = '\0';
	return p;
}

/*******************************************************************************
* Function   : int strcmp(const char *s1, const char *s2);
* Author     : jhlicfoocbar@gmail.com, remove foobar for email
* Description: A user defined implementation of C library strcmp.
******************************************************************************/
int strcmp(const char *s1, const char *s2)
{
	for (; *s1 && *s1 == *s2; s1++, s2++) ;
	return *s1 - *s2;
}

/*******************************************************************************
* Function   : int strncmp(const char *s1, const char *s2, size_t n);
* Author     : jhlicfoocbar@gmail.com, remove foobar for email
* Description: A user defined implementation of C library strncmp.
******************************************************************************/
#include <stddef.h>
int strncmp(const char *s1, const char *s2, size_t n)
{
	for (; --n && *s1 && *s1 == *s2; s1++, s2++) ;
	return *s1 - *s2;
}

/*******************************************************************************
* Function   : size_t strlen(const char *p);
* Author     : jhlicfoocbar@gmail.com, remove foobar for email
* Description: A user defined implementation of C library strlen.
******************************************************************************/
#include <stddef.h>
size_t strlen(const char *p)
{
	size_t n = 0;

	while (*p++) n++;
	return n;
}

/*******************************************************************************
* Function   : void *memcpy(void *s, const void *s0, size_t n);
* Author     : jhlicfoocbar@gmail.com, remove foobar for email
* Description: Copy s0 to s, always copy n bytes. Return s.
******************************************************************************/
#include <stddef.h>
void *memcpy(void *s, const void *s0, size_t n)
{
	char *s1 = s;
	const char *s2 = s0;

	while (n--) *s1++ = *s2++;
	return s;
}

/*******************************************************************************
* Function   : void *memmove(void *s, const void *s0, size_t n);
* Author     : jhlicfoocbar@gmail.com, remove foobar for email
* Description: Copy s0 to s, always copy n bytes. Return s. Copying between
*              objects that overlap will take place correctly.
******************************************************************************/
#include <stddef.h>
void *memmove(void *s, const void *s0, size_t n)
{
	char *s1 = s;
	const char *s2 = s0;

	if (s1 <= s2)
		while (n--) *s1++ = *s2++;
	else {
		s1 += n, s2 += n;
		while (n--) *--s1 = *--s2;
	}
	return s;
}

/*******************************************************************************
* Function   : char *strstr(const char *str, const char *sub);
* Author     : jhlicfoocbar@gmail.com, remove foobar for email
* Description: A user defined implementation of C library strstr.
******************************************************************************/
char *strstr(const char *str, const char *sub)
{
	int i, j;

	for (i = 0; str[i]; i++){
		for (j = 0; sub[j]; j++)
			if (str[i + j] != sub[j]) break;
		if (!sub[j]) return &str[i];
	}
	return 0;
}

/*******************************************************************************
* Function   : int factorial(int n);
* Author     : jhlicfoocbar@gmail.com, remove foobar for email
* Description: Calculate factorial of a number.
******************************************************************************/
int factorial(int n)
{
	if (n == 0) return 1;
	else        return n * factorial(n - 1);
}

/*******************************************************************************
* Function   : char toupper(char low);
* Author     : jhlicfoocbar@gmail.com, remove foobar for email
* Description: A user defined implementation of C library toupper.
******************************************************************************/
char toupper(char low)
{
	return low >= 'a' && low <= 'z' ?
		low + 'A' - 'a' :
	low ;
}

/*******************************************************************************
* Function   : int isprime(unsigned n);
* Author     : jhlicfoocbar@gmail.com, remove foobar for email
* Description: Determine if n is prime, return non-zero if it is prime.
******************************************************************************/
int isprime(unsigned n)
{
	unsigned m;

	if (n <= 1) return 0;
	for (m = n - 1; m > 1; m--)
		if (!(n % m)) return 0;
	return 1;
}

/*******************************************************************************
* Function   : char *strrvs(char *p);
* Author     : jhlicfoocbar@gmail.com, remove foobar for email
* Date       : 2006.9
* Description: Reverse a string, e.g. from "9876543210" to "0123456789".
******************************************************************************/
char *strrvs(char *p)
{
	char *p1, *p2, ch;

	for (p1 = p; *(p1 + 1); p1++) ;
	for (p2 = p; p2 < p1; p2++, p1--)
		ch = *p2, *p2 = *p1, *p1 = ch;
	return p;
}

/*******************************************************************************
* Function   : char *compact(char *p);
* Author     : jhlicfoocbar@gmail.com, remove foobar for email
* Date       : 2007.9
* Description: Remove the same array elements except the first one from
*              adjacent elements, e.g.
*
* 011123333455666777789,  len: 21
* 0123456789,             len: 10
******************************************************************************/
char *compact(char *p)
{
	char *p1, *p2;

	for (p1 = p + 1; *p1; p1++)
		if (*(p1 - 1) == *p1){
			for (p2 = p1; *(p2 - 1); p2++)
				*(p2 - 1) = *p2;
			p1--;
		}
		return p;
}

/*******************************************************************************
* Function   : int *mtxrot1d(int *p, int n);
* Author     : jhlicfoocbar@gmail.com, remove foobar for email
* Date       : 2007.10.8
* Description: Rotate an n * n matrix of integers of any size whose length
*              equals to width by 90 degrees clockwise. 1d for 1 dimension
*              array version. e.g.
*
* for a 5 x 5 matrix:  |  for a 6 x 6 matrix:
*                      |
*  1  2  3  4  5       |   1  2  3  4  5  6
*  6  7  8  9 10       |   7  8  9 10 11 12
* 11 12 13 14 15       |  13 14 15 16 17 18
* 16 17 18 19 20       |  19 20 21 22 23 24
* 21 22 23 24 25       |  25 26 27 28 29 30
*                      |  31 32 33 34 35 36
* 21 16 11  6  1       |
* 22 17 12  7  2       |  31 25 19 13  7  1
* 23 18 13  8  3       |  32 26 20 14  8  2
* 24 19 14  9  4       |  33 27 21 15  9  3
* 25 20 15 10  5       |  34 28 22 16 10  4
*                      |  35 29 23 17 11  5
*                      |  36 30 24 18 12  6
*
******************************************************************************/
int *mtxrot1d(int *p, int n)
{
	int r, c, i;
	const int m = n % 2 ? n / 2 - 1 : (n - 1) / 2;
	const int k = n - 1;

	for (r = 0; r <= k / 2; r++)
		for (c = 0; c <= m; c++){
			i                           = *(p + n * r       + c    );
			*(p + n * r       + c    )  = *(p + n * (k - c) + r    );
			*(p + n * (k - c) + r    )  = *(p + n * (k - r) + k - c);
			*(p + n * (k - r) + k - c)  = *(p + n * c       + k - r);
			*(p + n * c       + k - r)  = i;
		}
		return p;
}

/*******************************************************************************
* Function   : void *mtxrot2d(void *mtx);
* Author     : jhlicfoocbar@gmail.com, remove foobar for email
* Date       : 2007.10.7
* Description: Rotate a matrix of integers of any size by 90 degrees colckwise
*              if its length equals to width, 2d for 2 dimensiln array version.
******************************************************************************/
#define MTXROT_SIZE 6 /* length or width of the matrix */
void *mtxrot2d(void *mtx)
{
	int (*p)[MTXROT_SIZE] = mtx;
	const int M = MTXROT_SIZE % 2 ? MTXROT_SIZE / 2 - 1 : (MTXROT_SIZE - 1) / 2;
	const int N = MTXROT_SIZE - 1;
	int r, c, i;

	for (r = 0; r <= N / 2; r++)
		for (c = 0; c <= M; c++){
			i               = p[r    ][c    ];
			p[r    ][c    ] = p[N - c][r    ];
			p[N - c][r    ] = p[N - r][N - c];
			p[N - r][N - c] = p[c    ][N - r];
			p[c    ][N - r] = i;
		}
		return p;
}

/*******************************************************************************
* Function   : char *wrdrvs(char *p);
* Author     : jhlicfoocbar@gmail.com, remove foobar for email
* Date       : 2007.10.4
* Description: Reverse order of space-separated words, e.g.
*              " hello  code   monkey    " becomes "    monkey   code  hello ".
*
* [ hello  code   monkey    ]
* [hello  code   monkey     ]
* [hell  code   monkey    o ]
* [hel  code   monkey    lo ]
* [he  code   monkey    llo ]
* [h  code   monkey    ello ]
* [  code   monkey    hello ]
* [ code   monkey     hello ]
* [code   monkey      hello ]
* [cod   monkey    e  hello ]
* [co   monkey    de  hello ]
* [c   monkey    ode  hello ]
* [   monkey    code  hello ]
* [  monkey     code  hello ]
* [ monkey      code  hello ]
* [monkey       code  hello ]
* [monke    y   code  hello ]
* [monk    ey   code  hello ]
* [mon    key   code  hello ]
* [mo    nkey   code  hello ]
* [m    onkey   code  hello ]
* [    monkey   code  hello ]
*
******************************************************************************/
char *wrdrvs(char *p)
{
	enum STATUS {SPC, NSPC, UNDEF} prestt = UNDEF;
	char *p1, *p2, *p3, ch;

	for (p1 = p; *p1; p1++)
		;
	p1--;
	for (p2 = p; p2 <= p1; p2++)
		if (*p2 != ' '){
			if (prestt == SPC)
				for (; p2 > p; p2--){
					ch = *(p2 - 1);
					for (p3 = p2; p3 <= p1; p3++)
						*(p3 - 1) = *p3;
					*--p3 = ch;
					p1--;
				}
				prestt = NSPC;
		} else if (*p2 == ' '){
			if (prestt == NSPC)
				for (; p2 > p; p2--){
					ch = *(p2 - 1);
					for (p3 = p2; p3 <= p1; p3++)
						*(p3 - 1) = *p3;
					*--p3 = ch;
					p1--;
				}
				prestt = SPC;
		}
		return p;
}

/*******************************************************************************
* Function   : void sort_sel(char *a, int l, int r);
* Author     : jhlicfoocbar@gmail.com, remove foobar for email
* Date       : 2007.10.15
* Description: Selection sort an array of intergers range between index l and
*              r in ascending order. e.g. sort "312" into "123".
******************************************************************************/
void sort_sel(int *a, int l, int r)
{
	int i, j, n;

	for (i = l; i < r; i++)
		for (j = i + 1; j <= r; j++)
			if (a[i] > a[j]){
				n = a[i];
				a[i] = a[j];
				a[j] = n;
			}
}

/*******************************************************************************
* Function   : void sort_bub(int *a, int l, int r);
* Author     : jhlicfoocbar@gmail.com, remove foobar for email
* Date       : 2007.10.16
* Description: Bubble sort an array of intergers range between index l and
*              r in ascending order. e.g. sort "312" into "123".
******************************************************************************/
void sort_bub(int *a, int l, int r)
{
	int i, n;

	for (; l < r; r--)
		for (i = l; i < r; i++)
			if (a[i] > a[i + 1]){
				n = a[i];
				a[i] = a[i + 1];
				a[i + 1] = n;
			}
}

/*******************************************************************************
* Function   : int search_bin(const int *a, int l, int r, int i);
* Author     : jhlicfoocbar@gmail.com, remove foobar for email
* Date       : 2007.10.15
* Description: Binary search a number in an ascending sorted array of integers
*              range between index l and r.
******************************************************************************/
int search_bin(const int *a, int l, int r, int i)
{
	int n;

	while (l <= r){
		n = (l + r) / 2;
		if (a[n] == i)
			return n;
		else if (a[n] > i)
			r = n - 1;
		else if (a[n] < i)
			l = n + 1;
	}
	return -1;
}

/*******************************************************************************
* Function   : struct node *list_rvs(struct node *p);
* Author     : jhlicfoocbar@gmail.com, remove foobar for email
* Date       : 2007.10.17
* Description: Reverse a single directional non-circle list. e.g.
*
*   p                               |                               p
*   |                               |                               |
* +-+-+    +---+    +---+    +---+  |  +---+    +---+    +---+    +-+-+
* | 1 + -> | 2 + -> | 3 + -> | 4 |  |  | 1 | <- + 2 | <- + 3 | <- + 4 |
* +---+    +---+    +---+    +---+  |  +---+    +---+    +---+    +---+
*
******************************************************************************/
extern struct node {int data; struct node *next;};
struct node *list_rvs(struct node *p)
{
	struct node *p1 = p, *p2 = p->next, *p3;

	while (p2){
		p3 = p2->next;
		p2->next = p1;
		p1 = p2;
		p2 = p3;
	}
	p->next = 0;
	p = p1;
	return p;
}

/*******************************************************************************
* Function   : unsigned bitcount(unsigned i);
* Author     : jhlicfoocbar@gmail.com, remove foobar for email
* Date       : 2007.11.6
* Description: Count the bit set in an integer.
*              eg. integer: 0x0110101f, bitcount: 8
******************************************************************************/
unsigned bitcount(unsigned i)
{
	unsigned cnt = 0, mask;

	for (mask = 0x1; mask; mask <<= 1)
		if ((mask & i) == mask)
			cnt++;
	return cnt;
}

/*******************************************************************************
* Function   : int max(int n1, int n2);
* Author     : jhlicfoocbar@gmail.com, remove foobar for email
* Date       : 2007.11.18
* Description: Determine the maximum of two integers. NOTE: This works on twos-
*              complement machines. It may involve undefined behavior and isn't
*              portable code. This is a perverse demonstration to such kind of
*              question, "how to compare two numbers without judgement and
*              library function calls, e.g.  if, :?, etc.".
******************************************************************************/
#include <limits.h>
int max(int n1, int n2)
{
	int a[2];

	a[0] = n1, a[1] = n2;
	return a[(unsigned)(a[0] - a[1]) >> sizeof *a * CHAR_BIT - 1];
}
#define MAX(N1, N2) (max((N1), (N2)))

/*******************************************************************************
* Function   : int ispalind(const char *s);
* Author     : jhlicfoocbar@gmail.com, remove foobar for email
* Date       : 2006.5.8
* Description: Determine if a string is palindromic. Return non-zero if s is
*              palindromic. e.g. a palindrome "A man, a plan, a canal, Panama!"
******************************************************************************/
#include <string.h>
#include <ctype.h>
int ispalind(const char *s)
{
	const char *r = s + strlen(s) - 1;

	for (; s < r; s++, r--){
		if (!isalnum(*s)){
			r++;
			continue;
		}
		if (!isalnum(*r)){
			s--;
			continue;
		}
		if (toupper(*s) != toupper(*r))
			return 0;
	}
	return 1;
}

/*******************************************************************************
* Function   : char *strrmv(char *s1, const char *s2);
* Author     : jhlicfoocbar@gmail.com, remove foobar for email
* Date       : 2007.11.27
* Description: Remove sub string s2 from s1.
******************************************************************************/
char *strrmv(char *s1, const char *s2)
{
	int i, j, w = 0, r = 0;

	for (i = 0; s1[i]; i++){
		for (j = 0; s2[j]; j++)
			if (s1[i + j] != s2[j]) break;
		if (!s2[j] && j){
			if (r) for (; r != i; s1[w++] = s1[r++]) ;
			else   w = i;
			r = i + j, i = r - 1;
		}
		if (r && !s1[i + 1])
			for (; r <= i + 1; s1[w++] = s1[r++]) ;
	}
	return s1;
}