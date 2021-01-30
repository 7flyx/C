# define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>


int main()
{  //倒着写乘法口诀表
	int i, j;
	int m = 0;
	for (i = 9; i >= 1; i--)  //行
	{
		for (j = 9 - m; j >= 1; j--)  //列
		{
			printf("%d*%d=%02d ", i, j, i * j);
		}
		m++;
		printf("\n");
		int n = m;
		while (n)
		{
			printf("       ");
			n--;
		}
	}	
	return 0;
}



//#include<stdio.h>
//
//int main()
//{
//    int n, cnt1 = 0, cnt2 = 0;
//    scanf("%d", &n);
//    int a[n];
//    for (int i = 0; i < n; i++)
//        scanf("%d", &a[i]);
//    for (int i = 1; i < n - 1; i++)
//    {
//        if (a[i] >= a[i - 1] && a[i + 1] >= a[i])
//            cnt1++;
//        else if (a[i]<a[i - 1] && a[i]>a[i + 1])
//            cnt2++;
//    }
//    if (cnt1 == n - 2 || cnt2 == n - 2)
//        printf("sorted");
//    else
//        printf("unsorted");
//    return 0;
//}


//
//int main()
//{
//	int n,i;
//	scanf("%d", &n);
//	//int max = 0;
//	//int min = 100;
//	int num = 0;
//	int arr[50];
//	for (i = 0; i < n; i++)
//		scanf("%d", &arr[i]);
//	if (arr[0] >= arr[1])
//	{
//		for (i = 0; i < n - 1; i++)
//		{
//			if (arr[i] > arr[i + 1])
//				;
//			else
//				break;
//		}
//	}
//	else
//	{
//		for (i = 0; i < n; i++)
//		{
//			if (arr[i] < arr[i + 1])
//				;
//			else
//				break;
//		}
//	}
//
//	if (i == n - 1)
//		printf("sorted\n");
//	else
//		printf("unsorted\n");
//	//printf("%d\n", max - min);
//	return 0;
//}

//
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	printf("%d\n", n * (1 + n) / 2);
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 0 };
//	int i;
//	int count = 0;
//	for (i = 0; i < 10; i++)
//		scanf("%d", &arr[i]);
//	for (i = 0; i < 10; i++)
//	{
//		if (arr[i] > 0)
//			count++;// 正整数
//	}
//	printf("positive:%d\n", count);
//	printf("negative:%d\n", 10 - count);
//	return 0;
//}


//int main()
//{
//	int arr[10] = { 0 };
//	int i;
//	for (i = 0; i < 10; i++)
//		scanf("%d", &arr[i]);
//	for (i = 0; i < 10; i++)
//		printf("%d ", arr[i]);
//	return 0;
//}

//int main()
//{
//	int m, n, sum = 0;
//	scanf("%d%d", &n, &m);
//	int i, j;
//	int arr[100][100] = { 0 };
//	//输入数值
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < m; j++)
//		{
//			scanf("%d", &arr[i][j]);
//			//判断是否大于0
//			if (arr[i][j] > 0)
//				sum += arr[i][j];
//		}
//	}
//	printf("%d\n", sum);
//	
//	return 0;
//}

//
//int Cmp_int(const void* e1, const void* e2)
//{
//	return (*(int*)e1 - *(int*)e2);
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int arr[50] = { 0 };
//	int i;
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	scanf("%d", &arr[n]);
//	int sz = n + 1;
//	qsort(arr, sz, sizeof(arr[0]), Cmp_int);
//	for (i = 0; i < n + 1; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//int main()
//{
//	int n, i;
//	scanf("%d", &n);//表示n科
//	float arr[20] = { 0 };
//	float sum = 0.0;
//	float max = 0.0;
//	float min = 100.0;
//
//	for (i = 0; i < n; i++)
//	{
//		scanf("%f", &arr[i]);
//		if (arr[i] < min)
//			min = arr[i];
//		if (arr[i] > max)
//			max = arr[i];
//		sum += arr[i];
//	}
//	printf("%.2f %.2f %.2f\n", max, min, (sum / n));
//	return 0;
//}





//int cmp_int(const void* e1, const void* e2)
//{
//	//return (*(int*)e2 - *(int*)e1);  //e2减去e1  ，得到降序
//	return (*(int*)e1 - *(int*)e2);    //e1减去e2，得到升序
//}
//
//int main()
//{
//	int arr[10] = { 1,2,4,90,5,6,7,854,8,9 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	qsort(arr, sz, sizeof(arr[0]), cmp_int);
//
//	int i = 0;
//	for (i = 0; i < sz; i++)
//		printf("%d ", arr[i]);
//	return 0;
//}


//int main()
//{
//	int m, n;
//	scanf("%d%d", &m, &n);
//	 
//	return 0;
//}


//
//
//int main()
//{
//
//	short n = 0;
//	int arr[98] = { 0 };
//	while (scanf("%hd", &n) != EOF)
//	{
//		int i, j;
//		int count = 0;
//		for (i = 2; i <= n; i++)
//		{
//			for (j = 2; j <= n; j++)
//			{
//				if (i % j == 0 && j != i)
//				{
//					arr[i] = 0;
//					break;
//				}
//			}
//			if (j == n + 1)
//				arr[i] = i;
//		}
//		for (i = 2; i <= n; i++)
//		{
//			if (arr[i] != 0)
//				printf("%d ", arr[i]);
//			else
//				count++;
//		}
//		printf("\n%d\n",count);
//	}
//	return 0;
//}



//int Add(int x, int y)
//{
//	return x + y;
//}
//
//int main()
//{
//	int arr[10] = { 0 };
//	int x = 0;
//	
//	//数组指针
//	int (*parr)[10] = &arr;
//	//函数指针
//	int (*padd)(int, int) = Add;
//	//整形指针
//	int* px = &x;
//
//	// 函数指针数组
//	int (*(*pAdd[5]))(int, int) = &padd;
//	//函数指针数组的指针
//	int (*(*psadd)[5])(int, int) = &pAdd;
//
//	return 0;
//}




//int main()
//{
//	int i, j;
//	int count = 1;
//	for (i = 0; i < 3; i++) // 上半部分
//	{
//		//加空格补充
//		printf("  ");
//		for (j = 0; j < 7; j++)
//		{
//			if (j < 3 - i)
//				printf("    "); //3格
//			else if (j > 3 + i)
//				printf("    ");
//			else
//				printf("%d   ", count++);
//		}
//		printf("\n");
//	}
//
//	for (i = 0; i < 4; i++)  //下半部分  包括中间
//	{
//		//需要注意的是，在下半部分，越往下走，需要的空格加2
//		//因为上半部分输出的是个位数，与下面的产生一定的差距
//		if (i >= 1)
//			printf("  ");
//		if (i >= 2)
//			printf("  ");
//		if (i >= 3)
//			printf("  ");
//		for (j = 0; j < 8; j++)
//		{
//			if (j < 1 + i)
//				printf("  ");
//			else if (j > 7 - i)
//				printf("  ");
//			else
//				printf("%d  ", count++);
//		}
//		printf("\n");
//	}
//	return 0;
//}

