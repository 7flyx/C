# define _CRT_SECURE_NO_WARNINGS 


#include <stdio.h>
#include <stdlib.h>


#define MAX 4  //代表有四个权值结点

typedef struct HFManTree
{
	int weight; //相应结点的权重
	int lchild, rchild, parent;  //用于数组的下标值
}HFManTree;


void HFFTree(HFManTree arr[], int w[])
{
	//将数组的一些值进行初始化
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
	return *(int*)e1 - *(int*)e2;  //左减去右，得到升序
}

//哈夫曼树，以数组存储相应的值
int main()
{
	HFManTree arr[2 * MAX - 1];
	printf("请输入权值:");
	int i, j;
	int w[MAX] = { 0 };

	//先对权值的数组进行升序的排序，对后续的算法简化
	qsort(w, MAX, sizeof(int), cmp_int);

	for (i = 0; i < MAX; i++)
	{
		scanf("%d", &w[i]);
	}
	HFFTree(arr, w); //建立哈夫曼树
	return 0;
}