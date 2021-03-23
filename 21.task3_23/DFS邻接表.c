#include <stdio.h>
#include <stdlib.h>

#define MAXVEX 10

int visited[MAXVEX];  //ȫ�ֱ���


//�ڽӱ����������߱��������������ķ�װ
typedef struct arcList 
{
	int vexs_num;  //�ýڵ��ڶ���������±�
	struct arcList* next;
}arcList;

typedef struct VEXS
{
	int data; //����Ĵ洢��
	arcList* firstNode;  //ָ���һ���ڵ�
}VEXS;

typedef struct Graph
{
	VEXS vexs[MAXVEX];
	int numVex,numArc;
}Graph;

void create_Graph(Graph* G)
{
	int i,x,y;
	arcList* e = NULL;  //������ʱ�ı߱�
	//���붥���������
	printf("�����붥���������:");
	scanf("%d%d",&G->numVex,&G->numArc);

	//������Ӧ�Ķ�����Ϣ
	for(i=0;i<G->numVex;i++)
	{
		printf("�����붥����Ϣ:");
		scanf("%d",&G->vexs[i]);
		G->vexs[i].firstNode = NULL;
	}

	//������Ӧ�ıߵĹ�ϵ�������Ȩֵ��Ӧ���¶���ṹ�壬��Ȩֵ�����ݷ��붥�������У�������������Ĳ���
	for(i=0;i<G->numArc;i++)
	{
		printf("������(vi,vj)������֮��Ĺ�ϵ��ע���˴���������±�ֵ��:");
		scanf("%d%d",&x,&y);

		e = (arcList*)malloc(sizeof(arcList));
		if(!e)
			return;
		e->vexs_num = x;
		e->next = G->vexs[y].firstNode;
		G->vexs[y].firstNode = e;

		e = (arcList*)malloc(sizeof(arcList));
		if(!e)
			return;
		e->vexs_num = y;
		e->next = G->vexs[x].firstNode;
		G->vexs[x].firstNode = e;
		//����ͼ��������malloc�Ĵ�����������ͼ��ֻ��һ���������ǳ��Ȼ������
	}
}

void DFS(Graph G,int i)
{
	arcList* p = NULL;
	visited[i] = 1;  //��־����
	printf("%d ",G.vexs[i]);

	p = G.vexs[i].firstNode;

	while(p)
	{
		if(!visited[p->vexs_num])
			DFS(G,p->vexs_num);
		p = p->next;
	}
}

void DFSTreverse(Graph G)
{
	int i;
	//����visited����ĳ�ʼ��
	for(i=0;i<G.numVex;i++)
		visited[i] = 0; 

	//���б���
	for(i=0;i<G.numVex;i++)
		if(!visited[i])
			DFS(G,i);
}


//����ͼ�ڽӱ����ȱ���
int main()
{
	Graph G;

	create_Graph(&G);

	//����ͼ����ȱ���---�ڽӱ�Ĵ洢
	DFSTreverse(G);


	return 0;
}