# define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>

int Digitsum(int n)
{
	if (n > 0)
		return n % 10 + Digitsum(n / 10);
	else
		return 0;
}

int main()
{
	int n;
	scanf("%d", &n);
	int sum = Digitsum(n);
	printf("%d\n", sum);
	return 0;
}



//int main()
//{
//	int line = 0;
//	scanf("%d", &line);
//	int i, j;
//	//��ӡ�ϰ벿��
//	for (i = 0; i < line; i++)
//	{
//		for (j = 0; j < line - 1 - i; j++)
//			printf(" ");
//		for (j = 0; j < 2 * (i) + 1; j++)
//			printf("*");
//		printf("\n");
//	}
//	//��ӡ�°岿��
//	for (i = 0; i < line - 1; i++)
//	{
//		for (j = 0; j <= i; j++)
//			printf(" ");
//		for (j = 0; j < 2 * (line - 1 - i) - 1; j++)
//			printf("*");
//		printf("\n");
//	}
//	return 0;
//}


//
//int main()
//{
//	//0-100000֮���ˮ�ɻ���
//	int i = 0;
//	for (i = 0; i <= 100000; i++)
//	{
//		//1.����i��λ��   n
//		int tmp = i;
//		int n = 1;
//		int sum = 0;
//		while (tmp /= 10)
//		{
//			n++;
//		}
//		//2. ����i��n�η��ĺ�  sum
//		tmp = i;
//		while (tmp)
//		{
//			sum += pow(tmp % 10, n);
//			tmp /= 10;
//		}
//		//3. �Ƚ�sum��i�Ƿ����
//		if (i == sum)
//			printf("%d ", i);
//
//	}
//	return 0;
//}


//int main()
//{
//	//����2+22+222+2222+22222  �ȵȣ�n��ʾ2��m��ʾ��λ��
//	int n, m, i;
//	scanf("%d%d", &n, &m);
//	int sum = 0;
//	int ret = 0;
//	for (i = 0; i < m; i++)
//	{
//		ret = ret * 10 + n;
//		//�㷨ʵ�֣�����һ�����Ľ����Ϊ��һ�����Ĳ������м��㣬����˼·
//		sum += ret;
//	}
//	printf("%d\n", sum);
//	return 0;
//}



//void Research(char* str)
//{
//	//��Ȼ��Ҫ����һ���ַ���������λ�ã���Ҫ�õ��±�
//	assert(str);  //���ԣ���֤�������Ĳ��ǿ�ָ��
//	int len = strlen(str);
//	char* left = str;
//	char* right = str + len - 1;
//	//�˴������±꣬��������Ķ��������һ���������飬ֱ���������±��ܹ�����
//	//���Ǵ˴�������һ���ַ�����������һ�����ֿ϶����У�Ӧ�ü�����Ԫ�صĵ�ַ��
//	//���ܻ������Ԫ�صĵ�ַ����������±�0�����Ӳ���0 ���ƺ������˴��ţ������������
//	//�ӵ� str  ��ʵ��һ����ַ���������±�0
//
//
//	while (left < right)
//	{
//		//��������
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		*left++;
//		*right--;
//	}
//}
//
//int main()
//{
//	char arr[100] = { 0 };
//	gets(arr);  //��ȡһ�е�����
//	Research(arr);
//	printf("%s\n", arr);
//	return 0;
//}









//#include <stdio.h>
//int main()
//{
//    int m, n, count = 0;  //m��  n��
//    int arr1[100][100] = { 0 };
//    int arr2[100][100] = { 0 };
//    scanf("%d%d", &m, &n);
//    int i, j;
//    for (i = 0; i < m; i++)  // arr1����
//    {
//        for (j = 0; j < n; j++)
//        {
//            scanf("%d", &arr1[i][j]);
//        }
//    }
//
//    for (i = 0; i < m; i++)
//    {
//        for (j = 0; j < n; j++)
//        {
//            scanf("%d", &arr2[i][j]);
//        }
//    }
//    //�Ƚ�����
//    for (i = 0; i < m; i++)
//    {
//        for (j = 0; j < n; j++)
//        {
//            if (arr1[i][j] == arr2[i][j])
//            {
//                count++;
//            }
//        }
//    }
//    float sum = (float)count / (m * n) * 100;
//    printf("%.2f", sum);
//    return 0;
//}








//#include <stdio.h>
//int main()
//{
//    int n, m, x, i;
//    int arr[50] = { 0 };
//    scanf("%d", &n);
//    for (i = 0; i < n; i++)
//        scanf("%d", &arr[i]);
//    scanf("%d", &x); //�������
//    for (i = n - 1; i >= 0; i--)
//    {
//        if (arr[i] > x)
//            arr[i + 1] = arr[i];
//        else
//        {
//            arr[i+1] = x; 
//            break;
//        }
//    }
//    if (i == -1)
//        arr[i+1] = x;
//    for (i = 0; i <= n; i++)
//        printf("%d ", arr[i]);
//    return 0;
//}