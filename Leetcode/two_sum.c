#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* arr, int size, int target) {

    int i = 0;
    int j = size - 1;

    int* ans = (int*)malloc(2 * sizeof(int));

    while (i < j) {

        int sum = arr[i] + arr[j];

        if (sum == target) {

            // 1-based indexing
            ans[0] = i + 1;
            ans[1] = j + 1;

            return ans;
        }

        else if (sum < target) {
            i++;
        }

        else {
            j--;
        }
    }
    /* *returSize = 2
    return ans;*/
    return NULL;
}

int main() {

    int arr[] = {2, 7, 11, 15};
    int target = 9;

    int size = sizeof(arr) / sizeof(arr[0]);

    int* result = twoSum(arr, size, target);

    printf("[%d, %d]", result[0], result[1]);

    free(result);

    return 0;
}