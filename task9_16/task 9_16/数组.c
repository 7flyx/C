# define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int a = 10;
	int b = 20;
	int max;
	
	max = (a > b ? a : b);//��Ŀ������;��ע�⣿�����a��b��˳��
	//ǰ����������������������һλ���ʽ����֮������ڶ�λ

	printf("max=%d\n", max);

	return 0;
}
//int Max(int x ,int y)
//{
//	if (x > y)
//		return x;
//	else
//		return y;
//}
//int main()
//{
//	int num1 = 89;
//	int num2 = 99;
//	int num3 = 39;
//	int max;
//
//	max = Max(Max(num1, num2), num3);//Ƕ�׺�����
//	printf("max=%d\n", max);
//	return 0;
//}

//int main()
//{
//	int a = (int)3.141;//ǿ������ת��
//	printf("%d\n", a);
//	return 0;
//}
//int main()
//{
//	int a = 0;//4���ֽڣ���Ϊ32��bitλ
//	int b = ~a;
//	//ԭ��a����32��0��  00000000000000000000000000000000
//	//��~a����32��1��   11111111  ��ȫ��ȡ��
//	//�����ڴ洢ʱΪ�����ƵĲ���
//
//	//���룺11111111111111111111111111111111
//	//���룺11111111111111111111111111111110   �������1�õ���
//	//ԭ�룺10000000000000000000000000000001   �������һλ�����䣬����ȡ����
//
//	printf("%d\n", b);//����ӡʱ��ԭ�룬���轫�������ת����ӡ
//	//int a = 10;
//	//int arr[] = { 1,2,3,4,5,6 };
//
//	//printf("%d\n", sizeof (a));
//	//printf("%d\n", sizeof(arr) / sizeof(arr[0]));//arr��ʹ����ҪԲ���� 
//
//	//	return 0;
//}