#include <stdio.h>
int main() {
    int num,original,remainder,digit = 0;
    double sum = 0;
    printf("Enter the number: ");
    scanf("%d",&num);
    original = num;
    while (num!=0) {
        digit++;
        num = num/10;
    }
    num = original;
    while (num!=0) {4
        remainder = num%10;
        sum = sum + pow(remainder, digit);
        num = num/10;
    }
    if ((int)sum == original) {
        printf("%d is amstrong number",original);
    }
    else {
        printf("The number is not amstrong %d",original);
    }
    return 0;
}

