# define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#define MAX_SIZE 10

typedef struct CNODE
{
	//���ӽ��--���������ڴ洢��������ڱ�ͷ�����е��±�
	//������Ԫ�ض����ڱ�ͷ������
	int child;
	struct CNODE* next;
}CNODE;

typedef struct
{
	//��ͷ������
	CNODE data;
	int parent; //��ʾ˫�׵��±�λ��
	CNODE* fristChild; //ָ���һ�����ӵ�ָ��
}List_Head;

struct
{
	//���ṹ
	List_Head arr[MAX_SIZE];
	int r, n; //�ֱ��ʾ�������±�������
};

int main()
{
	//˫�׺��ӱ�ʾ����

	return 0;
}