#include <stdio.h>
int main() {
    int n =0;
    for (int i = 20; i<=40; i++) {
        if (i%2 == 0) {
            n = n+i;
            printf("The even number are = %d\n",i);
        }
    }
    printf("The sum first 10 number is = %d",n);
}