#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAXNUM 20  //�������Ԫ�ظ���


void swap(int arr[], int L, int R)
{
    int tmp = arr[L];
    arr[L] = arr[R];
    arr[R] = tmp;
}

//ð������
void BubbleSort(int arr[], int arrLength)
{
    if (arr == NULL)
        return; //��ָ�룬��ǰ�˳�

    int i = 0;
    int flag = 0; //��ΪC����û��bool���ͣ��������δ��档 
    for (i = 0; i < arrLength - 1 && flag != 1; i++) //һ��ѭ�����flag����1��������
    {
        int j = 0;
        flag = 1;
        for (j = 0; j < arrLength - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1]) //����
            {
                swap(arr, j, j + 1);
                flag = 0; //���if����������˵����ǰ���黹�������
            }
        }
    }
}


//ѡ������
void selectSort(int arr[], int arrLength)
{
    if (arr == NULL)
        return; //��ָ�룬��ǰ�˳�

    int i, j, minIndex;
    for (i = 0; i < arrLength; i++)
    {
        minIndex = i;
        for (j = i + 1; j < arrLength; j++)
        {
            if (arr[minIndex] < arr[j])
                minIndex = j; //������Сֵ���±�
        }
        if (minIndex != i)
            swap(arr, minIndex, i); //���minIndex����i��˵������Сֵ
    }
}


//��������
void insertSort(int arr[], int arrLength)
{
    if (arr == NULL)
        return; //��ָ�룬��ǰ�˳�

    int i = 0;
    int j = 0;
    for (i = 1; i < arrLength; i++)
    {
        int insertValue = arr[i];
        for (j = i - 1; j >= 0 && insertValue < arr[j]; j--) //insertValue < arr[j]
        {
            arr[j + 1] = arr[j]; //ǰһ�����������ƶ�
        }
        if (insertValue != arr[i]) //�������ѭ��������������ȣ�˵��ѭ�������ƶ�������
            arr[++j] = insertValue; //����ֵ��ע����ǣ�forѭ��ֹͣʱ��j-- �Ѿ��Լ���
    }
}


//�鲢����
void merge(int arr[], int left, int mid, int right)
{
    int help[MAXNUM] = { 0 }; //������ʱ�洢��������ϲ�ʱ����������
    int i = 0; //ָ��help����
    int p1 = left; //ָ��������
    int p2 = mid + 1; //ָ��������
    while (p1 <= mid && p2 <= right)
        help[i++] = arr[p1] < arr[p2] ? arr[p1++] : arr[p2++]; //˭��С���ͷ���help����

    while (p1 <= mid)  //������黹�����ݣ��ͷ���help
        help[i++] = arr[p1++];

    while (p2 <= right) //�ұ����黹�����ݣ��ͷ���help
        help[i++] = arr[p2++];

    //��help������������ݰ���˳�����ԭ����arr
    int j = 0;
    for (j = 0; j < i; j++)
        arr[left + j] = help[j];
}
void mergerSort(int arr[], int left, int right)
{
    if (arr == NULL || left == right)
        return;
    int mid = left + ((right - left) >> 1); //ȡ�м�����Ҳ���� ��left + right��/2
    mergerSort(arr, left, mid); //�ݹ����������
    mergerSort(arr, mid + 1, right); //�ݹ����������
    merge(arr, left, mid, right); //��������ֱ�����󣬺ϲ���һ��
}


