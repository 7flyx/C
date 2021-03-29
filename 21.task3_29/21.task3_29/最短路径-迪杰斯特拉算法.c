# define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#define MAXVEX 20
#define INF 32767


//#include <stdio.h>
//int main()
//{
//	int i, temp = 0, j = 0;
//	int a[10] = { 2,5,8,9,6,4,3,1,7,8 };
//	for (i = 0; i < 9; i++)
//	{
//		for (j = 0; j < 9 - i; j++) {
//			if (a[j] > a[j + 1]) {
//				temp = a[j];
//				a[j] = a[j + 1];
//				a[j + 1] = temp;
//			}
//
//		}	
//	}
//	for(i=0;i<10;i++)
//		printf("%d", a[i]);
//
//	return 0;
//}

typedef struct Graph
{
	int vexs[MAXVEX];
	int arc[MAXVEX][MAXVEX];
	int numArc, numVex;
}Graph;

void create_Graph(Graph* G)
{
	int i, j, x, y, w;
	printf("请输入顶点数与边数:");
	scanf("%d%d", &G->numVex, &G->numArc);

	for (i = 0; i < G->numVex; i++)
	{
		printf("请输入顶点信息:");
		scanf("%d", &G->vexs[i]);
		for (j = 0; j < G->numVex; j++)  //一起初始化二维数组
		{
			if (i == j)
				G->arc[i][j] = 0;
			else
				G->arc[i][j] = INF;
		}
	}

	//有向图的邻接矩阵
	for (i = 0; i < G->numArc; i++)
	{
		printf("请输入(vi,vj)顶点的下标以及权值（出度）:");
		scanf("%d%d%d", &x, &y, &w);
		G->arc[x][y] = w;
		//G->arc[y][x] = w;
	}
}

void Print_path(int path[], int k, int num)
{
	//将数组中的数据，放入一个新的数组，再从后面开始访问
	int tmp[MAXVEX], n = 0, m = k;

	while (num--)
	{
		tmp[n++] = path[k];
		k = path[k];		
	}
	for (int i = n - 2; i >= 0; i--)  //循环了num次，而n与num本身就相差了一次，再加上n自增增加后的一次
		//所以为2次
		printf("%d ", tmp[i]);
	printf("%d ", m);  //k本身就是最后那一个终点--因并存入path数组
}

void minPath(Graph G, int num)

{
	//s数组、dite数组、path数组
	int s[MAXVEX] = { 0 };  //存储哪些结点被访问过
	int dite[MAXVEX], path[MAXVEX]; //dite存储当前行的所有权值，path存储结点的上一结点的下标
	int i, sum, k, min;

	s[num] = 1; //1代表已经访问过，0则相反

	for (i = 0; i < G.numVex; i++)
	{
		//第k行的权值初始化
		dite[i] = G.arc[num][i];
		if (dite[i] == INF)
			path[i] = -1;  //正无穷的情况
		else
			path[i] = num;
	}
	sum = 1;
	k = num;
	while (sum < G.numVex)  //以顶点数作为判断条件
	{
		min = INF;
		for (i = 0; i < G.numVex; i++)
		{
			//得到当前行的最小权值
			if (!s[i] && G.arc[num][i] < min)
			{
				min = G.arc[num][i];  //存储最小权值
				k = i;  //存储最小权值终点的下标
			}
		}
		s[k] = 1;
		num = k;  //更新num的值，为了下一次循环做准备

		//判断这个最小值与dite数组权值的大小关系
		for (i = 0; i < G.numVex; i++)
		{
			if (!s[i] && (dite[k] + G.arc[k][i] < dite[i]))
			{
				dite[i] = dite[k] + G.arc[k][i];  //将此时最小权值，赋值给dite数组
				path[i] = k;
			}
		}
		sum++;
	}
	//倒序打印出path数组，即就是打印出源点到终点的路径
	Print_path(path, k, sum -1); //k为循环最后一次时,k本身就是一个终点
}

//最短路径-迪杰斯特拉算法---与最小生成树（prim算法）很相似
//s、dite、path三个数组，s数组表示已经访问过的结点
//dite数组表示当前这一行的所有权值--path数组，表示每个结点中，上一个结点的位置（下标）
int main()
{
	Graph G;
	int k = 0;  //源点
	create_Graph(&G);

	//计算最短路径
	minPath(G, k);
	return 0;
}