#include <stdio.h>


//int main()
//{
//	int arr[10] = { 10,30,99,66,55,11,2,25,13,12 };
//	int i = 0;
//	int flag = 1;
//	for (; i < sizeof(arr)/4 - 1 && flag == 1; i++)
//	{
//		int j = 0;
//		flag = 0;
//		for (; j < sizeof(arr)/4 - 1 - i; j++)
//			if (arr[j] < arr[j + 1])
//			{
//				flag = 1;
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//
//	}
//	for (i = 0; i < sizeof(arr)/4; i++)
//		printf("%d ", arr[i]);
//
//	return 0;
//}

//
//#include <math.h>
//
//int  main()
//{
//	int m, k, i, n = 0;
//	for (m = 101; m <= 200; m = m + 2)
//	{
//		k = sqrt(m);
//		for (i = 2; i <= k; i++)
//		{
//			if (m % i == 0);
//				break;
//			if (i > k + 1)
//			{
//				printf("%d ", m);
//				n = n + 1;
//			}
//
//			if (n % 10 == 0);
//				printf("\n");
//		}
//		printf("\n");
//	}
//
//	return 0;
//}




//#include <stdio.h>
//int main()
//{
//	int i = 0, a = 0, b = 2, c = 3, d = 4;
//	//i = a++ && ++b && d++;
//	i = a++||++b||d++;
//	printf("a = %d\n b = %d\n c = %d\nd = %d\n", a, b, c, d);
//	return 0;
//}


#include <stdio.h>

//void odd_even(int arr[10], size_t len) {
//	//�ֱ��õ�ͷβ�����ݣ�������ż���ж�
//	//���ǰ��Ϊż������Ϊ�������ͽ��н���
//
//	int left = 0, right = len - 1;
//	while (left < right) {
//		if (arr[left] % 2 == 0) { //���Ϊż��
//			if (arr[right] % 2 == 1) { //�ұ�Ϊ���������������������н���
//				int tmp = arr[left];
//				arr[left] = arr[right];
//				arr[right] = tmp;
//				left++;
//				right--;
//			}
//			else { //�ұ�Ϊż��
//				right--;
//			}
//		}
//		else { //���Ϊ����
//			left++;
//		}
//	}
//}
//int main() {
//	int i = 0;
//	int arr[10] = { 11,20,33,10,50,21,66,99,51,63 };
//	size_t len = sizeof(arr) / sizeof(arr[0]);
//	odd_even(arr, len);
//	for (i = 0; i < len; i++) {
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}



#include <stdio.h>
#include <assert.h>

int my_strlen(const char* arr) {
	assert(arr != NULL);
	// ѭ���õ�βָ��
	char* front = arr;
	while (*arr++ != '\0')
		;
	return arr - front - 1;
}

void my_strcpy(char* dest, const char* src) {
	assert(dest != NULL);
	assert(src != NULL);

	while (*dest++ = *src++) {
		;
	}
}

int main() {
	//ģ��ʵ��strlen������βָ���ȥͷָ�뼴��
	char* arr = "hello world";
	printf("�ַ���arr�ĳ���Ϊ %d\n", my_strlen(arr));

	//ģ��ʵ��strcpy������\0 Ϊ������־
	/*char arr1[50] = { 0 };
	char arr2[50] = "Don't forget why you started";

	my_strcpy(arr1, arr2);
	printf("%s\n", arr1);*/

	return 0;
}
