# define _CRT_SECURE_NO_WARNINGS 

#include "contact.h"


void Initcontact(struct Con* ps)
{
	//��data�����ݳ�ʼ��Ϊ0
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
	//����ڴ�ռ�������Լ��Ƿ���Ҫ����
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
	//�����ж�ͨѶ¼�Ƿ�����
	CheckCapacity(ps);
	
	printf("����������:>");
	scanf("%s", ps->data[ps->size].name);		
	printf("����������:>");
	scanf("%d", &(ps->data[ps->size].age));
	printf("�������Ա�:>");
	scanf("%s", ps->data[ps->size].sex);
	printf("������绰:>");
	scanf("%s", ps->data[ps->size].tele);
	printf("��ӳɹ�\n");
	ps->size++; //������size���ӣ�Ϊ�´��������׼��

}

void show_contact(const struct Con* ps)
{
	//�����ж�ͨѶ¼�Ƿ�Ϊ��
	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		int i = 0;
		printf("%-10s\t%-4s\t%-5s\t%-12s\n", "����", "����", "�Ա�", "�绰");
		for (i = 0; i < ps->size; i++)
			printf("%-10s\t%-4d\t%-5s\t%-12s\n",
				ps->data[i].name,
				ps->data[i].age,
				ps->data[i].sex,
				ps->data[i].tele);
	}
}

//���Һ���--static���Σ���ֻ�������Դ�ļ�ʹ��
static int FindByCon(const struct Con* ps, char name[MAX_NAME])
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (strcmp(ps->data[i].name, name) == 0)
		{
			return i; //�ҵ��ˣ����ظ�Ԫ���±�
		}
	}
	return -1; //û�ҵ�������-1
}
void del_contact(struct Con* ps) //ɾ����Ϣ
{
	//������Ҫɾ����Ϣ���Ǹ���
	char name[MAX_NAME];
	printf("��������Ҫɾ���˵�����:>");
	scanf("%s", name);
	int pos = FindByCon(ps, name);

	//�жϲ�ɾ��
	if (-1 == pos)
	{
		//��ѭ�����˵ģ���û���ҵ�Ҫɾ�����Ǹ���
		printf("û���ҵ���Ҫɾ���ĸ�����Ϣ\n");
	}
	else
	{
		int j = 0;
		for (j = pos; j < ps->size - 1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		printf("ɾ���ɹ�\n");
		//ʵ��ûɾ����ֻ�ǽ������������ǰ�ƶ��˶��ѣ�����Ҫɾ������Ϣ������
		//ps->size  ֮������Ҫ��һ������Ϊ�����ڴ�ӡ��ʱ�򣬲���ӡ�����һ��Ԫ�ص���Ϣ
		ps->size--;
	}
}


void sear_contact(const struct Con* ps)
{
	char name[MAX_NAME];
	printf("��������Ҫ�����˵���Ϣ:>");
	scanf("%s", name);
	int pos = FindByCon(ps, name);
	if (-1 == pos)
	{
		//û�ҵ�
		printf("û���ҵ�����Ϣ\n");
	}
	else
	{
		printf("%-10s\t%-4s\t%-5s\t%-12s\n", "����", "����", "�Ա�", "�绰");
			printf("%-10s\t%-4d\t%-5s\t%-12s\n",
				ps->data[pos].name,
				ps->data[pos].age,
				ps->data[pos].sex,
				ps->data[pos].tele);
	}
}

void modi_contact(struct Con* ps)
{
	//����������Ҫ�޸Ķ��������
	char name[MAX_NAME];
	printf("��������Ҫ�޸��˵�����:>");
	scanf("%s", name);
	int pos = FindByCon(ps, name);
	if (-1 == pos)
	{
		//û�ҵ�'
		printf("û���ҵ���Ҫ�޸Ķ������Ϣ\n");
	}
	else
	{
		printf("����������:>");
		scanf("%s", ps->data[pos].name);
		printf("����������:>");
		scanf("%d", &(ps->data[pos].age));
		printf("�������Ա�:>");
		scanf("%s", ps->data[pos].sex);
		printf("������绰:>");
		scanf("%s", ps->data[pos].tele);

		printf("�޸ĳɹ�\n");
	}
}


void DestroyCapacity(struct Con* ps) //�ͷ��ڴ�ռ�
{
	free(ps->data);
	ps->data = NULL;
}