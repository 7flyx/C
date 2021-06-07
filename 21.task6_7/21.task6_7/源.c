#include <stdio.h>

char* myStrstr(const char* str1, const char* str2)
{
	const char* s1 = str1;
	const char* s2 = str2;
	const char* cp = str1;
	while (*cp)
	{
		s1 = cp;
		s2 = str2;
		while (*s1 && *s2 && *s1 == *s2)
			s1++,s2++;
		
		if (!*s2)
			return (char*)cp;
		cp++;
	}
	return NULL;
}

int main()
{
	//模拟实现strstr
	char arr1[20] = "hello world";
	char arr2[] = "world ";
	char* ret = myStrstr(arr1, arr2);
	if (ret != NULL)
		printf("%s\n", ret);
	else
		printf("不是该子串\n");
	return 0;
}


//char* myStrcat(char* dest, const char* src)
//{
//	if (src == NULL)
//		return dest;
//	char* tmp = dest;
//	//先找到dest的\0
//	while (*dest++ != '\0')
//		;
//	dest--;
//
//	while (*dest++ = *src++)
//		;
//	return tmp;
//}
//
//int main()
//{
//	//模拟实现strcat
//	char arr1[20] = "******";
//	char arr2[] = "hello world";
//	
//	printf("%s\n", myStrcat(arr1, arr2));
//	return 0;
//}


//
//int myStrcmp(const char* dest, const char* src)
//{
//	if (*src == '\0')
//		return 1;
//	else if (*dest == '\0')
//		return -1;
//	while (*dest && *src && *dest == *src)
//		dest++, src++;
//	return *dest - *src;
//}
//
//int main()
//{
//	//模拟实现strcmp
//	char arr1[20] = "hello";
//	char arr2[20] = "helo";
//	int ret = myStrcmp(arr1, arr2);
//	if (ret < 0)
//		printf("<");
//	else if (ret > 0)
//		printf(">");
//	else
//		printf("=");
//	return 0;
//}


//void myStrcpy(char* dest, const char* src)
//{
//	if (dest == NULL|| src == NULL)
//		return;
//	
//	while (*dest++ = *src++)
//		;
//}
//
//int main()
//{
//	//实现strcpy
//	char arr1[20] = "###############";
//	char arr2[] = "abcde";
//	myStrcpy(arr1, arr2);
//	printf("%s\n", arr1);
//	return 0;
//}



//int myStrlen(const char* s)
//{
//	if (s == NULL)
//		return -1;
//	else if (*s == '\0')
//		return 0;
//	else
//		return 1 + myStrlen(s + 1);
//}
//
//int main()
//{
//	char s[] = "abcde";
//	printf("%d ", myStrlen(s));
//	return 0;
//}


//int cmp_int(void* e1, void* e2)
//{
//	return *(int*)(e1) - *(int*)e2;
//}
//int cmp_char(void* e1, void* e2)
//{
//	return *(char*)e1 - *(char*)e2;
//}
//void swap(char* L, char* R, int size)
//{
//	int i = 0;
//	for (i = 0; i < size; i++)
//	{
//		char tmp = *L;
//		*L = *R;
//		*R = tmp;
//		L++;
//		R++;
//	}
//}
//void myQSort(void* arr, int size, int length, int (*cmp)(void*, void*))
//{
//	int i, j;
//	for (i = 0; i < length - 1; i++)
//	{
//		for (j = 0; j < length - 1 - i; j++)
//		{
//			//满足条件就进行交换
//			if (cmp(((char*)arr + size * j), ((char*)arr + size * (j + 1))) > 0)
//			{
//				swap((char*)arr + size * j, (char*)arr + size * (j + 1),size);
//			}
//		}
//	}
//}
//int main()
//{
//	//qsort函数的实现
//	int arr[10] = { 2,1,3,6,4,5,7,89,10,99 };
//	char arr2[5] = { 'a','d','e','s','q' };
//	myQSort(arr, sizeof(int), 10, cmp_char);
//	int i = 0;
//	for (i = 0; i < 5; i++)
//		printf("%c ", arr2[i]);
//	return 0;
//}