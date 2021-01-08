# define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>



int main()
{
	int count = 0;
	int year = 0;
	for (year = 1000; year <= 2000; year++)
	{
		/*1.能被4整除 且不能被100整除的是闰年
		2.能被400整除的是闰年*/
		
		if (year % 4 == 0 && year % 100 != 0)
		{
			printf("%d ", year);
			count++;
		}
		else if (year % 400 == 0)
		{
			printf("%d ", year);
			count++;
		}

	}
	printf("\ncount=%d\n", count);

	return 0;
}


//int main()
//{
//	int m = 0;
//	int n = 0;
//	int r = 0;
//	scanf("%d%d", &m, &n);
//
//	while (m % n)
//	{
//		r = m % n;   //辗转相处法
//		m = n;
//		n = r;
//	}
//	printf("最大公因数:%d\n", n);
//	return 0;
//}



//int main()
//{
//	//从小到大的顺序输出
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	scanf("%d%d%d", &a, &b, &c);//2  1  3
//	//算法实现----按顺序重新赋值给a,b,c即可
//	//a中放最大值，b次之，c最小
//
//	if (a < b)
//	{
//		int tmp = a;//创建临时变量，让原来a的值不丢失
//		a = b;    //b赋值给a
//		b = tmp;
//	}
//	if (a < c)
//	{
//		int tmp = a;
//		a = c;
//		c = tmp;
//	}
//	if (b < c)
//	{
//		int tmp = b;
//		b = c;
//		c = tmp;
//	}
//	printf("%d %d %d\n", a, b, c);
//	return 0;
//}


//int bin_search(int arr[], int left, int right, int key)
//{
//	int mid = 0;
//	while (left <= right)
//	{
//		mid = (left + right) >> 1;
//		if (arr[mid] > key)
//		{
//			right = mid - 1;
//		}
//		else if (arr[mid] < key)
//		{
//			left = mid + 1;
//		}
//		else
//			return mid;//找到了，返回下标
//	}
//	return -1;//找不到
//}


//
//int main()
//{
//	int i = 0;
//	char password[20] = { 0 };
//	
//
//	for (i = 0; i < 3; i++)
//	{
//		scanf("%s", password);
//		if (strcmp(password, "123456") == 0)//两个字符串判断是否相等，不能用‘==’
//		{//strcmp，是库函数<string.h>,用于比较两个字符串是否相等
//			//如果相等，返回0.    如果前者大于后者，返回大于0的数字，如果前者小于后者，返回小于0的数字
//			printf("登陆成功!\n");
//			break;
//		}
//		if (i < 2)
//		{
//			printf("密码错误，请重新输入!\n");
//		}
//	}
//	if (i == 3)
//	{
//		printf("登陆失败，请稍后再试\n");
//	}
//	return 0;
//}
//
////int main()
////{
////	char arr1[] = "hello world";
////	char arr2[] = "***********";
////
////	int left = 0;
////	int right = strlen(arr2) - 1;
////
////	while (left <= right)
////	{
////		arr2[left] = arr1[left];
////		arr2[right] = arr1[right];
////		Sleep(1000);//引用头文件<windows.h>
////		system("cls");//执行系统命令的一个函数-cls-清空屏幕，引用头文件<stdlid.h>
////		left++;
////		right--;
////		printf("%s\n", arr2);
////	}
////	return 0;
////}
////
////
//
////二分查找算法
////int main()
////{
////	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
////	int k = 9;//对象
////
////	int left = 0;//左下标
////	int right = sizeof(arr) / sizeof(arr[0]) - 1;//右下标
////	
////	while (left <= right)
////	{
////		int mid = (left + right) / 2;//二分
////		if (arr[mid] < k)
////		{
////			left = mid + 1;
////		}
////		else if (arr[mid] > k)
////		{
////			right = mid - 1;
////		}
////		else
////		{
////			printf("找到了，下标是%d\n", mid);
////			break;
////		}
////		if (left > right)		
////			printf("对不起，找不到\n");
////		
////
////	}
////
////	return 0;
////}