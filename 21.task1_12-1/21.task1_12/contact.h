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

//������Ϣ
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
	struct infor data[MAX];  //����MAX����ϵ�˵�������д洢
	int count;  //�����Ѿ��ж����˴���ͨѶ¼��
};




//����������
void Initcontact(struct Con* ps);  //��ʼ��ͨѶ¼
void add_contact(struct Con* ps);  //������ϵ��
void show_contact(const struct Con* ps); // ��ʾͨѶ¼
void del_contact(struct Con* ps); //ɾ����ϵ��
void search_contact(const struct Con* ps); //������ϵ��
void modifi_contact(struct Con* ps); //�޸���ϵ��