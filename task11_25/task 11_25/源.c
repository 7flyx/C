# define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>


//��Ŀ����������int���͵���ֵ�����������У���ͬ��λ��bit���ĸ���


//int count_num2(int x, int y)
//{
//	//��λ���ĽǶ������
//	int count = 0;
//	int i = 0;
//	for (i = 0; i < 32; i++)
//	{
//		if ((x >> i) ^ (y >> i) == 1)
//			count++;
//	}
//	return count;
//}
//0011   3
//0110   6
//1001   9

//1010   10 
//1111   15


int count_num2(int n, int m) {
	int re = m ^ n;//  ��һ��֮��ÿ�ζ�Ҫ��λ��������re��ʾʣ��ģ�
	int sum = 0;
	//while (re) {
	//	if ((re & 1) == 1) {
	//		//re & 1���re���λ��1����������1����ʾ��λ��ͬsum++��
	//		sum++;
	//	}
	//	re = re >> 1;//������λ

	//}
	//return sum;
	return re;
}
int main()
{
	int x, y;
	scanf("%d%d", &x, &y);

	int count = count_num2(x, y);

	printf("��ͬλ�ĸ���Ϊ:%d\n", count);
	printf("%d\n", count);

	return 0;
}







//�ⷨһ����λ�������
//int count_num(int x)
//{
//	int count = 0;
//	int n = 0;
//	for (n = 0; n < 32; n++)
//	{
//		if (((x >> n) & 1) == 1)
//			count++;
//	}
//	return count;
//}




//�ⷨ������Ч�ⷨ-----  x=x&(x-1)
//x=13

//1101  x
//1100  x-1
//1100  ��x
//1011  x-1
//1000  ��x
//0111  x-1
//0000  ��x

//�ܽ᣺ÿһ����λ��(x-1)���ܹ���������������������һ��1
//�㷨ʵ��
//int count_num(int x)
//{
//	int count = 0;
//	while (x)
//	{
//		x = x & (x - 1);
//		count++;
//	}
//	return count;
//}
//
//
//
//int main()
//{
//	int input = 0;
//	scanf("%d", &input);
//	int count = count_num(input);
//
//	printf("��%d��\n",count);
//	return 0;
//}



//�޷��������������������ôת��Ϊ�޷�������
//int count_a_one(unsigned int n)
//{
//	int count = 0;
//	while (n)
//	{
//		if (1 == n % 2)
//		{
//			count++;
//		}
//		n /= 2;
//	}
//	return count;
//}
//
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	int count = count_a_one(a);
//
//	printf("%d\n", count);
//
//	return 0;
//}



//int count_input_one(int n)
//{
//	int count = 0;
//	int i = 0;
//	for (i = 0; i < 32; i++)
//	{
//		if (1 ==((n >> i) & 1))  //ע�������ŵ�������������
//		{
//			count++;
//		}
//	}
//	return count;
//}
//
//int main()
//{
//	int input = 0;
//	printf("��������ֵ��>");
//	scanf("%d", &input);
//	int count = count_input_one(input);
//	printf("%d\n", count);
//	
//	return 0;
//}
