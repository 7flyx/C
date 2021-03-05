# define _CRT_SECURE_NO_WARNINGS 

#define MAXSIZE 10

typedef int ElemType;


typedef struct CNODE
{
	//孩子结点
	int child;
	struct CNODE* next;
}CNODE;

typedef struct List_Head
{
	//表头结点
	ElemType data;  //存储结点的数据
	int parent;  //指向该结点的双亲
	CNODE* FristChild;
}List;

struct Tree
{
	//树结构
	List arr[MAXSIZE];
	int r, n; //表示 根结点的下标 和  结点总数
};


//数的存储结构---双亲孩子表示法
int main()
{



	return 0;
}