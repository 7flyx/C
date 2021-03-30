# define _CRT_SECURE_NO_WARNINGS 


#include <stdio.h>


int main()
{

	int a = 3, b = 3, c = 2, d;
	printf("%d,", !a && !b && c);
	printf("%d,", !a || !b || c);
	printf("%d\n", a >= b && b > c);
	d = c-- || (b = 6) && a++;
	printf("a=%d,b=%d,c=%d,d=%d\n", a, b, c, d);

	return 0;
}
