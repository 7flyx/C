# define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

//void* my_memmove(void* dest, const void* src, size_t num)
//{
//	void* ret = dest;// 保存dest的值
//
//	//首先判断dest与src的位置关系
//	if (dest < src)
//	{
//		//dest的地址在src的左边
//		while (num--)
//		{
//			*(char*)dest = *(char*)src;
//			++(char*)dest;
//			++(char*)src;
//		}
//	}
//	else
//	{
//		//dest的地址在src的右边
//		while (num--)
//		{
//			//实则循环进来说时，加上num，只加上了num-1 的值，捋清楚该点，为关键
//			*((char*)dest + num) = *((char*)src + num);
//		}
//	}
//	return ret;
//
//}
//
//int main()
//{
//	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
//
//	//my_memmove(arr1 + 2, arr1, 20);
//	my_memmove(arr1, arr1 + 2, 20);
//	int i = 0;
//	for (i = 0; i < 10; i++)
//		printf("%d ", arr1[i]);
//	return 0;
//}


//int cmp_int(const void* e1, const void* e2)
//{
//	return *(int*)e2 - *(int*)e1;
//}
//
//void Exch(char* cmp1, char* cmp2, size_t width)
//{
//	int i = 0;
//	for (i = 0; i < width; i++)
//	{
//		char tmp = *cmp1;
//		*cmp1 = *cmp2;
//		*cmp2 = tmp;
//		cmp1++, cmp2++; //逗号表达式，从左到右，依次执行
//	}
//}
//
//void my_sort(void* base, size_t sz, size_t width, int (*cmp)(void*, void*))
//{
//	//函数里面实则还是冒泡排序
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		int j = 0;
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			//进行判断和交换
//			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
//			{
//				//此处函数传参的时，并非只需要传递两个需要交换的数据，还有数据的大小，即就是字节数
//				//例如是整体数据交换，而Swap函数，其实函数里面需要循环4次才行，因为是4个字节的数据嘛
//				Exch((char*)base + j * width, (char*)base + (j + 1) * width, width);
//			}
//		}
//	}
//}
//
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	my_sort(arr, sz, sizeof(arr[0]), cmp_int);
//	int i = 0;
//	for (i = 0; i < 10; i++)
//		printf("%d ", arr[i]);
//	return 0;
//}







//
//int main()
//{
//	char arr1[10] = { 0 };
//	memset(arr1, '#', 10);// 特别注意，函数的最后一个参数，并不是表示元素的个数，而是总共需要修改的元素的大小，单位是字节
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%c ", arr1[i]);
//	}
//	return 0;
//}


//int main()
//{
//	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int arr2[] = { 1,2,3,4,6,7,8,4,10 };
//
//	int ret = memcmp(arr1, arr2, 12);
//	//注释：后面的那个参数，还是指的是比较的元素全部的大小，单位字节
//	//简记：左边小于右边，返回小于0------<
//	//      左边大于右边，返回大于0,----->
//	//   相等的话，就是等于0
//	printf("%d\n", ret);
//	return 0;
//}








//
//typedef struct Stu
//{
//	char c;
//	char name[20];
//	int age;
//	struct Stu n;
//}stu;
//
//int main()
//{
//	struct Stu s1 = { 'n',"张三",20 };
//	stu s2;
//	printf("%c %s %d \n", s1.c, s1.name, s1.age);
//
//	return 0;
//}


#include <stddef.h>

#pragma pack(4)  //设置默认对齐数4
struct Stu
{
	char a;
	char arr[10];
	int su;
};
#pragma pack()  //取消默认对齐数

int main()
{
	struct Stu s = { 0 };
	printf("%d \n", offsetof(struct Stu, a));  //求结构体变量成员的偏移量
	printf("%d \n", offsetof(struct Stu, arr));
	//printf("%d\n", sizeof(s));
	return 0;
}