# define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

//void* my_memmove(void* dest, const void* src, size_t num)
//{
//	void* ret = dest;// ����dest��ֵ
//
//	//�����ж�dest��src��λ�ù�ϵ
//	if (dest < src)
//	{
//		//dest�ĵ�ַ��src�����
//		while (num--)
//		{
//			*(char*)dest = *(char*)src;
//			++(char*)dest;
//			++(char*)src;
//		}
//	}
//	else
//	{
//		//dest�ĵ�ַ��src���ұ�
//		while (num--)
//		{
//			//ʵ��ѭ������˵ʱ������num��ֻ������num-1 ��ֵ��������õ㣬Ϊ�ؼ�
//			*((char*)dest + num) = *((char*)src + num);
//		}
//	}
//	return ret;
//
//}
//
//int main()
//{
//	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
//
//	//my_memmove(arr1 + 2, arr1, 20);
//	my_memmove(arr1, arr1 + 2, 20);
//	int i = 0;
//	for (i = 0; i < 10; i++)
//		printf("%d ", arr1[i]);
//	return 0;
//}


//int cmp_int(const void* e1, const void* e2)
//{
//	return *(int*)e2 - *(int*)e1;
//}
//
//void Exch(char* cmp1, char* cmp2, size_t width)
//{
//	int i = 0;
//	for (i = 0; i < width; i++)
//	{
//		char tmp = *cmp1;
//		*cmp1 = *cmp2;
//		*cmp2 = tmp;
//		cmp1++, cmp2++; //���ű��ʽ�������ң�����ִ��
//	}
//}
//
//void my_sort(void* base, size_t sz, size_t width, int (*cmp)(void*, void*))
//{
//	//��������ʵ����ð������
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		int j = 0;
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			//�����жϺͽ���
//			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
//			{
//				//�˴��������ε�ʱ������ֻ��Ҫ����������Ҫ���������ݣ��������ݵĴ�С���������ֽ���
//				//�������������ݽ�������Swap��������ʵ����������Ҫѭ��4�β��У���Ϊ��4���ֽڵ�������
//				Exch((char*)base + j * width, (char*)base + (j + 1) * width, width);
//			}
//		}
//	}
//}
//
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	my_sort(arr, sz, sizeof(arr[0]), cmp_int);
//	int i = 0;
//	for (i = 0; i < 10; i++)
//		printf("%d ", arr[i]);
//	return 0;
//}







//
//int main()
//{
//	char arr1[10] = { 0 };
//	memset(arr1, '#', 10);// �ر�ע�⣬���������һ�������������Ǳ�ʾԪ�صĸ����������ܹ���Ҫ�޸ĵ�Ԫ�صĴ�С����λ���ֽ�
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%c ", arr1[i]);
//	}
//	return 0;
//}


//int main()
//{
//	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int arr2[] = { 1,2,3,4,6,7,8,4,10 };
//
//	int ret = memcmp(arr1, arr2, 12);
//	//ע�ͣ�������Ǹ�����������ָ���ǱȽϵ�Ԫ��ȫ���Ĵ�С����λ�ֽ�
//	//��ǣ����С���ұߣ�����С��0------<
//	//      ��ߴ����ұߣ����ش���0,----->
//	//   ��ȵĻ������ǵ���0
//	printf("%d\n", ret);
//	return 0;
//}








//
//typedef struct Stu
//{
//	char c;
//	char name[20];
//	int age;
//	struct Stu n;
//}stu;
//
//int main()
//{
//	struct Stu s1 = { 'n',"����",20 };
//	stu s2;
//	printf("%c %s %d \n", s1.c, s1.name, s1.age);
//
//	return 0;
//}


#include <stddef.h>

#pragma pack(4)  //����Ĭ�϶�����4
struct Stu
{
	char a;
	char arr[10];
	int su;
};
#pragma pack()  //ȡ��Ĭ�϶�����

int main()
{
	struct Stu s = { 0 };
	printf("%d \n", offsetof(struct Stu, a));  //��ṹ�������Ա��ƫ����
	printf("%d \n", offsetof(struct Stu, arr));
	//printf("%d\n", sizeof(s));
	return 0;
}