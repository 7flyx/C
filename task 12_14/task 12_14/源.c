# define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main()
{
	//����һ���������ж����Ƶ������ӡ
	int n = 0;
	int sum = 0;//�洢������
	scanf("%d", &n);
	int m = 0;
	while (n)
	{
		if ((m = n % 2) == 1)
		{
			sum <<= 1;//����һλ
			sum = sum | 1; //��1��Ϊ1
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
//		for (i = 0; i < n; i++)//��
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
//			//��ӡn��
//			for (j = 0; j < n; j++)
//			{
//				//��б������б��
//				//����Ӧ����������б����ϴ�ӡ�����ǳ���ķ�Ϊ���²���
//				if (j == i)  //  ��ӡ��\��
//					printf("*");
//				else if (j == n - i - 1)//��ӡ��/��
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
//			//��ӡ�ϰ벿��
//			for (j = 0; j <= 2 * n - i; j++)
//			{
//				//��ӡһ�У���ӡǰ��Ŀո�
//				if (j < 2 * (n - i))
//					printf(" ");
//				else
//					printf("*");
//			}
//			printf("\n");
//		}
//
//		for (i = 0; i < n + 1; i++)
//		{  //��ӡ�м����һ��
//			printf("*");
//			if (i == n)
//				printf("\n");
//		}
//
//		for (i = 0; i < n; i++)
//		{  //��ӡ�°벿��
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
