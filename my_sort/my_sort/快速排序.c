# define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

//
//#include <stdio.h>
//int main()
//{
//	//��������
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	//����Ԫ�ظ���----��������Ĵ�С��ȥһ��Ԫ�صĴ�С��������������Ĵ�//С�ˣ���λ�ֽ�
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i, j;//ѭ������
//	//��Ȼ����Ҫע��ľ���  δ��ʼ���ľֲ��������������ֵ
//	//��ȫ�ֱ���δ��ʼ������Ĭ����0
//
//	for (i = 0; i < sz; i++)  //��������
//	{
//		for (j = 0; j < sz - 1 - i; j++)  //����һ������Ҫ���������ݶ���
//		{
//			//sz-1-i   �����������������ӣ�������һ������Ҫ������
//			//���ݾ�Խ��Խ��
//			if (arr[j] < arr[j + 1])
//			{
//				//������ʱ������������һ�����ݾ��Ƚ��б���
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//	//�������Ǿ�ʵ����ð�������ʵ��
//
//	for (i = 0; i < sz; i++)
//		printf("%d ", arr[i]);
//	//����ٴ�ӡ����
//
//	return 0;
//}

void exch(char* ex1, char* ex2, int width)
{
	//�ڽ������ݵĽ���ʱ�����ǲ���֪��������Ҫ�������ٸ��ֽڣ���ʱ��width��������
	int i = 0;
	for (i = 0; i < width; i++)
	{
		//������ʱ���������н���
		int tmp = *ex1;
		*ex1 = *ex2;
		*ex2 = tmp;
		ex1++;
		ex2++;
	}
}

void my_sort(void* base, int sz, int width, int (*cmp)(void* e1,void* e2))
{
	//��������ĵײ�ԭ����ð�������ԭ��
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			//������ֵ���жϣ��Լ�����
			if (cmp((char*)base + (j * width), (char*)base + (j + 1) * width) > 0)
				exch((char*)base + (j * width), (char*)base + (j + 1) * width, width);
				//exchange -�����������ݵ�λ��
		}
	}
}

int cmp_int(void* e1, void* e2)
{
	//��ߵ�ֵ��ȥ�ұߵ�ֵ���õ�������
	//��֮������ǽ���
	return *(int*)e1 - *(int*)e2;
}

int main()
{
	//�Լ�ʵ�ֿ���������
	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);

	my_sort(arr, sz, sizeof(arr[0]), cmp_int);
	int i = 0;
	for (i = 0; i < sz; i++)
		printf("%d ", arr[i]);
	return 0;
}
