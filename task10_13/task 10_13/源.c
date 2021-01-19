# define _CRT_SECURE_NO_WARNINGS 
//#include <stdio.h>
//#include <string.h>
//#include <math.h>


#include <stdio.h>
#include<conio.h>
#define SIZE sizeof(struct stu_type)

#include <string.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS
struct stu_type
{
	int num;
	char name[16];
	int class1;
	int age;
	int score;
	char addr[20];
	struct stu_type* next;
	int n;
};

struct stu_type* create(void) {
	struct stu_type* head, * New, * last;
	int flag = 1;
	head = last = NULL;
	while (flag != 0) {
		int n;
		New = (struct stu_type*)malloc(SIZE);
		printf("输入学生的学号:");
		scanf("%d", &New->num);
		printf("输入学生的姓名:");
		scanf("%s", &New->name);
		printf("输入学生的班级:");
		scanf("%d", &New->class1);
		printf("输入学生的年龄:");
		scanf("%d", &New->age);
		printf("输入学生的成绩:");
		scanf("%d", &New->score);
		printf("输入学生的地址:");
		scanf("%s", New->addr);
		if (n == 1) head = New;
		else last->next = New;
		last = New;
		printf("\n是否继续输入下一个学生信息<1or0>:");
		scanf("%d", &flag);
	}
	last->next = NULL;
	return (head);
}

void show(struct stu_type* head) {
	struct stu_type* p;
	int n;
	printf("\n链表有%d个结点:\n", n);
	p = head;
	n = 1;
	while (p != NULL) {
		printf("第%d个结点:", n);
		printf("d,%s,%d,%d,%d,%s\n", p->num, p->name, p->class1, p->age, p->score, p->addr);
		p = p->next;
		n += 1;
	}
}

void find(struct stu_type* head) {
	struct stu_type* p;
	int num0;
	printf("\n输入要查找的学生学号:");
	scanf("%d", &num0);
	p = head;
	while (p != NULL) {
		if (p->num == num0) {
			printf("d,%s,%d,%d,%d,%s\n", p->num, p->name, p->class1, p->age, p->score, p->addr);
			break;
		}
		p = p->next;
	}
	if (p == NULL)
		printf("\n%d学号的学生没找到\n", num0);
}

struct stu_type* insert(struct stu_type* head) {
	struct stu_type* New, * p1, * p2;
	printf("输入要插入的学生信息:");
	New = (struct stu_type*)malloc(SIZE);
	printf("输入学生的学号:");
	scanf("%d", &New->num);
	printf("输入学生的姓名:");
	scanf("%s", &New->name);
	printf("输入学生的班级:");
	scanf("%d", &New->class1);
	printf("输入学生的年龄:");
	scanf("%d", &New->age);
	printf("输入学生的成绩:");
	scanf("%d", &New->score);
	printf("输入学生的地址:");
	scanf("%s", New->addr);
	p1 = head;
	if (head == NULL) {
		head = New;
		New->next = NULL;
	}
	else {
		while ((New->num > p1->num) && p1->next != NULL) {
			p2 = p1;
			p1 = p1->next;
		}
		if (New->num <= p1->num) {
			if (head == p1) head = New;
			else p2->next = New;
			New->next = p1;
		}
		else {
			p1->next = New;
			New->next = NULL;
		}
	}

	return (head);
}

struct stu_type* delete(struct stu_type* head) {
	struct stu_type* p1, * p2;
	int num0;
	printf("\n输入要删除的学生学号:");
	scanf("%d", &num0);
	if (head != NULL);
	{
		p1 = p2 = head;
		while (num0 != p1->num && p1->next != NULL) {
			p2 = p1;
			p1 = p1->next;
		}
		if (num0 == p1->num) {
			if (p1 == head) head = p1->next;
			else p2->next = p1->next;
			printf("delete:%d\n", num0);
			free(p1);

		}
		else
			printf("没有找到要删除的学生");
	}

