# define _CRT_SECURE_NO_WARNINGS 



#include <stdio.h>
#define MAXVEX 10


typedef struct arcList
{
	int adjvex;  //邻接点域，存储与表头结点  邻接点的下标
	int weight; //网图时，相应的权值
	struct arcList* next;  //指向下一个结点的指针
}arcList;

typedef struct
{
	char data;  //存储顶点的信息
	arcList* fristNode;  //指向边表的第一个结点
}vertexType;  //表头的类型 

typedef struct
{
	vertexType vexs[MAXVEX];  //表头数组
	int arcNum, vexNum;  //顶点数和边数
}Graph;


void create_graph(Graph* G)
{
	//跟邻接矩阵差不多，三大步
	//1. 输入顶点数和边数
	//2. 输入顶点的信息
	//3. 输入边之间的关系

	printf("请输入顶点数与边数:");
	scanf("%d%d", &G->vexNum, &G->arcNum);

	for (int i = 0; i < G->vexNum; i++)
	{
		printf("请输入顶点的信息:");
		scanf(" %c", &G->vexs[i].data);
		G->vexs[i].fristNode = NULL;
	}

	//输入两个顶点之间的关系
	for (int i = 0; i < G->arcNum; i++)
	{
		arcList* p;
		int i, j;  //分别表示两个顶点的下标

		//1. 此处，输入的其实是边的两个顶点在数组中的下标。
		//通过下标，分别去设置边的关系,与邻接矩阵有些相似
		//邻接矩阵，直接进行的赋值运算，而邻接表需要同时开辟两块空间，
		//进行下标的交换，数值的交换
		//2. ARCList中的adjvex，存储的是相应顶点在表头的下标值，与树中的孩子表示法一样的效果
		printf("请输入（vi，vj）两顶点的序号，即就是在数组中的下标：");
		scanf("%d%d", &i, &j);
		p = (arcList*)malloc(sizeof(arcList));
		if (!p)
		{
			printf("开辟空间失败");
			return;
		}
		p->adjvex = j;
		p->next = G->vexs[i].fristNode;  //使用头插法
		G->vexs[i].fristNode = p;


		p = (arcList*)malloc(sizeof(arcList));
		if (!p)
		{
			printf("开辟空间失败");
			return;
		}
		p->adjvex = i;
		p->next = G->vexs[j].fristNode;
		G->vexs[j].fristNode = p;
	}
}

//邻接表的创建，有三个结构体，一个是边表（存储邻接点的单链表，也就是边的关系）
//第二个结构体是一个表头结构体，用于存储一个顶点的信息
//第三个结构体是 表头结构体的数组和顶点数，边数
int main()
{
	Graph g;
	create_graph(&g); 

	return 0;
}