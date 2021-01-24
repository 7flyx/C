# define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>

//int main()
//{
//	int a = 10000;
//	FILE* ps = fopen("test.txt", "wb");  //wb就是以二进制的形式输入  --write binary
//	fwrite(&a, 4, 1, ps);  //文件输入，第一个：输入的内容   第二个：内存空间，字节
//	//第三个：输入几个这样的数值，第四个：输入的目标地址
//	fclose(ps);  //文件关闭
//	ps = NULL;
//	
//	return 0;
//}




//int main()
//{
//	int a = 10000;
//	FILE* ps = fopen("test.txt", "r");  
//
//	/*printf("%c",fgetc(ps));
//	printf("%c", fgetc(ps));
//	printf("%c", fgetc(ps));
//	printf("%c", fgetc(ps));
//	printf("%c", fgetc(ps));*/
//
//
//	fclose(ps);
//	ps = NULL;
//	return 0;
//}




#include<stdio.h>
#include<string.h>
//假定输入的字符串中只包含字母和*号，请编写程序，它的功能是：将字符串中的前导*号全部移到字符串的尾部。
void fun(char* arr)
{
	int n = 0;
	int j = 0;
	int len = strlen(arr);
	int i = 0;
	for (i = 1; i <= len; i++)
	{
		//1.不是*号，跳出循环
		if ((arr[i-1] >= 'a' && arr[i-1] <= 'z') || (arr[i-1] >= 'A' && arr[i-1] <= 'Z'))
			break;
		//得到前导*号的个数    i
	}
	//从第i个元素开始，全部向前移动，后面的补*即可
	for (n = i-1; n < len; n++)
	{	
		arr[j] = arr[n];
		j++;
	}

	for (n = j; n < len; n++)
		arr[n] = '*';
	printf("%s\n", arr);
}
int main()
{
	char arr[50] = "*****abcd*f*e***";   //->abcd*f*e********
	fun(arr);
	printf("%s", arr);
	return 0;
}