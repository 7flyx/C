# define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <string.h>

#define MAX 1000
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12

enum uotion
{
	EXIT,//0
	ADD, //..
	DEL, 
	SEARCH,
	MODIFI,
	SHOW
};

//个人信息
struct infor
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
};

//通讯录类型
struct Con
{
	struct infor data[MAX];  //创建MAX个联系人的数组进行存储
	int count;  //计算已经有多少人存入通讯录了
};




//函数的声明
void Initcontact(struct Con* ps);  //初始化通讯录
void add_contact(struct Con* ps);  //增加联系人
void show_contact(const struct Con* ps); // 显示通讯录
void del_contact(struct Con* ps); //删除联系人
void search_contact(const struct Con* ps); //查找联系人
void modifi_contact(struct Con* ps); //修改联系人