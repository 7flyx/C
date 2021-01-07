# define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>

//enum Color
//{
//	RED,
//	GREEN,
//	BLUE
//};
//
//enum Sex
//{
//	BOY,
//	GIRL
//};
//int main()
//{
//	//枚举常量---也就是一一列举
//	//比标识符常量好用一点
//	//enum的大小，就是一个整形，就是四个字节的大小
//	enum Color c = BLUE;
//	enum Sex s = BOY;
//
//	return 0;
//}



//union sn
//{
//	//联合体---共用体
//	//其实和结构体有些相似，就是占用的空间是同一块的而已
//	//可以运用共用体巧妙的计算出大小端字节序
//	char c;
//	int i;
//};
int check_num()
{
	union
	{
		char c;
		int i;
	}u;
	u.i = 1;

	return u.c; //直接返回去，能够得到第一个字节的空间
}

int main()
{
	int ret = check_num();
	if (ret == 1)
		printf("小端\n");
	else
		printf("大端\n");
	return 0;
}