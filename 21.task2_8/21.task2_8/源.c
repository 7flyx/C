# define _CRT_SECURE_NO_WARNINGS 

#include <stddef.h>
#include <stdio.h>

struct S
{
	char a;
	int b;
	char c;
};

#define OFFSETOF(struct_name,memmer_name) (int)&(((struct_name*)0)->memmer_name)
//offsetof--是计算偏移量的宏
int main()
{
	printf("%d\n", offsetof(struct S, a));
	printf("%d\n", OFFSETOF(struct S, a));
	return 0;
}
