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
//offsetof--�Ǽ���ƫ�����ĺ�
int main()
{
	printf("%d\n", offsetof(struct S, a));
	printf("%d\n", OFFSETOF(struct S, a));
	return 0;
}
