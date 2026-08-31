#include <stdio.h>

// Partition function
int partition(int nums[], int low, int high) {
    int pivot = nums[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (nums[j] < pivot) {
            i++;

            // Swap nums[i] and nums[j]
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }

    // Place pivot in its correct position
    int temp = nums[i + 1];
    nums[i + 1] = nums[high];
    nums[high] = temp;

    return i + 1;
}

// Quick Sort function
void quick_sort(int nums[], int low, int high) {

    if (low < high) {

        // Find pivot position
        int pivot = partition(nums, low, high);

        // Sort left part
        quick_sort(nums, low, pivot - 1);

        // Sort right part
        quick_sort(nums, pivot + 1, high);
    }
}

int main() {

    int nums[] = {8, 3, 8, 1, 3, 5};

    const int n = sizeof(nums) / sizeof(nums[0]);

    quick_sort(nums, 0, n - 1);

    printf("Sorted array: ");

    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}