//#define _CRT_SECURE_NO_WARNINGS
//
//
//#include <stdio.h>
//#include <stdlib.h>
//
//
//
//typedef struct BiTree
//{
//	//�������������---������������
//	char data;
//	struct BiTree* lchild, * rchild;
//	int ltag, rtag;  //ltag ��ָ����ı�־��rtag��ʾ��ָ����ı�־
//}BiTree;
//
//
//void InitThread(BiTree* head)
//{
//	//��������������ν���������----��ȷ���������ʲô��ʽ���б����ģ�ǰ��������������
//	//ѭ���жϵ���������Ϊ�������������һ��������ָ����Ҳ����ͷ����ѭ������
//	//������Ҫ����������һ������ͷ���ĵ�ַ��һ������ѭ��ʱ��
//	static BiTree* pre = NULL;  //ȫ�ֱ���---ʼ��ָ��ոշ��ʹ��Ľ��
//	if (head)  //�ݹ���ֹ����
//		return;
//		//ʼ�ձ���������Ĵ���˳��--����
//		InitThread(head->lchild); //������
//
//		if (!head->lchild)
//		{
//			//ltag��ֵ0����ʾ�ý��û�к�������
//			head->ltag = 1;
//			head->lchild = pre;  //��ָ����ָ��ǰ��
//		}
//		if (pre!=NULL && (!pre->rchild))  //ǰ��û���Һ���
//		{
//			pre->rtag = 1;
//			pre->rchild = head;  //ǰ�������Һ���ָ�룬ָ��ǰ�Ľ��head
//		}
//		pre = head;  //ʼ�ձ���ǰ���Ĺ�ϵ
//
//		InitThread(head->rchild); //������
//	
//
//}
//
////�������Ĵ���--- һ��ָ��ķ�����������Ҫ����malloc����������ַ��ָ��
//BiTree* Create_Tree(BiTree* T)
//{
//	//����������ĸ���---#----���򴴽�������
//	char ch = 0;
//	printf("�������ַ���");
//	scanf(" %c", &ch);
//	if (ch == '#')
//		T = NULL;
//	else
//	{	
//		T = (BiTree*)malloc(sizeof(BiTree));  //���ʲ���--��
//		if (!T)
//		{
//			printf("�ڴ濪��ʧ��!\n");
//			exit(0);
//		}
//		
//		//�ݹ����ý�����Ӻ��Һ���Ŷ	
//		T->lchild = Create_Tree(T->lchild);  //������
//		T->data = ch;
//		T->ltag = 0;
//		T->rtag = 0;
//		T->rchild = Create_Tree(T->rchild);  //������
//	}
//	return T;  //���ص�ǰ���ٿռ��ָ��
//}
//
//void InorderTraverse(BiTree* T)
//{
//	//�����������ı���---
//	//�ݹ���ֹ����:�������߱�������ʱ
//	BiTree* p = T->lchild; //pָ������
//	while (T != p)
//	{
//		while (p->ltag == 0)
//		{
//			//��ltag����0ʱ��ѭ������������ĵ�һ����㴦
//			p = p->lchild;
//		}
//		printf("%c ", p->data);
//
//		//�����һ����㿪ʼ��ӡ
//		while (p->rtag == 1 && p->rchild != T)
//		{
//			p = p->rchild;
//			printf("%c ", p->data);
//		}
//
//		p = p->rchild;  //��ȥ���������д�ӡ
//	}
//}
//
////void InOrderTraverse_Thr(BiTree* T)
////{
////	BiTree* p;
////	p = T->lchild; /* pָ������ */
////	while (p != T)
////	{ /* �������������ʱ,p==T */
////		while (p->ltag == 0)
////			p = p->lchild;
////		if (!visit(p->data)) /* ������������Ϊ�յĽ�� */
////			return;
////		while (p->rtag == 1 && p->rchild != T)
////		{
////			p = p->rchild;
////			visit(p->data); /* ���ʺ�̽�� */
////		}
////		p = p->rchild;
////	}
////	return OK;
////}
//
////������������ʵ���˫�������ʽ��࣬Ҳ��ͷ���ָ���������ĸ����
////����������ָ����ָ�����������  �������  �����һ�����
////--------------------------------------------------------------
////����֮������һ��������ָ����ָ����� ͷ���
////����֮��ĵ�һ��������ָ����Ҳ��ָ�� ͷ���
//int main()
//{
//	BiTree* head = (BiTree*)malloc(sizeof(BiTree));
//	if (!head)
//		return 0; //���ٿռ�ʧ��
//
//	//����������
//	Create_Tree(head->lchild );
//	//��������������
//	InitThread(head);
//	//�����������ı���
//	InorderTraverse(head);
//	return 0;
//}