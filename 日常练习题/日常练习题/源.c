# define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


//int main()
//{
//	//����a+aa+aaa+aaaa+aaaaa��ֵ
//	int n, k; 
//	scanf("%d%d", &n, &k);
//	int sum = 0;
//	while (k)
//	{
//		sum += sum * 10 + n;
//		k--;
//	}
//	printf("%d\n", sum);
//	return 0;
//}


//��������Ϸ
//int main()
//{
//	int n = 0;
//	srand((unsigned int)time(NULL));
//	int s = rand() % 100 + 1;//���������1-100֮��
//	while (1)
//	{
//		printf("������֣�>");
//		scanf("%d", &n);
//		if (n > s)
//			printf("��´��ˣ�\n");
//		else if (n < s)
//			printf("���С�ˣ�\n");
//		else
//			break;	
//	}
//	printf("��ϲ�㣬�¶��ˣ�\n");
//	return 0;
//}


//쳲�������
//int main()
//{
//	int n, i;
//	scanf("%d", &n);
//	int a = 1;
//	int b = 1;
//	int c = 0;
//	if (n <= 2)
//	{
//		printf("1\n");
//	}
//	else
//	{
//		for (i = 0; i < n - 2; i++)
//		{
//			c = a + b;
//			a = b;
//			b = c;
//		}
//		printf("%d\n", c);
//	}
//	return 0;
//}



//��дһ������ʵ��n^k��ʹ�õݹ�ʵ��
//int my_pow(int n, int k)
//{
//	if (k == 1)
//		return n;
//	else
//		return my_pow(n, k - 1) * n;
//}
//
//int main()
//{
//	int n = 0;
//	int k = 0;
//	scanf("%d%d", &n, &k);
//	
//	printf("%d\n", my_pow(n, k));
//	return 0;
//}



//дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮�ͣ�
//���磬����DigitSum(1729)����Ӧ�÷���1 + 7 + 2 + 9�����ĺ���19
//int DigitSum(int n)
//{
//	if (n < 10)
//		return n;
//	else
//		return DigitSum(n / 10) + (n % 10);
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d\n", DigitSum(n));
//	return 0;
//}




//��дһ������ reverse_string(char * string)���ݹ�ʵ�֣�
//ʵ�֣��������ַ����е��ַ��������С�
//Ҫ�󣺲���ʹ��C�������е��ַ�������������
void reverse_string(char* string)
{
	//�㷨˼�룺������ַ����Ĵ�С�����±�Ϊ0��Ԫ�����±����һ��������Ȼ��ָ��++--
	int len = strlen(string);
	char* left = string;
	char* right = string + len - 1;
	while (left < right)
	{
		char tmp = *right;
		*right = *left;
		*left = tmp;
		left++;
		right--;
	}
}

int main()
{
	char arr[] = "abcedf";
	reverse_string(arr);
	printf("%s\n", arr);
	return 0;
}