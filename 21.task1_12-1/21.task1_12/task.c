# define _CRT_SECURE_NO_WARNINGS 

#include "contact.h"



void menu()
{
	printf("***********************************\n");
	printf("*****   1. add      2. del   ******\n");
	printf("*****   3. search   4. modifi******\n");
	printf("*****   5. show     0. exit  ******\n");
	printf("***********************************\n");
}

int main()
{
	int input = 0;
	struct Con con; //声明一个通讯录类型，相当于一本通讯录，名叫con
	Initcontact(&con); //初始化通讯录
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
			//根据ADD等常量背后的值，进行判断
		case ADD:
			add_contact(&con);
			break;
		case DEL:
			del_contact(&con);
			break;
		case SEARCH:
			search_contact(&con);
			break;
		case MODIFI:
			modifi_contact(&con);
			break;
		case SHOW :
			show_contact(&con);
			break;
		default :
			printf("选择错误\n");
			break;
		}
	} while(input);
	return 0;
}