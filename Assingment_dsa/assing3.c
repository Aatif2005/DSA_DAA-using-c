//Use malloc() function to allocate dynamic memory to store marks of the students obtained in a subject. Then use realloc() function to increase the size of the memory (we want to add marks of some new students). Find the average marks of the students in the subject.//

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m, i;
    float average;

    int * marks;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    marks = (int *) malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        printf("Enter marks for student %d:", i+1);
        scanf("%d", &marks[i]);
    }

    printf("Enter the number of new students to add:");
    scanf("%d", &m);

    marks = (int *) realloc(marks, (n+m) *sizeof(int));

    for (int i = n; i < (n+m); i++)
    {
        printf("Enter marks for student %d:", i+1);
        scanf("%d", &marks[i]);
    }

    int sum = 0;
    for (i = 0; i < (n + m); i++) {
        sum += marks[i];
    }
    average = (float)sum / (n + m);
    printf("Average marks of the students: %.2f\n", average);

    free(marks);

    return 0;
}
