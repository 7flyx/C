# define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>

//int main()
//{
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//		return 0;
//	//写文件
//	fputs("hello bit", pf);
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	char arr[100] = { 0 };
//	if (pf == NULL)
//		return 0;
//	//读文件
//
//	fgets(arr, 5, pf);  //fgets会自动在末尾放个\n，占了一个字节的空间
//	printf("%s\n", arr);
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}


int main()
{
	char arr[1024] = { 0 };

	/*fgets(arr, 1024, stdin);
	fputs(arr, stdout);*/

	//等价与  gets与puts，只是用法有点不一样，上面的用到标准输入输出
	gets(arr);
	puts(arr);

	return 0;
}