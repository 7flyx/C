# define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>


//int main()
//{
//	//在使用动态内存开辟的内存时，需要对malloc的返回地址进行判断，如果为空指针，程序会崩
//	int* p = (int*)malloc(10 * sizeof(int));
//	int i = 0;
//	if (p != NULL)
//	{
//		for (i = 0; i < 10; i++)
//			{
//				*(p + i) = i;
//			}
//	}
//	free(p);
//	p = NULL;
//	
//	//使用动态内存时，注意几个点：
//	//1. 对空指针进行解引用，会使程序崩溃
//	//2. 对开辟出来的空间进行了越界访问
//	//3. 对不是动态内存开辟的空间进行释放（free），程序也会崩
//	//4. 使用free函数去回收空间时，传入的地址应该是开辟空间的首元素地址，
//	//而非这块内存中的其他地址，也就是说，我们在使用malloc等函数开辟的空间时，应避免对函数返回的
//	//指针进行增减操作，例如：p++或p--
//	//5.对同一块内存空间多次释放，程序会崩
//	//6. 内存开辟后不释放，容易导致内存泄漏
//	return 0;
//}

void Getmemory(char** ptr)
{
	*ptr = (char*)malloc(100);
}

void test()
{
	char* p = NULL;
	Getmemory(&p);  //这里需要进行传址，而非传值，不然不然不能改变p的值
	strcpy(p, "hello world");	
	printf(p);  //这里的打印函数，直接给地址也可以打印出字符串

	free(p);
	p = NULL;
}

int main()
{
	test();
	return 0;
}