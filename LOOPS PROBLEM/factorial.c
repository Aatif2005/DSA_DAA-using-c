#include <stdio.h>
int main() {
    int n;
    int fact = 1;
    printf("Enter the num for factorial: ");
    scanf("%d",&n);
    for (int i =1; i<= n;i++) {
        fact = fact*i;
        printf("The factorial is %d\n",fact*i);
    }
    printf("The fact of number is = %d",fact);
}