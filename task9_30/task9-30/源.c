# define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
//void test()
//{
//	//static ���ξֲ�����
//	//�ֲ��������������ڱ䳤
//	//static  ����ȫ�ֱ���
//	//�ı��˱�����������  -�������̬��ȫ�ֱ���ֻ���ڸ�Դ�ļ��ڲ�ʹ��
//	//static  ���κ���
//	//�ı��˺�������������-----�ⲿ��������--���ڲ���������
//
//	static int a = 1;//a��һ����̬�ľֲ�����
//	a++;
//	printf("a=%d\n", a);
//}
//
//int main()
//{
//	int i = 0;
//	extern int g_val;//extern---�����ⲿ���ŵ�
//	printf("%d\n", g_val);
//	while (i < 5)
//	{
//		test();
//		i++;
//
//	}
//	return 0;
//}

//��������
int Max(int x, int y)
{
	if (x > y)
		return x;
	else
		return y;
}
//#define  �����
#define MAX(X,Y) (X>Y?X:Y)

int main()
{
	int a, b;
	a = 10;
	b = 20;
	//��������
	//int max = Max(a, b);
	//printf("max=%d\n", max);
	//������  max=(a>b?a:b)
	max = MAX(a, b);
	printf("max=%d\n", max);

	return 0;
}

//int main()
//{
//	int a = 10;
//	int* p=&a;//---ȡa�ĵ�ַ
//	//��һ�ֱ�����������ŵ�ַ��----ָ�����
//	//  int*  ��p������
//	printf("%p\n", &a);
//	printf("%p\n", p);
//	//��ӡ��������16���Ƶĵ�ַ
//	//%p ��������ӡ��ַ��
//	*p = 20;//*_  ��ʾ  �����ò�����
//	//��˼�ǽ�20��ֵ��a��������a=20
//	printf("a=%d\n", a);
//
//	return 0;
//}

//int main()
//{
//	char ch = 'w';
//	char* CH=&ch;
//	//*CH = 'a';ע���������ʲô���ͣ�����ָ�����ʲô����+*����
//
//	printf("%c\n",ch);
//	return 0;
//}