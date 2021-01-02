# define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <assert.h>


char* my_strstr(const char* p1, const char* p2)
{
	assert(p1 && p2);
	//���ȱ���p1 p2�ĵ�ַ�����ܸı�p1 2������
	char* s1 = (char*)p1;
	char* s2 = (char*)p2;
	char* cur = (char*)p1;
	while (*cur)  //Ŀ�ĵص��ַ���Ϊ\0ʱ������ѭ��
	{
		//1. ���Ƚ��µĵ�ַ����cur��s2
		s2 = (char*)p2; //��֤ÿ��ѭ��ʱ���Ǵӵ�һ���ַ���ʼ�жϵ�
		s1 = cur;   //��֤�´�ѭ����ʱ���Ǵ��ϴο�ʼ�жϵ���һ���ַ����¿�ʼѭ���ж�

		//2. ��ʼ�ж�--�����ж����� �����ַ���������\0����*s1��*s2���������
		while (*s1 && *s2 && (*s1 == *s2))
		{
			s1++;
			s2++;
		}

		//3. �ж�Դͷ���ַ��ǲ���\0������ǵĻ���˵�����ַ����ҵ��ˣ�����Ŀ�ĵ�  �ĵ�ַ
		if (*s2 == '\0')
			return cur;
		
		//���Ŀ�ĵص��ַ������������ˣ�������Ŀ�ĵ��ַ������ҵ�\0�ˣ�������������û����
		//˵����Ŀ�ĵ��ַ����Ҳ��������ؿ�ָ�뼴��
		if (&s1 == '\0')
			return NULL;

		//4.�����ѭ����û�ߵĻ���Ŀ�ĵ��ַ�������ַ����ߣ���������
		cur++;
	}
	// 5. ����ѭ������󣬻�û�ҵ���˵��û�У����ؿ�ָ�뼴��
	return NULL;
}

//ʵ��strstr�ĺ���
int main()
{
	char arr1[] = "abcdef";
	char arr2[] = "cdef";
	char* ret = my_strstr(arr1, arr2);
	if (ret == NULL)
		printf("���ַ���û���ҵ���\n");
	else
		printf("%s\n", ret);
	return 0;
}