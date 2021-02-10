# define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>



int main()
{
	int i = 0;
	int n = 10;
	for (i = 0; i < n - 1; i++)
	{
		//一趟
		int j = 0;
		for (j = 0; j < n - 1 - i; j++)//越在后面，比较的对数越来越少
		{
			if (arr[j] < arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

//void Print1(int arr[3][5], int x, int y)//普通的变量名作为形参接收
//{
//	int i = 0;
//	for (i = 0; i < x; i++)
//	{
//		int j = 0;
//		for (j = 0; j < y; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//}
//void Print2(int(*p)[5], int x, int y)
//{
//	int i = 0;
//	for (i = 0; i < x; i++)
//	{
//		int j = 0;
//		for (j = 0; j < y; j++)
//		{
//			//printf("%d ", *(*(p + i) + j));
//			//先对这一行进行解引用，然后再加j，再进行解引用进行打印
//			printf("%d ", *(p[i] + j));
//			printf("%d ", p[i][j]);
//			//其实可以将此处想象为数组下标的访问方式
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int arr[3][5] = { {1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7} };
//	Print1(arr, 3, 5);
//	Print2(arr, 3, 5);
//	return 0;
//}