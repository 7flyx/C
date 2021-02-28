# define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>


#define MAXSIZE 100

typedef struct DATA
{
	int data[MAXSIZE];  //���飬�����ʾһ�����У�˳��
	int front;  //��ʾ  ָ����еĵ�һ��Ԫ��
	int rear;  //��ʾ  ָ����е����һ��Ԫ��
}DATA;
void enter_DATA(DATA* test, int x)
{
	//�����ж϶����Ƿ�����
	if ((test->rear + 1) % MAXSIZE == test->front)
	{
		printf("�����Ѿ�����");
		return;
	}

	//û�������ڣ�βָ�룩��λ�÷���Ԫ��
	test->data[test->rear] = x;
	test->rear = (test->rear + 1) % MAXSIZE;
}
void export_DATA(DATA* test, int* m)
{
	//�����ж϶����Ƿ�Ϊ��
	if (test->front == test->rear)
	{
		printf("����Ϊ��!\n");
		return;
	}

	//û�գ���ȡ����ǰfrontλ�õ�Ԫ��
	*m = test->data[test->front];
	test->front = (test->front + 1) % MAXSIZE;
}
int main()
{
	//���е�˳��洢--Ϊ���ж϶����Ƿ����ˣ�ͨ���ǰѶ����˷�һ��ռ䣬��Ϊ�ж��Ƿ����˵�����
	//����rear+1��% MAXSIZE ʱ��������� front ����ʱ˵��������
	int x = 2020;
	int m = 0;  //���ڴ�ų�����ʱ������
	int length = 0;
	DATA* test = (DATA*)malloc(sizeof(DATA));
	if (!test)
	{
		printf("���ٿռ�ʧ�ܣ�\n");
		return 0;
	}

	//��ʼ���ն���-----���±�Ϊ0�ĵط���ʼ
	test->front = 0;
	test->rear = 0;

	//�����
	enter_DATA(test,x);
	//������
	export_DATA(test, &m);

	//����ѭ�����еĳ���---(ƨ��-�Կ�+�ܳ�)%�ܳ�
	length = (test->rear - test->front + MAXSIZE) & MAXSIZE; 

	free(test);
	test = NULL;
	return 0;
}