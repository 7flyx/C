# define _CRT_SECURE_NO_WARNINGS 

#include "contact.h"


void Initcontact(struct Con* ps)
{
	memset(ps->data, 0, sizeof(ps->data));
	ps->count = 0;
}


void add_contact(struct Con* ps)
{
	//�����ж�ͨѶ¼�Ƿ�����
	if (ps->count == MAX)
	{
		printf("ͨѶ¼����\n");
	}
	else
	{
		printf("����������:"); scanf("%s", ps->data[ps->count].name);
		printf("����������:"); scanf("%d", &(ps->data[ps->count].age));  //���ַ������ݣ���Ҫȡ��ַ
		printf("�������Ա�:"); scanf("%s", ps->data[ps->count].sex);
		printf("������绰:"); scanf("%s", ps->data[ps->count].tele);
		printf("��ӳɹ�\n");
		ps->count++;
	}
}

//��ʾͨѶ¼
void show_contact(const struct Con* ps)
{
	int i = 0;
	printf("%-10s\t%-4s\t%-5s\t%-12s\n", "����", "����", "�Ա�", "�绰");
	for (i = 0; i < ps->count; i++)
	{
		printf("%-10s\t", ps->data[i].name);
		printf("%-4d\t", ps->data[i].age);
		printf("%-5s\t", ps->data[i].sex);
		printf("%-12s\n", ps->data[i].tele);
	}
}

//ɾ����ϵ��
void del_contact(struct Con* ps)
{
	printf("��������Ҫɾ�����������:");
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
		printf("ͨѶ¼û�и���ϵ��\n");
	}
	else
	{
		int j = 0;
		for (j = i; j < ps->count - 1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->count--;  //�������һ��Ԫ�أ��ظ���
		printf("ɾ���ɹ�\n");
	}
}

//������ϵ��
void search_contact(const struct Con* ps)
{
	int i = 0;
	printf("��������Ҫ���Ҷ��������:");
	char name[MAX_NAME];
	scanf("%s", name);
	for (i = 0; i < ps->count; i++)
	{
		if (strcmp(ps->data[i].name, name) == 0)
		{
			printf("%-10s\t%-4s\t%-5s\t%-12s\n", "����", "����", "�Ա�", "�绰");
			printf("%-10s\t", ps->data[i].name);
			printf("%-4d\t", ps->data[i].age);
			printf("%-5s\t", ps->data[i].sex);
			printf("%-12s\n", ps->data[i].tele);
			break;
		}
	}
}



//�޸���ϵ��
void modifi_contact(struct Con* ps)
{
	char name[MAX_NAME];
	printf("��������Ҫ�޸Ķ��������:");
	scanf("%s", name);
	int i = 0;
	for (i = 0; i < ps->count; i++)
	{
		if (strcmp(ps->data[i].name, name) == 0)
		{
			printf("����������:"); scanf("%s", ps->data[i].name);
			printf("����������:"); scanf("%d", &(ps->data[i].age));  //���ַ������ݣ���Ҫȡ��ַ
			printf("�������Ա�:"); scanf("%s", ps->data[i].sex);
			printf("������绰:"); scanf("%s", ps->data[i].tele);
			printf("�޸ĳɹ�\n");
			break;
		}
	}
}