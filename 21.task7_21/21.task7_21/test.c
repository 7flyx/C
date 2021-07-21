#define _CRT_SECURE_NO_WARNINGS 1

#include "Contact.h"



int main()
{
	//实现通讯录，增删查改以及排序功能
	//通过链表实现

	int input = 0;
	Contact con = { {NULL}, {0} };
	InitContact(&con);

	do
	{
		menu();
		printf("请选择:");
		scanf("%d", &input);

		switch (input)
		{
			case ADD:
				contactAdd(&con);
				break;
			case DEL:
				contactDel(&con);
				break;
			case SEARCH:
				searchPer(&con);
				break;
			case MODIFY:
				modifyPer(&con);
				break;
			case SORT:
				sortAscending(&con);
				printPer(&con);
				break;
			case CLEAR:
				spaceFree(&con);
				break;
			case PRINT:
				printPer(&con);
				break;
			case SAVE:
				savePer(&con);
				break;
			case EXIT:
				spaceFree(&con);
				break;
			default:
				printf("input value error.");
				break;
		}
	} while (input);

	return 0;
}