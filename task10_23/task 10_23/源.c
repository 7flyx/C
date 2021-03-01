# define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>

//��ŵ������
void move(char c1, char c2)
{
	printf("%c -> %c\n", c1, c2);
}
void hanoi(int n, char x, char y, char z)
{
	if (1 == n)
		move(x, z);
	else
	{
		hanoi(n - 1, x, z, y);
		move(x, z);
		hanoi(n - 1, y, x, z);
	}
}

int main()
{
	int n = 0;
	printf("������������:");
	scanf("%d", &n);
	char a = 'a';
	char b = 'b';
	char c = 'c';
	hanoi(n, a, b, c);
	return 0;
}


//int main()
//{
//	int arr[10] = { 3,1,2,4,5 };
//	printf("%p\n", &arr[0]);
//	printf("%p\n", arr);//��������ʡ����һ����ַ��Ҳ����˵��������Ҫ���ʵ�ַ��ʱ�򣬲�����Ҫ &������
//	printf("%d\n", *arr);
//	//*��ӷ��ʲ����������飩�ڽ��д�ӡ��ʱ��ֻ�Ǵ�ӡ�˸�����ĵ�һ��Ԫ�ض���
//	return 0;
//}


//int main()
//{
//	int a = 4;
//	int b = (++a) + (++a);//��һ������a=5���ڶ�������a=6����ʱa=6���ٲſ�ʼ�ӷ�����ֵ��b
//	//�˴���a�Լ�����������ٲſ�ʼ��ֵ��b
// 	printf("%d \n", b);
//	return 0;
//}

//int main()
//{
//	int arr[3][4] = { {1,2,3,4},{5,6,7,8} };
//	//��ά����ķ�����Ȼ�����±�������
//	//ֻ�������к��е��±�һ���ʾ
//	int h = 0;//��
//	for (h = 0; h < 3; h++)
//	{
//		int l = 0;//��
//		for (l = 0; l < 4; l++)
//		{
//			printf("%d ", arr[h][l]);
//			//����ӡ�����в�û�и�ֵʱ����ӡ�ľ���0
//		}
//		printf("\n");
//	}
//	return 0;
//}


//int main()
//{
//	int arr[3][4] = { 1,2,3,4,5,6,7,8,9 };//��ά����
//	//     ��  ��
//	int arr2[][4] = { {1,2,3,4},{5,6,7,8} };
//	//��ά��������ܹ�ʡ�ԣ��в���ʡ�ԣ�
//	int arr3[1][5] = { 1,2,3,4,5 };
//
//	return 0;
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };// һά����
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("&arr[%d]=%p\n", i,&arr[i]);//�������ڴ�����������ŵġ�
//	//��Ϊ��int���ͣ�����ÿ��Ԫ�صĵ�ַ���4
//
//	}
//	return 0;
//}



//int main()
//{
//	char arr1[] = "abc";//a b c \0
//	char arr2[] = { 'a','b','c' };
//	printf("%d\n", sizeof(arr1));//4	
//	printf("%d\n", sizeof(arr2));//3
//	printf("%d\n", strlen(arr1));//3
//	printf("%d\n", strlen(arr2));//���ֵ
//
//	return 0;
//}
//int main()
//{
//	int arr1[10] = { 1,2,3 };//����ȫ��ʼ��
//	char arr4[] = "abcdef";//7
//	printf("%d\n", sizeof(arr4));//7��Ԫ��--char 7*1=7.��������������\0��
//	//sizeof�Ǽ���arr4����ռ�ռ�Ĵ�С
//	printf("%d\n", strlen(arr4));//6
//	//strlen  ���ַ�������---��\0��֮ǰ���ַ�����
//	return 0;
//}