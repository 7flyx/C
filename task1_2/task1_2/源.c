# define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>



//int my_strcmp(const char* str1, const char* str2)
//{
//	//其实字符串比较，比的不是整体的长度
//	//而是一个个字母去比较，在过程中，谁的ASCII码值大，这个字符串就大
//	//整体比较完之后，才是等于
//
//	while (*str1 == *str2)
//	{
//		if (*str1 == '\0')
//			return 0; //相等的时候
//		str1++;
//		str2++;
//	}
//	if (*str1 > * str2)
//		return 1;//大于
//	else
//		return -1;//小于
//}
//
//int main()
//{
//	char* p1 = "abcedf";
//	char* p2 = "qwert";
//	int ret = my_strcmp(p1, p2);
//	printf("ret = %d\n", ret);
//	return 0;
//}




//strncpy函数的实现
//char*  my_strncpy(char* str1, const char* str2, int n)
//{
//	int i = 0;
//	char* tmp = str1; //还是需要保存首元素的地址，需要返回
//	int len = strlen(str2); //当源头的字符串不够时，需要补0
//	for (i = 0; i < n; i++)
//	{
//		if (i > len)
//			*str1 = 0;
//		else
//			*str1 = *str2;
//		str1++;
//		str2++;
//	}
//	return tmp;
//}
//char* my_strncpy(char* str1, const char* str2, size_t n)
//{
//	char* tmp = str1; //还是需要保存首元素的地址，需要返回
//	while (n && (*str1++ = *str2++))
//		n--;
//	if (n)
//		while (--n)
//			*str1 = 0;//当源头的字符串不够时，补0
//	return tmp;
//}
//int main()
//{
//	char arr1[10] = "abcdef";
//	char arr2[] = "qwert";
//	my_strncpy(arr1, arr2, 7);
//	printf("%s\n", arr1);
//	return 0;
//}





//strncat的函数实现

char* my_strncat(char* str1, char* str2, size_t n)
{
	//老规矩，保存首元素的地址
	char* tmp = str1;
	while (*str1 != '\0')  //找到目的地的最后面的地址
		str1++;  
	while (n--) 
	{
		if (*str2 == '\0')  //保证str2不会越界，拷到最后的\0就直接跳出循环
			break;
		*str1++ = *str2++;
	}
	if (*str1 != '\0')
		*str1 = '\0';  //当上面没有拷到\0时，补一个
	return tmp;
}

int main()
{
	char arr1[20] = "abcdef";
	char arr2[] = "qwert";

	//字符串追加 strncat
	my_strncat(arr1, arr2, 5);  //看似只追加5个字符，实则后面还有一个\0，即就是6个
	printf("%s\n", arr1);
	return 0;
}