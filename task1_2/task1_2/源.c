# define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>



//int my_strcmp(const char* str1, const char* str2)
//{
//	//��ʵ�ַ����Ƚϣ��ȵĲ�������ĳ���
//	//����һ������ĸȥ�Ƚϣ��ڹ����У�˭��ASCII��ֵ������ַ����ʹ�
//	//����Ƚ���֮�󣬲��ǵ���
//
//	while (*str1 == *str2)
//	{
//		if (*str1 == '\0')
//			return 0; //��ȵ�ʱ��
//		str1++;
//		str2++;
//	}
//	if (*str1 > * str2)
//		return 1;//����
//	else
//		return -1;//С��
//}
//
//int main()
//{
//	char* p1 = "abcedf";
//	char* p2 = "qwert";
//	int ret = my_strcmp(p1, p2);
//	printf("ret = %d\n", ret);
//	return 0;
//}




//strncpy������ʵ��
//char*  my_strncpy(char* str1, const char* str2, int n)
//{
//	int i = 0;
//	char* tmp = str1; //������Ҫ������Ԫ�صĵ�ַ����Ҫ����
//	int len = strlen(str2); //��Դͷ���ַ�������ʱ����Ҫ��0
//	for (i = 0; i < n; i++)
//	{
//		if (i > len)
//			*str1 = 0;
//		else
//			*str1 = *str2;
//		str1++;
//		str2++;
//	}
//	return tmp;
//}
//char* my_strncpy(char* str1, const char* str2, size_t n)
//{
//	char* tmp = str1; //������Ҫ������Ԫ�صĵ�ַ����Ҫ����
//	while (n && (*str1++ = *str2++))
//		n--;
//	if (n)
//		while (--n)
//			*str1 = 0;//��Դͷ���ַ�������ʱ����0
//	return tmp;
//}
//int main()
//{
//	char arr1[10] = "abcdef";
//	char arr2[] = "qwert";
//	my_strncpy(arr1, arr2, 7);
//	printf("%s\n", arr1);
//	return 0;
//}





//strncat�ĺ���ʵ��

char* my_strncat(char* str1, char* str2, size_t n)
{
	//�Ϲ�أ�������Ԫ�صĵ�ַ
	char* tmp = str1;
	while (*str1 != '\0')  //�ҵ�Ŀ�ĵص������ĵ�ַ
		str1++;  
	while (n--) 
	{
		if (*str2 == '\0')  //��֤str2����Խ�磬��������\0��ֱ������ѭ��
			break;
		*str1++ = *str2++;
	}
	if (*str1 != '\0')
		*str1 = '\0';  //������û�п���\0ʱ����һ��
	return tmp;
}

int main()
{
	char arr1[20] = "abcdef";
	char arr2[] = "qwert";

	//�ַ���׷�� strncat
	my_strncat(arr1, arr2, 5);  //����ֻ׷��5���ַ���ʵ����滹��һ��\0��������6��
	printf("%s\n", arr1);
	return 0;
}