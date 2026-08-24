#include <stdio.h>
int main() {
     int n;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    int marks[n][2]; 
    int total[n];
    int i;

    for(i = 0; i < n; i++) {
        printf("Enter theory marks for student %d: ", i + 1);
        scanf("%d", &marks[i][0]);

        printf("Enter lab marks for student %d: ", i + 1);
        scanf("%d", &marks[i][1]);

        total[i] = marks[i][0] + marks[i][1];
    }

    printf("\nTotal marks of students:\n");
    for(i = 0; i < n; i++) {
        printf("Student %d: %d\n", i + 1, total[i]);
    }

    return 0;
}
