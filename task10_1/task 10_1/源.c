# define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
int main()
{
	int line = 0;
	//printf("������δ�ɹ���ͬ־����Ŭ��\n");

	while (line < 100)
	{
		++line;
		printf("%d:������δ�ɹ���ͬ־����Ŭ��\n",line);
		
	}
	if (line >= 100)
		printf("�ɹ�\n");
	return 0;	
}
//int main()
//{
//	int a = 0;
//	printf("������������1 or 2��>:\n",a);
//	scanf("%d", &a);
//	if (a == 1)
//		printf("�ú�ѧϰ���кõĽ��\n");
//	else
//		printf("���ȥ������\n");
//	return 0;
//}
//int main()
//{
//	char arr1[] = "bit";//�ַ���������\0��Ϊ������־�������ַ�������
//	char arr2[] = { 'b','i','t' };//û��\0��Ϊ������־�����Ժ�����������
//	char arr3[] = { 'b','i','t','\0' };//����\0�����Խ���
//
//	printf("%s\n", arr1);
//	printf("%s\n", arr2);
//	printf("%s\n", arr3);
//	return 0;
//}

//#define MAX(x,y) (x>y?x:y)
//int main()
//{
//	int a = 10;
//	int b = 20;
//
//	int max = MAX(a, b);
//	
//	printf("max=%d\n", max);
//	return 0;
//}
//int main()
//{
//	int a = 10;
//	int* b = &a;//b��ŵ���a�ĵ�ַ
//
//	*b = 20;
//
//	printf("%p\n", b);
//	return 0;
//}