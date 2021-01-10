#pragma once
#include <stdio.h>
#include <string.h>

#define MAX 1000

#define MAX_NAME 10
#define MAX_SEX 5
#define MAX_TELE 12	

enum option
{
	//使用枚举常量，运用于switch里面的case语句，提高代码的阅读性
	EXIT,// 0
	ADD, //1
	DEL,//...
	SEARCH,
	MODIFI,
	SHOW,
	SORT
};

//information 个人信息
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
	struct infor data[MAX];
	int size;
};

//声明函数
void Initcontact(struct Con* ps);//初始化通讯录
void add_contact(struct Con* ps);//添加联系人
void show_contact(const struct Con* ps);//打印通讯录
void del_contact(struct Con* ps); //删除信息
void sear_contact(const struct Con* ps); //查找信息
void modi_contact(struct Con* ps); // 修改信息