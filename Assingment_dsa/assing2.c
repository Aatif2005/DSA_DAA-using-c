//  Ask the user to enter the total number of students in the class. //Enter marks of the students (max marks:100) in 5 subjects using a 2-dimensional array. Print total marks percentage obtained by each student.//
#include <stdio.h>

int main() {

    int n;

    printf("Enter the number of students:");
    scanf("%d", &n);

    int marks[n][5];
    int total[n];
    int i, j;

    for(i = 0; i < n; i++) {

        total[i] = 0; 
        printf("Enter marks for student %d:\n", i + 1);

        for(j = 0; j < 5; j++) {

            printf(" Subject %d: ", j + 1);
            scanf("%d", &marks[i][j]);

            total[i] += marks[i][j];
        }
    }
    for(i = 0; i < n; i++) {
        float percentage = (total[i] / 500.0) * 100; 
        printf("Total marks percentage for student %d: %.2f%%\n", i + 1, percentage);
    }
    return 0;
}