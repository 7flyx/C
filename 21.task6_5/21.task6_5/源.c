#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAXNUM 20  //数组最大元素个数


void swap(int arr[], int L, int R)
{
    int tmp = arr[L];
    arr[L] = arr[R];
    arr[R] = tmp;
}

//冒泡排序
void BubbleSort(int arr[], int arrLength)
{
    if (arr == NULL)
        return; //空指针，提前退出

    int i = 0;
    int flag = 0; //因为C语言没有bool类型，就以整形代替。 
    for (i = 0; i < arrLength - 1 && flag != 1; i++) //一次循环完后，flag还是1，则有序
    {
        int j = 0;
        flag = 1;
        for (j = 0; j < arrLength - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1]) //升序
            {
                swap(arr, j, j + 1);
                flag = 0; //如果if语句进来后，则说明当前数组还是无序的
            }
        }
    }
}


//选择排序
void selectSort(int arr[], int arrLength)
{
    if (arr == NULL)
        return; //空指针，提前退出

    int i, j, minIndex;
    for (i = 0; i < arrLength; i++)
    {
        minIndex = i;
        for (j = i + 1; j < arrLength; j++)
        {
            if (arr[minIndex] < arr[j])
                minIndex = j; //保存最小值的下标
        }
        if (minIndex != i)
            swap(arr, minIndex, i); //如果minIndex不是i，说明有最小值
    }
}


//插入排序
void insertSort(int arr[], int arrLength)
{
    if (arr == NULL)
        return; //空指针，提前退出

    int i = 0;
    int j = 0;
    for (i = 1; i < arrLength; i++)
    {
        int insertValue = arr[i];
        for (j = i - 1; j >= 0 && insertValue < arr[j]; j--) //insertValue < arr[j]
        {
            arr[j + 1] = arr[j]; //前一个数据往后移动
        }
        if (insertValue != arr[i]) //如果经过循环后，这两个不相等，说明循环里面移动过数据
            arr[++j] = insertValue; //这里值得注意的是，for循环停止时，j-- 已经自减了
    }
}


//归并排序
void merge(int arr[], int left, int mid, int right)
{
    int help[MAXNUM] = { 0 }; //用于临时存储两个数组合并时的有序数组
    int i = 0; //指向help数组
    int p1 = left; //指向左数组
    int p2 = mid + 1; //指向右数组
    while (p1 <= mid && p2 <= right)
        help[i++] = arr[p1] < arr[p2] ? arr[p1++] : arr[p2++]; //谁更小，就放入help数组

    while (p1 <= mid)  //左边数组还有数据，就放入help
        help[i++] = arr[p1++];

    while (p2 <= right) //右边数组还有数据，就放入help
        help[i++] = arr[p2++];

    //将help数组的所有数据按照顺序放入原数组arr
    int j = 0;
    for (j = 0; j < i; j++)
        arr[left + j] = help[j];
}
void mergerSort(int arr[], int left, int right)
{
    if (arr == NULL || left == right)
        return;
    int mid = left + ((right - left) >> 1); //取中间数，也就是 （left + right）/2
    mergerSort(arr, left, mid); //递归调用左数组
    mergerSort(arr, mid + 1, right); //递归调用右数组
    merge(arr, left, mid, right); //左右数组分别有序后，合并到一起
}


//快速排序
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

    int minRange = left - 1; //<区范围
    int maxRange = right; //>区范围，将最后一个元素先放到>区范围，总共整体排序后，与>区的第一个元素交换
    int index = left; //循环判断的索引值

    while (index < maxRange) //索引值不跟>区范围遇到，循环继续
    {
        if (arr[index] < arr[right])
            swap(arr, index++, ++minRange); //放入<区，过后，索引值index++
        else if (arr[index] > arr[right])
            swap(arr, index, --maxRange); //放入>区,过后，索引值不变，因为从>区过来的值还不知道是大是小，所以还需要判断
        else
            index++; //相等的话，不交换，索引值index++即可
    }

    swap(arr, maxRange, right); //>区的第一个元素与数组的最后一个元素交换
    *LMid = minRange + 1; //等于区的第一个元素
    *RMid = maxRange; //等于区的最后一个元素
}
void process(int arr[], int left, int right)
{
    if (left >= right)
        return;

    //随机数srand放入主函数
    swap(arr, left + rand() % (right - left + 1), right); //从数组中随机抽取一个元素与数组最后的元素交换位置
                                                        //这里也是快排时间复杂度变为O（N logN）的原因

    int LMid, RMid; //三个区中，等于区的第一个元素下标，和最后一个元素下标----也就是上面文字解释中的{40,40}的下标
    netherlandsFlag(arr, left, right, &LMid, &RMid); //就是上面解释的，将数组分为三个区
    process(arr, left, LMid - 1); //递归调用 <区的数据，上面文字解释中的 {10,30,20}
    process(arr, RMid + 1, right); //递归调用 >区的数据，上面文字解释中的 {50,60}
}
void quickSort(int arr[], int arrLength)
{
    if (arr == NULL || arrLength < 2)
        return;
    process(arr, 0, arrLength - 1);
}


//堆排序
void heapInsert(int arr[], int index)
{
    //数组是以下标为0处开始放入数据的
    //则根结点和左右孩子有以下关系
    //index 的根结点index/2, index的 左孩子为index*2+1，右孩子就是index*2+2
    //新插入的结点，插入到叶子结点处，然后去寻找父节点，判断二者之间的大小，比父节点大的话，就要往上移动
    while (arr[index] > arr[(index - 1) / 2])
    {
        swap(arr, index, (index - 1) / 2);
        index = (index - 1) / 2;
    }
}
void heapify(int arr[], int index, int heapSize)
{
    int leftChild = index * 2 + 1; //拿到左孩子的结点下标
    while (leftChild < heapSize)
    {
        int maxChild = leftChild + 1 < heapSize && arr[leftChild] < arr[leftChild+ 1] ?
        leftChild + 1 : leftChild; //判断左右孩子的大小
        maxChild = arr[index] > arr[maxChild] ? index : maxChild; //判断根结点与左右孩子中最大的 那个孩子的  大小

        if (maxChild == index) //如果最大数值下标就是index，说明不需要向下层移动
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
        heapInsert(arr, i); //大根堆的形式插入

    //经过上面的循环之后，形成了大根堆。此时就将根结点的数据与数组中最后一个元素进行交换
    //交换之后，根结点的数据并不是此时这颗树的最大值，所有将这个结点的数据往下层移动
    int heapSize = arrLength;
    swap(arr, 0, --heapSize);
    while (heapSize > 0)
    {
        heapify(arr, 0, heapSize); //判断左右孩子结点和根结点的关系，条件成立，就往下层移动
        swap(arr, 0, --heapSize);
    }
}



int main()
{
    int i;
    int arr[10] = { 20,10,30,60,90,100,111,44,21,99 };
    srand((unsigned) time(NULL));

    //BubbleSort(arr, 10); //冒泡排序
    //selectSort(arr, 10); //选择排序
    //insertSort(arr, 10); //插入排序
    //mergerSort(arr, 0, 9); //归并排序
    //quickSort(arr, 10); //快速排序
    //heapSort(arr, 10); //堆排序

    for (i = 0; i < 10; i++)
        printf("%d ", arr[i]);
	return 0;
}