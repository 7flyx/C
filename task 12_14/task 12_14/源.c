# define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main()
{
	//输入一个数，进行二进制的逆序打印
	int n = 0;
	int sum = 0;//存储二进制
	scanf("%d", &n);
	int m = 0;
	while (n)
	{
		if ((m = n % 2) == 1)
		{
			sum <<= 1;//左移一位
			sum = sum | 1; //有1即为1
		}
		else
		{
			sum <<= 1;
		}
		n /= 2;				
	}
	printf("%d\n", sum);
	return 0;
}


//
//int main()
//{
//	double a, b, c, d, e;
//	a = b = c = d = e = 0.0;
//	scanf("%lf%lf%lf%lf%lf", &a, &b, &c, &d, &e);	
//	double sum = a + b + c + d + e;
//	printf("%.2f\n", sum / 5);
//	return 0;
//}


//
//int main()
//{
//	short n = 0;
//	while (scanf("%hd", &n) != EOF)
//	{
//		int i, j;
//		for (i = 0; i < n; i++)//行
//		{
//			
//			if (i < n - 1)
//			{
//				for (j = 0; j < n; j++)
//				{
//					if (j == i || j == 0)
//						printf("* ");
//					else
//						printf("  ");					
//				}
//				printf("\n");
//			}
//			else
//			{
//				for (i = 0; i < n; i++)
//					printf("* ");
//				printf("\n");
//			}
//		}
//	}
//	return 0;
//}


//int main()
//{
//	short n = 0;
//	while (scanf("%hd", &n) != EOF)
//	{
//		int i, j;
//		for (i = 0; i < n; i++)
//		{
//			if (i == 0 || i == n - 1)
//			{
//				for (j = 0; j < n; j++)
//					printf("* ");
//				printf("\n");
//			}
//			else
//			{
//				for (j = 0; j < n; j++)
//				{
//					if (j == 0 || j == n - 1)
//						printf("* ");
//					else
//						printf("  ");
//				}
//				printf("\n");
//			}
//		}
//	}
//	return 0;
//}




//
//
//int main()
//{
//	short n = 0;
//	while (scanf("%hd", &n) != EOF)
//	{
//		int i, j;
//		for (i = 0; i < n; i++)
//		{
//			//打印n行
//			for (j = 0; j < n; j++)
//			{
//				//反斜线与正斜线
//				//此题应考虑用两条斜线组合打印，而非常规的分为上下部分
//				if (j == i)  //  打印‘\’
//					printf("*");
//				else if (j == n - i - 1)//打印‘/’
//					printf("*");
//				else
//					printf(" ");
//			}
//			printf("\n");
//		}
//	}
//	return 0;
//}

//
//int main()
//{
//	short n = 0;
//	while (scanf("%hd", &n) != EOF)
//	{
//		int i, j;
//		for (i = 0; i < n; i++)
//		{
//			for(j = 0;j < n;j++)
//			{
//				if (n - i - 1 == j)
//					printf("*");
//				else
//					printf(" ");
//			}
//			printf("\n");
//		}
//	}
//	return 0;
//}


//
//int main()
//{
//	short n = 0;
//	while (scanf("%hd", &n) != EOF)
//	{
//		int i, j;
//		for (i = 0; i < n; i++)
//		{
//			for (j = 0; j < n; j++)
//			{
//				if (i == j)
//					printf("*");
//				else
//					printf(" ");
//			}
//			printf("\n");
//		}
//	}
//	return 0;
//}


//
//int main()
//{
//	short n = 0;
//
//	while (scanf("%hd", &n) != EOF)
//	{
//		int i, j;
//		for (i = 0; i < n; i++)
//		{
//			//打印上半部分
//			for (j = 0; j <= 2 * n - i; j++)
//			{
//				//打印一行，打印前面的空格
//				if (j < 2 * (n - i))
//					printf(" ");
//				else
//					printf("*");
//			}
//			printf("\n");
//		}
//
//		for (i = 0; i < n + 1; i++)
//		{  //打印中间的那一行
//			printf("*");
//			if (i == n)
//				printf("\n");
//		}
//
//		for (i = 0; i < n; i++)
//		{  //打印下半部分
//			for (j = 0; j < 2 + n + i; j++)
//			{
//				if (j < 2 * (1 + i))
//					printf(" ");
//				else
//					printf("*");
//			}
//			printf("\n");
//		}		
//	}
//	return 0;
//}
