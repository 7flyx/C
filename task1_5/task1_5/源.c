# define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>


//struct s
//{
//	char a[10];
//	char s;
//	int age;
//};




//λ�Σ��ṹ���е�һ������
//���þ���Ϊ�˽�ʡ�ռ䣬��Ȼʹ��λ�Σ�Ҳ��һЩע�⣬�����ƽ̨��
//λ�����ڴ��еĴ洢�кܶ಻ȷ�����أ����Դ�볣��ֲ������ʹ��λ�λ��ر�ע��λ�ε�ʹ��
struct Stu
{
	char a : 2;
	char b : 4;
	char c : 7;
	char d : 8;
};

int main()
{
	struct Stu s = { 0 };

	s.a = 2;
	s.b = 15;
	s.c = 20;
	s.d = 100;

	return 0;
}