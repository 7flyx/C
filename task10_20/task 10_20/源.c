# define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>


//��ŵ������
void move(char c1, char c2)
{
	printf("%c -> %c\n", c1, c2);  //%c������� �ַ���%s������� �ַ���
}

void hanoi(int n, char x, char y, char z)
{
	if (1 == n)
		move(x, z);
	else
	{
		hanoi(n - 1, x, z, y);
		move(x, z);
		hanoi(n - 1, y, x, z);
	}
}
int main()
{
	int n = 0;
	printf("������������");
	scanf("%d", &n);
	char a = 'a';
	char b = 'b';
	char c = 'c';
	hanoi(n,a,b,c);
	      //a����b����c��
	return 0;
}

//    
////int Fib(int n)
////{
////	if (n <= 2)
////		return 1;
////	else  //���Լ��㣬�������˴����ظ��ļ��㣬Ч�����ˣ�����  ����
////		return Fib(n - 1) + Fib(n - 2);
////}
//
//
//int Fib(int n)
//{
//	//1   1   2    3    5    8    13  ....
//	//a   b   c 
//	//��ǰ����ĺ�ȥ��������
//	int a = 1;
//	int b = 1;
//	int c = 1;   //���ǵ�n<=2ʱ�����Ƿ���1�����Գ�ʼ��Ϊ 1 ��������0��
//	while (n > 2)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//		n--;
//	}
//	return c;
//}
//int main()
//{
//	//�����n��쳲���������
//	int n = 0;
//	scanf("%d", &n);
//	int ret = 0;
//	ret = Fib(n);
//	printf("%d\n", ret);
//	return 0;
//
//
////ѭ���ķ�ʽ
////int Fac1(int n)
////{
////	int i = 0;
////	int ret = 1;
////	for (i = 1; i <= n; i++)
////	{
////		ret *= i;
////	}
////	return ret;
////}
//
////�ݹ�ķ�ʽ
////int Fac2(int n)
////{
////	if (n <= 1)
////		return 1;
////	else
////		return n * Fac2(n - 1);
////}
////int main()
////{
////	//����n�Ľ׳ˡ�
////	int n = 0;
////	scanf("%d", &n);
////	int ret = 0;
////	ret = Fac2(n);
////
////	printf("%d\n", ret);
////	return 0;
//}
