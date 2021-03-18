# define _CRT_SECURE_NO_WARNINGS 



#include <stdio.h>
#define MAXVEX 10


typedef struct arcList
{
	int adjvex;  //�ڽӵ��򣬴洢���ͷ���  �ڽӵ���±�
	int weight; //��ͼʱ����Ӧ��Ȩֵ
	struct arcList* next;  //ָ����һ������ָ��
}arcList;

typedef struct
{
	char data;  //�洢�������Ϣ
	arcList* fristNode;  //ָ��߱�ĵ�һ�����
}vertexType;  //��ͷ������ 

typedef struct
{
	vertexType vexs[MAXVEX];  //��ͷ����
	int arcNum, vexNum;  //�������ͱ���
}Graph;


void create_graph(Graph* G)
{
	//���ڽӾ����࣬����
	//1. ���붥�����ͱ���
	//2. ���붥�����Ϣ
	//3. �����֮��Ĺ�ϵ

	printf("�����붥���������:");
	scanf("%d%d", &G->vexNum, &G->arcNum);

	for (int i = 0; i < G->vexNum; i++)
	{
		printf("�����붥�����Ϣ:");
		scanf(" %c", &G->vexs[i].data);
		G->vexs[i].fristNode = NULL;
	}

	//������������֮��Ĺ�ϵ
	for (int i = 0; i < G->arcNum; i++)
	{
		arcList* p;
		int i, j;  //�ֱ��ʾ����������±�

		//1. �˴����������ʵ�Ǳߵ����������������е��±ꡣ
		//ͨ���±꣬�ֱ�ȥ���ñߵĹ�ϵ,���ڽӾ�����Щ����
		//�ڽӾ���ֱ�ӽ��еĸ�ֵ���㣬���ڽӱ���Ҫͬʱ��������ռ䣬
		//�����±�Ľ�������ֵ�Ľ���
		//2. ARCList�е�adjvex���洢������Ӧ�����ڱ�ͷ���±�ֵ�������еĺ��ӱ�ʾ��һ����Ч��
		printf("�����루vi��vj�����������ţ��������������е��±꣺");
		scanf("%d%d", &i, &j);
		p = (arcList*)malloc(sizeof(arcList));
		if (!p)
		{
			printf("���ٿռ�ʧ��");
			return;
		}
		p->adjvex = j;
		p->next = G->vexs[i].fristNode;  //ʹ��ͷ�巨
		G->vexs[i].fristNode = p;


		p = (arcList*)malloc(sizeof(arcList));
		if (!p)
		{
			printf("���ٿռ�ʧ��");
			return;
		}
		p->adjvex = i;
		p->next = G->vexs[j].fristNode;
		G->vexs[j].fristNode = p;
	}
}

//�ڽӱ�Ĵ������������ṹ�壬һ���Ǳ߱��洢�ڽӵ�ĵ�����Ҳ���ǱߵĹ�ϵ��
//�ڶ����ṹ����һ����ͷ�ṹ�壬���ڴ洢һ���������Ϣ
//�������ṹ���� ��ͷ�ṹ�������Ͷ�����������
int main()
{
	Graph g;
	create_graph(&g); 

	return 0;
}