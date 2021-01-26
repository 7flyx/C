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
	struct S s = { "张三","男", 20 };
	if (pf == NULL)
		return 0;
	//scanf("%s %s %d", s.name, s.sex, &(s.age));
	//写入文件
	//fprintf(pf, "%s %s %d\n", s.name, s.sex, s.age);  //将s结构体中的数据，写入test文本当中
	fscanf(stdin, "%s %s %d", s.name, s.sex, &(s.age));
	//关闭文件
	fclose(pf);
	pf = NULL;
	return 0;
}