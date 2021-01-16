# define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>


//汉诺塔问题
void move(char c1, char c2)
{
	printf("%c -> %c\n", c1, c2);  //%c用于输出 字符，%s用于输出 字符串
}

void hanoi(int n, char x, char y, char z)
{
	if (1 == n)
		move(x, z);
	else
	{
		hanoi(n - 1, x, z, y);
		move(x, z);
		hanoi(n - 1, y, x, z);
	}
}
int main()
{
	int n = 0;
	printf("请输入盘数：");
	scanf("%d", &n);
	char a = 'a';
	char b = 'b';
	char c = 'c';
	hanoi(n,a,b,c);
	      //a柱，b柱，c柱
	return 0;
}

//    
////int Fib(int n)
////{
////	if (n <= 2)
////		return 1;
////	else  //可以计算，但是做了大量重复的计算，效率慢了，考虑  迭代
////		return Fib(n - 1) + Fib(n - 2);
////}
//
//
//int Fib(int n)
//{
//	//1   1   2    3    5    8    13  ....
//	//a   b   c 
//	//用前两项的和去迭代计算
//	int a = 1;
//	int b = 1;
//	int c = 1;   //考虑到n<=2时，都是返回1，所以初始化为 1 ，而不是0。
//	while (n > 2)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//		n--;
//	}
//	return c;
//}
//int main()
//{
//	//计算第n个斐波那契数列
//	int n = 0;
//	scanf("%d", &n);
//	int ret = 0;
//	ret = Fib(n);
//	printf("%d\n", ret);
//	return 0;
//
//
////循环的方式
////int Fac1(int n)
////{
////	int i = 0;
////	int ret = 1;
////	for (i = 1; i <= n; i++)
////	{
////		ret *= i;
////	}
////	return ret;
////}
//
////递归的方式
////int Fac2(int n)
////{
////	if (n <= 1)
////		return 1;
////	else
////		return n * Fac2(n - 1);
////}
////int main()
////{
////	//计算n的阶乘。
////	int n = 0;
////	scanf("%d", &n);
////	int ret = 0;
////	ret = Fac2(n);
////
////	printf("%d\n", ret);
////	return 0;
//}
