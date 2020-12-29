# define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

//
//#include <stdio.h>
//int main()
//{
//	//创建数组
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	//计算元素个数----整个数组的大小除去一个元素的大小，就是整个数组的大//小了，单位字节
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i, j;//循环变量
//	//当然，需要注意的就是  未初始化的局部变量，他是随机值
//	//而全局变量未初始化，他默认是0
//
//	for (i = 0; i < sz; i++)  //这是躺数
//	{
//		for (j = 0; j < sz - 1 - i; j++)  //这是一趟中需要交换的数据对数
//		{
//			//sz-1-i   就是随着躺数的增加，我们这一趟中需要交换的
//			//数据就越来越少
//			if (arr[j] < arr[j + 1])
//			{
//				//创建临时变量，将其中一个数据就先进行保存
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//	//这样我们就实现了冒泡排序的实现
//
//	for (i = 0; i < sz; i++)
//		printf("%d ", arr[i]);
//	//最后再打印出来
//
//	return 0;
//}

void exch(char* ex1, char* ex2, int width)
{
	//在进行数据的交换时，我们并不知道具体需要交换多少个字节，此时的width就有作用
	int i = 0;
	for (i = 0; i < width; i++)
	{
		//创建临时变量，进行交换
		int tmp = *ex1;
		*ex1 = *ex2;
		*ex2 = tmp;
		ex1++;
		ex2++;
	}
}

void my_sort(void* base, int sz, int width, int (*cmp)(void* e1,void* e2))
{
	//快速排序的底层原理还是冒泡排序的原理
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			//进行数值的判断，以及交换
			if (cmp((char*)base + (j * width), (char*)base + (j + 1) * width) > 0)
				exch((char*)base + (j * width), (char*)base + (j + 1) * width, width);
				//exchange -交换两个数据的位置
		}
	}
}

int cmp_int(void* e1, void* e2)
{
	//左边的值减去右边的值，得到是升序
	//反之，这就是降序
	return *(int*)e1 - *(int*)e2;
}

int main()
{
	//自己实现快速排序函数
	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);

	my_sort(arr, sz, sizeof(arr[0]), cmp_int);
	int i = 0;
	for (i = 0; i < sz; i++)
		printf("%d ", arr[i]);
	return 0;
}
