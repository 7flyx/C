# define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>



int main()
{
	int count = 0;
	int year = 0;
	for (year = 1000; year <= 2000; year++)
	{
		/*1.�ܱ�4���� �Ҳ��ܱ�100������������
		2.�ܱ�400������������*/
		
		if (year % 4 == 0 && year % 100 != 0)
		{
			printf("%d ", year);
			count++;
		}
		else if (year % 400 == 0)
		{
			printf("%d ", year);
			count++;
		}

	}
	printf("\ncount=%d\n", count);

	return 0;
}


//int main()
//{
//	int m = 0;
//	int n = 0;
//	int r = 0;
//	scanf("%d%d", &m, &n);
//
//	while (m % n)
//	{
//		r = m % n;   //շת�ദ��
//		m = n;
//		n = r;
//	}
//	printf("�������:%d\n", n);
//	return 0;
//}



//int main()
//{
//	//��С�����˳�����
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	scanf("%d%d%d", &a, &b, &c);//2  1  3
//	//�㷨ʵ��----��˳�����¸�ֵ��a,b,c����
//	//a�з����ֵ��b��֮��c��С
//
//	if (a < b)
//	{
//		int tmp = a;//������ʱ��������ԭ��a��ֵ����ʧ
//		a = b;    //b��ֵ��a
//		b = tmp;
//	}
//	if (a < c)
//	{
//		int tmp = a;
//		a = c;
//		c = tmp;
//	}
//	if (b < c)
//	{
//		int tmp = b;
//		b = c;
//		c = tmp;
//	}
//	printf("%d %d %d\n", a, b, c);
//	return 0;
//}


//int bin_search(int arr[], int left, int right, int key)
//{
//	int mid = 0;
//	while (left <= right)
//	{
//		mid = (left + right) >> 1;
//		if (arr[mid] > key)
//		{
//			right = mid - 1;
//		}
//		else if (arr[mid] < key)
//		{
//			left = mid + 1;
//		}
//		else
//			return mid;//�ҵ��ˣ������±�
//	}
//	return -1;//�Ҳ���
//}


//
//int main()
//{
//	int i = 0;
//	char password[20] = { 0 };
//	
//
//	for (i = 0; i < 3; i++)
//	{
//		scanf("%s", password);
//		if (strcmp(password, "123456") == 0)//�����ַ����ж��Ƿ���ȣ������á�==��
//		{//strcmp���ǿ⺯��<string.h>,���ڱȽ������ַ����Ƿ����
//			//�����ȣ�����0.    ���ǰ�ߴ��ں��ߣ����ش���0�����֣����ǰ��С�ں��ߣ�����С��0������
//			printf("��½�ɹ�!\n");
//			break;
//		}
//		if (i < 2)
//		{
//			printf("�����������������!\n");
//		}
//	}
//	if (i == 3)
//	{
//		printf("��½ʧ�ܣ����Ժ�����\n");
//	}
//	return 0;
//}
//
////int main()
////{
////	char arr1[] = "hello world";
////	char arr2[] = "***********";
////
////	int left = 0;
////	int right = strlen(arr2) - 1;
////
////	while (left <= right)
////	{
////		arr2[left] = arr1[left];
////		arr2[right] = arr1[right];
////		Sleep(1000);//����ͷ�ļ�<windows.h>
////		system("cls");//ִ��ϵͳ�����һ������-cls-�����Ļ������ͷ�ļ�<stdlid.h>
////		left++;
////		right--;
////		printf("%s\n", arr2);
////	}
////	return 0;
////}
////
////
//
////���ֲ����㷨
////int main()
////{
////	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
////	int k = 9;//����
////
////	int left = 0;//���±�
////	int right = sizeof(arr) / sizeof(arr[0]) - 1;//���±�
////	
////	while (left <= right)
////	{
////		int mid = (left + right) / 2;//����
////		if (arr[mid] < k)
////		{
////			left = mid + 1;
////		}
////		else if (arr[mid] > k)
////		{
////			right = mid - 1;
////		}
////		else
////		{
////			printf("�ҵ��ˣ��±���%d\n", mid);
////			break;
////		}
////		if (left > right)		
////			printf("�Բ����Ҳ���\n");
////		
////
////	}
////
////	return 0;
////}