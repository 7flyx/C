# define _CRT_SECURE_NO_WARNINGS 



#include <stdio.h>

int main()
{

	int x = 0;
	int i = 0;
	printf("������ɼ���");
	scanf("%d", &x);

	if (x >= 90 && x <= 100)
		i = 1;
	else if (x >= 80 && x < 90)
		i = 2;
	else if (x >= 70 && x < 80)
		i = 3;
	else if (x >= 60 && x < 70)
		i = 4;
	else
		i = 0;

	switch (i)
	{
	case 1:
		printf("A");
		break;
	case 2:
		printf("B");
		break;
	case 3:
		printf("C");
		break;
	case 4:
		printf("D");
		break;
	default:
		printf("E��������");
		break;
	}
	return 0;
}

//쳲��������ҷ������ûƽ�ָ��˼�룬����һ��쳲��������У������е����ֵ��Ҫ�ȱ����ҵ�����size-1�󼴿�
//���磬a[11],쳲��������е������Ҫ����11-1�������Ǵ���10�������쳲��������еĴ�С�Ľ���

int F[20];  //ȫ�ֵ�쳲���������
int Fbi_Serch(int a[], int size, int key)
{
	int low, high, i, k, mid;
	k = 0;
	low = 0; //��������ĵ�һ��Ԫ��
	high = size - 1;  //������������һ��Ԫ��

	while (size > F[k] - 1)  //��λsize��쳲����������λ�ã�����������Ĵ�С��쳲��������е��ĸ�λ��
		k++;
	for (i = size; i < F[k] - 1; i++) 
	{
		//������whileѭ���м����k��ֵ���˴���Ҫ��䱻�������������һ��Ԫ�ص�
		//���磺��������һ��Ԫ��Ϊ99��������Ĵ�СΪ10����k��ֵΪ13���������±�Ϊ11��12����Ҫ���
		a[i] = a[size];  //���ܻᵼ��Խ����ʣ���Ҫ��������Ĵ�С����
	}

	//������������������ͨ���ַ��Ĳ��ң���Щϸ�����ⲻͬ����
	while (low <= high)
	{
		mid = low + F[k - 1] - 1; //ȷ��mid��ֵ������ͨ���ַ���ͬ���ƽ�ָ��
		if (a[mid] > key)
		{
			high = mid - 1;
			k -= 1; //kֵ��Ҫ��1
		}
		else if (a[mid] < key)
		{
			low = mid + 1;
			k -= 2;  //�˴���k��Ҫ��2��������Ĳ�ͬ
		}
		else //��ȵ����
		{
			if (mid <= size)
				return mid;  //�����ʱ��midֵ��ԭ����size�ķ�Χ�࣬˵���ǲ��ҳɹ���
			else
				return size;  //midֵ����ԭ����size�ķ�Χ�࣬�������ں��油���λ���ϡ��ͷ������һ��Ԫ�ص��±�
		}
	}
	return 0; //û���ҵ��������ֱ�ӷ���0
	
}