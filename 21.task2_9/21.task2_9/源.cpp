# define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>

//int Insert_arr(int (*arr)[10], int size, int x)
//{
//	int i, j;
//	for (i = size - 1; i >= 0; i--)
//	{
//		//�ж�x�Ƿ�С��Ԫ��arr[i]�������Ļ����Ͳ���
//		if (x <= *(*(arr + i)) && *(*(arr + i))!= 0)
//		{
//			//����
//			*(*(arr + i)) = x;
//			return 1;
//		}
//		else
//		{
//			//Ԫ��������
//			*(*(arr + i + 1)) = *(*(arr + i));
//		}
//	}
//	return 0;
//}

int Insert_arr(int ps[10], int size, int x)
{
	int i = 0;
	for (i = size - 1; i >= 0; i--)
	{
		if (x >= ps[i] && ps[i] != 0)
		{
			ps[i+1] = x;
			return 1;
		}
		else if(i+1 < size)
			ps[i + 1] = ps[i];
	}
	return 0;
}

int main()
{
	//��3��˳��������--�±�Ϊ2
	int arr[10] = { 1,2,4,5,6,7,8,9 };
	int size = sizeof(arr)/sizeof(int);
	int ret = 0;
	ret = Insert_arr(arr, size, 3);
	if (ret)
		printf("����ɹ�!\n");
	else
		printf("����ʧ��!\n");
	int i = 0;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	return 0;
}