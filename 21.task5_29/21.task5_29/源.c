#define  _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <String.h>

int IsRotateString(char arr1[], char arr2[])
{
	//严谨一点话，该判断是否为NULL，C语言就不必了
	int len1 = strlen(arr1);
	int len2 = strlen(arr2);
	if (len1 != len2)
		return 0; //不一样长，直接返回0
	int rotateNum = 0;
	for (rotateNum = 0; rotateNum < len1; rotateNum++) //从0开始，万一没旋转呢
	{
		//拿到arr2数组中循环了rotateNum次数的字符进行比较
		int i = 0; //arr2的下标
		int j = 0; //arr1的下标
		for (i = rotateNum; j < len1; i = (++i + len1) % len1)
		{
			if (arr1[j] == arr2[i])
				j++;
			else
				break;
		}
		if (j == len1)
			return 1; //说明匹配上了
	}
	return 0; //上面循环完了，还么提前退出函数，就是没啦

}
int main()
{
	//循环队列，每次往前 前进一步，循环队列判断即可，字符串多长，就循环几次，时间复杂度O(N^2)
	char arr1[20] = { 0 };
	char arr2[20] = { 0 };
	printf("请输入主串:");
	gets(arr1);
	printf("请输入旋转子串:");
	gets(arr2);
	
	if (IsRotateString(arr1,arr2))
		printf("是该字符串的旋转子串\n");
	else
		printf("不是该字符串的旋转子串\n");
	return 0;
}



//void reverse(char arr[], int left, int right)
//{
//	while (left < right)
//	{
//		int tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//		right--;
//		left++;
//	}
//}
//int main()
//{
//	//左旋字符串
//	//解法一： 不改变原来字符串的存储顺序，用循环队列，旋转几次，就从第几个字符开始顺序访问，循环遍历一次即可
//	//解法二： 需要改变原来字符串的实际存储顺序
//	char arr[20] = { 0 };
//	gets(arr);
//
//	//解法一：循环队列
//	int len = strlen(arr);
//	int rotateNum = 0;
//	printf("请输入左旋转次数:");
//	scanf("%d", &rotateNum);
//	int i = 0;
//	for (i = 0; i < len; i++)
//	{
//		printf("%c ", arr[rotateNum]);
//		rotateNum = (++rotateNum + len) % len;
//	}
//	
//	//解法二：三步翻转法
//	//reverse(arr, 0, len - 1); //整个数组翻转
//	//reverse(arr, 0, len - 1 - rotateNum); //旋转左边
//	//reverse(arr, len - rotateNum, len - 1);
//	//for (i = 0; i < len; i++)
//	//	printf("%c ", arr[i]);
//
//	return 0;
//}






//int Find(int arr[][4], int row, int col, int targer)
//{
//	if (row == 4 || col == -1)
//		return -1; //没找到
//	if (arr[row][col] == targer)
//		return arr[row][col];
//	else if (arr[row][col] > targer)
//		return Find(arr, row, col - 1, targer);
//	else
//		return Find(arr, row + 1, col, targer);
//}
//
//int main()
//{
//	//杨氏矩阵
//	//从右上角看就是一颗二叉搜索树，左子树小于等于根，右子树大于等于根，递归的思想解决
//	int arr[4][4] = {
//		{1,2,8,9} ,
//		{2,4,9,12},
//		{4,7,10,13},
//		{6,8,11,15}
//	};
//	int row = 0; //行
//	int col = 3; //列
//	int targer = 7;//被查找数
//	int num = Find(arr, row, col,targer);
//	printf("num = %d\n", num);
//	return 0;
//}



//int main()
//{
//	//从问题的本质出发，共五人，每个人都有名词，每个人都在第一到第五的范围内，只能一个个尝试
//	int a, b, c, d, e;
//	for(a=1;a <= 5;a++)
//		for(b = 1; b <= 5; b++)
//			for(c = 1; c <= 5; c++)
//				for(d = 1; d <= 5; d++)
//					for(e = 1; e <= 5; e++)
//						if (((b == 2) + (a == 3) == 1)
//							&& ((b == 2) + (e == 4) == 1)
//							&& ((c == 1) + (d == 4) == 1)
//							&& ((c == 5) + (d == 3) == 1)
//							&& ((b == 4) + (a == 1) == 1)
//							&&(a*b*c*d*e == 120))
//						{
//							
//							printf("a=%d b=%d c=%d d=%d e=%d\n", a, b, c, d, e);
//						}
//
//	return 0;
//}




//int main()
//{
//	//判断嫌疑人
//	char killer = 0;
//	for (killer = 'A'; killer <= 'D'; killer++)
//	{
//		if ((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D') == 3)
//			printf("%c\n", killer);
//	}
//
//	return 0;
//}





//int triangle(int i, int j)
//{
//	if (j == 1 || i == j)
//		return 1;
//	return triangle(i - 1, j) + triangle(i - 1, j - 1);
//
//}
//
//int main()
//{
//	//打印杨辉三角，递归的角度
//	int n = 0;
//	scanf("%d", &n);
//	int i, j;
//	for (i = 1; i <= n; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf("%3d", triangle(i, j));
//		}
//		printf("\n");
//	}
//	return 0;
//}