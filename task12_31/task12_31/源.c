# define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <string.h>
#include <assert.h>


//int my_strlen(char* str)
//{
//	if (*str != '\0')
//		//return my_strlen(str + 1) + 1;
//		return my_strlen(++str) + 1;
//	else
//		return 0;
//
//}
//int main()
//{
//	printf("%d\n", my_strlen("abcdef"));
//	return 0;
//}




//char* my_strcpy(char* dest, const char* src)
//{
//	//�����ж�������ַ���ǿյ�ַ
//	assert(dest != NULL);
//	assert(src != NULL);
//	char* ret = dest;//���ȱ���dest����Ԫ�ص�ַ
//
//
//
//	//���ַ�����򵥣������һ��\0������dest�󣬸ñ��ʽ�Ľ��Ϊ�٣����˳�ѭ��
//	while (*dest++ = *src++)
//	{
//		;
//	}
//
//	////�ڶ��ַ���--�÷���û��ֻ�ǲ������
//	//while (*src != '\0')
//	//{
//	//	*dest = *src;
//	//	dest++;
//	//	src++;
//	//}
//	//*dest = *src;//���������Ǹ�\0
//
//	return ret;//����dest����Ԫ�ص�ַ
//}
//
//int main()
//{
//	char arr1[] = "abcdefg";
//	char arr2[] = "bit";
//
//	my_strcpy(arr1, arr2); // �ַ�����������\0Ҳһ�����˹�ȥ
//	printf("%s\n", arr1);
//	return 0;
//}





char* my_strcat(char* dest, const char* src)
{
	//���ȱ���dest�ĵ�ַ�����淵��ֵ��Ҫ
	char* ret = dest;
	//1. �ҵ�dest�ַ��������\0
	while (*dest != '\0')
		dest++;
	//2. �ٴ�\0��λ�ÿ�ʼ����
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}

int main()
{
	//ʵ��strcat���ַ���׷�Ӻ���
	//ʹ�øú���ʱ����Ҫע��Ŀ�������Ƿ��ܹ��洢��
	char arr1[30] = "abcedfg";
	char arr2[] = "hello";

	my_strcat(arr1, arr2);
	printf("%s\n", arr1);
	return 0;
}


