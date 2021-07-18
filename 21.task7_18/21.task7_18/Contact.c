#define _CRT_SECURE_NO_WARNINGS 1
#include "Contact.h"


void menu()
{
	printf("******************************\n");
	printf("***** 1.add    2.del     *****\n");
	printf("***** 3.search 4.modify  *****\n");
	printf("***** 5.sort   6.clear   *****\n");
	printf("***** 7.print  0.exit    *****\n");
	printf("******************************\n");
}

void contactAdd(Contact* con)
{
	Info* tmp = (Info*)malloc(sizeof(Info));
	printf("������������"); scanf("%s", tmp->name);
	printf("�������Ա�"); scanf("%s", tmp->sex); 
	printf("���������䣺"); scanf("%s", tmp->age); 
	printf("������绰��"); scanf("%s", tmp->tele); 
	printf("�������ַ��"); scanf("%s", tmp->addr);

	tmp->next = con->info;
	con->info = tmp; //ͷ�巨
}

void spaceFree(Contact* con)
{
	//����ȫ���Ŀռ�
	while (con->info != NULL)
	{
		Info* next = con->info->next;
		free(con->info);
		con->info = next;
	}
}

void printPer(const Contact* con)
{
	//��ӡȫ������ϵ��
	if (con->info == NULL)
	{
		printf("contact list is empty.\n");
	}
	else
	{
		Info* node = con->info;
		printf("%20s\t%5s\t%3s\t%11s\t%20s\n", "����", "�Ա�", "����", "�绰", "��ַ");
		while (node != NULL)
		{
			printf("%20s\t%5s\t%3s\t%11s\t%20s\n",
				node->name, node->sex, node->age, node->tele, node->addr);
			node = node->next;
		}
	}
}

void contactDel(Contact* con)
{
	char aimName[MAX_NAME] = { 0 };
	printf("��������Ҫɾ�����������:");
	scanf("%s", aimName);
	//����������ɾ������
	Info* cur = con->info;
	Info* pre = NULL;
	while (cur != NULL)
	{
		if (strcmp(aimName, cur->name) == 0)
		{
			if (pre == NULL)
				con->info = cur->next;
			else
				pre->next = cur->next;
			free(cur);
			printf("delete success.\n");
			return;
		}
		else
		{
			pre = cur;
			cur = cur->next;
		}
	}
	printf("delete fail. contact list not the name\n");
}

void searchPer(const Contact* con)
{
	char aimName[MAX_NAME] = { 0 };
	printf("��������Ҫ���ҵ���ϵ������:");
	scanf("%s", aimName);

	Info* node = con->info;
	while (node != NULL)
	{
		if (strcmp(node->name, aimName) == 0)
		{
			printf("%20s\t%5s\t%3s\t%11s\t%20s\n", "����", "�Ա�", "����", "�绰", "��ַ");
			printf("%20s\t%5s\t%3s\t%11s\t%20s\n",
				node->name, node->sex, node->age, node->tele, node->addr);
			node = node->next;
			return;
		}
		else
		{
			node = node->next;
		}
	}
	printf("search fail. contact list not the name.");
}

void modifyPer(Contact* con)
{
	char aimName[MAX_NAME] = { 0 };
	printf("��������Ҫ�޸ĵ���ϵ������:");
	scanf("%s", aimName);
	Info* node = con->info;
	while (node != NULL)
	{
		if (strcmp(node->name, aimName) == 0)
		{
			printf("������������"); scanf("%s", node->name);
			printf("�������Ա�"); scanf("%s", node->sex);
			printf("���������䣺"); scanf("%s", node->age);
			printf("������绰��"); scanf("%s", node->tele);
			printf("�������ַ��"); scanf("%s", node->addr);
			printf("modify success.\n");
			return;
		}
		else
		{
			node = node->next;
		}
	}
	printf("modify fail. contact list not the name.");
}

void sortAscending(Contact* con)
{
	//��������������������
	//�Ƚ�con��Info֮��Ͽ����ֱ�������ָ��ȥָ������
	Info* infoP = con->info;
	Info* cur = NULL;
	Info* pre = NULL;
	con->info = NULL;
	while (infoP != NULL)
	{
		if (cur != NULL)
		{
			if (strcmp(infoP->name, cur->name) <= 0)
			{
				//����
				if (pre != NULL)
				{
					Info* tmp = infoP;
					infoP = infoP->next;
					tmp->next = cur;
					pre->next = tmp;
					
					cur = con->info;
					pre = NULL;
				}
				else
				{
					Info* tmp = infoP;
					infoP = infoP->next;
					tmp->next = con->info;
					con->info = tmp;
					cur = con->info;
				}
			}
			else
			{
				//curָ�����
				pre = cur;
				cur = cur->next;
			}
		}
		else
		{
			//ֱ�Ӳ���
			if (pre != NULL)
			{
				pre->next = infoP;
				infoP = infoP->next;
				pre->next->next = NULL;
				pre = NULL; //��0
				cur = con->info;
			}
			else
			{
				con->info = infoP;
				infoP = infoP->next;
				con->info->next = NULL;
				cur = con->info;
			}

		}
		
	}
}