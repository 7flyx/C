# define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


//int main()
//{
//	//计算a+aa+aaa+aaaa+aaaaa的值
//	int n, k; 
//	scanf("%d%d", &n, &k);
//	int sum = 0;
//	while (k)
//	{
//		sum += sum * 10 + n;
//		k--;
//	}
//	printf("%d\n", sum);
//	return 0;
//}


//猜数字游戏
//int main()
//{
//	int n = 0;
//	srand((unsigned int)time(NULL));
//	int s = rand() % 100 + 1;//生成随机数1-100之间
//	while (1)
//	{
//		printf("请猜数字：>");
//		scanf("%d", &n);
//		if (n > s)
//			printf("你猜大了！\n");
//		else if (n < s)
//			printf("你猜小了！\n");
//		else
//			break;	
//	}
//	printf("恭喜你，猜对了！\n");
//	return 0;
//}


//斐波那契数
//int main()
//{
//	int n, i;
//	scanf("%d", &n);
//	int a = 1;
//	int b = 1;
//	int c = 0;
//	if (n <= 2)
//	{
//		printf("1\n");
//	}
//	else
//	{
//		for (i = 0; i < n - 2; i++)
//		{
//			c = a + b;
//			a = b;
//			b = c;
//		}
//		printf("%d\n", c);
//	}
//	return 0;
//}



//编写一个函数实现n^k，使用递归实现
//int my_pow(int n, int k)
//{
//	if (k == 1)
//		return n;
//	else
//		return my_pow(n, k - 1) * n;
//}
//
//int main()
//{
//	int n = 0;
//	int k = 0;
//	scanf("%d%d", &n, &k);
//	
//	printf("%d\n", my_pow(n, k));
//	return 0;
//}



//写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和，
//例如，调用DigitSum(1729)，则应该返回1 + 7 + 2 + 9，它的和是19
//int DigitSum(int n)
//{
//	if (n < 10)
//		return n;
//	else
//		return DigitSum(n / 10) + (n % 10);
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d\n", DigitSum(n));
//	return 0;
//}




//编写一个函数 reverse_string(char * string)（递归实现）
//实现：将参数字符串中的字符反向排列。
//要求：不能使用C函数库中的字符串操作函数。
void reverse_string(char* string)
{
	//算法思想：计算出字符串的大小，将下标为0的元素与下标最后一个交换，然后指针++--
	int len = strlen(string);
	char* left = string;
	char* right = string + len - 1;
	while (left < right)
	{
		char tmp = *right;
		*right = *left;
		*left = tmp;
		left++;
		right--;
	}
}

int main()
{
	char arr[] = "abcedf";
	reverse_string(arr);
	printf("%s\n", arr);
	return 0;
}