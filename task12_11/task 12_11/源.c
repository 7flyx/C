# define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <math.h>

void Judge_month(int month)
{
	int arr[] = { 1,3,5,7,8,10,12 };		
	int i;
	for (i = 0; i < 7; i++)
	{
		if (arr[i] == month)
		{
			printf("31\n");
			break;
		}
	}
	if (i == 7)
		printf("30\n");	
}

int main()
{
	int year, month;
	while (scanf("%d%d", &year, &month) != EOF)
	{
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		{
			//闰年
			if (month == 2)
				printf("29\n");
			else
				Judge_month(month);//判断大月小月
		}
		else
		{
			//平年
			if (month == 2)
				printf("28\n");
			else
				Judge_month(month);//判断大月小月
		}
	}
	return 0;
}

//
//int main()
//{
//	float a, b, c;
//	//ax^2+bx+c=0
//	while (scanf("%f%f%f", &a, &b, &c) != EOF)
//	{
//		//判断是否为一元二次方程
//		if (a != 0)
//		{
//			//判断方程是否有解
//			if ((b * b - 4 * a * c) > 0)
//			{
//				float x1 = -(b + sqrt(b * b - 4 * a * c)) / (2 * a);//小
//				float x2 = (sqrt(b * b - 4 * a * c) - b) / (2 * a);//大
//				printf("x1=%.2f;x2=%.2f\n", x1, x2);
//			}
//			else if ((b * b - 4 * a * c) == 0)
//			{
//				float x = ((b * b - 4 * a * c) - b) / (2 * a);
//				printf("x1=x2=%.2f\n", x);
//			}
//			else
//			{
//				float s = -(b) / (2 * a);//实部
//				float x = sqrt(-(b * b - 4 * a * c)) / (2 * a);//虚部
//				printf("x1=%.2f-%.2fi;x2=%.2f+%.2fi\n", s, x, s, x);
//			}
//		}
//		else
//			printf("Not quadratic equation\n");
//	}
//	return 0;
//}



//int main()
//{
//
//	int high, weight ;
//	while (scanf("%d%d",&weight, &high) != EOF)
//	{
//		float high2 = (float)high / 100;
//		float BMI = weight / (high2 * high2);
//		if (BMI < 18.5)
//			printf("Underweight\n");
//		else if (BMI >= 18.5 && BMI <= 23.9)
//			printf("Normal\n");
//		else if (BMI > 23.9 && BMI <= 27.9)
//			printf("Overweight\n");
//		else
//			printf("Obese\n");
//	}
//	return 0;
//}


//
//int main()
//{
//	int a, b, c;
//	while (scanf("%d%d%d", &a, &b, &c) != EOF)
//	{
//		if (a == b && b == c && c != 0)
//			printf("Equilateral triangle!\n");
//		else
//		{
//			if ((a + b) > c && (a + c) > b && (b + c) > a)
//			{
//				if (a == b || a == c || b == c)
//					printf("Isosceles triangle!\n");
//			}
//			else
//				printf("Not a triangle!\n");
//
//		}
//	}
//	return 0;
//}




//#include <stdio.h>
//int main()
//{
//    float num;
//    short y, d, n;
//    scanf("%f%hd%hd%hd", &num, &y, &d, &n);
//    if (y == 11 && d == 11)
//    {
//        if (1 == n)
//        {
//            if (num * 0.7 - 50 > 0)
//                printf("%.2f\n", num * 0.7 - 50);
//            else
//                printf("%.2f", 0.00);
//        }
//        else
//            printf("%.2f\n", num * 0.7);
//    }
//    else if (y == 12 && d == 12)
//    {
//        if (1 == n)
//        {
//            if (num * 0.8 - 50 > 0)
//                printf("%.2f\n", num * 0.8 - 50);
//            else
//                printf("%.2f", 0.00);
//        }
//        else
//            printf("%.2f\n", num * 0.8);
//    }
//    else
//        printf("%.2f\n", num - 50);
//    return 0;
//}



//int main()
//{
//	int a, b;
//	scanf("0x%x 0%o", &a, &b);
//	printf("%d\n", a + b);
//	return 0;
//}

//
//int main()
//{
//	float a, b, c;
//	scanf("%f%f%f", &a, &b, &c);
//	printf("%.2f %.2f", (a + b + c), (a + b + c) / 3);
//	return 0;
//}


//int main()
//{
//	int hour = 0;
//	int min = 0;
//	int sec = 0;
//	int seconds;
//	scanf("%d", &seconds);
//	if (seconds >= 60)
//	{
//		 min = seconds / 60;  //分钟数
//		 sec = seconds % 60;  //剩余秒数
//		 if (min >= 60)
//		 {
//			 hour = min / 60;  //小时数
//			 min %= 60;
//		 }
//	}
//	else
//	{
//		sec = seconds;
//	}
//	printf("%d %d %d\n", hour, min, sec);
//	return 0;
//}