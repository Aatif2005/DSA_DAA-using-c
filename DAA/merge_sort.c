#include <stdio.h>

void merge(int nums[], int low, int mid, int high) {
    int i = low;
    int j = mid + 1;
    int k = 0;

    int temp[high - low + 1];

    // Compare elements from both halves
    while (i <= mid && j <= high) {
        if (nums[i] <= nums[j]) {
            temp[k] = nums[i];
            i++;
        }
        else {
            temp[k] = nums[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements from left half
    while (i <= mid) {
        temp[k] = nums[i];
        i++;
        k++;
    }

    // Copy remaining elements from right half
    while (j <= high) {
        temp[k] = nums[j];
        j++;
        k++;
    }

    // Copy sorted elements back to original array
    for (i = low, k = 0; i <= high; i++, k++) {
        nums[i] = temp[k];
    }
}

void merge_sort(int arr[], int low, int high) {

    if (low < high) {
       const int mid = low + (high - low) / 2;

        // Sort left half
        merge_sort(arr, low, mid);

        // Sort right half
        merge_sort(arr, mid + 1, high);

        // Merge both halves
        merge(arr, low, mid, high);
    }
}

int main() {
    int nums[] = {50, 20, 40, 10, 30, 60, 80};
    const int n = sizeof(nums) / sizeof(nums[0]);

    merge_sort(nums, 0, n - 1);

    printf("Sorted array: ");

    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}