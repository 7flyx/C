# define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>


int main()
{

	int arr[] = { 1,3,45,67,4,367,8,9,0,20 };
	int i;
	int n = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (i = 0; i < sz; i++)
	{
		if (arr[n] < arr[i])
		{
			int tmp = n;
			n = arr[i];
			arr[i] = tmp;
		}
	}
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}



//int main()
//{
//	int num1, num2;
//	char n;
//	printf("注意!注意！仅限于四大运算！\n");
//	printf("请输入两个数值，请注意先后顺序！！！\n");
//	printf("请输入:>");
//	scanf("%d%d", &num1, &num2);
//	getchar();
//	printf("请输入运算符:>");
//	scanf("%c", &n);
//	
//	if (n == '+')
//	{
//		printf("%d + %d = %d\n", num1, num2, num1 + num2);
//	}
//	else if (n == '-')
//	{
//		printf("%d - %d = %d\n", num1, num2, num1 - num2);
//	}
//	else if (n == '*')
//	{
//		printf("%d * %d = %d\n", num1, num2, num1 * num2);
//	}
//	else
//	{
//		printf("%d / %d = %d\n", num1, num2, num1 / num2);
//	}
//	return 0;
//}
//
////
////int main()
////{
////	int num;
////	printf("请输入数值:>");
////	scanf("%d", &num);
////	if (num % 2 == 1)
////	{
////		printf("%d是奇数！\n", num);
////	}
////	else
////	{
////		printf("%d是偶数！\n", num);
////	}
////	return 0;
////}
//
////int main()
////{
////	char arr[] = { 'A','E','I','O','U','a','e','i','o','u' };
////	char n;
////	int i;
////	printf("请输入字母:>");
////	scanf("%c", &n);
////	for (i = 0; i < 10; i++)
////	{
////		if (n == arr[i])
////		{
////			printf("%c是元音字母！\n", n);
////			break;
////		}
////	}
////	if (10 == i)
////	{
////		printf("%c不是元音字母！\n",n);
////	}
////	return 0;
////}
