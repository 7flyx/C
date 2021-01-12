# define _CRT_SECURE_NO_WARNINGS 


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

//int main()
//{
//	int* p = (int*)malloc(10 * sizeof(int));
//	//如果申请成功，返回第一个空间的地址，不成功的话，返回空指针
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			*(p + i) = i;
//		}
//		for (i = 0; i < 10; i++)
//		{
//			printf("%d ", *(p + i));
//		}
//	}
//	//使用完之后，需要释放空间，并将指针赋值为空指针，以防后面的代码使用，导致错误
//	free(p);
//	p = NULL;
//	return 0;
//}



int main()
{
	//calloc，前面的参数是申请多少个元素，后面的是每个元素的大小，注：这里不是数组的意思
	//这个函数与malloc函数的区别在于，calloc申请空间后会自动初始化为0，而malloc函数不会
	int* p = (int*)calloc(10, sizeof(int));
	if (p != NULL)  //有可能会返回空指针
	{
		int i = 0;
		for (i = 0; i < 10; i++)
			printf("%d ", *(p + i));
	}

	//先创建临时变量，存储指针，以防realloc函数的返回值是空指针，把原来的指针变量弄丢了
	int* p2=(int*)realloc(p, 20);
	if (p2 != NULL)
		p = p2;

	//释放空间
	free(p);
	p = NULL;
	return 0;
}