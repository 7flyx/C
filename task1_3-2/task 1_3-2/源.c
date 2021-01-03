# define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <string.h>


//strtok函数的用法
//int main()
//{
//	char arr1[] = "fly@qq.com";  //源字符串
//	char* p = "@."; //分隔符的字符集合，用指针变量保存
//
//	//1. 先做一份拷贝，因为strtok会改变源字符串的内容
//	char arr2[1024] = { 0 };
//	strcpy(arr2, arr1);
//
//	//2. for循环使用
//	char* ret = NULL;
//	for (ret = strtok(arr2, p); ret != NULL; ret = strtok(NULL, p))
//	{
//		printf("%s ", ret);
//	}
//	return 0;
//}

//
//
//#include <errno.h>
////strerror
//int main()
//{
//	//错误码信息转换
//	//例如 0----no error
//	//......
//	FILE* pf = fopen("扫雷","r");  //文件名为扫雷，‘r’就是阅读的意思
//	//如果阅读不成功，返回的是空指针
//	if (pf == NULL)
//		printf("%s\n", strerror(errno));
//	else
//		printf("oper file success");
//	/*char* p = strerror(errno);
//		printf("%s\n", p);*/
//	return 0;
//}


//struct s
//{
//	char name[20];
//	int age;
//	//char a;
//};
//void* my_memcpy(void* dest, const void* src, size_t num)
//{
//	//首先保存dest的地址，后面返回
//	void* ret = dest;
//	while (num--)
//	{
//		*(char*)dest = *(char*)src;  //一个个的字节，慢慢拷贝
//		//(char*)dest++; 注意，此处这样写有问题，因为++的优先级要高，它先与dest结合
//		++(char*)dest; //考虑符号的优先级与结合性
//		++(char*)src;
//	}
//	return ret;
//}
//int main()
//{
//	struct s arr1[] = { {"张三", 20} };
//	struct s arr2[] = { 0 };
//	my_memcpy(arr2, arr1, sizeof((arr1)));
//
//
//	//printf("%d\n", arr2->age);
//	return 0;
//}



void* my_memmove(void* dest, const void* src, size_t num)
{
	//首先保存dest的内容，后面返回
	void* ret = dest;
	//1. 先进行判断，看dest这个地址时在src的什么位置
	//如果在src至src+num这个区间呢，我们需要从 后往前 移动
	
	char* s2 = (char*)src + num - 1;  //源头区的最后一个元素地址
	char* d = (char*)dest + num - 1;  //找到目标区的最后一个元素地址
	//为什么需要减1？？因为从原来的地址，加上num个字节后，其实，原来本身还占一个数，因此多了
	//当我们不减1时，看似我们是多加了一个元素的地址，其实并不是，而是小端模式时，机缘巧合的错了位
	if (dest >= src && dest <= s2)
	{
		//dest在src与s2之间时
		while (num--)
		{
			*d = *s2;
			--d;
			--s2;
		}
	}
	else
	{
		//dest不在src与s2之间时
		while (num--)
		{
			*(char*)dest = *(char*)src;
			++(char*)src;
			++(char*)dest;
		}
	}
	return ret; // 返回原始dest的地址
}
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	
	my_memmove(arr + 2, arr, 20);  //将12345移动带到34567的位置
	int i = 0;
	for (i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	return 0;
}