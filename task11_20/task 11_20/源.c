# define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>


int main()
{

	int arr[] = { 1,3,45,67,4,367,8,9,0,20 };
	int i;
	int n = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (i = 0; i < sz; i++)
	{
		if (arr[n] < arr[i])
		{
			int tmp = n;
			n = arr[i];
			arr[i] = tmp;
		}
	}
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}



//int main()
//{
//	int num1, num2;
//	char n;
//	printf("ע��!ע�⣡�������Ĵ����㣡\n");
//	printf("������������ֵ����ע���Ⱥ�˳�򣡣���\n");
//	printf("������:>");
//	scanf("%d%d", &num1, &num2);
//	getchar();
//	printf("�����������:>");
//	scanf("%c", &n);
//	
//	if (n == '+')
//	{
//		printf("%d + %d = %d\n", num1, num2, num1 + num2);
//	}
//	else if (n == '-')
//	{
//		printf("%d - %d = %d\n", num1, num2, num1 - num2);
//	}
//	else if (n == '*')
//	{
//		printf("%d * %d = %d\n", num1, num2, num1 * num2);
//	}
//	else
//	{
//		printf("%d / %d = %d\n", num1, num2, num1 / num2);
//	}
//	return 0;
//}
//
////
////int main()
////{
////	int num;
////	printf("��������ֵ:>");
////	scanf("%d", &num);
////	if (num % 2 == 1)
////	{
////		printf("%d��������\n", num);
////	}
////	else
////	{
////		printf("%d��ż����\n", num);
////	}
////	return 0;
////}
//
////int main()
////{
////	char arr[] = { 'A','E','I','O','U','a','e','i','o','u' };
////	char n;
////	int i;
////	printf("��������ĸ:>");
////	scanf("%c", &n);
////	for (i = 0; i < 10; i++)
////	{
////		if (n == arr[i])
////		{
////			printf("%c��Ԫ����ĸ��\n", n);
////			break;
////		}
////	}
////	if (10 == i)
////	{
////		printf("%c����Ԫ����ĸ��\n",n);
////	}
////	return 0;
////}
