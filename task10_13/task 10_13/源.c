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
		printf("����ѧ����ѧ��:");
		scanf("%d", &New->num);
		printf("����ѧ��������:");
		scanf("%s", &New->name);
		printf("����ѧ���İ༶:");
		scanf("%d", &New->class1);
		printf("����ѧ��������:");
		scanf("%d", &New->age);
		printf("����ѧ���ĳɼ�:");
		scanf("%d", &New->score);
		printf("����ѧ���ĵ�ַ:");
		scanf("%s", New->addr);
		if (n == 1) head = New;
		else last->next = New;
		last = New;
		printf("\n�Ƿ����������һ��ѧ����Ϣ<1or0>:");
		scanf("%d", &flag);
	}
	last->next = NULL;
	return (head);
}

void show(struct stu_type* head) {
	struct stu_type* p;
	int n;
	printf("\n������%d�����:\n", n);
	p = head;
	n = 1;
	while (p != NULL) {
		printf("��%d�����:", n);
		printf("d,%s,%d,%d,%d,%s\n", p->num, p->name, p->class1, p->age, p->score, p->addr);
		p = p->next;
		n += 1;
	}
}

void find(struct stu_type* head) {
	struct stu_type* p;
	int num0;
	printf("\n����Ҫ���ҵ�ѧ��ѧ��:");
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
		printf("\n%dѧ�ŵ�ѧ��û�ҵ�\n", num0);
}

struct stu_type* insert(struct stu_type* head) {
	struct stu_type* New, * p1, * p2;
	printf("����Ҫ�����ѧ����Ϣ:");
	New = (struct stu_type*)malloc(SIZE);
	printf("����ѧ����ѧ��:");
	scanf("%d", &New->num);
	printf("����ѧ��������:");
	scanf("%s", &New->name);
	printf("����ѧ���İ༶:");
	scanf("%d", &New->class1);
	printf("����ѧ��������:");
	scanf("%d", &New->age);
	printf("����ѧ���ĳɼ�:");
	scanf("%d", &New->score);
	printf("����ѧ���ĵ�ַ:");
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
	printf("\n����Ҫɾ����ѧ��ѧ��:");
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
			printf("û���ҵ�Ҫɾ����ѧ��");
	}

	printf("\n�������޽��\n");
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
//	int max = arr[0];//ע��Сϸ�����⣬����˴���ʼ��Ϊ0.������ģ�Ӧ�ó�ʼ��Ϊ�������ĳһ��Ԫ��
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
//			sum1 += 1.0 / i;//ע��������ֵ��������ʱ��С������ᱻ�ضϡ�   �������Ͳ���
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



//��������n�о���

//int main()
//{//��1-100֮�京��9����ֵ
//	int i = 0;
//	int count = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 10 == 9)
//			count++;
//		if (i / 10 == 9)   //����99/10��ʵ������һ��9֮����һ��9��ֻȡ�̵��Ǹ�9����Ϊ�����Σ����Ǹ�����
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
//		//���i=a*b,˵��i�Ͳ�������
//		//��:16=2*8=4*4,   ��a��b��������һ������<= ��ƽ����i
//		//2<=��ƽ����16
//
//		int j = 0;
//		for (j = 2; j <= sqrt(i); j++)    //sqrt ���ǿ�������˼������ѧ�⺯����ͷ�ļ�<math.h>
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
//		//�������ж�ԭ��----�ܱ�1�ͱ�����������
//		//��Ȼֻ�ܱ����������������Ǿʹ�����������֮�������һһȥȡģ����
//		//����2  -> i-1 ֮�����ֵ  
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
//	char password1[20] = { 0 };//�˴����������
//	char password2[20] = "123456";//�ƶ˱��������
//	printf("����������:>");
//	
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		scanf("%s", password1);
//		if (strcmp(password1, password2) == 0)
//		{
//			printf("��½�ɹ�!\n");
//			break;
//		}
//		else if (i < 2)
//		{
//			printf("�����������������:>");
//		}
//		else
//		{
//			printf("��������Ƶ�������Ժ�����!\n");
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
//		//˭ȡģ��˭���������������,����˴�����nΪ�������,շת�����
//		m = n;
//		n = r;
//	}
//	printf("���������%d\n", n);
//	return 0;
//}