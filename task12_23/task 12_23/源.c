# define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main()
{
	long n = 0;
	int count1 = 0;
	int count2 = 0;
	int count3 = 1, t2;  //---count 计数判断
	long long num;  //num临时存储最小二段数-
	while (scanf("%ld", &n) && n)
	{
		long m = 1;
		long long sum = 0;
		while (1)
		{
			//注意两个不同类型数值进行运算时，特别注意会不会算术溢出
			sum = n * m;//n的倍数		
			num = sum;
			//判断是否为二段数
			while (1)
			{
				t2 = sum % 10;
				//1.是二段数---  count2 = 2 就不是二段数
				while (num)
				{
					//模除运算
					long t1 = num % 10;
					//count3 *= 10;
					if (t1 == t2 && count2 != 2)
					{
						count1 = 1;
						//t2 = num % 10;
					}
					else if (count1 == 1)
					{
						t2 = num % 10;  //更新t2的值
						count1 += 1;
					}

					if (count1 == 2 && t1 == t2) //此处的if - else 用于判断是不是二段数
					{
						count2 = 2;
					}
					else if (count2 == 2)
					{
						count2 = 3;
						break;
					}
					num /= 10;
				}
				break;
			}
			if (count2 == 2)  //是二段数
				break;
			else
				m += 1;
		}
		printf("%ld: %lld\n", n, sum);
	}
	return 0;
}







//#include<stdio.h>
//int main()
//{
//	int n, i = 0, k, a[100001] = { 0 };
//	scanf("%d", &n);
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &k);
//		a[k] = k;
//		//因为输入的k只能在1到n之间，所以之间将k作为下标存入进去，这样就避免了重复的
//	}
//	for (i = 0; i <= n; i++)
//	{
//		if (a[i])
//			printf("%d ", a[i]);
//	}
//	return 0;
//}


//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//int cmp_int(void* e1, void* e2)
//{
//	return *(int*)e1 - *(int*)e2;
//}
//
//int  main()
//{
//	int n, i, j, m;
//	scanf("%d", &n);
//	int arr[10] = { 0 };
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &m);
//		for (j = 0; j < i; j++)
//		{
//			if (arr[j] == m)
//			{
//				arr[i] = 0;
//				break;
//			}
//		}
//		if (j == i)
//			arr[i] = m;
//	}
//	qsort(arr, n, sizeof(arr[0]), cmp_int);
//	for (i = 0; i < n; i++)
//	{
//		if (arr[i] != 0)
//			printf("%d ", arr[i]);
//	}
//	return 0;
//}



//int cmp_int(void* e1, void* e2)
//{
//	return *(int*)e1 - *(int*)e2;
//}
//
//int main()
//{
//	int i, n, m, j, x = 0;
//	scanf("%d", &n);
//	int arr[10] = { 0 };
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &m);  //临时判断，将重合的，不存入数组
//		for (j = 0; j < x; j++)
//		{
//			if (m == arr[j])
//				break;
//		}
//		if (j == x)
//		{
//			arr[x] = m;
//			x++;
//		}
//	}
//
//	qsort(arr, x, sizeof(arr[0]), cmp_int);
//	for (i = 0; i < x; i++)
//		printf("%d ", arr[i]);
//	return 0;
//}



//int main()
//{
//	long n = 0;
//	int i = 0, x = 0;
//	int arr[100] = { 0 };
//	scanf("%ld", &n);
//	//倒着存入
//	while (n)
//	{
//		arr[i] = n % 2;
//		i++;
//		n /= 10;
//	}
//	//倒着输出
//	int arr1[100] = { 0 };
//	while (i)
//	{
//		arr1[x] = arr[i - 1];
//		x++;
//		i--;
//	}
//	for (i = 0; i < x; i++)
//	{
//		if (arr[i] == 0 && n == 0) //省略最前面的0
//			n++;
//		else
//			printf("%d", arr1[i]);
//	}
//	return 0;
//}


//int main()
//{
//
//	int n, m;
//	scanf("%d%d", &n, &m);
//	int tmp = 0; //存储最大公因数
//	int x = n, y = m;//临时变量，存储nm的值
//	while (1)
//	{
//		if (n % m == 0)
//		{
//			//此时m就是最大公因数
//			tmp = m;
//			break;
//		}
//		else
//		{
//			int tmp = n;
//			n = m;
//			m = tmp % m;
//		}
//	}
//	//最小公倍数---应理解最小公倍数是怎么来的
//	printf("%d\n", tmp * (x / m) * (y / m) + tmp);
//	return 0;
//}



//int main()
//{
//	int arr[2][3] = { {1,2,3}, {4,5,6} };
//	int* p;
//	p = arr[0];
//	printf("%d", arr[0]);
//	return 0;
//}



//int Is_num(int i, int j)
//{
//	if (j == 1 || j == i)
//		return 1;
//	else
//		return Is_num(i - 1, j) + Is_num(i - 1, j - 1);
//}
//
//int main()
//{
//	int n, i, j;
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf("%5d", Is_num(i, j));
//		}
//		printf("\n");
//	}
//	return 0;
//}


//int main()
//{
//	int n, m, i, j, k;
//	scanf("%d%d", &n, &m);
//	int arr[10][10] = { 0 };
//	//输入
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < m; j++)
//		{
//			scanf("%d", &arr[i][j]);
//		}
//	}
//	scanf("%d", &k);
//	while (k)
//	{
//		char t = 0;
//		int a, b;
//		scanf(" %c %d %d", &t, &a, &b);  //%c前面补空格，吸收上次的\n
//		if (t == 'r')  // 行交换
//		{
//			for (j = 0; j < m; j++)
//			{
//				int pdc = arr[a - 1][j];
//				arr[a - 1][j] = arr[b - 1][j];
//				arr[b - 1][j] = pdc;
//			}
//		}
//		else if (t == 'c')//列交换
//		{
//			for (i = 0; i < n; i++)
//			{
//				int pdc = arr[i][a - 1];
//				arr[i][a - 1] = arr[i][b - 1];
//				arr[i][b - 1] = pdc;
//			}
//		}
//		k--;
//	}
//	for (i = 0; i < n; i++) // 打印
//	{
//		for (j = 0; j < m; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}



//int main()
//{
//	int n, m, i, j;
//	scanf("%d%d", &n, &m);
//	int arr[10][10] = { 0 };
//	//输入
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < m; j++)
//		{
//			scanf("%d", &arr[i][j]);
//		}
//	}
//
//	//输出
//	for (j = 0; j < m; j++)
//	{
//		for (i = 0; i < n; i++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}




