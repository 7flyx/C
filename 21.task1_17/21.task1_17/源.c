# define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
//
//struct s
//{
//	int n;
//	int arr[];//柔性数组，也叫伸缩性数组,在后期使用的时候，搭配malloc等函数进行使用
//}stu;
//
//int main()
//{
//	struct s* ps = (struct s*)malloc(sizeof(struct s) + 5 * sizeof(int));
//
//
//	free(ps);
//	return 0;
//}

//
//#include <stdio.h>
//struct str {
//    int len;
//    char s[0];
//};
//
//struct foo {
//    struct str* a;
//};
//
//int main(int argc, char** argv) {
//    struct foo f = { 0 };
//    if (f.a->s) {
//        printf(f.a->s);
//    }
//    return 0;
//}


struct S
{
	int n;
	int arr[];
	//柔性数组存在的意义
	// 1.与分开创建数组指针（int* arr）来说。 能够创建连续的内存空间，以供cpu的快速访问
	//可以想想CPU是如何在内存读取数据，CPU->寄存器->高速缓存区->内存->硬盘
};

int main()
{
	struct S* s = (struct S*)malloc(sizeof(struct S) + 10 * sizeof(int));
	int i = 0;
	s->n = 100;

	for (i = 0; i < 10; i++)
	{
		s->arr[i] = i;
		printf("%d ", s->arr[i]);
	}
	
	return 0;
}