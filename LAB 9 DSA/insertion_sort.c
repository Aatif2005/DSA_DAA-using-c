#include <stdio.h>

void insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {64, 25, 12, 38, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Before: ");
    printArray(arr, size);

    insertionSort(arr, size);

    printf("After:  ");
    printArray(arr, size);

    return 0;
}