# define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>

int main()
{
	int num = 0;
	printf("请输入:");
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
//		m++;//此时m=3
//	case 2:
//		n++;//n=2
//	case 3:
//		switch (n)//此时（整形表达式）的n为2
//		{
//		case 1:
//			n++;
//		case 2://所以从case 2 开始执行
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
//	printf("请输入:");
//	scanf("%d", &day);
//
//	switch (day)
//	{
//	case 1:
//	case 2:
//	case 3:
//	case 4:
//	case 5:
//		printf("工作日\n");
//		break;
//	case 6:
//	case 7:
//		printf("休息日\n");
//		break;
//	default:
//		printf("输入错误\n");
//	}
//	return 0;
//}



//int main()
//{
//	int day = 0;
//	printf("请输入：");
//	scanf("%d", &day);
//	switch (day)
//	{
//	case 1:
//		printf("星期一\n");
//		break;
//	case 2:
//		printf("星期二\n");
//		break;
//	case 3:
//		printf("星期三\n");
//		break;
//	case 4:
//		printf("星期四\n");
//		break;
//	case 5:
//		printf("星期五\n");
//		break;
//	case 6:
//		printf("星期六\n");
//		break;
//	case 7:
//		printf("星期天\n");
//		break;
//		//break意思是跳出switch语句
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


       //例1
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
//	//悬空else问题；前提是第一个if后面没有{}
//	//else只与最近的，未匹配的if组合，即上面的else与第九行的if组合
//	return 0;
//}
        //例2

//int main()
//{
//	int a = 0;
//	int b = 2;
//
//	if (a == 1)//后面接{}，不存在悬空else问题 
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
	//		printf("未成年\n");
	//	else
	//	{
	//		if (age >= 18 && age < 28)//嵌套在else语句中，逻辑一样
	//			printf("青年\n");
	//		else if (age >= 28 && age < 50)
	//			printf("壮年\n");
	//		else if (age >= 50 && age < 90)
	//			printf("老年\n");
	//		else
	//			printf("老不死\n");
	//	}

		//if (age < 18)
		//	printf("未成年\n");
		//else if (age >= 18 && age < 28)//多支选择语句，判断条件应用 ‘&&’
		//	printf("青年\n");
		//else if (age >= 28 && age < 50)
		//	printf("壮年\n");
		//else if (age >= 50 && age < 90)
		//	printf("老年\n");
		//else
		//	printf("老不死\n");

		//if (18 <= age < 28)//这样写判断条件不对，该条件执行起来为(0<28),为真
			//printf("青年\n");
	//return 0;
 //}