# define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>

//int Insert_arr(int (*arr)[10], int size, int x)
//{
//	int i, j;
//	for (i = size - 1; i >= 0; i--)
//	{
//		//判断x是否小于元素arr[i]，成立的话，就插入
//		if (x <= *(*(arr + i)) && *(*(arr + i))!= 0)
//		{
//			//插入
//			*(*(arr + i)) = x;
//			return 1;
//		}
//		else
//		{
//			//元素往后移
//			*(*(arr + i + 1)) = *(*(arr + i));
//		}
//	}
//	return 0;
//}

int Insert_arr(int ps[10], int size, int x)
{
	int i = 0;
	for (i = size - 1; i >= 0; i--)
	{
		if (x >= ps[i] && ps[i] != 0)
		{
			ps[i+1] = x;
			return 1;
		}
		else if(i+1 < size)
			ps[i + 1] = ps[i];
	}
	return 0;
}

int main()
{
	//将3按顺序插入表中--下标为2
	int arr[10] = { 1,2,4,5,6,7,8,9 };
	int size = sizeof(arr)/sizeof(int);
	int ret = 0;
	ret = Insert_arr(arr, size, 3);
	if (ret)
		printf("插入成功!\n");
	else
		printf("插入失败!\n");
	int i = 0;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	return 0;
}