#include <stdio.h>
int main() {
    int num, remainder,reverse = 0;
    printf("Enter the number ");
    scanf("%d",&num);
    while (num!=0) {
        remainder = num %10;
        num = num/10;
        reverse = reverse*10+remainder;
    }
    printf("Reverse of the number is %d ",reverse);
    return 0;
}