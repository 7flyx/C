# define _CRT_SECURE_NO_WARNINGS 



#include <stdio.h>
#define MAXVEX 10   //��󶥵���
#define INTMAX 32767   //��ʾ�����

//����ͼ�ڽӾ���Ĵ������ö�ά�����ʾ��������֮��Ĺ�ϵ�������Ȩֵ�Ļ���ֱ������Ȩֵ
//û��Ȩֵ�ģ���1������������֮�������ӹ�ϵ

typedef char dataType;
typedef struct
{
	dataType vexs[MAXVEX];  //��������
	int arc[MAXVEX][MAXVEX];  //�����ߣ�Ҳ��Ȩֵ
	int vertexNum, arcNum;  //�������ͱߵĸ���  
}Graph;

//�����ڽӾ���
void createGraph(Graph* G)
{
	printf("�����붥�����ͱ���:");
	scanf("%d%d", &G->vertexNum, &G->arcNum);

	//����ÿ���������Ϣ
	for (int i = 0; i < G->vertexNum; i++)
	{
		getchar();
		printf("�����붥�����Ϣ:");
		scanf(" %c", &G->vexs[i]);
	}
		

	//��ʼ����ά�����������Ϣ���������ͼ����Ӧ���塰�����
	for (int i = 0; i < G->vertexNum; i++)
		for (int j = 0; j < G->vertexNum; j++)
			G->arc[i][j] = INTMAX;

	//��������У��ߵ�Ȩֵ
	int i, j, tmp;
	for (int k = 0; k < G->arcNum; k++)
	{		
		printf("������(i��j)������֮���Ȩֵ:");
		scanf("%d%d%d", &i, &j, &tmp);

		//�����Ӧ����֮���Ȩֵ
		G->arc[i][j] = tmp;
		G->arc[j][i] = tmp;  //�Ӿ������ϵ����£������Ƕ�Ӧ�ģ���������ͼ��˵������ͼ���ܲ��ǶԳƵ�
	}

}

int main()
{
	Graph G;
	createGraph(&G);
	return 0;
}