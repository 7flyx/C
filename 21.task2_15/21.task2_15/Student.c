# define _CRT_SECURE_NO_WARNINGS 
#include "Student.h"

void InputStudent(Link node)
{
	printf("请输入姓名:>");
	scanf("%s", node->data.name);
	printf("请输入学号:>");
	scanf("%s", node->data.studentID);
}

void add_student(Link head)
{
	//新建结点，填入数据
	Link node = (Link)malloc(sizeof(Node));
	//node->next  未初始化
	InputStudent(node);

	//声明q，p，表示指向前一结点和后一结点
	Link q = head;
	Link p = head->next;

	//按学号大小，排序好链表
	while (p != NULL)
	{
		//判断学号大小
		if (strcmp(node->data.studentID , p->data.studentID) <= 0 )
		{
			//插入
			node->next = q->next;
			q->next = node;
			printf("添加成功\n");
			return; //提前退出
		}
		else
		{
			//q，p指针向后移
			q = p;
			p = p->next;
		}
	}

	//p=NULL时，直接插入即可
	q->next = node;
	node->next = NULL;
	printf("添加成功\n");
}

void clear_list(Link head)
{
	//指向前后结点的指针
	//Link q = head; //头结点
	Link p = head->next; //指向第一个结点
	           
	while (p != NULL)
	{	                                 
		head->next = p->next;
		free(p);
		p = head->next;
	}
	printf("清空成功\n");
}


void show_student(Link head)
{
	Link p = head->next;
	printf("%s\t%s\n","姓名","学号");
	while (p != NULL)
	{
		printf("%s\t%s\n", p->data.name, p->data.studentID);
		p = p->next;
	}
}


void dele_student(Link head)
{
	//声明前后结点
	Link q = head;
	Link p = head->next;


	//输入需要删除的学生姓名
	Link node = (Link)malloc(sizeof(Node));
	InputStudent(node);
	//循环判断并删除
	while (p != NULL)
	{
		if (strcmp(node->data.studentID, p->data.studentID) == 0)
		{
			//删除
			q->next = p->next;
			free(p);
			printf("删除成功\n");
			return;
		}
		else
		{
			//指针后移
			q = p;
			p = p->next;
		}
	}

	//循环完后，就是没有这个人的信息
	printf("没找到该学生信息\n");
}

void sear_student(Link head)
{
	//前后结点
	Link q = head;
	Link p = head->next;

	//输入需要查找的学生姓名
	Link node = (Link)malloc(sizeof(Node));
	InputStudent(node);
	//循环判断
	while (p != NULL)
	{
		if (strcmp(node->data.studentID, p->data.studentID) == 0)
		{
			//找到了
			printf("%s\t%s\n", "姓名", "学号");
			printf("%s\t%s\n", p->data.name, p->data.studentID);
			return;
		}
		else if(strcmp(node->data .name , p->data .name ) == 0)
		{
			//找到了
			printf("%s\t%s\n", "姓名", "学号");
			printf("%s\t%s\n", p->data.name, p->data.studentID);
		}
		else
		{
			//指针后移
			q = p;
			p = p->next;
		}
	}

}


void modi_strdent(Link head)
{
	//前后结点
	Link q = head;
	Link p = head->next;

	//输入需要修改的学生信息
	Link node = (Link)malloc(sizeof(Node));
	printf("请输入需要被修改的学生信息\n");
	InputStudent(node);
	//循环判断
	while (p != NULL)
	{
		if (strcmp(node->data.studentID, p->data.studentID) == 0)
		{
			//找到了
			printf("请重新输入信息!\n");
			printf("请输入姓名:>");
			scanf("%s", p->data.name);
			printf("请输入学号:>");
			scanf("%s", p->data.studentID);
			printf("修改成功\n");
			return;
		}
		else
		{
			//指针后移
			q = p;
			p = p->next;
		}
	}
}

void statis_student(Link head)
{
	//前后结点
	Link q = head;
	Link p = head->next;
	int count = 0;

	while (p != NULL)
	{
		count += 1;
		q = p;
		p = p->next;
	}
	printf("共有%d位学生信息\n", count);
}