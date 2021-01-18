# define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <math.h>

int is_prime(int arr[], int k, int sz)
{
	int left = 0;
	int right = sz - 1;

	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] > k)
		{
			right = mid - 1;
		}
		else if (arr[mid] < k)
		{
			left = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}



int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int k = 0;
	printf("请输入1--10内的数字:");
	scanf("%d", &k);
	int sz = sizeof(arr) / sizeof(arr[0]);
	
	if (-1 == is_prime(arr, k, sz))
	{
		printf("对不起，找不到！\n");
	}
	else
	{
		printf("找到了，下标是%d\n", is_prime(arr, k, sz));
	}
	return 0;
}



//int is_prime(int n)
//{
//	int i = 2;
//	for (i = 2; i <= sqrt(n); i++)
//	{
//		if (n % i == 0)
//			return 0;
//	}
//	return 1;
//}
//
//int main()
//{
//	int n = 0;
//	for (n = 100; n <= 200; n++)
//	{
//		if (1 == is_prime(n))
//			printf("%d ", n);
//
//	}
//	return 0;
//}




//void move(char c1, char c2)
//{
//	printf("%c -> %c\n", c1, c2);
//}
//
//
//void hanoi(int n, char x, char y, char z)
//{
//	if (1 == n)
//		move(x, z);
//	else
//	{
//		hanoi(n - 1, x, z, y);
//		move(x, z);
//		hanoi(n - 1, y, x, z);
//	}
//}
//
//int main()
//{
//	int n = 0;
//	printf("请输入盘子数：");
//	scanf("%d", &n);
//	char a = 'a';
//	char b = 'b';
//	char c = 'c';
//
//	hanoi(n, a, b, c);
//
//	return 0;
//}