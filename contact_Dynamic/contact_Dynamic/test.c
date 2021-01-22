# define _CRT_SECURE_NO_WARNINGS 
#include "contact.h"


void menu()
{
	printf("*******************************\n");
	printf("*****  1.add      2.del   *****\n");
	printf("*****  3.search   4.modifi*****\n");
	printf("*****  5.show     6.sort  *****\n");
	printf("*****  0.exit             *****\n");
	printf("*******************************\n");
}
int main()
{
	//创建通讯录
	struct Con con;
	//初始化通讯录
	Initcontact(&con);
	int input = 0;
	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			add_contact(&con);
			break;
		case DEL:
			del_contact(&con);
			break;
		case SEARCH:
			sear_contact(&con);
			break;
		case MODIFI:
			modi_contact(&con);
			break;
		case SHOW:
			show_contact(&con);
			break;
		case SORT:
			break;
		case EXIT:
			//释放malloc开辟的内存空间
			DestroyCapacity(&con);
			printf("退出通讯录\n");
			break;
		default :
			printf("选择错误\n");
			break;
		}
	} while (input);
	return 0;
}