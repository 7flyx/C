# define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
int Is_num(int i, int j)
{
	if (j == 1 || j == i)
		return 1;
	else
		return Is_num(i - 1, j) + Is_num(i - 1, j - 1);
}

int main()
{
	int n, i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%5d", Is_num(i, j));
		}
		printf("\n");
	}
	return 0;
}