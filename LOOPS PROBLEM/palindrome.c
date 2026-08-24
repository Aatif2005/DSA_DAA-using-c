#include <stdio.h>

int main() {
    int num, reverse = 0, remainder, original;

    printf("Enter a number: ");
    scanf("%d", &num);

    original = num;

    // Reverse the number
    while (num != 0) {
        remainder = num % 10;
        reverse = reverse * 10 + remainder;
        num = num / 10;
    }

    if (original == reverse) {
        printf("%d is a Palindrome \n", original);
    } else {
        printf("%d is NOT a Palindrome \n", original);
    }

    return 0;
}