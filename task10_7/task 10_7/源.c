# define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>


int main()
{
	char arr1[] = "##############";
	char arr2[] = "welcome to bit";

	int left = 0;//���±�
	int right = strlen(arr2) - 1;//strlen�������ַ�������   �� ���±�

	while (left<=right)
	{
		arr1[left] = arr2[left];
		arr1[right] = arr2[right];

		printf("%s\n", arr1);

		left++;
		right--;
	}

	return 0;
}


//���ֲ��ҷ�
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);//����Ԫ�ظ���
//	int k = 7;//���ҵ���ֵ
//
//	int left = 0;//���±�
//	int right = sz - 1;//���±�
//		
//	while (left<=right)
//	{
//		int mid = (left + right) / 2;//�м�Ԫ���±�
//		if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			printf("�ҵ��ˣ��±���:%d\n", mid);
//			break;
//		}//�ر�ע�����������
//	}
//	if (left > right)
//		printf("�Բ��𣬸�����û��\n");
//
//	return 0;
//
//}


//int main()
//{
//	//��Ŀ:����n�Ľ׳�
//

//	int i = 0;
//	int n = 0;
//	int ret = 1;
//	scanf("%d", &n);
//
//	for (i = 1; i <= n; i++)
//	{
//		ret = ret * i;//�ϴμ����ret��ֵ�����������������Ե��Կ���
//	}
//	printf("%d\n", ret);
//	return 0;
//}

//int main()
//{
//	int n = 0;
//	int i = 0;
//	//scanf("%d", &n);
//
//	int sum = 0;
//	for (n=1;n<=3;n++)
//	{
//		int ret = 1;
//		for (i = 1; i <= n; i++)
//		{
//			ret = ret * i;//����׳�
//		}
//		sum = sum + ret;
//	}
//	printf("sum=%d\n", sum);
//	
//	return 0;
//}

int main()
{
	char password[20] = { 0 };
	int ch = 0;
	int m = 0;

	
	printf("����������:");
	scanf("%s", password);

	printf("��ȷ��(Y/N):>");

	while ((m = getchar()) != '\n')
	{
		;
	}

	ch = getchar();
	if (ch == 'Y')
		printf("ȷ�ϳɹ�\n");//���������⣬��\n��
	else
		printf("����ȷ��\n");



	return 0;
}