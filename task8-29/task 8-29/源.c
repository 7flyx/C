# define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>

int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	
	scanf("%d%d", &a, &b);//输入函数scanf
		c = a + b;
		printf("c =%d\n", c);
	return 0;
}

//int main()
//{
//	int a = 0;
//	int b = ~a;
//	printf("%d\n", b);
//	return 0;
//}


//int main()
//{
//	int a = 0;
//	int arr[] = { 1,2,3,4,5,6 };
//	printf("%d\n", sizeof(int));
//	printf("%d\n",sizeof(a));
//	printf("%d\n", sizeof (arr)/ sizeof(arr[0]));//arr必须用圆括号包起来，[0]表示第一个元素‘1’
//	return 0;
//}
//





//int Max(int x, int y)  //构造新函数，并注意返回值为函数本身，而不是 0
//{
//	if (x > y)
//		return x;
//	else
//		return y;
//}
//
//int main()
//{
//	int num1 = 79;
//	int num2 = 80;
//	int max = 0;
//
//	max = Max(num1, num2); //用新变量接收上述的函数值
//	if (num1 > num2)
//		printf("最大值：%d\n", max);
//	else
//		printf("最大值：%d\n", max);

//}