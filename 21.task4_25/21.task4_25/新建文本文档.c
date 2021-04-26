# define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>  

typedef struct NODE
{
	char ID[20];  //学号
	char name[10]; //性名
	char sex[5]; //性别
	char intime[10];    //进入时间
	char outtime[10]; //出去时间
	int age;  //年龄
	double temp;  //体温
	struct NODE* next;
}NODE;

enum option
{
	EXIT,  //0
	ADD,
	DEL,
	MODIFI,
	SEARCH,
	STAT,
	SAVE,
	PRINT
};

void menu()
{
	printf("----------------------------\n");
	printf("---  0.退出       1.添加 ---\n");
	printf("---  2.删除       3.修改 ---\n");
	printf("---  4.查找       5.统计 ---\n");
	printf("---  6.保存       7.显示 ---\n");
	printf("----------------------------\n");
}

void add_information(NODE** p)
{
	NODE* s = (NODE*)malloc(sizeof(NODE));
	NODE* tmp1, * tmp2;
	if (!s) return;  //开辟空间失败
	s->next = NULL;

	printf("请输入性名:"); scanf("%s", s->name);
	printf("请输入性别:"); scanf("%s", s->sex);
	printf("请输入年龄:"); scanf("%d", &s->age);
	printf("请输入学号:"); scanf("%s", s->ID);
	printf("请输入体温（例如:36.8）:"); scanf("%lf", &s->temp);
	printf("请输入进入图书馆时间(例如: 9:30):"); scanf("%s", s->intime);
	printf("请输入离开图书馆时间(例如: 21:30):"); scanf("%s", s->outtime);

	//根据体温进行排序
	if (!(*p)->next)
	{
		(*p)->next = s;
	}
	else
	{
		tmp1 = *p;
		tmp2 = (*p)->next;  //指向第一个结点
		while (tmp2)
		{
			if (tmp2->temp < s->temp)
			{
				s->next = tmp2;
				tmp1->next = s;
				break;
			}
			else
			{
				tmp1 = tmp2;
				tmp2 = tmp2->next;
			}
		}
	}
}

void del_infomation(NODE** p)
{
	//根据学号进行删除
	char ID[20];
	NODE* tmp1 = *p;  //前一结点
	NODE* tmp2 = (*p)->next; //后一结点
	printf("请输入需要删除对象的学号:");
	scanf("%s", ID);
	while (tmp2)
	{
		if (strcmp(tmp2->ID, ID) == 0)
		{
			NODE* s = tmp2;
			tmp1->next = tmp2->next;
			free(s);
			printf("删除成功!\n");
			return;
		}
		tmp1 = tmp2;
		tmp2 = tmp2->next;
	}
	printf("为找到学号为%s的相关信息!\n", ID);
}

void mod_infomation(NODE** p)
{
	//根据学号进行修改信息
	char ID[20];
	NODE* tmp1 = *p;  //前一结点
	NODE* tmp2 = (*p)->next; //后一结点
	NODE* s = (NODE*)malloc(sizeof(NODE));
	if (!s) return;
	printf("请输入需要修改对象的学号:");
	scanf("%s", ID);
	while (tmp2)
	{
		if (strcmp(tmp2->ID, ID) == 0)
		{
			NODE* q = tmp2;
			tmp1->next = tmp2->next;
			free(q);
			printf("请输入性名:"); scanf("%s", s->name);
			printf("请输入性别:"); scanf("%s", s->sex);
			printf("请输入年龄:"); scanf("%d", &s->age);
			printf("请输入学号:"); scanf("%s", s->ID);
			printf("请输入体温（例如:36.8）:"); scanf("%lf", &s->temp);
			printf("请输入进入图书馆时间(例如: 9:30):"); scanf("%s", s->intime);
			printf("请输入离开图书馆时间(例如: 21:30):"); scanf("%s", s->outtime);
			printf("修改成功!\n");

			//对新的数据进行排序处理
			tmp1 = *p;
			tmp2 = (*p)->next;  //指向第一个结点
			while (tmp2)
			{
				if (tmp2->temp < s->temp)
				{
					s->next = tmp2;
					tmp1->next = s;
					break;
				}
				else
				{
					tmp1 = tmp2;
					tmp2 = tmp2->next;
				}
			}
			return;
		}
		tmp1 = tmp2;
		tmp2 = tmp2->next;
	}
	printf("为找到学号为%s的相关信息!\n", ID);
}

void sear_infomation(NODE** p)
{
	//根据学号查找信息
	char ID[20];
	NODE* tmp1 = *p;  //前一结点
	NODE* tmp2 = (*p)->next; //后一结点
	printf("请输入需要查找对象的学号:");
	scanf("%s", ID);
	while (tmp2)
	{
		if (strcmp(tmp2->ID, ID) == 0)
		{
			//姓名 年龄 性别 学号 体温 进出时间
			printf("%s\t%s\t%s\t%-16s %s\t%s %s\n", "姓名", "年龄", "性别", "学号", "体温", "进入时间", "离开时间");
			printf("%s\t%d\t%s\t%s\t%.1lf\t%s\t%s\n", tmp2->name, tmp2->age, tmp2->sex, tmp2->ID, tmp2->temp, tmp2->intime, tmp2->outtime);
			return;
		}
		tmp1 = tmp2;
		tmp2 = tmp2->next;
	}
	printf("为找到学号为%s的相关信息!\n", ID);
}

