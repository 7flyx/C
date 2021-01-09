# define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
//void test()
//{
//	//static 修饰局部变量
//	//局部变量的生命周期变长
//	//static  修饰全局变量
//	//改变了变量的作用域  -让这个静态的全局变量只能在该源文件内部使用
//	//static  修饰函数
//	//改变了函数的链接属性-----外部链接属性--》内部链接属性
//
//	static int a = 1;//a是一个静态的局部变量
//	a++;
//	printf("a=%d\n", a);
//}
//
//int main()
//{
//	int i = 0;
//	extern int g_val;//extern---声明外部符号的
//	printf("%d\n", g_val);
//	while (i < 5)
//	{
//		test();
//		i++;
//
//	}
//	return 0;
//}

//函数类型
int Max(int x, int y)
{
	if (x > y)
		return x;
	else
		return y;
}
//#define  定义宏
#define MAX(X,Y) (X>Y?X:Y)

int main()
{
	int a, b;
	a = 10;
	b = 20;
	//函数类型
	//int max = Max(a, b);
	//printf("max=%d\n", max);
	//宏类型  max=(a>b?a:b)
	max = MAX(a, b);
	printf("max=%d\n", max);

	return 0;
}

//int main()
//{
//	int a = 10;
//	int* p=&a;//---取a的地址
//	//有一种变量是用来存放地址的----指针变量
//	//  int*  是p的类型
//	printf("%p\n", &a);
//	printf("%p\n", p);
//	//打印出来的是16进制的地址
//	//%p 是用来打印地址的
//	*p = 20;//*_  表示  解引用操作符
//	//意思是将20赋值给a，即现在a=20
//	printf("a=%d\n", a);
//
//	return 0;
//}

//int main()
//{
//	char ch = 'w';
//	char* CH=&ch;
//	//*CH = 'a';注：定义的是什么类型，后面指针就是什么类型+*即可
//
//	printf("%c\n",ch);
//	return 0;
//}