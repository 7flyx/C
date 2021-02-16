# define _CRT_SECURE_NO_WARNINGS 

#include "多项式加法.h"


int main()
{

	Link headA = (Link)malloc(sizeof(Node));
	headA->next = NULL;


	Link headB = (Link)malloc(sizeof(Node));
	headB->next = NULL;
	//写两个多项式，用链表存储
	Input_Num(headA);
	show_Num(headA);
	Input_Num(headB);
	//show_Num(headB);

	Add_Num(headA, headB);
	//释放headB的空间
	free(headB);
	headB = NULL;

	Link p = headA->next;
	printf("合并之后的等式为：\n");
	while (p)
	{
		printf("%d %d\n", p->coefficient, p->exponent);
		p = p->next;
	}

	return 0;
}