# define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include "add.h"


//�ݹ�ĽǶ�ȥд����ʹ����ʱ����
int my_strlen(char* str)
{

	if (*str != '\0')
	{
		return 1 + my_strlen(str+1);
		  //��ַ��һ������������һ���ַ����жϣ������ǹ������i��
	}
	return 0;
	
}

int main()
{
	char arr[] = "bit";
	int len = my_strlen(arr);//arr����ȥ���ǵ�һ��Ԫ�صĵ�ַ

	printf("len=%d\n", len);
	return 0;
}

//�ݹ�
//void prime(int n)
//{
//	//1234,�ֱ��ӡ1 2 3 4
//	if (n > 9)
//	{
//		prime(n / 10);//123			
//	}
//	printf("%d ", n % 10);
//}
//
//int main()
//{
//	int num = 0;
//	scanf("%d", &num);//1234
//
//	prime(num);
//	return 0;
//}



//int main()
//{
//	int a = 10;
//	int b = 20;
//	int sum = Add(a, b);
//
//	printf("%d\n", sum);
//	return 0;
//}