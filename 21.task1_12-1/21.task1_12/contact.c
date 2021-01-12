# define _CRT_SECURE_NO_WARNINGS 

#include "contact.h"


void Initcontact(struct Con* ps)
{
	memset(ps->data, 0, sizeof(ps->data));
	ps->count = 0;
}


void add_contact(struct Con* ps)
{
	//首先判断通讯录是否满了
	if (ps->count == MAX)
	{
		printf("通讯录已满\n");
	}
	else
	{
		printf("请输入姓名:"); scanf("%s", ps->data[ps->count].name);
		printf("请输入年龄:"); scanf("%d", &(ps->data[ps->count].age));  //非字符串内容，需要取地址
		printf("请输入性别:"); scanf("%s", ps->data[ps->count].sex);
		printf("请输入电话:"); scanf("%s", ps->data[ps->count].tele);
		printf("添加成功\n");
		ps->count++;
	}
}

//显示通讯录
void show_contact(const struct Con* ps)
{
	int i = 0;
	printf("%-10s\t%-4s\t%-5s\t%-12s\n", "姓名", "年龄", "性别", "电话");
	for (i = 0; i < ps->count; i++)
	{
		printf("%-10s\t", ps->data[i].name);
		printf("%-4d\t", ps->data[i].age);
		printf("%-5s\t", ps->data[i].sex);
		printf("%-12s\n", ps->data[i].tele);
	}
}

//删除联系人
void del_contact(struct Con* ps)
{
	printf("请输入需要删除对象的姓名:");
	char name[MAX_NAME];
	scanf("%s", name);
	int i = 0;
	for (i = 0; i < ps->count; i++)
	{
		if (strcmp(ps->data[i].name, name) == 0)
		{
			break;
		}
	}
	if (i == ps->count)
	{
		printf("通讯录没有该联系人\n");
	}
	else
	{
		int j = 0;
		for (j = i; j < ps->count - 1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->count--;  //忽略最后一个元素，重复了
		printf("删除成功\n");
	}
}

//查找联系人
void search_contact(const struct Con* ps)
{
	int i = 0;
	printf("请输入需要查找对象的姓名:");
	char name[MAX_NAME];
	scanf("%s", name);
	for (i = 0; i < ps->count; i++)
	{
		if (strcmp(ps->data[i].name, name) == 0)
		{
			printf("%-10s\t%-4s\t%-5s\t%-12s\n", "姓名", "年龄", "性别", "电话");
			printf("%-10s\t", ps->data[i].name);
			printf("%-4d\t", ps->data[i].age);
			printf("%-5s\t", ps->data[i].sex);
			printf("%-12s\n", ps->data[i].tele);
			break;
		}
	}
}



//修改联系人
void modifi_contact(struct Con* ps)
{
	char name[MAX_NAME];
	printf("请输入需要修改对象的姓名:");
	scanf("%s", name);
	int i = 0;
	for (i = 0; i < ps->count; i++)
	{
		if (strcmp(ps->data[i].name, name) == 0)
		{
			printf("请输入姓名:"); scanf("%s", ps->data[i].name);
			printf("请输入年龄:"); scanf("%d", &(ps->data[i].age));  //非字符串内容，需要取地址
			printf("请输入性别:"); scanf("%s", ps->data[i].sex);
			printf("请输入电话:"); scanf("%s", ps->data[i].tele);
			printf("修改成功\n");
			break;
		}
	}
}