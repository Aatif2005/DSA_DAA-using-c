#include <stdio.h>

int binary_search(int nums[], const int low, const int high, const int target) {
    // Base case: element not found
    if (low > high) {
        return -1;
    }
    const int mid = low + (high - low) / 2;
    // Element found
    if (nums[mid] == target) {
        return mid;
    }
    // Search in right half
    if (nums[mid] < target) {
        return binary_search(nums, mid + 1, high, target);
    }
    // Search in left half
    return binary_search(nums, low, mid - 1, target);
}
int main() {
    int nums[] = {20, 30, 40, 50, 60, 70, 80};
    int n = sizeof(nums) / sizeof(nums[0]);
    int target;

    printf("Enter element to search: ");
    scanf("%d", &target);

    const int result = binary_search(nums, 0, n - 1, target);

    if (result != -1) {
        printf("Element found at index %d\n", result);
    }
    else {
        printf("Element not found\n");
    }

    return 0;
}