	printf("\n链表中无结点\n");
	return (head);
}

int main() {
	int n = 0;
	struct stu_type* head;
	head = create();
	show(head);
	find(head);
	head = insert(head);
	show(head);
	head = delete(head);
	show(head);
	getchar();
}




//int main()
//{
//	int arr[] = { -1,-2,-3,-4,-5,-6,-7,-8,-9,-10 };
//	int max = arr[0];//注意小细节问题，例如此处初始化为0.有问题的，应该初始化为该数组的某一个元素
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		if (arr[i] > max)
//		{
//			max = arr[i];
//		}
//	}
//	printf("max=%d\n", max);
//	return 0;
//}


//
//int main()
//{
//	int i = 1;
//	double sum1 = 0.0;
//	double sum2 = 0.0;
//
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 2 == 1)
//		{
//			sum1 += 1.0 / i;//注意整形数值在做除法时，小数后面会被截断。   浮点类型不会
//		}
//		else if (i % 2 == 0)
//		{
//			sum2 += 1.0 / i;
//		}
//		
//	}
//
//	printf("%lf\n", sum1 - sum2);
//	return 0;
//}
//



//素数求解的n中境界

//int main()
//{//求1-100之间含有9的数值
//	int i = 0;
//	int count = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 10 == 9)
//			count++;
//		if (i / 10 == 9)   //例如99/10，实则是商一个9之后，余一个9，只取商的那个9，因为是整形，不是浮点型
//			count++;
//	}
//	printf("count=%d\n", count);
//	return 0;
//}




//int main()
//{
//	int i = 0;
//	int count = 0;
//
//	for (i = 100; i <= 200; i++)
//	{
//		//如果i=a*b,说明i就不是素数
//		//例:16=2*8=4*4,   则a和b中至少有一个数是<= 开平方的i
//		//2<=开平方的16
//
//		int j = 0;
//		for (j = 2; j <= sqrt(i); j++)    //sqrt 就是开方的意思，是数学库函数，头文件<math.h>
//		{
//			if (i % j == 0)
//			{
//				break;
//			}
//		}
//		if (j>sqrt(i))
//		{
//			count++;
//			printf("%d ", i);
//		}
//	}
//	printf("\ncount=%d\n", count);
//	return 0;
//}



//int main()
//{
//	int i = 0;
//	int count = 0;
//
//	for (i = 100; i <= 200; i++)
//	{
//		//素数的判断原理----能被1和本身整除的数
//		//既然只能被这两个数整除，那就创建这两个数之间的数，一一去取模即可
//		//创建2  -> i-1 之间的数值  
//		int j = 0;
//		for (j = 2; j <= i - 1; j++)
//		{
//			if (i % j == 0)
//			{
//				break;
//			}
//		}
//		if (i == j)
//		{
//			count++;
//			printf("%d ", i);
//		}
//	}
//	printf("\ncount=%d\n", count);
//	return 0;
//}

//int main()
//{
//	char password1[20] = { 0 };//此次输入的密码
//	char password2[20] = "123456";//云端保存的密码
//	printf("请输入密码:>");
//	
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		scanf("%s", password1);
//		if (strcmp(password1, password2) == 0)
//		{
//			printf("登陆成功!\n");
//			break;
//		}
//		else if (i < 2)
//		{
//			printf("密码错误，请重新输入:>");
//		}
//		else
//		{
//			printf("密码输入频繁，请稍后重试!\n");
//		}
//
//	}
//	return 0;
//}



//int main()
//{
//	int m = 0;
//	int n = 0;
//	int r = 0;
//	scanf("%d%d", &m, &n);
//	while (r = m % n)
//	{
//		//谁取模，谁就是最后的最大公因数,例如此处就是n为最大公因数,辗转相除法
//		m = n;
//		n = r;
//	}
//	printf("最大公因数是%d\n", n);
//	return 0;
//}