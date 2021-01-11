# define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>


int main()
{
	char arr1[] = "##############";
	char arr2[] = "welcome to bit";

	int left = 0;//左下标
	int right = strlen(arr2) - 1;//strlen，计算字符串长度   。 右下标

	while (left<=right)
	{
		arr1[left] = arr2[left];
		arr1[right] = arr2[right];

		printf("%s\n", arr1);

		left++;
		right--;
	}

	return 0;
}


//二分查找法
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);//计算元素个数
//	int k = 7;//查找的数值
//
//	int left = 0;//左下标
//	int right = sz - 1;//右下标
//		
//	while (left<=right)
//	{
//		int mid = (left + right) / 2;//中间元素下标
//		if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			printf("找到了，下标是:%d\n", mid);
//			break;
//		}//特别注意代码块的问题
//	}
//	if (left > right)
//		printf("对不起，该数组没有\n");
//
//	return 0;
//
//}


//int main()
//{
//	//题目:计算n的阶乘
//

//	int i = 0;
//	int n = 0;
//	int ret = 1;
//	scanf("%d", &n);
//
//	for (i = 1; i <= n; i++)
//	{
//		ret = ret * i;//上次计算的ret的值被保留了下来，可以调试看看
//	}
//	printf("%d\n", ret);
//	return 0;
//}

//int main()
//{
//	int n = 0;
//	int i = 0;
//	//scanf("%d", &n);
//
//	int sum = 0;
//	for (n=1;n<=3;n++)
//	{
//		int ret = 1;
//		for (i = 1; i <= n; i++)
//		{
//			ret = ret * i;//计算阶乘
//		}
//		sum = sum + ret;
//	}
//	printf("sum=%d\n", sum);
//	
//	return 0;
//}

int main()
{
	char password[20] = { 0 };
	int ch = 0;
	int m = 0;

	
	printf("请输入密码:");
	scanf("%s", password);

	printf("请确认(Y/N):>");

	while ((m = getchar()) != '\n')
	{
		;
	}

	ch = getchar();
	if (ch == 'Y')
		printf("确认成功\n");//缓冲区问题，‘\n’
	else
		printf("放弃确认\n");



	return 0;
}