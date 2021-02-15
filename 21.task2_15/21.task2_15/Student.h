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


//学生个人信息
typedef struct Student
{
	char name[11];
	char studentID[20];
}St;

//链表结点的结构体
typedef struct Node
{
	St data; //数据域
	struct Node* next; //指针域
}Node,*Link;


//函数声明
void add_student(Link head);
void clear_list(Link head);
void show_student(Link head);
void dele_student(Link head);
void sear_student(Link head);
void modi_strdent(Link head);
void statis_student(Link head);






