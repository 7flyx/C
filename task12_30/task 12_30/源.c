# define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <assert.h>

//����һ������������⣬ֱ��һ����������
//void left_move(char* arr, int k)
//{
//	assert(arr != NULL);
//	int len1 = strlen(arr);
//	//k�������������ַ���������ѭ������
//	int i = 0;
//	for (i = 0; i < k; i++)
//	{
//		char tmp = *arr;  //�洢��һ��Ԫ��
//		int j = 0;
//		for (j = 0; j < len1 - 1; j++)
//			*(arr + j) = *(arr + j + 1);
//		*(arr + len1 - 1) = tmp;
//	}
//}

//��������������ת��  
//���磺ab cdef  ��ת2��
//��һ����ba cdef
//�ڶ�����ba fedc
//������������ȫ����ת �õ�fedcba

//void reserve(char* left, char* right)
//{
//	assert(left != NULL);
//	assert(right != NULL);
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		right--;
//		left++;
//	}
//}

//void left_move(char* arr, int k)
//{
//	assert(arr != NULL);
//	int len = strlen(arr);
//	assert(k <= len); //��֤��ת����ֵ���ܴ��������ַ���
//	reserve(arr, arr + k - 1);//����ת��һ���������ַ����
//	reserve(arr + k, arr + len - 1);//����ת�ڶ���
//	reserve(arr, arr + len - 1);//����ת������
//}

//int main()
//{
//	char arr[] = "abcdef";
//	left_move(arr, 3);
//	printf("%s\n", arr);
//	return 0;
//}

//int is_left_move(char* s1, char* s2)
//{
//	//ÿ��תһ�ξ���ԭ�ַ������бȽϼ���----�ȽϵĴ������Ǹ��ַ����ĳ���
//	int len = strlen(s1);
//	int i = 0;
//	for (i = 0; i < len; i++)
//	{
//		left_move(s2, 1);  //һ�δεķ�ת�ٱȽ�
//		int a = strcmp(s1, s2);  //����ַ�����Ⱦͻ᷵��0
//		if (a == 0)
//			return 1;
//	}
//	return 0;
//}
//
//int main()
//{
//	//�Ƚ�arr2�ǲ���arr1��ת������
//	char arr1[] = "abcdef";
//	char arr2[] = "cdefab";
//
//	int ret = is_left_move(arr1, arr2);
//	if (ret == 1)
//		printf("Yes\n");
//	else
//		printf("No\n");
//
//	return 0;
//}






//�����������ÿ⺯��

//int is_left_move(char* str1, char* str2)
//{
//	//�⺯�� strcat��strncat��strstr
//
//	//1. ׷���ַ���
//	int len1 = strlen(str2);
//	int len2 = strlen(str1);
//	if (len1 != len2)
//		return 0;
//	strncat(str1, str1, len1);
//
//	//2. strstr����--���ص���Ԫ�ص�ַ
//	char* ret = strstr(str1, str2);
//	if (ret != NULL)
//		return 1;
//	else
//		return 0;
//}
//
//int main()
//{
//	char arr1[30] = "abcdef";
//	char arr2[] = "defab";
//
//	int ret = is_left_move(arr1, arr2);
//	if (ret == 1)
//		printf("Yes\n");
//	else
//		printf("No\n");
//
//	return 0;
//}





//int Findnum(int arr[3][3], int row, int col, int k)
//{
//	int x = 0;
//	int y = col - 1;//ȷ�����������Ͻǵ��Ǹ�Ԫ�ص�ַ
//
//	while (x <= row - 1 && y >= 0)
//	{
//		if (arr[x][y] > k)
//			y--;
//		else if (arr[x][y] < k)
//			x++;
//		else
//			return 1;//�ҵ���
//	}
//	return 0;
//}

int Findnum(int arr[3][3], int* px, int* py, int k)
{
	int x = 0;
	int y = *py - 1;//ȷ�����������Ͻǵ��Ǹ�Ԫ�ص�ַ

	while (x <= *px - 1 && y >= 0)
	{
		if (arr[x][y] > k)
			y--;
		else if (arr[x][y] < k)
			x++;
		else
		{
			*px = x;
			*py = y;
			return 1;//�ҵ���
		}
			
	}
	return 0;
}
//���Ͼ�������--���Ҹþ����е�����ʱ�临�Ӷ�ΪO(N)
int main()
{
	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
	int x = 3;
	int y = 3;
	int k = 7;//��Ҫ���ҵ���
	//int ret = Findnum(arr, 3, 3, k);
	//�����ͺ���
	int ret = Findnum(arr, &x, &y, k);
	if (ret == 1)
		printf("�ҵ���,�±���%d ��%d\n", x, y);
	else
		printf("�Ҳ���\n");
	return 0;
}

