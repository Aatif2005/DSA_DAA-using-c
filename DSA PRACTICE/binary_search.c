/*#include <stdio.h>

int binarySearch(int arr[], int size, int target)
{
    int left = 0, right = size - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2; // Avoids overflow

        if (arr[mid] == target)
            return mid; // Found! Return index
        else if (arr[mid] < target)
            left = mid + 1; // Search right half
        else
            right = mid - 1; // Search left half
    }

    return -1; // Not found
}

int main()
{
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 67, 90};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 23;

    int result = binarySearch(arr, size, target);

    if (result != -1)
        printf("Found %d at index %d\n", target, result);
    else
        printf("%d not found in array\n", target);

    return 0;
}*/

#include <stdio.h>
int binarysearch(int arr[], int size, int target)
{
    it left = 0, right = size - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(int);
    int target = 5;
    int searchIndex = binarysearch(arr, size, target);
    if (searchIndex != -1)
    {
        printf("The element %d was found at index %d\n", target, searchIndex);
    }
    else
    {
        printf("%d not found in array\n", target);
    }
    return 0;
}