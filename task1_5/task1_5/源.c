# define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>


//struct s
//{
//	char a[10];
//	char s;
//	int age;
//};




//位段，结构体中的一种类型
//作用就是为了节省空间，当然使用位段，也有一些注意，例如跨平台等
//位段在内存中的存储有很多不确定因素，如果源码常移植，需少使用位段或特别注意位段的使用
struct Stu
{
	char a : 2;
	char b : 4;
	char c : 7;
	char d : 8;
};

int main()
{
	struct Stu s = { 0 };

	s.a = 2;
	s.b = 15;
	s.c = 20;
	s.d = 100;

	return 0;
}