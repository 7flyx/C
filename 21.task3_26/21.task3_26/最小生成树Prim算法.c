# define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#define MAXVEX 10
#define INF 32767

typedef struct
{
	int vexs[MAXVEX];
	int arc[MAXVEX][MAXVEX];
	int numVex, numArc;
}Graph;

void MSTree(Graph G)
{
	//首先声明所需要的变量以及两个数组
	int min, j, k, i;
	int adjvex[MAXVEX];
	int lowcost[MAXVEX];

	//初始化，第一个结点，即就是下标为0的数据
	lowcost[0] = 0;  //“成本”数组，为0 ，即就是代表这个结点已经访问过了
	adjvex[0] = 0;

	//为lowcost数组进行初始化，从下标为1的地方开始
	for (j = 1; j < G.numVex; j++)
	{
		lowcost[j] = G.arc[0][j];  //得到第0行全部的权值,除了第0列
		adjvex[j] = 0;  //全部初始化为0
	}

	//接下来就是去判断除了第0行外，其他行的权值，并且进行判断，如果符合当前lowcost数组中最小的，就替换
	for (i = 1; j < G.numVex; j++)
	{
		min = INF;  //从正无穷开始往下判断
		k = 0;
		for (j = 1; j < G.numVex; j++)
		{
			if (lowcost[j] != 0 && lowcost[j] < min)  //lowcost的值不为0，且小于min
			{
				min = G.arc[k][j];  //拿到最小权值
				k = j; //拿到最小权值对应顶点的下标
			}
		}

		printf("(%d,%d)\n", adjvex[k], k);
		lowcost[k] = 0;  //代表已经访问过了

		for (j = 1; j < G.numVex; j++)
		{
			if (lowcost[j] != 0 && G.arc[k][j] < lowcost[j])
			{
				lowcost[j] = G.arc[k][j];
				adjvex[j] = k;
			}
		}
	}
}

//对于最小生成树，最初的概念还是邻接矩阵的转换，一切的根源还得从邻接矩阵和邻接表开始
//Prim算法，建立两个数组adjVex和lowcost，adjVex用于存储顶点信息，而lowcost用于存储权值的，例如：第一行 ，所有的权值，
//包含了正无穷
int main()
{

	return 0;
}