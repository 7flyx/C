# define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <string.h>


//strtok�������÷�
//int main()
//{
//	char arr1[] = "fly@qq.com";  //Դ�ַ���
//	char* p = "@."; //�ָ������ַ����ϣ���ָ���������
//
//	//1. ����һ�ݿ�������Ϊstrtok��ı�Դ�ַ���������
//	char arr2[1024] = { 0 };
//	strcpy(arr2, arr1);
//
//	//2. forѭ��ʹ��
//	char* ret = NULL;
//	for (ret = strtok(arr2, p); ret != NULL; ret = strtok(NULL, p))
//	{
//		printf("%s ", ret);
//	}
//	return 0;
//}

//
//
//#include <errno.h>
////strerror
//int main()
//{
//	//��������Ϣת��
//	//���� 0----no error
//	//......
//	FILE* pf = fopen("ɨ��","r");  //�ļ���Ϊɨ�ף���r�������Ķ�����˼
//	//����Ķ����ɹ������ص��ǿ�ָ��
//	if (pf == NULL)
//		printf("%s\n", strerror(errno));
//	else
//		printf("oper file success");
//	/*char* p = strerror(errno);
//		printf("%s\n", p);*/
//	return 0;
//}


//struct s
//{
//	char name[20];
//	int age;
//	//char a;
//};
//void* my_memcpy(void* dest, const void* src, size_t num)
//{
//	//���ȱ���dest�ĵ�ַ�����淵��
//	void* ret = dest;
//	while (num--)
//	{
//		*(char*)dest = *(char*)src;  //һ�������ֽڣ���������
//		//(char*)dest++; ע�⣬�˴�����д�����⣬��Ϊ++�����ȼ�Ҫ�ߣ�������dest���
//		++(char*)dest; //���Ƿ��ŵ����ȼ�������
//		++(char*)src;
//	}
//	return ret;
//}
//int main()
//{
//	struct s arr1[] = { {"����", 20} };
//	struct s arr2[] = { 0 };
//	my_memcpy(arr2, arr1, sizeof((arr1)));
//
//
//	//printf("%d\n", arr2->age);
//	return 0;
//}



void* my_memmove(void* dest, const void* src, size_t num)
{
	//���ȱ���dest�����ݣ����淵��
	void* ret = dest;
	//1. �Ƚ����жϣ���dest�����ַʱ��src��ʲôλ��
	//�����src��src+num��������أ�������Ҫ�� ����ǰ �ƶ�
	
	char* s2 = (char*)src + num - 1;  //Դͷ�������һ��Ԫ�ص�ַ
	char* d = (char*)dest + num - 1;  //�ҵ�Ŀ���������һ��Ԫ�ص�ַ
	//Ϊʲô��Ҫ��1������Ϊ��ԭ���ĵ�ַ������num���ֽں���ʵ��ԭ������ռһ��������˶���
	//�����ǲ���1ʱ�����������Ƕ����һ��Ԫ�صĵ�ַ����ʵ�����ǣ�����С��ģʽʱ����Ե�ɺϵĴ���λ
	if (dest >= src && dest <= s2)
	{
		//dest��src��s2֮��ʱ
		while (num--)
		{
			*d = *s2;
			--d;
			--s2;
		}
	}
	else
	{
		//dest����src��s2֮��ʱ
		while (num--)
		{
			*(char*)dest = *(char*)src;
			++(char*)src;
			++(char*)dest;
		}
	}
	return ret; // ����ԭʼdest�ĵ�ַ
}
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	
	my_memmove(arr + 2, arr, 20);  //��12345�ƶ�����34567��λ��
	int i = 0;
	for (i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	return 0;
}