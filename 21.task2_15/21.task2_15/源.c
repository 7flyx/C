# define _CRT_SECURE_NO_WARNINGS 
#include "Student.h"

void menu()
{
	printf("* * * * * * * 菜  单 * * * * * * *\n");
	printf("    1 增加学生信息   2 删除学生信息\n");
	printf("    3 查找学生信息   4 修改学生信息\n");
	printf("    5 显示学生信息   6 统计学生人数\n");
	printf("    0 退出系统\n");
	printf("* * * * * * * * * * * * * * * * * *\n");
}

int main()
{
	//创建头结点
	Link head = (Link)malloc(sizeof(Node));
	head->next = NULL;

	//菜单，进入系统等操作
	int input = 0;
	do
	{
		menu(); 
		printf("请选择操作:>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			add_student(head);
			break;
		case DELETE:
			dele_student(head);
			break;
		case SEARCH:
			sear_student(head);
			break;
		case MODIFIY:
			modi_strdent(head);
			break;
		case SHOW:
			show_student(head);
			break;
		case STATISTICS:
			statis_student(head);
			break;
		case EXIT:
			//清空链表，并释放空间
			clear_list(head);
			break;
		}
	} while (input);


	return 0;
}