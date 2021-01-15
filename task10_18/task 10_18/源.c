# define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <math.h>



int main()
{
	int c = 0;
	printf("请输入你的分数:");
	scanf("%d", &c);
	
	if (c >= 90)
	{
		printf("你的等级是%s\n", 'A');
	}
	else if (90 > c && c >= 80)
	{
		printf("你的等级是%s\n", 'B');
	}
	else if (80 > c && c >= 70)
	{
		printf("你的等级是%s\n", 'C');
	}
	else if (70 > c && c >= 60)
	{
		printf("你的等级是%s\n", 'D');
	}
	else
	{
		printf("你的等级是%s\n", 'E');
	}
	return 0;
}



//int Max(int x, int y)
//{
//	return (x > y ? x : y);
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = 30;
//	int max = Max(a, Max(b, c));
//	printf("max=%d\n", max);
//	return 0;
//}

//int sumber(int arr[],int k,int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	int mid = 0;
//
//	while (left <= right)
//	{
//		mid = (left + right) / 2;
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
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int k = 0;
//	scanf("%d", &k);  //所找的对象
//	int ret = sumber(arr, k, sz);
//	if (-1 == ret )
//	{
//		printf("对不起，该数组找不到！\n");
//	}
//	else
//	{
//		printf("找到了，该数的下标是%d\n", ret);
//	}
//	return 0;
//}

//int is_leap_year(int y)
//{
//	if ((y % 4 == 0 && y / 100 != 0) || (y % 400 == 0))
//	{
//		return 1;
//	}
//	return 0;
//}
//
//int main()
//{
//	int count = 0;
//	int year = 1000;
//	for (year = 1000; year <= 2000; year++)
//	{
//		int ret = 0;
//		ret = is_leap_year(year);
//		if (1 == ret)
//		{
//			printf("%d ", year);
//			count++;
//		}
//	}
//	printf("\ncount=%d\n", count);
//	return 0;
//}



//int is_prime(i)
//{
//	int j = 0;
//
//	for(j=2;j<=sqrt(i);j++)
//	{
//		if (i % j == 0)
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
//int main()
//{
//	int i = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		if (1 == is_prime(i))
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}