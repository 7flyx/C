# define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>

int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	
	scanf("%d%d", &a, &b);//���뺯��scanf
		c = a + b;
		printf("c =%d\n", c);
	return 0;
}

//int main()
//{
//	int a = 0;
//	int b = ~a;
//	printf("%d\n", b);
//	return 0;
//}


//int main()
//{
//	int a = 0;
//	int arr[] = { 1,2,3,4,5,6 };
//	printf("%d\n", sizeof(int));
//	printf("%d\n",sizeof(a));
//	printf("%d\n", sizeof (arr)/ sizeof(arr[0]));//arr������Բ���Ű�������[0]��ʾ��һ��Ԫ�ء�1��
//	return 0;
//}
//





//int Max(int x, int y)  //�����º�������ע�ⷵ��ֵΪ�������������� 0
//{
//	if (x > y)
//		return x;
//	else
//		return y;
//}
//
//int main()
//{
//	int num1 = 79;
//	int num2 = 80;
//	int max = 0;
//
//	max = Max(num1, num2); //���±������������ĺ���ֵ
//	if (num1 > num2)
//		printf("���ֵ��%d\n", max);
//	else
//		printf("���ֵ��%d\n", max);

//}