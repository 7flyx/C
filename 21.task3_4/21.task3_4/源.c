# define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#define MAX_SIZE 10

typedef struct CNODE
{
	//孩子结点--数据域用于存储这个数据在表头数组中的下标
	//而真正元素都存在表头数组中
	int child;
	struct CNODE* next;
}CNODE;

typedef struct
{
	//表头数组结点
	CNODE data;
	int parent; //表示双亲的下标位置
	CNODE* fristChild; //指向第一个孩子的指针
}List_Head;

struct
{
	//树结构
	List_Head arr[MAX_SIZE];
	int r, n; //分别表示根结点的下标与结点数
};

int main()
{
	//双亲孩子表示方法

	return 0;
}