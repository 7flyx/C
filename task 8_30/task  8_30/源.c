# define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int a = 100;
	int b = 20;
	int max = 0;

	max = (a > b ? a : b);
	printf("%d\n", max);

	return 0;
}





//int main()
//{
//	int a = 10;
//	int b = a++;  //����++����ʹ����++��
//	//���磺�����Ȱ�b=a=10���㣬�ٰ�a++����õ��µ�a
//	
//	//ͬ��ǰ��++����++��ʹ��
//	//int a = 10;
//	//int b = ++a;
//
//	printf("a = %d b = %d", a, b);
//	return 0;
//}
