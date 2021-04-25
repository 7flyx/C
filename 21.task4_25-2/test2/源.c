# define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>  

typedef struct NODE
{
	char ID[20];  //ѧ��
	char name[10]; //����
	char sex[5]; //�Ա�
	char intime[10];    //����ʱ��
	char outtime[10]; //��ȥʱ��
	int age;  //����
	double temp;  //����
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
	printf("---  0.�˳�       1.��� ---\n");
	printf("---  2.ɾ��       3.�޸� ---\n");
	printf("---  4.����       5.ͳ�� ---\n");
	printf("---  6.����       7.��ʾ ---\n");
	printf("----------------------------\n");
}

void add_information(NODE** p)
{
	NODE* s = (NODE*)malloc(sizeof(NODE));
	NODE* tmp1, * tmp2;
	if (!s) return;  //���ٿռ�ʧ��
	s->next = NULL;

	printf("����������:"); scanf("%s", s->name);
	printf("�������Ա�:"); scanf("%s", s->sex);
	printf("����������:"); scanf("%d", &s->age);
	printf("������ѧ��:"); scanf("%s", s->ID);
	printf("���������£�����:36.8��:"); scanf("%lf", &s->temp);
	printf("���������ͼ���ʱ��(����: 9:30):"); scanf("%s", s->intime);
	printf("�������뿪ͼ���ʱ��(����: 21:30):"); scanf("%s", s->outtime);

	//�������½�������
	if (!(*p)->next)
	{
		(*p)->next = s;
	}
	else
	{
		tmp1 = *p;
		tmp2 = (*p)->next;  //ָ���һ�����
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
	//����ѧ�Ž���ɾ��
	char ID[20];
	NODE* tmp1 = *p;  //ǰһ���
	NODE* tmp2 = (*p)->next; //��һ���
	printf("��������Ҫɾ�������ѧ��:");
	scanf("%s", ID);
	while (tmp2)
	{
		if (strcmp(tmp2->ID, ID) == 0)
		{
			NODE* s = tmp2;
			tmp1->next = tmp2->next;
			free(s);
			printf("ɾ���ɹ�!\n");
			return;
		}
		tmp1 = tmp2;
		tmp2 = tmp2->next;
	}
	printf("Ϊ�ҵ�ѧ��Ϊ%s�������Ϣ!\n", ID);
}

void mod_infomation(NODE** p)
{
	//����ѧ�Ž����޸���Ϣ
	char ID[20];
	NODE* tmp1 = *p;  //ǰһ���
	NODE* tmp2 = (*p)->next; //��һ���
	NODE* s = (NODE*)malloc(sizeof(NODE));
	if (!s) return;
	printf("��������Ҫ�޸Ķ����ѧ��:");
	scanf("%s", ID);
	while (tmp2)
	{
		if (strcmp(tmp2->ID, ID) == 0)
		{
			NODE* q = tmp2;
			tmp1->next = tmp2->next;
			free(q);
			printf("����������:"); scanf("%s", s->name);
			printf("�������Ա�:"); scanf("%s", s->sex);
			printf("����������:"); scanf("%d", &s->age);
			printf("������ѧ��:"); scanf("%s", s->ID);
			printf("���������£�����:36.8��:"); scanf("%lf", &s->temp);
			printf("���������ͼ���ʱ��(����: 9:30):"); scanf("%s", s->intime);
			printf("�������뿪ͼ���ʱ��(����: 21:30):"); scanf("%s", s->outtime);
			printf("�޸ĳɹ�!\n");

			//���µ����ݽ���������
			tmp1 = *p;
			tmp2 = (*p)->next;  //ָ���һ�����
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
	printf("Ϊ�ҵ�ѧ��Ϊ%s�������Ϣ!\n", ID);
}

void sear_infomation(NODE** p)
{
	//����ѧ�Ų�����Ϣ
	char ID[20];
	NODE* tmp1 = *p;  //ǰһ���
	NODE* tmp2 = (*p)->next; //��һ���
	printf("��������Ҫ���Ҷ����ѧ��:");
	scanf("%s", ID);
	while (tmp2)
	{
		if (strcmp(tmp2->ID, ID) == 0)
		{
			//���� ���� �Ա� ѧ�� ���� ����ʱ��
			printf("%s\t%s\t%s\t%-16s %s\t%s %s\n", "����", "����", "�Ա�", "ѧ��", "����", "����ʱ��", "�뿪ʱ��");
			printf("%s\t%d\t%s\t%s\t%.1lf\t%s\t%s\n", tmp2->name, tmp2->age, tmp2->sex, tmp2->ID, tmp2->temp, tmp2->intime, tmp2->outtime);
			return;
		}
		tmp1 = tmp2;
		tmp2 = tmp2->next;
	}
	printf("Ϊ�ҵ�ѧ��Ϊ%s�������Ϣ!\n", ID);
}

void save_infomation(NODE** p)
{
	/*�����ڴ��е���Ϣ��������
	�˴����ļ�·������ʹ�����·�������Ǿ���·��
	FILE* pf = fopen("E:\\vs����ѧϰ\\�ճ���ϰ\\test\\homework\\infomation.txt","w");*/
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
	strcat(date, ".txt"); //׷�� .txt

	FILE* pf = fopen(date, "w");
	if (!pf)
	{
		printf("save:%s", strerror(errno));
		return;
	}
	NODE* tmp = (*p)->next;

	fprintf(pf, "% s\t % s\t % s\t %-16s\t % s\t % s\t % s\n",
		"����", "����", "�Ա�", "ѧ��", "����", "����ʱ��", "�뿪ʱ��");

	while (tmp)
	{
		//д���ļ�--fprintf()��ʽ��д��
		fprintf(pf, "% s\t % d\t % s\t % s\t % .1lf\t % s\t % s\n",
			tmp->name, tmp->age, tmp->sex, tmp->ID, tmp->temp, tmp->intime, tmp->outtime);
		tmp = tmp->next;
	}
	printf("д��ɹ�!\n");
	fclose(pf);
	pf = NULL;
}

void InitInfomation(NODE** p)
{
	//�����Ѿ����ļ����е����ݽ����ڴ�
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
	printf("%s\t%s\t%s\t%-16s %s\t%s %s\n", "����", "����", "�Ա�", "ѧ��", "����", "����ʱ��", "�뿪ʱ��");
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
	printf("%s\t%s\t%s\t%-16s %s\t%s %s\n", "����", "����", "�Ա�", "ѧ��", "����", "����ʱ��", "�뿪ʱ��");
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
		return 0; //���ٿռ�ʧ��
	head->next = NULL;

	//�����ļ��е�����
	InitInfomation(&head);
	do
	{
		menu();
		printf("��������Ӧ�Ĳ���:");
		scanf("%d", &i);

		switch (i)
		{
		case EXIT:  //�˳� --�ͷ��ڴ�ռ�
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
			printf("ѡ�����!\n");
			break;
		}
	} while (i);

	free(head);
	return 0;
}

