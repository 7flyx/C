# define _CRT_SECURE_NO_WARNINGS 

#include "contact.h"


void Initcontact(struct Con* ps)
{
	//将data的数据初始化为0
	struct infor* ptr = (struct infor*)malloc(DEFAULT_SZ * sizeof(struct infor));
	if (ptr != NULL)
	{
		ps->data = ptr;
		ps->size = 0;
		ps->capacity = DEFAULT_SZ;
	}	
}
void CheckCapacity(struct Con* ps)
{
	//检查内存空间的容量以及是否需要增容
	if (ps->capacity == ps->size)
	{
		struct infor* ptr = (struct infor*)realloc(ps->data, (ps->capacity + 2) * sizeof(struct infor));
		if (ptr != NULL)
		{
			ps->data = ptr;
			ps->capacity += 2;
		}
	}
}

void add_contact(struct Con* ps)
{
	//首先判断通讯录是否满了
	CheckCapacity(ps);
	
	printf("请输入姓名:>");
	scanf("%s", ps->data[ps->size].name);		
	printf("请输入年龄:>");
	scanf("%d", &(ps->data[ps->size].age));
	printf("请输入性别:>");
	scanf("%s", ps->data[ps->size].sex);
	printf("请输入电话:>");
	scanf("%s", ps->data[ps->size].tele);
	printf("添加成功\n");
	ps->size++; //添加完后，size增加，为下次添加做好准备

}

void show_contact(const struct Con* ps)
{
	//首先判断通讯录是否为空
	if (ps->size == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		int i = 0;
		printf("%-10s\t%-4s\t%-5s\t%-12s\n", "姓名", "年龄", "性别", "电话");
		for (i = 0; i < ps->size; i++)
			printf("%-10s\t%-4d\t%-5s\t%-12s\n",
				ps->data[i].name,
				ps->data[i].age,
				ps->data[i].sex,
				ps->data[i].tele);
	}
}

//查找函数--static修饰，即只能在这个源文件使用
static int FindByCon(const struct Con* ps, char name[MAX_NAME])
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (strcmp(ps->data[i].name, name) == 0)
		{
			return i; //找到了，返回该元素下标
		}
	}
	return -1; //没找到，返回-1
}
void del_contact(struct Con* ps) //删除信息
{
	//查找需要删除信息的那个人
	char name[MAX_NAME];
	printf("请输入需要删除人的姓名:>");
	scanf("%s", name);
	int pos = FindByCon(ps, name);

	//判断并删除
	if (-1 == pos)
	{
		//是循环完了的，并没有找到要删除的那个人
		printf("没有找到需要删除的个人信息\n");
	}
	else
	{
		int j = 0;
		for (j = pos; j < ps->size - 1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		printf("删除成功\n");
		//实则并没删除，只是将后面的数据向前移动了而已，把需要删除的信息覆盖了
		//ps->size  之所以需要减一，是因为我们在打印的时候，不打印最后那一个元素的信息
		ps->size--;
	}
}


void sear_contact(const struct Con* ps)
{
	char name[MAX_NAME];
	printf("请输入需要查找人的信息:>");
	scanf("%s", name);
	int pos = FindByCon(ps, name);
	if (-1 == pos)
	{
		//没找到
		printf("没有找到该信息\n");
	}
	else
	{
		printf("%-10s\t%-4s\t%-5s\t%-12s\n", "姓名", "年龄", "性别", "电话");
			printf("%-10s\t%-4d\t%-5s\t%-12s\n",
				ps->data[pos].name,
				ps->data[pos].age,
				ps->data[pos].sex,
				ps->data[pos].tele);
	}
}

void modi_contact(struct Con* ps)
{
	//首先输入需要修改对象的姓名
	char name[MAX_NAME];
	printf("请输入需要修改人的姓名:>");
	scanf("%s", name);
	int pos = FindByCon(ps, name);
	if (-1 == pos)
	{
		//没找到'
		printf("没有找到需要修改对象的信息\n");
	}
	else
	{
		printf("请输入姓名:>");
		scanf("%s", ps->data[pos].name);
		printf("请输入年龄:>");
		scanf("%d", &(ps->data[pos].age));
		printf("请输入性别:>");
		scanf("%s", ps->data[pos].sex);
		printf("请输入电话:>");
		scanf("%s", ps->data[pos].tele);

		printf("修改成功\n");
	}
}


void DestroyCapacity(struct Con* ps) //释放内存空间
{
	free(ps->data);
	ps->data = NULL;
}