# define _CRT_SECURE_NO_WARNINGS 


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

//int main()
//{
//	int* p = (int*)malloc(10 * sizeof(int));
//	//�������ɹ������ص�һ���ռ�ĵ�ַ�����ɹ��Ļ������ؿ�ָ��
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			*(p + i) = i;
//		}
//		for (i = 0; i < 10; i++)
//		{
//			printf("%d ", *(p + i));
//		}
//	}
//	//ʹ����֮����Ҫ�ͷſռ䣬����ָ�븳ֵΪ��ָ�룬�Է�����Ĵ���ʹ�ã����´���
//	free(p);
//	p = NULL;
//	return 0;
//}



int main()
{
	//calloc��ǰ��Ĳ�����������ٸ�Ԫ�أ��������ÿ��Ԫ�صĴ�С��ע�����ﲻ���������˼
	//���������malloc�������������ڣ�calloc����ռ����Զ���ʼ��Ϊ0����malloc��������
	int* p = (int*)calloc(10, sizeof(int));
	if (p != NULL)  //�п��ܻ᷵�ؿ�ָ��
	{
		int i = 0;
		for (i = 0; i < 10; i++)
			printf("%d ", *(p + i));
	}

	//�ȴ�����ʱ�������洢ָ�룬�Է�realloc�����ķ���ֵ�ǿ�ָ�룬��ԭ����ָ�����Ū����
	int* p2=(int*)realloc(p, 20);
	if (p2 != NULL)
		p = p2;

	//�ͷſռ�
	free(p);
	p = NULL;
	return 0;
}