//��������
void netherlandsFlag(int arr[], int left, int right, int* LMid, int* RMid)
{
    if (left > right)
    {
        *LMid = *RMid = -1;
        return;
    }
    if (left == right)
    {
        *LMid = *RMid = left;
        return;
    }

    int minRange = left - 1; //<����Χ
    int maxRange = right; //>����Χ�������һ��Ԫ���ȷŵ�>����Χ���ܹ������������>���ĵ�һ��Ԫ�ؽ���
    int index = left; //ѭ���жϵ�����ֵ

    while (index < maxRange) //����ֵ����>����Χ������ѭ������
    {
        if (arr[index] < arr[right])
            swap(arr, index++, ++minRange); //����<������������ֵindex++
        else if (arr[index] > arr[right])
            swap(arr, index, --maxRange); //����>��,��������ֵ���䣬��Ϊ��>��������ֵ����֪���Ǵ���С�����Ի���Ҫ�ж�
        else
            index++; //��ȵĻ���������������ֵindex++����
    }

    swap(arr, maxRange, right); //>���ĵ�һ��Ԫ������������һ��Ԫ�ؽ���
    *LMid = minRange + 1; //�������ĵ�һ��Ԫ��
    *RMid = maxRange; //�����������һ��Ԫ��
}
void process(int arr[], int left, int right)
{
    if (left >= right)
        return;

    //�����srand����������
    swap(arr, left + rand() % (right - left + 1), right); //�������������ȡһ��Ԫ������������Ԫ�ؽ���λ��
                                                        //����Ҳ�ǿ���ʱ�临�Ӷȱ�ΪO��N logN����ԭ��

    int LMid, RMid; //�������У��������ĵ�һ��Ԫ���±꣬�����һ��Ԫ���±�----Ҳ�����������ֽ����е�{40,40}���±�
    netherlandsFlag(arr, left, right, &LMid, &RMid); //����������͵ģ��������Ϊ������
    process(arr, left, LMid - 1); //�ݹ���� <�������ݣ��������ֽ����е� {10,30,20}
    process(arr, RMid + 1, right); //�ݹ���� >�������ݣ��������ֽ����е� {50,60}
}
void quickSort(int arr[], int arrLength)
{
    if (arr == NULL || arrLength < 2)
        return;
    process(arr, 0, arrLength - 1);
}


//������
void heapInsert(int arr[], int index)
{
    //���������±�Ϊ0����ʼ�������ݵ�
    //����������Һ��������¹�ϵ
    //index �ĸ����index/2, index�� ����Ϊindex*2+1���Һ��Ӿ���index*2+2
    //�²���Ľ�㣬���뵽Ҷ�ӽ�㴦��Ȼ��ȥѰ�Ҹ��ڵ㣬�ж϶���֮��Ĵ�С���ȸ��ڵ��Ļ�����Ҫ�����ƶ�
    while (arr[index] > arr[(index - 1) / 2])
    {
        swap(arr, index, (index - 1) / 2);
        index = (index - 1) / 2;
    }
}
void heapify(int arr[], int index, int heapSize)
{
    int leftChild = index * 2 + 1; //�õ����ӵĽ���±�
    while (leftChild < heapSize)
    {
        int maxChild = leftChild + 1 < heapSize && arr[leftChild] < arr[leftChild+ 1] ?
        leftChild + 1 : leftChild; //�ж����Һ��ӵĴ�С
        maxChild = arr[index] > arr[maxChild] ? index : maxChild; //�жϸ���������Һ��������� �Ǹ����ӵ�  ��С

        if (maxChild == index) //��������ֵ�±����index��˵������Ҫ���²��ƶ�
            break;
        swap(arr, index, maxChild);
        index = maxChild;
        leftChild = index * 2 + 1;
    }
}
void heapSort(int arr[], int arrLength)
{
    if (arr == NULL || arrLength < 2)
        return;

    int i = 0;
    for (i = 0; i < arrLength; i++)
        heapInsert(arr, i); //����ѵ���ʽ����

    //���������ѭ��֮���γ��˴���ѡ���ʱ�ͽ����������������������һ��Ԫ�ؽ��н���
    //����֮�󣬸��������ݲ����Ǵ�ʱ����������ֵ�����н���������������²��ƶ�
    int heapSize = arrLength;
    swap(arr, 0, --heapSize);
    while (heapSize > 0)
    {
        heapify(arr, 0, heapSize); //�ж����Һ��ӽ��͸����Ĺ�ϵ�����������������²��ƶ�
        swap(arr, 0, --heapSize);
    }
}



int main()
{
    int i;
    int arr[10] = { 20,10,30,60,90,100,111,44,21,99 };
    srand((unsigned) time(NULL));

    //BubbleSort(arr, 10); //ð������
    //selectSort(arr, 10); //ѡ������
    //insertSort(arr, 10); //��������
    //mergerSort(arr, 0, 9); //�鲢����
    //quickSort(arr, 10); //��������
    //heapSort(arr, 10); //������

    for (i = 0; i < 10; i++)
        printf("%d ", arr[i]);
	return 0;
}