# define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>

int main()
{
	int num = 0;
	printf("������:");
	scanf("%d", &num);
	printf("%d\n", 5 * num);
	return 0;
}
//int main()
//{
//	int n = 1;
//	int m = 2;
//
//	switch (n)
//	{
//	case 1:
//		m++;//��ʱm=3
//	case 2:
//		n++;//n=2
//	case 3:
//		switch (n)//��ʱ�����α��ʽ����nΪ2
//		{
//		case 1:
//			n++;
//		case 2://���Դ�case 2 ��ʼִ��
//			m++;
//			n++;
//			break;
//		}
//	case 4:
//		m++;
//		break;
//	default:
//		break;
//	}
//	return 0;
//}

//int main()
//{
//	int day = 0;
//	printf("������:");
//	scanf("%d", &day);
//
//	switch (day)
//	{
//	case 1:
//	case 2:
//	case 3:
//	case 4:
//	case 5:
//		printf("������\n");
//		break;
//	case 6:
//	case 7:
//		printf("��Ϣ��\n");
//		break;
//	default:
//		printf("�������\n");
//	}
//	return 0;
//}



//int main()
//{
//	int day = 0;
//	printf("�����룺");
//	scanf("%d", &day);
//	switch (day)
//	{
//	case 1:
//		printf("����һ\n");
//		break;
//	case 2:
//		printf("���ڶ�\n");
//		break;
//	case 3:
//		printf("������\n");
//		break;
//	case 4:
//		printf("������\n");
//		break;
//	case 5:
//		printf("������\n");
//		break;
//	case 6:
//		printf("������\n");
//		break;
//	case 7:
//		printf("������\n");
//		break;
//		//break��˼������switch���
//
//	}
//
//	return 0;
//}


//int main()
//{
//	 int a =1;
//	
//	while(a<100)
//	{
//		if (1 == a % 2)
//		{
//		printf("%d ",a);
//		}
//		a++;
//		
//	}
//	return 0;
//}


       //��1
//int main()
//{
//	int a = 0;
//	int b = 2;
//
//	if (a == 1)
//		if (b == 2)
//			printf("hehe\n");
//		else
//			printf("haha\n");
//	//����else���⣻ǰ���ǵ�һ��if����û��{}
//	//elseֻ������ģ�δƥ���if��ϣ��������else��ھ��е�if���
//	return 0;
//}
        //��2

//int main()
//{
//	int a = 0;
//	int b = 2;
//
//	if (a == 1)//�����{}������������else���� 
//	{
//		if (b == 2)
//			printf("hehe\n");
//	}
//	else
//		printf("haha\n");
//	return 0;
//}


	//int main()
	//{
	//	int age = 1000;
	//
	//	if (age < 18)
	//		printf("δ����\n");
	//	else
	//	{
	//		if (age >= 18 && age < 28)//Ƕ����else����У��߼�һ��
	//			printf("����\n");
	//		else if (age >= 28 && age < 50)
	//			printf("׳��\n");
	//		else if (age >= 50 && age < 90)
	//			printf("����\n");
	//		else
	//			printf("�ϲ���\n");
	//	}

		//if (age < 18)
		//	printf("δ����\n");
		//else if (age >= 18 && age < 28)//��֧ѡ����䣬�ж�����Ӧ�� ��&&��
		//	printf("����\n");
		//else if (age >= 28 && age < 50)
		//	printf("׳��\n");
		//else if (age >= 50 && age < 90)
		//	printf("����\n");
		//else
		//	printf("�ϲ���\n");

		//if (18 <= age < 28)//����д�ж��������ԣ�������ִ������Ϊ(0<28),Ϊ��
			//printf("����\n");
	//return 0;
 //}