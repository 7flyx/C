# define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>

int Digitsum(int n)
{
	if (n > 0)
		return n % 10 + Digitsum(n / 10);
	else
		return 0;
}

int main()
{
	int n;
	scanf("%d", &n);
	int sum = Digitsum(n);
	printf("%d\n", sum);
	return 0;
}



//int main()
//{
//	int line = 0;
//	scanf("%d", &line);
//	int i, j;
//	//打印上半部分
//	for (i = 0; i < line; i++)
//	{
//		for (j = 0; j < line - 1 - i; j++)
//			printf(" ");
//		for (j = 0; j < 2 * (i) + 1; j++)
//			printf("*");
//		printf("\n");
//	}
//	//打印下板部分
//	for (i = 0; i < line - 1; i++)
//	{
//		for (j = 0; j <= i; j++)
//			printf(" ");
//		for (j = 0; j < 2 * (line - 1 - i) - 1; j++)
//			printf("*");
//		printf("\n");
//	}
//	return 0;
//}


//
//int main()
//{
//	//0-100000之间的水仙花数
//	int i = 0;
//	for (i = 0; i <= 100000; i++)
//	{
//		//1.计算i的位数   n
//		int tmp = i;
//		int n = 1;
//		int sum = 0;
//		while (tmp /= 10)
//		{
//			n++;
//		}
//		//2. 计算i的n次方的和  sum
//		tmp = i;
//		while (tmp)
//		{
//			sum += pow(tmp % 10, n);
//			tmp /= 10;
//		}
//		//3. 比较sum与i是否相等
//		if (i == sum)
//			printf("%d ", i);
//
//	}
//	return 0;
//}


//int main()
//{
//	//计算2+22+222+2222+22222  等等，n表示2，m表示几位数
//	int n, m, i;
//	scanf("%d%d", &n, &m);
//	int sum = 0;
//	int ret = 0;
//	for (i = 0; i < m; i++)
//	{
//		ret = ret * 10 + n;
//		//算法实现：以上一个数的结果作为下一个数的参数进行计算，捋清思路
//		sum += ret;
//	}
//	printf("%d\n", sum);
//	return 0;
//}



//void Research(char* str)
//{
//	//既然需要交换一个字符串的内容位置，就要拿到下标
//	assert(str);  //断言，保证传过来的不是空指针
//	int len = strlen(str);
//	char* left = str;
//	char* right = str + len - 1;
//	//此处的右下标，如果操作的对象仅仅是一个整形数组，直接用数字下标能够操作
//	//但是此处操作的一个字符串，单单的一个数字肯定不行，应该加上首元素的地址，
//	//可能会觉得首元素的地址，好像就是下标0啊，加不加0 ，似乎都无伤大雅，但并不是如此
//	//加的 str  其实是一个地址，而不是下标0
//
//
//	while (left < right)
//	{
//		//交换数据
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		*left++;
//		*right--;
//	}
//}
//
//int main()
//{
//	char arr[100] = { 0 };
//	gets(arr);  //读取一行的数据
//	Research(arr);
//	printf("%s\n", arr);
//	return 0;
//}









//#include <stdio.h>
//int main()
//{
//    int m, n, count = 0;  //m行  n列
//    int arr1[100][100] = { 0 };
//    int arr2[100][100] = { 0 };
//    scanf("%d%d", &m, &n);
//    int i, j;
//    for (i = 0; i < m; i++)  // arr1数组
//    {
//        for (j = 0; j < n; j++)
//        {
//            scanf("%d", &arr1[i][j]);
//        }
//    }
//
//    for (i = 0; i < m; i++)
//    {
//        for (j = 0; j < n; j++)
//        {
//            scanf("%d", &arr2[i][j]);
//        }
//    }
//    //比较数据
//    for (i = 0; i < m; i++)
//    {
//        for (j = 0; j < n; j++)
//        {
//            if (arr1[i][j] == arr2[i][j])
//            {
//                count++;
//            }
//        }
//    }
//    float sum = (float)count / (m * n) * 100;
//    printf("%.2f", sum);
//    return 0;
//}








//#include <stdio.h>
//int main()
//{
//    int n, m, x, i;
//    int arr[50] = { 0 };
//    scanf("%d", &n);
//    for (i = 0; i < n; i++)
//        scanf("%d", &arr[i]);
//    scanf("%d", &x); //插入的数
//    for (i = n - 1; i >= 0; i--)
//    {
//        if (arr[i] > x)
//            arr[i + 1] = arr[i];
//        else
//        {
//            arr[i+1] = x; 
//            break;
//        }
//    }
//    if (i == -1)
//        arr[i+1] = x;
//    for (i = 0; i <= n; i++)
//        printf("%d ", arr[i]);
//    return 0;
//}