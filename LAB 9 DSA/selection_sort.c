#include <stdio.h>

void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minIdx = i;

        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIdx])
            {
                minIdx = j;
            }
        }

        if (minIdx != i)
        {
            int ptr = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = ptr;
        }
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

    selectionSort(arr, size);

    printf("After:  ");
    printArray(arr, size);

    return 0;
}