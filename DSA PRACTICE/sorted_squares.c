#include <stdio.h>
#include <stdlib.h>

void displayArr(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/* Two pointers: largest squares sit at the ends of a sorted array.
   Fill result from right to left — O(n) time, O(n) space. */
int *sortedSquares(int *nums, int numsSize, int *returnSize) {
    int *result = (int *)malloc(numsSize * sizeof(int));
    if (result == NULL) {
        *returnSize = 0;
        return NULL;
    }

    int left = 0;
    int right = numsSize - 1;
    int k = numsSize - 1;

    while (left <= right) {
        int leftSq = nums[left] * nums[left];
        int rightSq = nums[right] * nums[right];

        if (leftSq > rightSq) {
            result[k--] = leftSq;
            left++;
        } else {
            result[k--] = rightSq;
            right--;
        }
    }

    *returnSize = numsSize;
    return result;
}

int main(void) {
    int nums[] = {-7, -3, 2, 3, 11};
    int n = sizeof(nums) / sizeof(nums[0]);
    int returnSize;

    printf("Original: ");
    displayArr(nums, n);

    int *ans = sortedSquares(nums, n, &returnSize);

    printf("Squared (sorted): ");
    displayArr(ans, returnSize);

    free(ans);
    return 0;
}
