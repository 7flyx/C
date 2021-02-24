# define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int a = 10;
	int b = 20;
	int max;
	
	max = (a > b ? a : b);//三目操作符;需注意？后面的a，b的顺序
	//前者条件成立，则输出？后第一位表达式，反之则输出第二位

	printf("max=%d\n", max);

	return 0;
}
//int Max(int x ,int y)
//{
//	if (x > y)
//		return x;
//	else
//		return y;
//}
//int main()
//{
//	int num1 = 89;
//	int num2 = 99;
//	int num3 = 39;
//	int max;
//
//	max = Max(Max(num1, num2), num3);//嵌套函数体
//	printf("max=%d\n", max);
//	return 0;
//}

//int main()
//{
//	int a = (int)3.141;//强制类型转换
//	printf("%d\n", a);
//	return 0;
//}
//int main()
//{
//	int a = 0;//4个字节，即为32个bit位
//	int b = ~a;
//	//原本a就是32个0，  00000000000000000000000000000000
//	//则~a就是32个1，   11111111  ，全部取反
//	//负数在存储时为二进制的补码
//
//	//补码：11111111111111111111111111111111
//	//反码：11111111111111111111111111111110   （补码减1得到）
//	//原码：10000000000000000000000000000001   （反码第一位数不变，其余取反）
//
//	printf("%d\n", b);//而打印时是原码，即需将补码进行转换打印
//	//int a = 10;
//	//int arr[] = { 1,2,3,4,5,6 };
//
//	//printf("%d\n", sizeof (a));
//	//printf("%d\n", sizeof(arr) / sizeof(arr[0]));//arr的使用需要圆括号 
//
//	//	return 0;
//}