# define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <string.h>
#include <assert.h>


//int my_strlen(char* str)
//{
//	if (*str != '\0')
//		//return my_strlen(str + 1) + 1;
//		return my_strlen(++str) + 1;
//	else
//		return 0;
//
//}
//int main()
//{
//	printf("%d\n", my_strlen("abcdef"));
//	return 0;
//}




//char* my_strcpy(char* dest, const char* src)
//{
//	//首先判断两个地址不是空地址
//	assert(dest != NULL);
//	assert(src != NULL);
//	char* ret = dest;//首先保存dest的首元素地址
//
//
//
//	//这种方法最简单，当最后一个\0被拷入dest后，该表达式的结果为假，就退出循环
//	while (*dest++ = *src++)
//	{
//		;
//	}
//
//	////第二种方法--该方法没错，只是不够简洁
//	//while (*src != '\0')
//	//{
//	//	*dest = *src;
//	//	dest++;
//	//	src++;
//	//}
//	//*dest = *src;//拷贝最后的那个\0
//
//	return ret;//返回dest的首元素地址
//}
//
//int main()
//{
//	char arr1[] = "abcdefg";
//	char arr2[] = "bit";
//
//	my_strcpy(arr1, arr2); // 字符串拷贝，将\0也一并拷了过去
//	printf("%s\n", arr1);
//	return 0;
//}





char* my_strcat(char* dest, const char* src)
{
	//首先保存dest的地址，后面返回值需要
	char* ret = dest;
	//1. 找到dest字符串里面的\0
	while (*dest != '\0')
		dest++;
	//2. 再从\0的位置开始拷贝
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}

int main()
{
	//实现strcat，字符串追加函数
	//使用该函数时，需要注意目标数组是否能够存储下
	char arr1[30] = "abcedfg";
	char arr2[] = "hello";

	my_strcat(arr1, arr2);
	printf("%s\n", arr1);
	return 0;
}


