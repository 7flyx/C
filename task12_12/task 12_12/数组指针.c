# define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>



int main()
{
	int i = 0;
	int n = 10;
	for (i = 0; i < n - 1; i++)
	{
		//һ��
		int j = 0;
		for (j = 0; j < n - 1 - i; j++)//Խ�ں��棬�ȽϵĶ���Խ��Խ��
		{
			if (arr[j] < arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

//void Print1(int arr[3][5], int x, int y)//��ͨ�ı�������Ϊ�βν���
//{
//	int i = 0;
//	for (i = 0; i < x; i++)
//	{
//		int j = 0;
//		for (j = 0; j < y; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//}
//void Print2(int(*p)[5], int x, int y)
//{
//	int i = 0;
//	for (i = 0; i < x; i++)
//	{
//		int j = 0;
//		for (j = 0; j < y; j++)
//		{
//			//printf("%d ", *(*(p + i) + j));
//			//�ȶ���һ�н��н����ã�Ȼ���ټ�j���ٽ��н����ý��д�ӡ
//			printf("%d ", *(p[i] + j));
//			printf("%d ", p[i][j]);
//			//��ʵ���Խ��˴�����Ϊ�����±�ķ��ʷ�ʽ
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int arr[3][5] = { {1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7} };
//	Print1(arr, 3, 5);
//	Print2(arr, 3, 5);
//	return 0;
//}