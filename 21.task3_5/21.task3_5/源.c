# define _CRT_SECURE_NO_WARNINGS 

#define MAXSIZE 10

typedef int ElemType;


typedef struct CNODE
{
	//���ӽ��
	int child;
	struct CNODE* next;
}CNODE;

typedef struct List_Head
{
	//��ͷ���
	ElemType data;  //�洢��������
	int parent;  //ָ��ý���˫��
	CNODE* FristChild;
}List;

struct Tree
{
	//���ṹ
	List arr[MAXSIZE];
	int r, n; //��ʾ �������±� ��  �������
};


//���Ĵ洢�ṹ---˫�׺��ӱ�ʾ��
int main()
{



	return 0;
}