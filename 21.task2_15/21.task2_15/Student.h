#pragma once


#include <stdio.h>
#include <string.h>

enum Option
{
	EXIT,
	ADD,
	DELETE,
	SEARCH,
	MODIFIY,
	SHOW,
	STATISTICS
};


//ѧ��������Ϣ
typedef struct Student
{
	char name[11];
	char studentID[20];
}St;

//������Ľṹ��
typedef struct Node
{
	St data; //������
	struct Node* next; //ָ����
}Node,*Link;


//��������
void add_student(Link head);
void clear_list(Link head);
void show_student(Link head);
void dele_student(Link head);
void sear_student(Link head);
void modi_strdent(Link head);
void statis_student(Link head);






