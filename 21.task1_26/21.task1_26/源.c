# define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>

struct S
{	
	char name[20];
	char sex[5];
	int age;	
};

int main()
{
	FILE* pf = fopen("test.txt", "r+");
	struct S s = { "����","��", 20 };
	if (pf == NULL)
		return 0;
	//scanf("%s %s %d", s.name, s.sex, &(s.age));
	//д���ļ�
	//fprintf(pf, "%s %s %d\n", s.name, s.sex, s.age);  //��s�ṹ���е����ݣ�д��test�ı�����
	fscanf(stdin, "%s %s %d", s.name, s.sex, &(s.age));
	//�ر��ļ�
	fclose(pf);
	pf = NULL;
	return 0;
}