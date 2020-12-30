# define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <assert.h>

//方法一：暴力解决问题，直接一个个交换的
//void left_move(char* arr, int k)
//{
//	assert(arr != NULL);
//	int len1 = strlen(arr);
//	//k决定交换几个字符，即就是循环几次
//	int i = 0;
//	for (i = 0; i < k; i++)
//	{
//		char tmp = *arr;  //存储第一个元素
//		int j = 0;
//		for (j = 0; j < len1 - 1; j++)
//			*(arr + j) = *(arr + j + 1);
//		*(arr + len1 - 1) = tmp;
//	}
//}

//方法二：三步翻转法  
//例如：ab cdef  翻转2个
//第一步：ba cdef
//第二步：ba fedc
//第三步：整体全部翻转 得到fedcba

//void reserve(char* left, char* right)
//{
//	assert(left != NULL);
//	assert(right != NULL);
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		right--;
//		left++;
//	}
//}

//void left_move(char* arr, int k)
//{
//	assert(arr != NULL);
//	int len = strlen(arr);
//	assert(k <= len); //保证翻转的数值不能大于整个字符串
//	reserve(arr, arr + k - 1);//逆序翻转第一步，传入地址即可
//	reserve(arr + k, arr + len - 1);//逆序翻转第二步
//	reserve(arr, arr + len - 1);//逆序翻转第三步
//}

//int main()
//{
//	char arr[] = "abcdef";
//	left_move(arr, 3);
//	printf("%s\n", arr);
//	return 0;
//}

//int is_left_move(char* s1, char* s2)
//{
//	//每翻转一次就与原字符串进行比较即可----比较的次数就是该字符串的长度
//	int len = strlen(s1);
//	int i = 0;
//	for (i = 0; i < len; i++)
//	{
//		left_move(s2, 1);  //一次次的翻转再比较
//		int a = strcmp(s1, s2);  //如果字符串相等就会返回0
//		if (a == 0)
//			return 1;
//	}
//	return 0;
//}
//
//int main()
//{
//	//比较arr2是不是arr1翻转得来的
//	char arr1[] = "abcdef";
//	char arr2[] = "cdefab";
//
//	int ret = is_left_move(arr1, arr2);
//	if (ret == 1)
//		printf("Yes\n");
//	else
//		printf("No\n");
//
//	return 0;
//}






//方法三：运用库函数

//int is_left_move(char* str1, char* str2)
//{
//	//库函数 strcat，strncat，strstr
//
//	//1. 追加字符串
//	int len1 = strlen(str2);
//	int len2 = strlen(str1);
//	if (len1 != len2)
//		return 0;
//	strncat(str1, str1, len1);
//
//	//2. strstr函数--返回的是元素地址
//	char* ret = strstr(str1, str2);
//	if (ret != NULL)
//		return 1;
//	else
//		return 0;
//}
//
//int main()
//{
//	char arr1[30] = "abcdef";
//	char arr2[] = "defab";
//
//	int ret = is_left_move(arr1, arr2);
//	if (ret == 1)
//		printf("Yes\n");
//	else
//		printf("No\n");
//
//	return 0;
//}





//int Findnum(int arr[3][3], int row, int col, int k)
//{
//	int x = 0;
//	int y = col - 1;//确定矩阵中右上角的那个元素地址
//
//	while (x <= row - 1 && y >= 0)
//	{
//		if (arr[x][y] > k)
//			y--;
//		else if (arr[x][y] < k)
//			x++;
//		else
//			return 1;//找到了
//	}
//	return 0;
//}

int Findnum(int arr[3][3], int* px, int* py, int k)
{
	int x = 0;
	int y = *py - 1;//确定矩阵中右上角的那个元素地址

	while (x <= *px - 1 && y >= 0)
	{
		if (arr[x][y] > k)
			y--;
		else if (arr[x][y] < k)
			x++;
		else
		{
			*px = x;
			*py = y;
			return 1;//找到了
		}
			
	}
	return 0;
}
//杨氏矩阵问题--查找该矩阵中的数，时间复杂度为O(N)
int main()
{
	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
	int x = 3;
	int y = 3;
	int k = 7;//需要查找的数
	//int ret = Findnum(arr, 3, 3, k);
	//返回型函数
	int ret = Findnum(arr, &x, &y, k);
	if (ret == 1)
		printf("找到了,下标是%d ，%d\n", x, y);
	else
		printf("找不到\n");
	return 0;
}

