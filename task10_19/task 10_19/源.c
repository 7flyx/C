# define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include "add.h"


//递归的角度去写，不使用临时变量
int my_strlen(char* str)
{

	if (*str != '\0')
	{
		return 1 + my_strlen(str+1);
		  //地址加一，代表将进行下一个字符的判断，即就是光标移向‘i’
	}
	return 0;
	
}

int main()
{
	char arr[] = "bit";
	int len = my_strlen(arr);//arr传过去的是第一个元素的地址

	printf("len=%d\n", len);
	return 0;
}

//递归
//void prime(int n)
//{
//	//1234,分别打印1 2 3 4
//	if (n > 9)
//	{
//		prime(n / 10);//123			
//	}
//	printf("%d ", n % 10);
//}
//
//int main()
//{
//	int num = 0;
//	scanf("%d", &num);//1234
//
//	prime(num);
//	return 0;
//}



//int main()
//{
//	int a = 10;
//	int b = 20;
//	int sum = Add(a, b);
//
//	printf("%d\n", sum);
//	return 0;
//}