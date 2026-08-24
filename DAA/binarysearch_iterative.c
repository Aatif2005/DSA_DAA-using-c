#include <stdio.h>
int binary_search(int nums[], int n, int target) {
    int low = 0;
    int high = n-1;
    while (low <= high) {
        const int mid = low + (high-low) / 2;
        if (nums[mid] == target) {
            return mid;                     // Element found
        }
        else if (nums[mid] < target) {
            low = mid + 1;               // Search right half
        }
        else {
            high = mid - 1;             // Search left half
        }
    }
    return -1;
}
int main() {
    int nums[] = {20, 30, 40, 50, 60, 70,80};
    int n = sizeof(nums) / sizeof(nums[0]);
    int target;
    printf("Enter element to search: ");
    scanf("%d", &target);
    int result = binary_search(nums,n,target);
    if (result != -1) {
        printf("Element found at index %d\n", result);
    }
    else {
        printf("Element not found: ");
    }
    return 0;
}