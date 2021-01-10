# define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <math.h>


int main()
{
	int n = 0;
	printf("请输入正整数:");
	scanf("%d", &n);
	int count = 1;
	if (n < 10)
	{
		printf("该数值的位数为%d\n", 1);
	}
	else
	{
		while (n >= 10)
		{
			n = n / 10;
			count++;
		}
		printf("该数值的位数为%d\n", count);
	}
	return 0;
}

//int prime(int arr[], int k, int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			return mid;
//		}
//	}
//	return -1;
//}
//
//
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int k = 3;
//	int p = prime(arr, k, sz);
//
//	if (-1 == p)
//	{
//		printf("对不起，没找到！ \n");
//	}
//	else
//	{
//		printf("找到了，下标是%d\n", p);
//	}
//	return 0;
//}
//int prime(int x)
//{
//	int n = 2;
//	for (n = 2; n <= sqrt(x); n++)
//	{
//		if (x % n == 0)
//		{
//			return 0;
//		}
//	}
//	return x;
//}
//int main()
//{
//	int i = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		int j = 0;
//		j = prime(i);
//		if (0 == j)
//		{
//			;
//		}
//		else
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}
