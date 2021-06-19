#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

int main()
{
	char buffer[] = "This is a test of the memset function";

	printf("Before: %s\n", buffer);
	memset(buffer, '*', 4); //设置为 * 
	printf("After:  %s\n", buffer);

	return 0;
}


//int main()
//{
//    char first[] = "12345678901234567890";
//    char second[] = "12345678901234567891";
//    int result;
//
//    printf("Compare '%.19s' to '%.19s':\n", first, second);
//    result = memcmp(first, second, 20);
//    if (result < 0)
//        printf("First is less than second.\n");
//    else if (result == 0)
//        printf("First is equal to second.\n");
//    else if (result > 0)
//        printf("First is greater than second.\n");
//    return 0;
//}



//int main()
//{
//	char str[] = "memmove can be very useful......";
//	memmove(str + 20, str + 15, 11);
//	puts(str);
//	return 0;
//}

//int main()
//{
//	int arr1[20] = { 1,2,3,4,5,6,7,8,9,10 };
//	int arr2[10] = { 3,3,3,3,3,4,4,4,4,4 };
//	int i = 0;
//	printf("拷贝前\n");
//	for (i = 0; i < 10; i++)
//		printf("%d ", arr1[i]);
//
//	memcpy(arr1, arr2,20); //20 ，指的是20个字节
//
//	printf("\n拷贝后\n");
//	for (i = 0; i < 10; i++)
//		printf("%d ", arr1[i]);
//
//	return 0;
//}


//int main()
//{
//    char str[] = "lazy";
//    char string[] = "The quick brown dog jumps over the lazy fox";
//    char fmt1[] = "         1         2         3         4         5";
//    char fmt2[] = "12345678901234567890123456789012345678901234567890";
//    char* pdest;
//    int  result;
//    printf("String to be searched:\n\t%s\n", string);
//    printf("\t%s\n\t%s\n\n", fmt1, fmt2);
//    pdest = strstr(string, str);
//    result = pdest - string + 1;
//    if (pdest != NULL)
//        printf("%s found at position %d\n\n", str, result);
//    else
//        printf("%s not found\n", str);
//    return 0;
//}



//int main()
//{
//	FILE* fp = fopen("test.txt", "r"); //以读取的形式打开test.txt文本文件
//	//printf("%s\n", strerror(errno)); 
//	perror("打开文件 ");
//	return 0;
//}


//int main()
//{
//	char strToken[20] = "http:www.baidu.com";
//	char string[20] = { 0 };
//	char* tmp = NULL;
//	char strDelimit[10] = "/:.";
//	strcpy(string, strToken); //先拷贝一份临时的
//	for (tmp = strtok(string, strDelimit); tmp != NULL; tmp = strtok(NULL, strDelimit))
//		printf("分隔得到的字符串: %s\n", tmp);
//	
//	return 0;
//}



//int main()
//{
//	char dest[20] = "我会信你吗？";
//	char src[20] = "我信你个鬼";
//	printf("追加之前: %s\n", dest);
//	strncat(dest, src, 4);
//	printf("追加之后: %s\n", dest);
//	return 0;
//}


//int main()
//{
//	char dest[20] = "C语言 ";
//	char src[10] = "万岁";
//	printf("追加之前: %s\n", dest);
//	strcat(dest, src);
//	printf("追加之后: %s\n", dest);
//	return 0;
//}


//int main()
//{
//	char s1[10] = "abcdef";
//	char s2[10] = "abcdfg";
//	int x1 = strncmp(s1, s2, 4); //比较前4个字符
//	int x2 = strncmp(s1, s2, 6); //比较前6个字符
//	printf("比较前4个字符: %d\n", x1);
//	printf("比较前6个字符: %d\n", x2);
//	return 0;
//}



//int main()
//{
//	char s1[15] = "hello world";
//	char s2[15] = "hello world";
//	char s3[15] = "hello";
//	int x1 = strcmp(s1, s2);
//	int x2 = strcmp(s1, s3);
//	printf("s1与s2: %d\n", x1);
//	printf("s1与s3: %d\n", x2);
//	return 0;
//}
// 
// 
// 

//int main()
//{
//	char dest[20] = "################";
//	char src[20] = "hello world";
//	printf("拷贝之前: %s\n", dest);
//	strncpy(dest, src, 5);
//	printf("拷贝之后: %s\n", dest);
//	return 0;
//}

//int main()
//{
//	char dest[20] = "################";
//	char src[10] = "hello";
//	printf("拷贝之前: %s\n", dest);
//	strcpy(dest, src);
//	printf("拷贝之后: %s\n", dest);
//
//	return 0;
//}


//int main()
//{
//    char s1[] = "hello";
//
//    printf("strlen:  %d\n", strlen(s1));
//    printf("sizeof:  %d\n", sizeof(s1));
//
//    return 0;
//}


//int main()
//{
//
//	int i = 0;
//	int arr[5] = { 0 };
//	for (i = 0; i < 5; i++)
//		scanf("%d", arr + i);
//
//	for (i = 0; i < 5; i++)
//		printf("%d ", arr[i]);
//	return 0;
//}