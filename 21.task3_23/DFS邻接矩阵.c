#include <stdio.h>

#define MAXVEX 10  //��󶥵���


//ȫ�ֱ���
int visited[MAXVEX];  //���ڱ�Ǹö����Ƿ񱻷��ʹ�


typedef struct 
{
	int vexs[MAXVEX]; //��������
	int arc[MAXVEX][MAXVEX]; //��ά���飬��ʾ�ߵĹ�ϵ
	int numVex,numArc;  //�����������
}Graph;

void create_Graph(Graph* G)
{
	int i,j;
	//�������붥���������
	printf("�����붥���������:");
	scanf("%d%d",&G->numVex,&G->numArc);

	//���붥���������Ϣ
	for(i=0;i< G->numVex;i++)
	{
		printf("�����붥����Ϣ:");
		scanf("%d",&G->vexs[i]);
	}
		

	//��ʼ����ά�������Ϣ
	for(i=0;i< G->numArc;i++)
	{
		for(j=0;j< G->numArc;j++)
			G->arc[i][j] = 0;
	}

	//���붥��֮��ߵĹ�ϵ
	for(i=0;i<G->numArc;i++)
	{
		int x,y;
		printf("������(vi,vj)����˵������֮���й�ϵ(ע��vi vj�Ƕ�Ӧ���±�):");
		scanf("%d%d",&x,&y);

		G->arc[x][y] = 1;
		G->arc[y][x] = 1;  //�ڽӾ�����жԳ���
	}
}

void DFS(Graph G,int i)
{
	int j;
	visited[i] = 1;
	printf("%d ",G.vexs[i]);

	for(j=0;j<G.numVex ;j++)
		if(G.arc [i][j] == 1 && !visited[j])  //��ʱ�β�i��Ϊһ�У�����һ�н���jֵ���жϣ��൱������������У��в��䣬����jֵ�ı任
			DFS(G,j);
}

void DFSTreverse(Graph G)
{
	int i;
	for(i=0;i<G.numVex ;i++)
		visited[i] = 0;  //��ʼ�����飬��ʾû�б����ʹ�

	for(i=0;i<G.numVex ;i++)
		if(!visited[i])
			DFS(G,i);  //û�б����ʹ���ֱ�ӵ���DFS�������б�������
}



//�ڽӾ����DFS������ȱ���
int main()
{
	Graph G;
	create_Graph(&G);

	//����������ȱ�������ӡ���������Ϣ
	//����DFS��������Ҫ��������
	DFSTreverse(G);


	return 0;
}