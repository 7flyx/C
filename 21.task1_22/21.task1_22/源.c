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




int main()
{
	int a = 10000;
	FILE* ps = fopen("test.txt", "r");  

	/*printf("%c",fgetc(ps));
	printf("%c", fgetc(ps));
	printf("%c", fgetc(ps));
	printf("%c", fgetc(ps));
	printf("%c", fgetc(ps));*/


	fclose(ps);
	ps = NULL;
	return 0;
}
