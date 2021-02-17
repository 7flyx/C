# define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int a = 100;
	int b = 20;
	int max = 0;

	max = (a > b ? a : b);
	printf("%d\n", max);

	return 0;
}





//int main()
//{
//	int a = 10;
//	int b = a++;  //后置++，先使用再++，
//	//例如：这里先把b=a=10计算，再把a++计算得到新的a
//	
//	//同理，前置++是先++再使用
//	//int a = 10;
//	//int b = ++a;
//
//	printf("a = %d b = %d", a, b);
//	return 0;
//}