void save_infomation(NODE** p)
{
	/*保存内存中的信息到磁盘中
	此处的文件路径可以使用相对路径或者是绝对路径
	FILE* pf = fopen("E:\\vs代码学习\\日常联习\\test\\homework\\infomation.txt","w");*/
	int j = 0;;
	char* date;
	char date1[50] = { 0 };
	time_t the_time;
	time(&the_time);
	//printf("The date is : %s \n", ctime(&the_time));  //Sun Apr 25 22:21:15 2021
	date = ctime(&the_time);
	for (int i = 4; i < 11; i++)
	{
		if (date[i] == ' ')
			continue;
		date1[j] = date[i];
		j++;
	}
	date = (char*)date1;
	strcat(date, ".txt"); //追加 .txt

	FILE* pf = fopen(date, "w");
	if (!pf)
	{
		printf("save:%s", strerror(errno));
		return;
	}
	NODE* tmp = (*p)->next;

	fprintf(pf, "% s\t % s\t % s\t %-16s\t % s\t % s\t % s\n",
		"姓名", "年龄", "性别", "学号", "体温", "进入时间", "离开时间");

	while (tmp)
	{
		//写入文件--fprintf()格式化写入
		fprintf(pf, "% s\t % d\t % s\t % s\t % .1lf\t % s\t % s\n",
			tmp->name, tmp->age, tmp->sex, tmp->ID, tmp->temp, tmp->intime, tmp->outtime);
		tmp = tmp->next;
	}
	printf("写入成功!\n");
	fclose(pf);
	pf = NULL;
}

void InitInfomation(NODE** p)
{
	//加载已经在文件中有的数据进入内存
	FILE* pf = fopen("infomation.txt", "r");
	if (!pf)
	{
		//printf("Init:%s\n", strerror(errno));
		return;
	}

	NODE* tmp1 = *p;
	NODE* s = (NODE*)malloc(sizeof(NODE));
	s->next = NULL;
	while (fscanf(pf, "%s\t %d\t %s\t %s\t %lf\t %s\t %s",
		s->name, &s->age, s->sex, s->ID, &s->temp, s->intime, s->outtime) != EOF)
	{
		tmp1->next = s;
		s = (NODE*)malloc(sizeof(NODE));
		s->next = NULL;
		tmp1 = tmp1->next;
	}
}

void print_infomation(NODE** p)
{
	NODE* tmp = (*p)->next;
	printf("%s\t%s\t%s\t%-16s %s\t%s %s\n", "姓名", "年龄", "性别", "学号", "体温", "进入时间", "离开时间");
	while (tmp)
	{
		printf("%s\t%d\t%s\t%s\t%.1lf\t%s\t%s\n",
			tmp->name, tmp->age, tmp->sex, tmp->ID, tmp->temp, tmp->intime, tmp->outtime);
		tmp = tmp->next;
	}

}

void del_interspace(NODE** p)
{
	NODE* tmp1 = *p;
	NODE* tmp2 = (*p)->next;
	while (tmp2)
	{
		NODE* q = tmp2;
		tmp2 = tmp2->next;
		tmp1->next = tmp2;
		free(q);
	}
}

void stat_infomation(NODE** p)
{
	NODE* tmp = (*p)->next;
	printf("%s\t%s\t%s\t%-16s %s\t%s %s\n", "姓名", "年龄", "性别", "学号", "体温", "进入时间", "离开时间");
	while (tmp->temp >= 37.0)
	{
		printf("%s\t%d\t%s\t%s\t%.1lf\t%s\t%s\n",
			tmp->name, tmp->age, tmp->sex, tmp->ID, tmp->temp, tmp->intime, tmp->outtime);
		tmp = tmp->next;
	}
}

int main()
{
	int i = 0;
	NODE* head = (NODE*)malloc(sizeof(NODE));
	if (!head)
		return 0; //开辟空间失败
	head->next = NULL;

	//加载文件中的数据
	InitInfomation(&head);
	do
	{
		menu();
		printf("请输入相应的操作:");
		scanf("%d", &i);

		switch (i)
		{
		case EXIT:  //退出 --释放内存空间
			del_interspace(&head);
			break;
		case ADD:
			add_information(&head);
			break;
		case DEL:
			del_infomation(&head);
			break;
		case MODIFI:
			mod_infomation(&head);
			break;
		case SEARCH:
			sear_infomation(&head);
			break;
		case STAT:
			stat_infomation(&head);
		case SAVE:
			save_infomation(&head);
			break;
		case PRINT:
			print_infomation(&head);
			break;
		default:
			printf("选择错误!\n");
			break;
		}
	} while (i);

	free(head);
	return 0;
}

