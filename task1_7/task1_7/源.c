# define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>

//enum Color
//{
//	RED,
//	GREEN,
//	BLUE
//};
//
//enum Sex
//{
//	BOY,
//	GIRL
//};
//int main()
//{
//	//ö�ٳ���---Ҳ����һһ�о�
//	//�ȱ�ʶ����������һ��
//	//enum�Ĵ�С������һ�����Σ������ĸ��ֽڵĴ�С
//	enum Color c = BLUE;
//	enum Sex s = BOY;
//
//	return 0;
//}



//union sn
//{
//	//������---������
//	//��ʵ�ͽṹ����Щ���ƣ�����ռ�õĿռ���ͬһ��Ķ���
//	//�������ù���������ļ������С���ֽ���
//	char c;
//	int i;
//};
int check_num()
{
	union
	{
		char c;
		int i;
	}u;
	u.i = 1;

	return u.c; //ֱ�ӷ���ȥ���ܹ��õ���һ���ֽڵĿռ�
}

int main()
{
	int ret = check_num();
	if (ret == 1)
		printf("С��\n");
	else
		printf("���\n");
	return 0;
}