# define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

void sort(int arr[], int size)
{
    int i, j, tmp;
    for (i = 0; i < size-1; i++)
    {
        for (j = 0; j < size - i-1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}
int main()
{

    int i = 0;
    int arr[10] = { 1,3,2,5,6,7,4,8,10,9 };
    int size = 10;

    sort(arr, size);
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);

    return 0;
}
