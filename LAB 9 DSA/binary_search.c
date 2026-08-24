#include <stdio.h>

int Binarysearch(int arr[], int left, int right, int key) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key)
            return mid;
        else if (key < arr[mid])
            return Binarysearch(arr, left, mid - 1, key);
        else
            return Binarysearch(arr, mid + 1, right, key);
    }
    return -1;
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key, result;

    printf("Enter the element to search: ");
    scanf("%d", &key);

    result = Binarysearch(arr, 0, n - 1, key);

    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}