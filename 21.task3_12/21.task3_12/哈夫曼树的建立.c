# define _CRT_SECURE_NO_WARNINGS 


#include <stdio.h>
#include <stdlib.h>


#define MAX 4  //�������ĸ�Ȩֵ���

typedef struct HFManTree
{
	int weight; //��Ӧ����Ȩ��
	int lchild, rchild, parent;  //����������±�ֵ
}HFManTree;


void HFFTree(HFManTree arr[], int w[])
{
	//�������һЩֵ���г�ʼ��
	int i, k1, k2;
	for (i = 0; i < 2 * MAX - 1; i++)
	{
		arr[i].lchild = -1;
		arr[i].parent = -1;
		arr[i].rchild = -1;
	}
	for (i = 0; i < MAX; i++)
		arr[i].weight = w[i];

	for (i = MAX; i < 2 * MAX - 1; i++)
	{

	}
}
int cmp_int(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;  //���ȥ�ң��õ�����
}

//����������������洢��Ӧ��ֵ
int main()
{
	HFManTree arr[2 * MAX - 1];
	printf("������Ȩֵ:");
	int i, j;
	int w[MAX] = { 0 };

	//�ȶ�Ȩֵ�����������������򣬶Ժ������㷨��
	qsort(w, MAX, sizeof(int), cmp_int);

	for (i = 0; i < MAX; i++)
	{
		scanf("%d", &w[i]);
	}
	HFFTree(arr, w); //������������
	return 0;
}