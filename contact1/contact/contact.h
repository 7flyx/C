#pragma once
#include <stdio.h>
#include <string.h>

#define MAX 1000

#define MAX_NAME 10
#define MAX_SEX 5
#define MAX_TELE 12	

enum option
{
	//ʹ��ö�ٳ�����������switch�����case��䣬��ߴ�����Ķ���
	EXIT,// 0
	ADD, //1
	DEL,//...
	SEARCH,
	MODIFI,
	SHOW,
	SORT
};

//information ������Ϣ
struct infor
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
};
//ͨѶ¼����
struct Con
{
	struct infor data[MAX];
	int size;
};

//��������
void Initcontact(struct Con* ps);//��ʼ��ͨѶ¼
void add_contact(struct Con* ps);//�����ϵ��
void show_contact(const struct Con* ps);//��ӡͨѶ¼
void del_contact(struct Con* ps); //ɾ����Ϣ
void sear_contact(const struct Con* ps); //������Ϣ
void modi_contact(struct Con* ps); // �޸���Ϣ